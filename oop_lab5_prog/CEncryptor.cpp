#include <iostream>
#include <cstring>
#include <string>
#include "CEncryptor.h"

using namespace std;

CEncryptor::CEncryptor(char* data){

	cData = new char[strlen(data) + 1];
	strcpy_s(cData, strlen(data) + 1, data);
}

CEncryptor::CEncryptor(char* data, int shift_value) : iShiftValue(shift_value) {
	cData = new char[strlen(data) + 1];
	strcpy_s(cData, strlen(data) + 1, data);
}

CEncryptor::CEncryptor(const CEncryptor& other) : iShiftValue(other.iShiftValue) {
	SetData(other.cData);
}

CEncryptor::CEncryptor(CEncryptor&& other) noexcept {
	cData = other.cData;
	delete[] other.cData;
	iShiftValue = other.iShiftValue;
	other.iShiftValue = 0;
}

CEncryptor::~CEncryptor() {
	delete[] cData;
}

void CEncryptor::SetData(const char* sData) {
	delete cData;
	cData = nullptr;
	cData = new char[strlen(sData) + 1];
	strcpy_s(cData, strlen(sData) + 1, sData);
}

void CEncryptor::SetShiftValue(const int value) {
	iShiftValue = value;
}

char* CEncryptor::GetData() const {
	return cData;
}

int CEncryptor::GetShiftValue() const {
	return iShiftValue;
}

void CEncryptor::Encrypt(){
	for (int i = 0; i < strlen(cData); ++i) {
	    if (cData[i] == ' ') {
	        continue;
	    }
	    if (isprint(static_cast<char>(cData[i]) + iShiftValue)) {
	        cData[i] = static_cast<char>(cData[i]) + iShiftValue;
	    }
	}
}

void CEncryptor::Decrypt(){
	for (int i = 0; i < strlen(cData); ++i) {
		if (cData[i] == ' ') {
			continue;
		}
		if (isprint(static_cast<char>(cData[i]) - iShiftValue)) {
			cData[i] = static_cast<char>(cData[i]) - iShiftValue;
		}
	}
}

CEncryptor& CEncryptor::operator ++ () {
	Encrypt();
	return *this;
}

CEncryptor CEncryptor::operator ++ (int value)
{
	CEncryptor temp(*this);
	++(*this);
	return temp;
}

CEncryptor& CEncryptor::operator--(){
	Decrypt();
	return *this;
}

CEncryptor CEncryptor::operator--(int)
{
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

CEncryptor& CEncryptor::operator=(CEncryptor&& other) noexcept
{
	delete[] cData;
	cData = new char[strlen(other.cData) + 1];
	strcpy_s(cData, strlen(other.cData) + 1, other.cData);
	iShiftValue = other.iShiftValue;
	other.iShiftValue = 0;

	return *this;
}



bool operator==(CEncryptor& left, CEncryptor& right)
{
	return (strcmp(left.cData, right.cData) == 0) && left.iShiftValue == right.iShiftValue;
}

ostream& operator << (ostream& output, const CEncryptor& other) {
	output << other.cData;
	return output;
}

istream& operator >> (istream& input, CEncryptor& other)
{
	int num{0};
	input >> num;
	++num;
	delete[] other.cData;
	other.cData = new char[num];
	input.ignore();
	input.getline(other.cData, num);

	return input;
}
