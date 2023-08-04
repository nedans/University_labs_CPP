#include <iostream>
#include "lab3.h"

CTime::CTime(int hours, int minutes, double seconds) : iHours(hours), iMinutes(minutes), dSeconds(seconds) {}

CTime::CTime(double TimeInSeconds) : dSeconds(TimeInSeconds) {
    AddSecToTime(0);
}

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

double CTime::AddSecToTime(const double seconds) {
    if (std::isnan(seconds)) {
        return NAN;
    }
    
    if(std::isinf(seconds)) {
        return INFINITY;
    }
    
    if (seconds < 0) {
        return -1;
    }

    dSeconds += seconds;
    const unsigned int cuiMinutesToAdd = static_cast<unsigned int>(dSeconds / 60.0);

    dSeconds -= cuiMinutesToAdd * 60.0;
    iMinutes += cuiMinutesToAdd;

    const unsigned int cuiHoursToAdd = static_cast<unsigned int>(iMinutes / 60);
    iMinutes -= cuiHoursToAdd * 60;
    iHours += cuiHoursToAdd;
}

double CTime::ConvertTimeToSeconds() const {
    if (iHours < 0 || iMinutes < 0 || dSeconds < 0) {
        return -1.0;
    }
    if (std::isnan(dSeconds)) {
        return NAN;
    }
    if (std::isinf(dSeconds)) {
        return INFINITY;
    }
    else {
        return static_cast<double>(iHours * 3600 + iMinutes * 60) + dSeconds;
    }
}

double CTime::MultiplyTheTimeBy(const double value) {
    if (std::isinf(value)) {
        return INFINITY;
    }
    
    if (std::isnan(value)) {
        return NAN;
    }
    
    double temp{ ConvertTimeToSeconds() * value };
    iHours = iMinutes = 0;
    dSeconds = 0;
    AddSecToTime(temp);
    
}

int CTime::Ñompare(const CTime & other) const {

    const double dSeconds = ConvertTimeToSeconds();
    const double dSecondsOther = other.ConvertTimeToSeconds();

    if (dSeconds > dSecondsOther) {
        return 1;
    }

    if (dSeconds < dSecondsOther) {
        return -1;
    }
    
    return 0;
}

double CTime::SubtractionDifferenceInSeconds(const CTime& other) {
    if (std::isnan(other.dSeconds) || std::isnan(dSeconds)) {
        return NAN;
    }

    if (std::isinf(other.dSeconds) || std::isinf(dSeconds)) {
        return INFINITY;
    }

    if (other.iHours < 0 || other.iMinutes < 0 || other.dSeconds < 0 || 
              iHours < 0 || iMinutes < 0 || dSeconds < 0) {

        return -1.0;
    }

    const double dSeconds = ConvertTimeToSeconds();
    const double dSecondsOther = other.ConvertTimeToSeconds();

    return dSeconds - dSecondsOther;
}

CTime CTime::Add(const CTime & time1) {
    CTime timeTemp(iHours, iMinutes, dSeconds);
    timeTemp.iHours += time1.iHours;
    timeTemp.iMinutes += time1.iMinutes;
    timeTemp.dSeconds += time1.dSeconds;
    timeTemp.AddSecToTime(0);
    return timeTemp;
}