#pragma once

using namespace std;

class CEncryptor {
public:
	CEncryptor() = default;
	CEncryptor(char* data);
	CEncryptor(char* data, int shift_value);
	CEncryptor(const CEncryptor& other);
	CEncryptor(CEncryptor&& other) noexcept;

	~CEncryptor();

	void SetData(const char*);
	void SetShiftValue(const int);

	char* GetData() const;
	int GetShiftValue() const;

	void Encrypt();
	void Decrypt();

	CEncryptor& operator ++ ();
	CEncryptor operator ++ (int);

	CEncryptor& operator -- ();
	CEncryptor operator -- (int);

	friend bool operator == (CEncryptor& left, CEncryptor& right);

	friend ostream& operator << (ostream& output, const CEncryptor& other);
	friend istream& operator >> (istream& input, CEncryptor& other);

	CEncryptor& operator = (const CEncryptor& other);

	CEncryptor& operator = (CEncryptor&& other) noexcept;

private:
	char* cData{nullptr};
	int iShiftValue{ 0 };
};