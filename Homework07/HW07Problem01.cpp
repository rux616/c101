/*
	Name:			Dan Cassidy
	Date:			2013-10-16
	Homework #:		07
    Problem #:      01
	Source File:	HW07Problem01.cpp
    Class:          C-101 MW 1030
	Action:			This program takes an input of a number of seconds and translates it into the format
					H:MM:SS.
*/

#include <iostream>
#include <iomanip>
using namespace std;

void DisplayTime(unsigned int Seconds);

void main()
{
	unsigned int TotalSeconds;

	cout << "This program translates a number of seconds into H:MM:SS format.\n\n";

	cout << "Enter Total Seconds: ";
	cin >> TotalSeconds;

	while (TotalSeconds > 0)
	{
		DisplayTime(TotalSeconds);

		cout << "Enter Total Seconds: ";
		cin >> TotalSeconds;
	}
}

/******************************* DisplayTime ************************************************
Action:			Computes and displays the H:MM:SS of the number of seconds
Paremeters:		
	IN:			Seconds, unsigned integer to translate into H:MM:SS
	OUT:		None
Returns:		None
Precondition:	Input Seconds needs to be non-negative
********************************************************************************************/
void DisplayTime(unsigned int Seconds)
{
	unsigned int NumHours, NumMinutes, NumSeconds;

	NumHours = Seconds / 3600;
	NumMinutes = (Seconds / 60) - (NumHours * 60);
	NumSeconds = Seconds % 60;

	cout << setfill('0');
	cout << NumHours << ":" << setw(2) << NumMinutes << ":" << setw(2) << NumSeconds << "\n";
}

/*
	PROGRAM OUTPUT

	Test Case 1: Limit (TotalSeconds = 1)
	Tests to make sure that the leading zeroes are displayed.
		0:00:01

	Test Case 2: Limit (TotalSeconds = 5025)
	Tests to make sure that the math is correct for determining the different components
		1:23:45
*/