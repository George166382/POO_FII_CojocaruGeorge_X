#pragma once
#include "Car.h"
class Fiat :
	public Car
{
public:
	Fiat();
	int getCap();
	 int getFuelCon();
	 int getAvgSpeed(Weather w);

};

