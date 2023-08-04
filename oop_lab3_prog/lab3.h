#pragma once

class CTime {
public:
	CTime() = default;
	CTime(int hours, int minutes, double seconds);
	explicit CTime(double TimeInSeconds);


	void SetHours(int value);
	void SetMinutes(int value);
	void SetSeconds(double value);

	int GetHours() const;
	int GetMinutes() const;
	double GetSeconds() const;

	double AddSecToTime(const double seconds);

	double ConvertTimeToSeconds() const;

	double MultiplyTheTimeBy(const double value);

	int Ñompare(const CTime & other) const;

	double SubtractionDifferenceInSeconds(const CTime & other);

	CTime Add(const CTime & time1);

private:
	int iHours{ 0 };
	int iMinutes{ 0 };
	double dSeconds{ 0.0 };
};

