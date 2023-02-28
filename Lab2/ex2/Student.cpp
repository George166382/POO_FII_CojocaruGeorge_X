#include <iostream>
#include <string.h>
#include "Student.h"

void Student::setName(const char* name)
{
	this->name = (char*)malloc(strlen(name)+1);
	memset(this->name, 0, strlen(name)+1);
	memcpy(this->name, name,strlen(name));
	this->name[strlen(this->name)] = '\0';
	//strncpy_s(this->name, name, strlen(name));
}
void Student::setMaths(float val)
{
	if (val < 1 || val > 10)
	{
		this->Maths = -1;
	}
	else
	{
		this->Maths = val;
	}
}
void Student::setEng(float val)
{
	if (val < 1 || val > 10)
	{
		this->Eng = -1;
	}
	else
	{
		this->Eng = val;
	}
}
void Student::setHist(float val)
{
	if (val < 1 || val > 10)
	{
		this->Hist = -1;
	}
	else
	{
		this->Hist = val;
	}
}
float Student::getMaths()
{
	return this->Maths;
}
float Student::getEng()
{
	return this->Eng;
}
float Student::getHist()
{
	return this->Hist;
}

float Student::getAvg()
{
	if (this->Eng == -1 || this->Maths == -1 || this->Hist == -1)
	{
		this->avg = -1;
	}
	else
		this->avg = (this->Maths + this->Hist + this->Eng) / 3;
	return this->avg;
}
char* Student::getName()
{
	return this->name;
}