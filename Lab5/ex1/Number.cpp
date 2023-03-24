#include "Number.h"
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

Number::Number(const char * value, int base) {
	int size;
	size = strlen(value) + 1;
	this->num = new char[size];
	memset(this->num, 0, size);
	memcpy(this->num, value, strlen(value));
	this->num[size - 1] = '\0';
	this->base = base;
	int p = 1;
	char *tmp = this->num;
	int i = size -2;
	while (i>=0)
	{
		if ((tmp[i] - '0') >= 0 && (tmp[i]-'0') <= 9)
		{
			this->nr = this->nr + (tmp[i] - '0') * p;
		}
		else
		{
			this->nr = this->nr + (tmp[i] - '7') *  p;
		}
		p = p * this->base;
		i--;
	}
	tmp = nullptr;
	delete[] tmp;
}
Number::~Number() {
	char* tmp = this->num;
	delete[] tmp;
	this->base = 0;
}

Number::Number(int val)
{
	this->base = 10;
	char* temp = new char[50];
	int index = 0;
	while (val)
	{
		temp[index++] = val % 10 + '0';
		val /= 10;
	}
	temp[index] = '\0';
	for (int i = 0; i < index / 2; i++)
		std::swap(temp[i], temp[index - i - 1]);
	Number n(temp, 10);
	n.SwitchBase(this->base);
	(*this) = n;
}

void Number::SwitchBase(int newBase)
{
	char *tmp;
	tmp = this->num;
	this->num = nullptr;
	delete[] tmp;
	this->base = newBase;
	int newNr = this->nr , p = 1, nr=0;
	while (newNr != 0)
	{
		
		nr++;
		newNr = newNr / this->base;
	}
	newNr = this->nr;
	char *newStr = new char[nr + 1];
	memset(newStr, 0, nr + 1);
	int i = nr - 1;
	while (i >= 0)
	{
		if (newNr % this->base < 10)
		{
			newStr[i] = (char)((newNr % this->base) + '0');
		}
		else
		{
			newStr[i] = (char) ((newNr % this->base) + '7');
		}
		newNr = newNr / this->base;
		i--;
	}
	newStr[nr] = '\0';
	this->num = newStr;
}

void Number::Print()
{
	std::cout << this->num << "\n";
}

int  Number::GetDigitsCount()
{
	return strlen(this->num);
}

Number operator+(Number a,Number b) {
	if (a.GetBase() > b.GetBase())
	{
		b.SwitchBase(a.GetBase());
	}
	else
	{
		a.SwitchBase(b.GetBase());
	}
	Number n("", 0);
	int nr = a.GetNr() + b.GetNr();
	n.SetNr(nr);
	n.SwitchBase(a.GetBase());
	return n;
}

Number operator-(Number a,Number b) {
	if (a.GetBase() > b.GetBase())
	{
		b.SwitchBase(a.GetBase());
	}
	else
	{
		a.SwitchBase(b.GetBase());
	}
	Number n("", 0);
	int nr =  a.GetNr() - b.GetNr();
	n.SetNr(nr);
	n.SwitchBase(a.GetBase());
	return n;
}

Number& Number::operator+=(Number& n)
{
	
	this->nr = this->nr + n.GetNr();
	this->SwitchBase(this->base);
	return (*this);
}

Number& Number::operator-=(Number& n)
{
	this->nr = this->nr - n.GetNr();
	this->SwitchBase(this->base);
	return (*this);
}



bool Number::operator>(Number b)
{
	return (this->nr > b.nr);
}
bool Number::operator<(Number b)
{
	return (this->nr < b.nr);
}
bool Number::operator>=(Number b)
{
	return (this->nr >= b.nr);
}
bool Number::operator<=(Number b)
{
	
	return (this->nr <= b.nr);
	
}
bool Number::operator==(Number b)
{
	return (this->nr == b.nr);
}

Number& Number::operator--()
{
	int len = this->GetDigitsCount();

	if (len == 0)
		return (*this);

	for (int i = 0; i < len - 1; i++)
		this->num[i] = this->num[i + 1];
	this->num[len - 1] = '\0';
	return (*this);
}

Number& Number::operator--(int value)
{
	char* text = this->num;
	int len = this->GetDigitsCount();

	if (len == 0)
		return (*this);

	text[len - 1] = '\0';
	Number temp(this->num, this->base);
	this->num = text;
	return temp;
}


int  Number::GetBase()
{
	return this->base;
}

Number::Number(const Number& s) {
	std::cout << "Copy\n";
	int size;
	size = strlen(s.num) + 1;
	this->num = new char[size];
	memset(this->num, 0, size);
	memcpy(this->num, s.num, strlen(s.num));
	this->num[size - 1] = '\0';
	this->base = s.base;
	this->nr = s.nr;
};

Number::Number(Number&& s) {
	printf("Move constructor\n");
	this->num = s.num;
	this->base = s.base;
	this->nr = s.nr;
	s.num = nullptr;
	s.base = 0;
	s.nr = 0;
}

Number& Number::operator=(const Number& s) {
	printf("Copy assignment\n");
	delete[] this->num;
	this->num = new char[strlen(s.num) + 1];
	strcpy_s(this->num, strlen(s.num) + 1, s.num);
	this->base = s.base;
	this->nr = s.nr;
	return *this;
}

Number& Number::operator=(int value)
{
	char* temp = new char[50];
	int index = 0;
	while (value)
	{
		temp[index++] = value % 10 + '0';
		value /= 10;
	}
	temp[index] = '\0';
	for (int i = 0; i < index / 2; i++)
		std::swap(temp[i], temp[index - i - 1]);
	Number n(temp, 10);
	n.SwitchBase(this->base);
	(*this) = n;
	return (*this);

}

Number& Number::operator=(const char* value)
{
	Number n(value, 10);
	n.SwitchBase(this->base);
	(*this) = n;
	return (*this);
}


Number& Number::operator=(Number&& s) {
	printf("Move assignment\n");
	this->num = s.num;
	this->base = s.base;
	this->nr = s.nr;
	s.num = nullptr;
	s.base = 0;
	s.nr = 0;
	return *this;
}

char Number::operator[](int index) {
	return this->num[index];
}

int Number::GetNr()
{
	return this->nr;
}
void Number::SetNr(int nr)
{
	this->nr = nr;
}