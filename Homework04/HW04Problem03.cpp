/*
	Name:			Dan Cassidy
	Date:			2013-09-23
	Homework #:		04
    Problem #:      03
	Source File:	HW04Problem03.cpp
    Class:          C-101 MW 1030
	Action:			This program has the user continually enter integers between 0 and 10 and calculates
					their sum until it is over 35.  It will then show the sum and the last number entered.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int Number;
	int Sum = 0;

	cout << "This program will ask you to continually enter integers between 0 and 10 and" << endl;
	cout << "and continuously calculate their sum until it is over 35. It will then show both" << endl;
	cout << "the sum and the last number entered." << endl << endl;

	do
	{
		cout << "Enter an integer between 0 and 10: ";
		cin >> Number;
		Sum += Number;
	} while (Sum < 35);

	cout << "Sum = " << Sum << endl;
	cout << "Last Number = " << Number << endl;

	return 0;
}

/*
	PROGRAM OUTPUT

	Test Case 1: Normal (Number = 10, Number = 9, Number = 8, Number = 7, Number = 6)
		Sum = 40
		Last Number = 6
	
	Test Case 2: Limit (Number = 10, Number = 10, Number = 10, Number = 4, Number = 1)
	Tests to make sure program stops at 35
		Sum = 35
		Last Number = 1
*/