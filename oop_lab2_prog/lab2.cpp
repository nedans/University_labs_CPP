#include <iostream>
#include "lab2.h"

double GetNeededCapacity(double dW, double dTimeInHours, double dRatio)
{
	if (dRatio <= 0 || dRatio >= 1) {
		return NAN;
	}
	else if (dW < 0 || dTimeInHours < 0) {
		return NAN;
	}
	else if (dW == NAN || dTimeInHours == NAN || dRatio == NAN) {
		return NAN;
	}
	else if (dW == DBL_MAX || dTimeInHours == DBL_MAX || dW == INFINITY || dTimeInHours == INFINITY || dRatio == INFINITY) {
		return INFINITY;
	}
	else {
		return ((dW * dTimeInHours)/dRatio);
	}
}