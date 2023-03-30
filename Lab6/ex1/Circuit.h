#pragma once
#include <stdio.h>
#include "Car.h"
#include "Weather.h"
#include "BMW.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Seat.h"
#include "Volvo.h"
class Circuit
{
	Car** v;
	Weather weather;
    int* rank;
	int length;
	int i;
public:
	Circuit();
	~Circuit();
	void AddCar(Car* c);
	void SetWeather(Weather w);
	void SetLength(int l);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

