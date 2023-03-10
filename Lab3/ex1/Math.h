#pragma once
class Math
{
public:

	static double Add(int, int);

	static double Add(int, int, int);

	static double Add(double, double);

	static double Add(double, double, double);

	static double Mul(int, int);

	static double Mul(int, int, int);

	static double Mul(double, double);

	static double Mul(double, double, double);

	static double Add(int count, ...); // sums up a list of integers

	static char* Add(const char *, const char *);
};

