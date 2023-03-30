#pragma once
#include "Weather.h"
class Car
{
protected:
	int fuelCap, fuelComp;
public:
	virtual int getCap() = 0;
	virtual int getFuelCon() = 0;
	virtual int getAvgSpeed(Weather w) = 0;
};

