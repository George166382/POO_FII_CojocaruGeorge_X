#include "Math.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double Math::Add(int x, int y)
{
	return x + y;
}
double Math::Add(int y, int x, int z)
{
	return x + y + z;
}
double Math::Add(double x, double y)
{
	return (double)(x + y);
}
double Math::Add(double x, double y, double z)
{
	return (double)(x + y + z);
}
double Math::Mul(int x, int y)
{
	return x * y;
}
double Math::Mul(int x, int y, int z)
{
	return x * y * z;
}
double Math::Mul(double x, double y)
{
	return (double)(x * y);
}
double Math::Mul(double x, double y, double z)
{
	return (double)(x * y * z);
}
double Math::Add(int count, ...)
{
	double val;
	double sum = 0;
	va_list vl;
	va_start(vl, count);
	for (int i = 0; i < count; i++)
	{
		val = va_arg(vl, double);
		sum += val;
	}
	va_end(vl);
	return sum;
}
char* Math::Add(const char* x, const char* y)
{
	char* sum;
	int len = strlen(x) + strlen(y) + 1;
	sum = (char*)malloc(len);
	memset(sum, 0, len);
	memcpy(sum, x, strlen(x));
	memcpy(sum + strlen(x), y, strlen(y));
	sum[len-1] = '\0';
	return sum;
}