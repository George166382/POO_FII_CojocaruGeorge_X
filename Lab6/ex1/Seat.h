#pragma once
#include "Car.h"
class Seat : 
	public Car
{
public:
	Seat();
	int getCap();
	int getFuelCon();
	int getAvgSpeed(Weather w);
};

