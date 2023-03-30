#include "Circuit.h"
#include <iostream>

Circuit::Circuit() {
	this->v = new Car*[10];
	this->length = 0;
	this->rank = new int[10];
	this->weather = Weather::Snow;
	this->i = 0;
}
Circuit::~Circuit() {
	for (int x = 0; x < i; x++) {
		Car *c = this->v[x];
		memset(c, 0, sizeof(c));
		delete c;
	}
	delete[] this->v;
	int *x = this->rank;
	delete[] x;
}

void Circuit::AddCar(Car *c) {
	if (this->i < 10) {
	
		this->v[i] = c;
		this->rank[i] = this->v[i]->getAvgSpeed(this->weather);
		this->i++;
	}
	else
	{
		printf("Nu se mai pot adauga masini\n");
	}
}
void Circuit::SetWeather(Weather w) {
	this->weather = w;
}
void Circuit::SetLength(int l) {
	this->length = l;
}
void Circuit::Race() {
	for (int x = 0; x < i; x++)
	{
		for (int y = 0; y < i - 1; y++)
		{
			if (this->rank[y] > this->rank[y + 1])
			{
				int aux = this->rank[y];
				this->rank[y] = this->rank[y + 1];
				this->rank[y + 1] = aux;
			}
		}
	}
}

void Circuit::ShowFinalRanks() {
	for (int x = 0; x < i; x++) {
		if (this->v[x]->getFuelCon() <= 10)
		{
			std::cout << "Speed: " << this->v[x]->getAvgSpeed(this->weather) << " Time: " << (float)this->rank[x] / this->length << "\n";
		}
		//std::cout << i << "\n";
	}
}
void Circuit::ShowWhoDidNotFinish() {
	std::cout << "Did not finish\n";
	for (int x = 0; x < i; x++) {
		if (this->v[x]->getFuelCon() > 10)
		{
			std::cout <<"Speed: "<< this->v[x]->getAvgSpeed(this->weather) << "\n";
		}
	}
}
