/*
	Name:			Dan Cassidy
	Date:			2013-09-23
	Homework #:		04
    Problem #:      04
	Source File:	HW04Problem04.cpp
    Class:          C-101 MW 1030
	Action:			This program lets the user enter any positive integer (not checked) and then calculates
					and displays the sum of the digits.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int Number;
	int Sum = 0;

	cout << "This program will ask for any positive integer and then calculate and display" << endl;
	cout << "the sum of its digits." << endl << endl;

	cout << "Enter a positive integer: ";
	cin >> Number;

	do
	{
		Sum += Number % 10;
		Number /= 10;
	} while (Number != 0);

	cout << "The sum of the number's digits is: " << Sum << endl;

	return 0;
}

/*
	PROGRAM OUTPUT

	Test Case 1: Normal (Number = 12345)
	Tests to make sure the loop can handle the numbers 1 through 5.
		The sum of the number's digits is: 15

	Test Case 2: Special (Number = 67890)
	Tests to make sure the loop can handle the numbers 6 through 9 and a trailing 0.
		The sum of the number's digits is: 30

	Test Case 3: Special (Number = 01234)
	Tests to make sure the loop can handle a preceding 0.
		The sum of the number's digits is: 10
*/