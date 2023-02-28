

#include <iostream>
#include <cstring>
#include "NumberList.h"

 
int main()
{
	NumberList n;
	n.Init();
	if (n.Add(3))
	{
		std::cout << "Adaugat\n";
	}
	if (n.Add(2))
	{
		std::cout << "Adaugat\n";
	}
	if (n.Add(7))
	{
		std::cout << "Adaugat\n";
	}
	if (n.Add(5))
	{
		std::cout << "Adaugat\n";
	}
	n.Sort();
	std::cout << "Sorted vector: ";
	n.Print();
	return 0;
}


