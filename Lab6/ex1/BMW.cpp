#include "BMW.h"
BMW::BMW() {
	fuelCap = 12;
	fuelComp = 7;
	
}

int BMW::getCap() {
	return this->fuelCap;
}
int BMW::getFuelCon() {
	return this->fuelComp;
}
int BMW::getAvgSpeed(Weather w) {

	switch (w)
	{
	case Weather::Rain:
		return 77;

	case Weather::Snow:
		return 65;
	default:
		return 130;

	}
}