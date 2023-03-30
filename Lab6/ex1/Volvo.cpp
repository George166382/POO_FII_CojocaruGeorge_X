#include "Volvo.h"
Volvo::Volvo() {
	fuelCap = 15;
	fuelComp = 11;
	
}

int Volvo::getCap() {
	return this->fuelCap;
}
int Volvo::getFuelCon() {
	return this->fuelComp;
}
int Volvo::getAvgSpeed(Weather w) {
	switch (w)
	{
	case Weather::Rain:
		return 60;
	
	case Weather::Snow:
		return 50;
	default:
		return 90;
		
	}
}