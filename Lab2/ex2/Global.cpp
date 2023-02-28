#include <iostream>
#include <string.h>
#include "Global.h"

int compare_students_name(Student &s1, Student &s2)
{
	if (strcmp(s1.getName(), s2.getName()) == 0)
	{
		return 0;
	}
	else if (strcmp(s1.getName(), s2.getName()) > 0)
	{
		return 1;
	}
	else return -1;
}
int compare_students_hist(Student &s1, Student &s2)
{
	if (s1.getHist() == s2.getHist())
	{
		return 0;
	}
	else if (s1.getHist()>s2.getHist())
	{
		return 1;
	}
	else return -1;
}
int compare_students_eng(Student &s1, Student &s2)
{
	if (s1.getEng() == s2.getEng())
	{
		return 0;
	}
	else if (s1.getEng() > s2.getEng())
	{
		return 1;
	}
	else return -1;
}
int compare_students_maths(Student &s1, Student &s2)
{
	if (s1.getMaths() == s2.getMaths())
	{
		return 0;
	}
	else if (s1.getMaths() > s2.getMaths())
	{
		return 1;
	}
	else return -1;
}
int compare_students_avg(Student &s1, Student &s2)
{
	if (s1.getAvg() == s2.getAvg())
	{
		return 0;
	}
	else if (s1.getAvg() > s2.getAvg())
	{
		return 1;
	}
	else return -1;
}