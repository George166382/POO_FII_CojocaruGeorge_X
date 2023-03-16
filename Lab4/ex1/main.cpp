
#include <iostream>
#include "Sort.h"

int main()
{
	Sort s("10,40,100,5,70");
	s.Print();
	std::cout << s.GetElementsCount() << "\n";
	std::cout<<s.GetElementFromIndex(2);
	s.BubbleSort(true);
	std::cout << "\n";
	s.Print();
	s.InsertSort(false);
	std::cout << "\n";
	s.Print();
	s.QuickSort(true);
	std::cout << "\n";
	s.Print();
	return 0;
}


