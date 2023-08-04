#pragma once
#include "CExceptions.h"



template <size_t ShiftCount>
class CEncryptor {
public:
	CEncryptor() noexcept {}

	explicit CEncryptor(const char* data) {

		if (ShiftCount == 0) {
			throw CExceptionZeroShiftValue();
		}

		for (size_t i = 0; i < strlen(data); ++i) {
			if (isalpha(data[i]) == 0) {
				if (data[i] == ' ') { continue; }
				throw CExceptionNonSymbol();
			}
		}

		cData = new char[strlen(data) + 1];
		strcpy_s(cData, strlen(data) + 1, data);
	}


	CEncryptor(const CEncryptor& other) {
		cData = nullptr;

		for (size_t i = 0; i < strlen(other.cData); ++i) {
			if (isalpha(other.cData[i]) == 0) {
				if (other.cData[i] == ' ') { continue; }
				throw CExceptionNonSymbol();
			}
		}




		cData = new char[strlen(other.cData) + 1];
		strcpy_s(cData, strlen(other.cData) + 1, other.cData);
	}


	CEncryptor(CEncryptor&& other) noexcept {
		cData = other.cData;
		other.cData = nullptr;
	}


	~CEncryptor() noexcept {
		delete[] cData;
	}


	void SetData(const char* sData) {
		delete[] cData;
		cData = nullptr;

		for (size_t i = 0; i < strlen(sData); ++i) {
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

	char* GetData() const noexcept {
		return cData;
	}


	size_t GetShiftValue() const noexcept {
		return ShiftCount;
	}


	void Encrypt() noexcept {
		for (size_t i = 0; i < strlen(cData); ++i) {
			if (cData[i] == ' ') {
				continue;
			}
			if (static_cast<int>(cData[i] + ShiftCount) > 127) {
				cData[i] = static_cast<char>(static_cast<int>(cData[i] + ShiftCount) - 127 + 31);
				continue;
			}
			if (isprint(static_cast<char>(cData[i]) + ShiftCount)) {

				cData[i] = static_cast<char>(cData[i]) + ShiftCount;
			}
		}
	}


	void Decrypt() noexcept {
		for (size_t i = 0; i < strlen(cData); ++i) {
			if (cData[i] == ' ') {
				continue;
			}
			if (static_cast<int>(cData[i] - ShiftCount) < 32) {
				cData[i] = static_cast<char>(static_cast<int>(cData[i] - ShiftCount) + 127 - 31);
				continue;
			}
			if (isprint(static_cast<char>(cData[i]) - ShiftCount)) {
				cData[i] = static_cast<char>(cData[i]) - ShiftCount;
			}
		}
	}


	CEncryptor& operator ++ () noexcept {
		Encrypt();
		return *this;
	}


	CEncryptor operator ++ (int value) noexcept {
		CEncryptor temp(*this);
		++(*this);
		return temp;
	}


	CEncryptor& operator--() noexcept {
		Decrypt();
		return *this;
	}


	CEncryptor operator--(int) noexcept {
		CEncryptor temp(*this);
		--(*this);
		return temp;
	}


	friend bool operator==(const CEncryptor& left, const CEncryptor& right) {
		return strcmp(left.cData, right.cData) == 0;
	}


	friend std::ostream& operator << (std::ostream& output, const CEncryptor& other) {
		output << other.cData;
		if (output.fail()) throw COutputException();
		return output;
	}


	friend std::istream& operator >> (std::istream& input, CEncryptor& other) {
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


	CEncryptor& operator=(const CEncryptor& other)
	{
		if (this == &other) {
			return *this;
		}

		delete[] cData;
		cData = new char[strlen(other.cData) + 1];
		strcpy_s(cData, strlen(other.cData) + 1, other.cData);

		return *this;
	}


	CEncryptor& operator=(CEncryptor&& other) noexcept {
		if (this == &other) {
			return *this;
		}

		delete[] cData;
		cData = new char[strlen(other.cData) + 1];
		strcpy_s(cData, strlen(other.cData) + 1, other.cData);

		return *this;
	}

private:
	char* cData{ nullptr };
};