#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <stdarg.h>
#include <initializer_list>

class Sort

{

	// add data members
	int *list;
	int sz;

public:

	// add constuctors
	Sort(int number, int min, int max);
	Sort(std::initializer_list<int> list);
	Sort(int *v, int size);
	Sort(int count, ...);
	Sort(const char * str);
	~Sort();
	void InsertSort(bool ascendent = false);

	void QuickSort(bool ascendent = false);

	void BubbleSort(bool ascendent = false);

	void Print();

	int  GetElementsCount();

	int  GetElementFromIndex(int index);

};

