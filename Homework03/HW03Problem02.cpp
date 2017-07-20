/*
	Name:			Dan Cassidy
	Date:			2013-09-16
	Homework #:		03
    Problem #:      02
	Source File:	HW03Problem02.cpp
    Class:          C-101 MW 1030
	Action:			(HW02P06) This program asks a user for a year and then tells the user whether that year
					is a yeap year or not.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int Year;

	cout << "This program will ask you to enter a year and then will tell you whether that" << endl;
	cout << "year is a leap year or not." << endl << endl;

	cout << "Please enter a year: ";
	cin >> Year;

	if (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0))
		cout << Year << " is a leap year" << endl;
	else
		cout << Year << " is not a leap year" << endl;

	return 0;
}

/* 
	PROGRAM OUTPUT

	Test Case 1: Normal (Year = 2012)
		2012 is a leap year

	Test Case 2: Normal (Year = 2000)
		2000 is a leap year

	Test Case 3: Normal (Year = 1900)
		1900 is not a leap year

	Test Case 4: Normal (Year = 1999)
		1999 is not a leap year
*/