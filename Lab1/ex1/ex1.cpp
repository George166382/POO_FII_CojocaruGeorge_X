// ex1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

int atoin(const char *c)
{
	int num = 0;
	for (int i=0 ; c[i]; i++)
	{
		num = num * 10 + (c[i] - 48) ;
	}
	return num;
}



int main()
{
	char ch;
	char cuv[30];
	int k = 0, sum = 0;
	
	FILE *f;
	int fp = fopen_s(&f,"in.txt", "r");
	memset(cuv, 0, 30);
	while ((ch = getc(f)) != EOF)
	{
		if (ch != '\n')
		{
			cuv[k++] = ch;
		}
		else
		{
			cuv[k++] = '\0';
			sum = sum + atoin(cuv);
			memset(cuv, 0, 30);
			k = 0;
		}
	}
	std::cout << sum << "\n";
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
