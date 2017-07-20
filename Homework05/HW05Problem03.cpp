/*
	Name:			Dan Cassidy
	Date:			2013-09-30
	Homework #:		05
    Problem #:      03
	Source File:	HW05Problem03.cpp
    Class:          C-101 MW 1030
	Action:			This program ask a user to enter positive integers and will keep a record of how many
					evens are entered. When the user enters 0 the program will then display how many evens
					were entered.
*/

#include <iostream>
using namespace std;

int main(void)
{
	unsigned int Number;
	unsigned int NumberOfEvens = 0;

	cout << "This program will ask you to enter a series of positive integers. When you enter"
		 << "'0', the program will then display how many evens were entered." << endl << endl;

	cout << "Enter a positive integer or '0' to quit: ";
	cin >> Number;

	while (Number != 0)
	{
		if (Number % 2 == 0)
			NumberOfEvens++;

		cout << "Enter a positive integer or '0' to quit: ";
		cin >> Number;
	}

	cout << "You entered " << NumberOfEvens << " even numbers." << endl;
	return 0;
}

/*
	PROGRAM OUTPUT

	Test Case 1: Specific (Sequence of inputs: Number = 3, 56, 4, 13, 779, 46, 0)
		You entered 3 even numbers.

	Test Case 2: Special (Sequence of inputs: Number = 0)
		You entered 0 even numbers.

	Test Case 3: All Evens (Sequence of Number = 2, 46, 802, 4680, 0)
		You entered 4 even numbers.

	Test Case 4: All Odds (Sequence of inputs: Number = 1, 35, 791, 3579, 0)
		You entered 0 even numbers.
*/