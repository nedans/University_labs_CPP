#include <iostream>
#include <cstring>
#include <string>
#include <memory>
#include "SmartPointerCEncryptor.h"

using namespace std;

SmartPointerCEncryptor::SmartPointerCEncryptor(char* data) : cData(make_unique<char[]>(strlen(data) + 1))
{
	strcpy_s(cData.get(), strlen(data) + 1, data);
}

SmartPointerCEncryptor::SmartPointerCEncryptor(char* data, int shift_value) : cData(make_unique<char[]>(strlen(data) + 1)), iShiftValue(shift_value)
{
	strcpy_s(cData.get(), strlen(data) + 1, data);
}

SmartPointerCEncryptor::SmartPointerCEncryptor(const SmartPointerCEncryptor& other) : iShiftValue(other.iShiftValue) {
	SetData(other.GetData());
}

SmartPointerCEncryptor::SmartPointerCEncryptor(SmartPointerCEncryptor&& other) noexcept: cData(move(other.cData)), iShiftValue(other.iShiftValue) {
	other.iShiftValue = 0;
}

void SmartPointerCEncryptor::SetData(const char* sData) {
	cData.reset();
	cData = make_unique<char[]>(strlen(sData) + 1);
	strcpy_s(cData.get(), strlen(sData) + 1, sData);
}

void SmartPointerCEncryptor::SetShiftValue(const int value) {
	iShiftValue = value;
}

char* SmartPointerCEncryptor::GetData() const {
	return cData.get();
}

int SmartPointerCEncryptor::GetShiftValue() const {
	return iShiftValue;
}

void SmartPointerCEncryptor::Encrypt() {
	for (int i = 0; i < strlen(cData.get()); ++i) {
		if (cData[i] == ' ') {
			continue;
		}
		if (isprint(static_cast<char>(cData[i]) + iShiftValue)) {
			cData[i] = static_cast<char>(cData[i]) + iShiftValue;
		}
	}
}

void SmartPointerCEncryptor::Decrypt() {
	for (int i = 0; i < strlen(cData.get()); ++i) {
		if (cData[i] == ' ') {
			continue;
		}
		if (isprint(static_cast<char>(cData[i]) - iShiftValue)) {
			cData[i] = static_cast<char>(cData[i]) - iShiftValue;
		}
	}
}

SmartPointerCEncryptor& SmartPointerCEncryptor::operator ++ () {
	Encrypt();
	return *this;
}

SmartPointerCEncryptor SmartPointerCEncryptor::operator ++ (int value)
{
	SmartPointerCEncryptor* temp = new SmartPointerCEncryptor(*this);
	++(*this);
	return *temp;
}

SmartPointerCEncryptor& SmartPointerCEncryptor::operator--() {
	Decrypt();
	return *this;
}

SmartPointerCEncryptor SmartPointerCEncryptor::operator--(int)
{
	SmartPointerCEncryptor* temp = new SmartPointerCEncryptor(*this);
	--(*this);
	return *temp;
}

SmartPointerCEncryptor& SmartPointerCEncryptor::operator=(SmartPointerCEncryptor& other) {	
	SetData(other.GetData());
	SetShiftValue(other.iShiftValue);
	
	return *this;
}

SmartPointerCEncryptor& SmartPointerCEncryptor::operator=(SmartPointerCEncryptor&& other) noexcept{
	cData = move(other.cData);
	iShiftValue = other.iShiftValue;
	other.iShiftValue = 0;

	return *this;
}


bool operator==(const SmartPointerCEncryptor& left, const SmartPointerCEncryptor& right) {
	return (strcmp(left.cData.get(), right.cData.get()) == 0) && left.iShiftValue == right.iShiftValue;
}

ostream& operator << (ostream& output, const SmartPointerCEncryptor& other) {
	output << other.cData.get();
	return output;
}

istream& operator >> (istream& input, SmartPointerCEncryptor& other) {
	int num{ 0 };
	input >> num;
	++num;
	other.cData.reset();
	unique_ptr<char[]> array(new char[num]);
	other.cData = move(array);
	input.ignore();
	input.getline(other.cData.get(), num);

	return input;
}
