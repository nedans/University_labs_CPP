#pragma once

using namespace std;

class CTime {
public:
	CTime();
	explicit CTime(int hours, int minutes, double seconds);
	explicit CTime(double TimeInSeconds);
	virtual ~CTime();

	void SetHours(int value);
	void SetMinutes(int value);
	void SetSeconds(double value);

	int GetHours() const;
	int GetMinutes() const;
	double GetSeconds() const;
	int GetAmountOfObjects() const;

	double SubtractionDifferenceInSeconds(const CTime& other) const;
	double SubtractionDifferenceInSeconds(int hours, int minutes, double seconds) const;

	CTime Add(const CTime& other) const;
	CTime Add(const double dTimeInSec) const;

	double ConvertTimeToSeconds() const;
	double ConvertTimeToSeconds(CTime& other) const;

	void NormalizeTime();

	static unsigned int HowManyObjects;

	CTime operator + (const CTime& other) const ;

	CTime operator + (const double seconds) const;

	double operator - (const CTime& other) const;

	operator double() const;

	CTime operator * (const double value) const;

	friend bool operator == (const CTime& other1, const CTime& other2);
	
	friend bool operator < (const CTime& other1, const CTime& other2);
	
	friend bool operator > (const CTime& other1, const CTime& other2);


	friend ostream& operator << (ostream& output, CTime& other);

	friend istream& operator >> (istream& input, CTime& other);
private:
	int iHours{ 0 };
	int iMinutes{ 0 };
	double dSeconds{ 0.0 };
};

