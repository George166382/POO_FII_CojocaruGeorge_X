#pragma once
#include "Car.h"
class BMW :
	public Car
{
public:
	BMW();
	int getCap();
	int getFuelCon();
	int getAvgSpeed(Weather w);
};

