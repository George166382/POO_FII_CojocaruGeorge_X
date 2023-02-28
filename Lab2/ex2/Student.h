#pragma once
class Student
{
	char* name;
	float Maths, Eng, Hist;
	float avg;
public:
	void setName(const char* name);
	void setMaths(float val);
	void setEng(float val);
	void setHist(float val);
	char* getName();
	float getMaths();
	float getEng();
	float getHist();
	float getAvg();
};

