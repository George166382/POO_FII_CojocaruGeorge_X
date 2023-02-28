#include <iostream>
#include "NumberList.h"

void NumberList::Init()
{
	this->count = 0;
}
bool NumberList::Add(int x)
{
	if (this->count >= 10)
	{
		return false;
	}
	else
	{
		this->numbers[this->count] = x;
		this->count++;
		return true;
	}
}

void NumberList::Sort()
{
	int ok;
	for (int i = 0; i < this->count - 1; i++)
	{
		ok = 0;
		for (int j = 0; j < this->count - i - 1; j++)
		{
			if (this->numbers[j] > this->numbers[j + 1])
			{
				int aux = this->numbers[j];
				this->numbers[j] = this->numbers[j + 1];
				this->numbers[j + 1] = aux;
				ok = 1;
			}
		}
		if (ok == 0)
			break;
	}
}
void NumberList::Print()
{
	for (int i = 0; i < this->count; i++)
	{
		std::cout << this->numbers[i] << " ";
	}
}