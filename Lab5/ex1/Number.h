#pragma once
class Number
{
	char* num;
	int base;
	int nr;
public:

	Number(const char * value, int base); // where base is between 2 and 16
	Number(int val);
	~Number();


	// add operators and copy/move constructor
	friend Number operator+(Number a,Number b);
	friend Number operator-(Number a,Number b);
	Number& operator+=( Number& n);
	Number& operator-=( Number& n);


	
	bool operator>(Number b);
	bool operator<(Number b);
	bool operator>=(Number b);
	bool operator<=(Number b);
	bool operator==(Number b);

	 Number& operator--();

	 Number& operator--(int);

	 Number(const Number& s);

	 Number(Number&& s);

	 Number& operator=(const Number& s);
	 Number& operator=(int value);

	 Number& operator=(const char* value);


	 Number& operator=(Number&& s);

	 char operator[](int index);
	void SwitchBase(int newBase);

	void Print();

	int GetDigitsCount(); // returns the number of digits for the current number

	int GetBase(); // returns the current base

	int GetNr();

	void SetNr(int nr);
};

