#pragma once
#include <string>
#include <istream>
#include <algorithm>




template <size_t CipherShiftCount, size_t RotateShiftCount>
class CEncryptor {
public:
	CEncryptor() {
		if (CipherShiftCount == 0) {
			throw CExceptionZeroShiftValue();
		}
		if (RotateShiftCount < 0) {
			throw CExceptionBelowZeroRotateShiftValue();
		}
	}

	explicit CEncryptor(const std::string& data) {

		if (CipherShiftCount == 0) {
			throw CExceptionZeroShiftValue();
		}
		if (RotateShiftCount < 0) {
			throw CExceptionBelowZeroRotateShiftValue();
		}

		for (size_t i = 0; i < data.length(); ++i) {
			if (isalpha(data[i]) == 0) {
				if (data[i] == ' ') { continue; }
				throw CExceptionNonSymbol();
			}
		}

		cData = data;
	}


	CEncryptor(const CEncryptor& other) {
		cData.erase();

		for (size_t i = 0; i < other.cData.length(); ++i) {
			if (isalpha(other.cData[i]) == 0) {
				if (other.cData[i] == ' ') { continue; }

				throw CExceptionNonSymbol();
			}
		}

		cData = other.cData;
	}


	CEncryptor(CEncryptor&& other) noexcept {
		cData = other.cData;
		other.cData.erase();
	}


	~CEncryptor() noexcept {
		cData.erase();
	}


	void SetData(const std::string& sData) {

		for (size_t i = 0; i < sData.length(); ++i) {
			if (isalpha(sData[i]) == 0) {
				if (sData[i] == ' ') { continue; }

				throw CExceptionNonSymbol();
			}
		}

		cData = sData;
	}

	std::string GetData() const noexcept {
		return cData;
	}


	size_t GetCipherShiftCount() const noexcept {
		return CipherShiftCount;
	}

	size_t GetRotateShiftCount() const noexcept {
		return RotateShiftCount;
	}

	void Encrypt() noexcept{//--------------------------------------------------------------------------
		int asciiShift = CipherShiftCount % 256;
		std::transform(cData.begin(), cData.end(), cData.begin(), [asciiShift](char c) {
			if (c != ' ') {
				if (static_cast<int>(c + CipherShiftCount) > 127) {
					c = static_cast<char>(static_cast<int>(c + CipherShiftCount) - 127 + 31);
				}
				else if(isprint(static_cast<char>(c) + CipherShiftCount)) {
					c = static_cast<char>(c) + CipherShiftCount;
				}
			}
			return c;
		});
	}

	void Decrypt() noexcept {//--------------------------------------------------------------------------
		int asciiShift = CipherShiftCount % 256;


		std::transform(cData.begin(), cData.end(), cData.begin(), [asciiShift](char c) {
			if (!(c == ' ')) {

				if (static_cast<int>(c - CipherShiftCount) < 32) {
					c = static_cast<char>(static_cast<int>(c - CipherShiftCount) + 127 - 31);

				}
				else if (isprint(static_cast<char>(c) - CipherShiftCount)) {

					c = static_cast<char>(c) - CipherShiftCount;
				}
			}
			return c;
			});
	}

	void ShiftElementsRight() noexcept{//--------------------------------------------------------------------------
		std::rotate(cData.rbegin(), cData.rbegin() + RotateShiftCount, cData.rend());
	}

	//--------------------------------------------------------------------------
	friend bool operator==(const CEncryptor<CipherShiftCount, RotateShiftCount>& left, const CEncryptor<CipherShiftCount, RotateShiftCount>& right) noexcept {
		return std::equal(left.cData.begin(), left.cData.end(), right.cData.begin(), right.cData.end());
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

	friend std::ostream& operator << (std::ostream& output, const CEncryptor& other) {//--------------------------------------------------------------------------

		std::for_each(other.cData.begin(), other.cData.end(), [&output](char c) {
			output << c;
			if (output.fail()) throw COutputException();
		});

		return output;

	}

	friend std::istream& operator>>(std::istream& input, CEncryptor& other) {
		if (input.fail()) throw CInputException();

		std::string data;
		std::getline(input, data);

		for (size_t i = 0; i < data.length(); ++i) {
			if (isalpha(data[i]) == 0) {
				if (data[i] == ' ') { continue; }
				throw CExceptionNonSymbol();
			}
		}

		other.cData = data;
		return input;
	}


	CEncryptor& operator=(const CEncryptor& other)
	{
		if (this == &other) {
			return *this;
		}

		cData = other.cData;

		return *this;
	}


	CEncryptor& operator=(CEncryptor&& other) noexcept {
		if (this == &other) {
			return *this;
		}


		cData = other.cData;

		return *this;
	}

private:
	std::string cData{"Info"};
};