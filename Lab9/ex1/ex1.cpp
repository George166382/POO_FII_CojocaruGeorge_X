

#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "Map.h"
int main()
{
	Map<int, const char *> m;
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";
	for (auto[key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	m[20] = "result";
	for (auto[key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	return 0;
}

