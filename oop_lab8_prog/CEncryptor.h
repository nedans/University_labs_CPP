#pragma once

class CEncryptor {
public:
	CEncryptor();
	CEncryptor(const char* data);
	CEncryptor(const char* data, const int shift_value);
	CEncryptor(const CEncryptor& other);
	CEncryptor(CEncryptor&& other) noexcept;

	~CEncryptor() noexcept;

	void SetData(const char*);
	void SetShiftValue(const int);

	char* GetData() const noexcept;
	int GetShiftValue() const noexcept;

	void Encrypt() noexcept;
	void Decrypt() noexcept;

	CEncryptor& operator ++ () noexcept;
	CEncryptor operator ++ (int) noexcept;

	CEncryptor& operator -- () noexcept;
	CEncryptor operator -- (int) noexcept;

	friend bool operator == (CEncryptor& left, CEncryptor& right) noexcept;

	friend std::ostream& operator << (std::ostream& output, const CEncryptor& other) noexcept;
	friend std::istream& operator >> (std::istream& input, CEncryptor& other);

	CEncryptor& operator = (const CEncryptor& other);

	CEncryptor& operator = (CEncryptor&& other) noexcept;

private:
	char* cData{ nullptr };
	int iShiftValue{ 0 };
};