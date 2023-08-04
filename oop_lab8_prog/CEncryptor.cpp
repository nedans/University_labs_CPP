#include <iostream>
#include <sstream>
#include "CEncryptor.h"
#include "CExceptions.h"

CEncryptor::CEncryptor() : cData(nullptr), iShiftValue(1) {}

CEncryptor::CEncryptor(const char* data) {
	cData = nullptr;
	for (int i = 0; i < strlen(data); ++i) {
		if (isalpha(data[i]) == 0) {
			if (data[i] == ' ') { continue; }
			throw CExceptionNonSymbol();
			//std::stringstream str;
			//str.fail();
		}
	}
	
	cData = new char[strlen(data) + 1];
	strcpy_s(cData, strlen(data) + 1, data);
}

CEncryptor::CEncryptor(const char* data, const int shift_value){
	cData = nullptr;

	if (shift_value == 0) {
		throw CExceptionZeroShiftValue();
	}

	for (int i = 0; i < strlen(data); ++i) {
		if (isalpha(data[i]) == 0) {
			if (data[i] == ' ') { continue; }
			throw CExceptionNonSymbol();
		}
	}

	iShiftValue = shift_value;
	
	cData = new char[strlen(data) + 1];
	strcpy_s(cData, strlen(data) + 1, data);
}

CEncryptor::CEncryptor(const CEncryptor& other) {
	cData = nullptr;

	if (other.iShiftValue == 0) {
		throw CExceptionZeroShiftValue();
	}
	for (int i = 0; i < strlen(other.cData); ++i) {
		if (isalpha(other.cData[i]) == 0) {
			if (other.cData[i] == ' ') { continue; }
			throw CExceptionNonSymbol();
		}
	}

	iShiftValue = other.iShiftValue;

	
	cData = new char[strlen(other.cData) + 1];
	strcpy_s(cData, strlen(other.cData) + 1, other.cData);
}

CEncryptor::CEncryptor(CEncryptor&& other) noexcept {
	cData = other.cData;
	delete[] other.cData;
	iShiftValue = other.iShiftValue;
	other.iShiftValue = 0;
}

CEncryptor::~CEncryptor() noexcept{
	delete[] cData;
}

void CEncryptor::SetData(const char* sData) {
	delete[] cData;
	cData = nullptr;

	for (int i = 0; i < strlen(sData); ++i) {
		if (isalpha(sData[i]) == 0) {
			if (sData[i] == ' ') { continue; }

			delete[] cData;
			cData = nullptr;

			throw CExceptionNonSymbol();
		}
	}

	cData = new char[strlen(sData) + 1];
	strcpy_s(cData, strlen(sData) + 1, sData);
}

void CEncryptor::SetShiftValue(const int value) {
	if (value == 0) {
		throw CExceptionZeroShiftValue();
	}

	iShiftValue = value;
}

char* CEncryptor::GetData() const noexcept {
	return cData;
}

int CEncryptor::GetShiftValue() const noexcept {
	return iShiftValue;
}

void CEncryptor::Encrypt() noexcept {
	for (int i = 0; i < strlen(cData); ++i) {
		if (cData[i] == ' ') {
			continue;
		}
		if (isprint(static_cast<char>(cData[i]) + iShiftValue)) {
			cData[i] = static_cast<char>(cData[i]) + iShiftValue;
		}
	}
}

void CEncryptor::Decrypt() noexcept {
	for (int i = 0; i < strlen(cData); ++i) {
		if (cData[i] == ' ') {
			continue;
		}
		if (isprint(static_cast<char>(cData[i]) - iShiftValue)) {
			cData[i] = static_cast<char>(cData[i]) - iShiftValue;
		}
	}
}

CEncryptor& CEncryptor::operator ++ () noexcept {
	Encrypt();
	return *this;
}

CEncryptor CEncryptor::operator ++ (int value) noexcept {
	CEncryptor temp(*this);
	++(*this);
	return temp;
}

CEncryptor& CEncryptor::operator--() noexcept {
	Decrypt();
	return *this;
}

CEncryptor CEncryptor::operator--(int) noexcept {
	CEncryptor temp(*this);
	--(*this);
	return temp;
}

CEncryptor& CEncryptor::operator=(const CEncryptor& other)
{
	delete[] cData;
	cData = new char[strlen(other.cData) + 1];
	strcpy_s(cData, strlen(other.cData) + 1, other.cData);

	iShiftValue = other.iShiftValue;

	return *this;
}

CEncryptor& CEncryptor::operator=(CEncryptor&& other) noexcept {
	delete[] cData;
	cData = new char[strlen(other.cData) + 1];
	strcpy_s(cData, strlen(other.cData) + 1, other.cData);
	iShiftValue = other.iShiftValue;
	other.iShiftValue = 0;

	return *this;
}



bool operator==(CEncryptor& left, CEncryptor& right) noexcept{
	return (strcmp(left.cData, right.cData) == 0) && left.iShiftValue == right.iShiftValue;
}


std::ostream& operator << (std::ostream& output, const CEncryptor& other) noexcept {
	output << other.cData;
	if (output.fail()) throw COutputException();
	return output;
}

std::istream& operator >> (std::istream& input, CEncryptor& other)
{
	int num{ 0 };
	input >> num;
	if (input.fail()) throw CInputException();

	++num;
	delete[] other.cData;
	other.cData = new char[num];
	input.ignore();
	input.getline(other.cData, num);
	if (input.fail()) throw CInputException();

	for (int i = 0; i < num; ++i) {
		if (isalpha(other.cData[i]) == 0) {
			throw CExceptionNonSymbol();

			delete other.cData;
			other.cData = nullptr;
		}
	}

	return input;
}
