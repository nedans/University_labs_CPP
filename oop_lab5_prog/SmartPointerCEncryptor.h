#pragma once

using namespace std;

class SmartPointerCEncryptor {
public:
	SmartPointerCEncryptor() = default;
	SmartPointerCEncryptor(char* data);
	SmartPointerCEncryptor(char* data, int shift_value);


	SmartPointerCEncryptor(const SmartPointerCEncryptor& other);
	SmartPointerCEncryptor(SmartPointerCEncryptor&& other) noexcept;


	void SetData(const char*);
	void SetShiftValue(const int);

	char* GetData() const;
	int GetShiftValue() const;

	void Encrypt();
	void Decrypt();

	SmartPointerCEncryptor& operator ++ ();
	SmartPointerCEncryptor operator ++ (int);

	SmartPointerCEncryptor& operator -- ();
	SmartPointerCEncryptor operator -- (int);

	friend bool operator == (const SmartPointerCEncryptor& left, const SmartPointerCEncryptor& right);

	friend ostream& operator << (ostream& output, const SmartPointerCEncryptor& other);
	friend istream& operator >> (istream& input, SmartPointerCEncryptor& other);



	SmartPointerCEncryptor& operator = (SmartPointerCEncryptor& other);
	
	SmartPointerCEncryptor& operator=(SmartPointerCEncryptor&& other) noexcept;
private:
	unique_ptr<char[]> cData;
	int iShiftValue{ 0 };
};