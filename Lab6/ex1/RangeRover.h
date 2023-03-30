#pragma once
#include "Car.h"
class RangeRover :
	public Car
{
public:
	RangeRover();
	int getCap();
	int getFuelCon();
	int getAvgSpeed(Weather w);
};

