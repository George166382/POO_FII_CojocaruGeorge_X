
#include <iostream>
#include <stdio.h>
#include "Math.h"

int main()
{
	std::cout << Math::Add(2, 3) << "\n";
	std::cout << Math::Add(2, 3, 6) << "\n";
	std::cout << Math::Add(2.4, 6.3) << "\n";
	std::cout << Math::Add(6, 3.0, 4.0, 2.0, 1.0, 6.0, 2.0) << "\n";
	char *t = Math::Add("Ana ", "are");
	printf("%s\n", t);
	free(t);
	return 0;
}


