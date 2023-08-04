#include <iostream>
#include "lab4.h"

unsigned int CTime::HowManyObjects = 0;

CTime::CTime() {
    ++HowManyObjects;
}

CTime::CTime(int hours, int minutes, double seconds) : iHours(hours), iMinutes(minutes), dSeconds(seconds) { ++HowManyObjects; }

CTime::CTime(double TimeInSeconds) : dSeconds(TimeInSeconds) {
    NormalizeTime();
    ++HowManyObjects;
}

CTime::~CTime() { --HowManyObjects; }

void CTime::SetHours(int value) {
    iHours = value;
}
void CTime::SetMinutes(int value) {
    iMinutes = value;
}
void CTime::SetSeconds(double value) {
    dSeconds = value;
}

int CTime::GetHours() const {
    return iHours;
}
int CTime::GetMinutes() const {
    return iMinutes;
}
double CTime::GetSeconds() const {
    return dSeconds;
}
int CTime::GetAmountOfObjects() const {
    return HowManyObjects;
}

double CTime::SubtractionDifferenceInSeconds(const CTime& other) const {
    if (iHours < 0 || iMinutes < 0 || dSeconds < 0 || other.iHours < 0 || other.iMinutes < 0 || other.dSeconds < 0) { return -1.0; }

    if (std::isnan(dSeconds) || std::isnan(other.dSeconds)) { return NAN; }

    if (std::isinf(dSeconds) || std::isinf(other.dSeconds)) { return INFINITY; }

    return (*this - other);
}

double CTime::SubtractionDifferenceInSeconds(const int hours, const int minutes, const double seconds) const {
    if (iHours < 0 || iMinutes < 0 || dSeconds < 0 || hours < 0 || minutes < 0 || seconds < 0) { return -1.0; }

    if (std::isnan(dSeconds) || std::isnan(seconds)) { return NAN; }

    if (std::isinf(dSeconds) || std::isinf(seconds)) { return INFINITY; }
    
    CTime time1(hours, minutes, seconds);

    return (*this - time1);
}

CTime CTime::Add(const CTime& other) const{
    CTime time{ *this + other };
    time.NormalizeTime();
    return time;
}

CTime CTime::Add(const double dTimeInSec) const{
    double time = *this;
    CTime TimeResult(0, 0, 0);

    TimeResult = TimeResult + (time + dTimeInSec);
    TimeResult.NormalizeTime();
    return TimeResult;
}

double CTime::ConvertTimeToSeconds() const {
    if (iHours < 0 || iMinutes < 0 || dSeconds < 0) { return -1.0; }

    if (std::isnan(dSeconds)) { return NAN; }

    if (std::isinf(dSeconds)) { return INFINITY; }

    return static_cast<double>(iHours * 3600 + iMinutes * 60) + dSeconds;
}

double CTime::ConvertTimeToSeconds(CTime& other) const {
    if (iHours < 0 || iMinutes < 0 || dSeconds < 0 || other.iHours < 0 || other.iMinutes < 0 || other.dSeconds < 0) { return -1.0; }

    if (std::isnan(dSeconds) || std::isnan(other.dSeconds)) { return NAN; }

    if (std::isinf(dSeconds) || std::isinf(other.dSeconds)) { return INFINITY; }

    return static_cast<double>((iHours + other.iHours) * 3600 + (iMinutes + other.iMinutes) * 60) + dSeconds + other.dSeconds;
}

void CTime::NormalizeTime() {

    const unsigned int cuiMinutesToAdd = static_cast<unsigned int>(dSeconds / 60.0);

    dSeconds -= cuiMinutesToAdd * 60.0;
    iMinutes += cuiMinutesToAdd;

    const unsigned int cuiHoursToAdd = static_cast<unsigned int>(iMinutes / 60);
    iMinutes -= cuiHoursToAdd * 60;
    iHours += cuiHoursToAdd;
}



CTime CTime::operator + (const CTime &other) const{
    CTime time(iHours + other.iHours, iMinutes + other.iMinutes, dSeconds + other.dSeconds);
    time.NormalizeTime();
    return time;
}

CTime CTime::operator + (const double seconds) const {
    CTime time(iHours, iMinutes, dSeconds + seconds);

    time.NormalizeTime();

    return time;
}

double CTime::operator - (const CTime& other) const{
    CTime time1(iHours - other.iHours, iMinutes - other.iMinutes, dSeconds - other.dSeconds);

    double time2{ time1 };

    return time2;
}

CTime::operator double() const{

    return (static_cast<double>(iHours * 3600 + iMinutes * 60) + dSeconds);
}

CTime CTime::operator *(const double value) const {
    CTime time(static_cast<int>(this->iHours * value), static_cast<int>(this->iMinutes * value), this->dSeconds * value);

    time.NormalizeTime();

    return time;
}

bool operator == (const CTime& other1, const CTime& other2) {
    return(other1.iHours == other2.iHours && other1.iMinutes == other2.iMinutes && other1.dSeconds == other2.dSeconds);
}

bool operator < (const CTime& other1, const CTime& other2) {
    CTime other1time(other1.GetHours(), other1.GetMinutes(), other1.GetSeconds()), other2time(other2.GetHours(), other2.GetMinutes(), other2.GetSeconds());
    double timeinsec1{ other1time }, timeinsec2{other2time};

    return timeinsec1 < timeinsec2;
}

bool operator > (const CTime& other1, const CTime& other2) {
    CTime other1time(other1.GetHours(), other1.GetMinutes(), other1.GetSeconds()), other2time(other2.GetHours(), other2.GetMinutes(), other2.GetSeconds());
    double timeinsec1{ other1time }, timeinsec2{ other2time };

    return timeinsec1 > timeinsec2;
}

ostream& operator << (ostream& output, CTime& other) {
    output << other.iHours << " " << other.iMinutes << " " << other.dSeconds << endl;
    return output;
}

istream& operator >> (istream& input, CTime& other) {
    input >> other.iHours >> other.iMinutes >> other.dSeconds;
    return input;
}