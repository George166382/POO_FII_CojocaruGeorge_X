#include "RangeRover.h"
RangeRover::RangeRover() {
	fuelCap = 7;
	fuelComp = 5;
	
}

int RangeRover::getCap() {
	return this->fuelCap;
}
int RangeRover::getFuelCon() {
	return this->fuelComp;
}
int RangeRover::getAvgSpeed(Weather w) {
	switch (w)
	{
	case Weather::Rain:
		return 74;

	case Weather::Snow:
		return 60;
	default:
		return 105;

	}
}