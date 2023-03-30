#include "Fiat.h"
Fiat::Fiat() {
	fuelCap = 10;
	fuelComp = 9;
}

int Fiat::getCap() {
	return this->fuelCap;
}
int Fiat::getFuelCon() {
	return this->fuelComp;
}
int Fiat::getAvgSpeed(Weather w) {
	switch (w)
	{
	case Weather::Rain:
		return 70;

	case Weather::Snow:
		return 55;
	default:
		return 99;

	}
}
	