

#include <iostream>
#include "Student.h"
#include "Global.h"
int main()
{
	Student s1;
	s1.setName("George");
	std::cout <<"First Student: "<< s1.getName() << "\n";
	s1.setHist(3.0);
	s1.setMaths(7.1);
	s1.setEng(5.5);
	std::cout << "English Mark: " << s1.getEng() << "\n";
	std::cout << "History Mark: " << s1.getHist() << "\n";
	std::cout << "Mathematics Mark: " << s1.getMaths() << "\n";
	Student s2;
	s2.setName("Alin");
	std::cout <<"Second Student: "<< s2.getName() << "\n";
	s2.setHist(4.0);
	s2.setMaths(3.1);
	s2.setEng(0.9);
	std::cout << "English Mark: " << s2.getEng() << "\n";
	std::cout << "History Mark: " << s2.getHist() << "\n";
	std::cout << "Mathematics Mark: " << s2.getMaths() << "\n";
	if (s1.getAvg() == -1) { std::cout << "Wrong Average, it has -1\n"; }
	else std::cout << "First Student Average Grade: " << s1.getAvg() << "\n";
	if (s2.getAvg() == -1) { std::cout << "Wrong Average, it has -1\n"; }
	else std::cout <<"Second Student Average Grade: "<< s2.getAvg() << "\n";
	if (compare_students_name(s1, s2) == 0)
	{
		std::cout << "Equal Name\n";
	}
	else if (compare_students_name(s1, s2) == 1)
	{
		std::cout << "First Student Name\n";
	}
	else
	{
		std::cout << "Second Student Name\n";
	}
	if (compare_students_hist(s1, s2) == 0)
	{
		std::cout << "Equal History\n";
	}
	else if (compare_students_hist(s1, s2) == 1)
	{
		std::cout << "First Student History\n";
	}
	else
	{
		std::cout << "Second Student History\n";
	}
	if (compare_students_eng(s1, s2) == 0)
	{
		std::cout << "Equal English\n";
	}
	else if (compare_students_eng(s1, s2) == 1)
	{
		std::cout << "First Student English\n";
	}
	else
	{
		std::cout << "Second Student English\n";
	}
	if (compare_students_maths(s1, s2) == 0)
	{
		std::cout << "Equal Maths\n";
	}
	else if (compare_students_maths(s1, s2) == 1)
	{
		std::cout << "First Student Maths\n";
	}
	else
	{
		std::cout << "Second Student Maths\n";
	}
	if (compare_students_avg(s1, s2) == 0)
	{
		std::cout << "Equal Average\n";
	}
	else if (compare_students_avg(s1, s2) == 1)
	{
		std::cout << "First Student Average\n";
	}
	else
	{
		std::cout << "Second Student Average\n";
	}
	return 0;
}


