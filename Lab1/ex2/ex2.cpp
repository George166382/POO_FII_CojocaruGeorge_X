// ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>


int main()
{
	 char s[100],cuv[5][20];
	 memset(s, 0, 100);
	scanf_s("%s",s);
	for (int k = 0; k < 5; k++)
	{
		memset(cuv[k], 0, 20);
	}
	int nrWrds = 0, k = 0;
	for (int i = 0; s[i]; i++)
	{
		if (s[i] != ' ') {
			cuv[nrWrds][k++] = s[i];
		}
		else
		{
			cuv[nrWrds][k++] = '\0';
			nrWrds++;
		}
	}
	for (int i = 0; i < nrWrds; i++)
	{
		for (int j = i + 1; j < nrWrds; j++)
		{
			if (strlen(cuv[i]) > strlen(cuv[j]))
			{
				char aux[20];
				memset(aux, 0, 20);
				strcpy_s(aux, cuv[i]);
				strcpy_s(cuv[i], cuv[j]);
				strcpy_s(cuv[j], aux);
				memset(aux, 0, 20);
			}
			else if (strlen(cuv[i]) == strlen(cuv[j]))
			{
				if (strcmp(cuv[i], cuv[j]))
				{
					for (int k = 0; k < strlen(cuv[i]); k++)
					{
						if (cuv[i][k] > cuv[j][k])
						{
							char aux[20];
							memset(aux, 0, 20);
							strcpy_s(aux, cuv[i]);
							strcpy_s(cuv[i], cuv[j]);
							strcpy_s(cuv[j], aux);
							memset(aux, 0, 20);
						}
					}
				}
			}
		}
	}
	for (int k = 0; k < 5; k++)
	{
		printf("%s\n", cuv[k]);
	}
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
