#pragma once
#include "Car.h"
class Volvo :
	public Car
{
public:
	Volvo();
	int getCap();
	int getFuelCon();
	int getAvgSpeed(Weather w);
};

