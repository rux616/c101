/*
	Name:			Dan Cassidy
	Date:			2013-09-10
	Homework #:		02
	Problem #:		03
	Source File:	HW02Problem03.cpp
	Class:			C-101 MW 1030
	Action:			This program will convert a total number of days into the corresponding number of years
					and days left over.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int NumberOfDays;
	int Years, DaysLeft;

	cout << "This program will convert the number of days you input into the corresponding" << endl;
	cout << "number of years and days left over." << endl;
	cout << endl;

	cout << "Number of days: ";
	cin >> NumberOfDays;

	cout << endl;

	if (NumberOfDays >= 0)
	{
		Years = NumberOfDays / 365;
		DaysLeft = NumberOfDays % 365;

		cout << Years << " year(s) and " << DaysLeft << " day(s)" << endl;
	}
	else
	{
		cout << "Sorry, you can't have a negative number of days." << endl;
	}

	return 0;
}

/*
	PROGRAM OUTPUT

	Test Case 1: Normal (NumberOfDays = 150)
		0 year(s) and 150 day(s)

	Test Case 2: Special (NumberOfDays = 364)
	Tests to make sure that the mod and div operators are working as intended at 365 +/- 1
		0 year(s) and 364 day(s)

	Test Case 3: Special (NumberOfDays = 365)
	Tests to make sure that the mod and div operators are working as intended at 365 +/- 1
		1 year(s) and 0 day(s)

	Test Case 4: Special (NumberOfDays = 366)
	Tests to make sure that the mod and div operators are working as intended at 365 +/- 1
		1 year(s) and 1 day(s)

	Test Case 5: Negative (NumberOfDays = -150)
	Tests to make sure that negative numbers are not accepted
		Sorry, you can't have a negative number of days.
*/