/*	
	Name:			Dan Cassidy
	Date:			2013-09-16
	Homework #:		03
    Problem #:      01
	Source File:	HW03Problem01.cpp
    Class:          C-101 MW 1030
	Action:			(HW01P03) This program asks the user for an input between 1 and 100 and displays "Good
					Input" if it is and "Bad Input" if it is not.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int Number;

	cout << "This program will ask you for a number between one and one-hundred and tell you" << endl;
	cout << "whether your input was good or bad." << endl << endl;

	cout << "Please enter a number between 1 and 100: ";
	cin >> Number;

	if (Number >= 1 && Number <= 100)
		cout << "Good Input" << endl;
	else
		cout << "Bad Input" << endl;

	return 0;
}

/*
	PROGRAM OUTPUT

	Test Case 1: Normal (Number = 50)
		Good Input

	Test Case 2: Illegal (Number = -50)
		Bad Input

	Test Case 3: Illegal (Number = 150)
		Bad Input
	
	Test Case 4: Limit (Number = 0)
	Tests to make sure that the condition check is working properly at 1 +/- 1
		Bad Input

	Test Case 5: Limit (Number = 1)
	Tests to make sure that the condition check is working properly at 1 +/- 1
		Good Input

	Test Case 6: Limit (Number = 2)
	Tests to make sure that the condition check is working properly at 1 +/- 1
		Good Input

	Test Case 7: Limit (Number = 99)
	Tests to make sure that the condition check is working properly at 100 +/- 1
		Good Input

	Test Case 8: Limit (Number = 100)
	Tests to make sure that the condition check is working properly at 100 +/- 1
		Good Input

	Test Case 9: Limit (Number = 101)
	Tests to make sure that the condition check is working properly at 100 +/- 1
		Bad Input
*/