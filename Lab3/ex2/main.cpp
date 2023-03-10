

#include <iostream>
#include "Canvas.h"

int main()
{
	Canvas c(100,100);
	c.Clear();
	c.DrawLine(2, 2, 2, 7,'x');
	//c.DrawCircle(50, 50, 7, '.');
	/*c.FillCircle(50, 50, 7, '.');
	c.DrawRect(13, 6, 20, 14, '*');
	c.FillRect(13, 6, 20, 14, 'A');
	c.SetPoint(33, 33, 'x');*/
	c.Print();
    std::cout << "Hello World!\n";
	//system("pause");
	return 0;
}


