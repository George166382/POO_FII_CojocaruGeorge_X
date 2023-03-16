#include "Sort.h"
#include <iostream>

Sort::Sort(int number, int min, int max)
{
	srand(time(NULL));
	this->sz = number;
	this->list = new int[number];
	memset(this->list, 0, number);
	for (int i = 0; i < number; i++)
	{
		this->list[i] = rand();
		if (this->list[i]<min || this->list[i]>max)
		{
			i--;
		}
	}
}
Sort::Sort(std::initializer_list<int> list)
{
	int nr = 0;
	for (int i : list)
	{
		nr++;
	}
	this->sz = nr;
	this->list = new int[nr];
	memset(this->list, 0, nr);
	int k = 0;
	for (int i : list)
	{
		this->list[k] = i;
		k++;
	}
}
Sort::Sort(int *v, int size)
{
	this->sz = size;
	this->list = new int[size];
	memset(this->list, 0, size);
	for (int i = 0; i < size; i++)
	{
		this->list[i] = v[i];
	}
}
Sort::Sort(int count, ...)
{
	va_list vl;
	va_start(vl, count);
	this->sz = count;
	this->list = new int[count];
	memset(this->list, 0, count);
	for (int i = 0; i < count; i++)
	{
		int val = va_arg(vl, int);
		this->list[i] = val;
	}
	va_end(vl);
}
Sort::Sort(const char * str)
{
	int nr = 0;
	for (int j = 0; j < strlen(str); j++)
	{
		if (str[j] == ',')
		{
			nr++;
		}
	}
	this->sz = nr + 1;
	this->list = new int[nr+1];
	memset(this->list, 0, nr+1);
	char * cuv; 
	int i = 0;
	char *temp = new char[strlen(str) + 1];
	strcpy(temp, str);
	cuv = strtok(temp, ",");
	while (cuv != nullptr)
	{
		this->list[i] = atoi((const char*)cuv);
		cuv = strtok(nullptr, ",");
		i++;
	}
	delete[] temp;
}

Sort::~Sort()
{
	int *v = this->list;
	delete[] v;
}

void Sort::Print()
{
	for (int i = 0; i < this->sz; i++)
	{
		std::cout << this->list[i] << " ";
	}
}

int  Sort::GetElementsCount()
{
	return this->sz;
}

int  Sort::GetElementFromIndex(int index)
{
	return this->list[index];
}

void Sort::BubbleSort(bool ascendent)
{
	if (ascendent == true)
	{
		bool ok;
		for (int i = 0; i < this->sz - 1; i++)
		{
			ok = false;
			for (int j = 0; j < this->sz - i - 1; j++)
			{
				if (this->list[j] > this->list[j + 1])
				{
					int aux = this->list[j];
					this->list[j] = this->list[j + 1];
					this->list[j + 1] = aux;
					ok = true;
				}
			}
			if (ok == false)break;
		}
	}
	else
	{
		bool ok;
		for (int i = 0; i < this->sz - 1; i++)
		{
			ok = false;
			for (int j = 0; j < this->sz - i - 1; j++)
			{
				if (this->list[j] < this->list[j + 1])
				{
					int aux = this->list[j];
					this->list[j] = this->list[j + 1];
					this->list[j + 1] = aux;
					ok = true;
				}
			}
			if (ok == false)break;
		}
	}
}

void Sort::InsertSort(bool ascendent)
{
	int i, j;
	if (ascendent == true)
	{
		for (i = 1; i < this->sz; i++)
		{
			int elem = this->list[i];
			j = i - 1;
			while (j >= 0 && this->list[j] > elem)
			{
				this->list[j + 1] = this->list[j];
				j = j - 1;
			}
			this->list[j + 1] = elem;
		}
	}
	else
	{
		for (i = 1; i < this->sz; i++)
		{
			int elem = this->list[i];
			j = i - 1;
			while (j >= 0 && this->list[j] < elem)
			{
				this->list[j + 1] = this->list[j];
				j = j - 1;
			}
			this->list[j + 1] = elem;
		}
	}
}

void QuickSortAsc(int v[], int st, int dr)
{
	if (st < dr)
	{
		int m = (st + dr) / 2;
		int aux = v[st];
		v[st] = v[m];
		v[m] = aux;
		int i = st, j = dr, d = 0;
		while (i < j)
		{
			if (v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		QuickSortAsc(v, st, i - 1);
		QuickSortAsc(v, i + 1, dr);
	}
}
void QuickSortDesc(int v[], int st, int dr)
{
	if (st < dr)
	{
		int m = (st + dr) / 2;
		int aux = v[st];
		v[st] = v[m];
		v[m] = aux;
		int i = st, j = dr, d = 0;
		while (i < j)
		{
			if (v[i] < v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		QuickSortDesc(v, st, i - 1);
		QuickSortDesc(v, i + 1, dr);
	}
}

void Sort::QuickSort(bool ascendent)
{
	if (ascendent == true)
	{
		QuickSortAsc(this->list, 0, (this->sz) - 1);
	}
	else
	{
		QuickSortAsc(this->list, 0, (this->sz) - 1);
	}
}



