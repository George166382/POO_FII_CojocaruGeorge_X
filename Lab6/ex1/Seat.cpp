#include "Seat.h"
Seat::Seat() {
	fuelCap = 9;
	fuelComp = 6;
}

int Seat::getCap() {
	return this->fuelCap;
}
int Seat::getFuelCon() {
	return this->fuelComp;
}
int Seat::getAvgSpeed(Weather w) {
	switch (w)
	{
	case Weather::Rain:
		return 74;

	case Weather::Snow:
		return 68;
	default:
		return 115;

	}
}