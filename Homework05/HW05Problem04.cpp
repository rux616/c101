/*
	Name:			Dan Cassidy
	Date:			2013-09-30
	Homework #:		05
    Problem #:      04
	Source File:	HW05Problem04.cpp
    Class:          C-101 MW 1030
	Action:			This program asks the user to enter a positive integer then checks that number to see
					if it is both odd and evenly divisible by 3. If so, a message is displayed confirming
					this and also displayed the right-most digit of the number. If not, a message is
					displayed to that effect as well. The program will loop until the user enters '0'.
*/

#include <iostream>
using namespace std;

int main(void)
{
	unsigned int Number;

	cout << "This program will ask you to input a positive integer and will check if that" << endl
		 << "number is odd and evenly divisible by three. If it is, a message will be shown" << endl
		 << "to that effect and the last digit of the number will also be displayed. If not," << endl
		 << "a message will state as such." << endl << endl;

	cout << "Enter a positive integer or '0' to quit: ";
	cin >> Number;

	while (Number != 0)
	{
		if (Number % 2 != 0 && Number % 3 == 0)
			cout << "That number is both odd and evenly divisible by 3." << endl
				 << "The rightmost digit of the number is " << Number % 10 << "." << endl;
		else
			cout << "Number does not work." << endl;

		cout << "Enter a positive integer or '0' to quit: ";
		cin >> Number;
	}

	return 0;
}

/*
	PROGRAM OUTPUT

	Test Case 1: Immediate Exit (Number = 0)
		Enter a positive integer or '0' to quit: 0
		Press any key to continue . . .

	Test Case 2: Divisible by 3 (Sequence of entries: Number = 6, 9, 279936, 531441, 0)
	Test small and large cases of even and odd, both divisible by 3.
		Enter a positive integer or '0' to quit: 6
		Number does not work.
		Enter a positive integer or '0' to quit: 9
		That number is both odd and evenly divisible by 3.
		The rightmost digit of the number is 9.
		Enter a positive integer or '0' to quit: 279936
		Number does not work.
		Enter a positive integer or '0' to quit: 531441
		That number is both odd and evenly divisible by 3.
		The rightmost digit of the number is 1.
		Enter a positive integer or '0' to quit: 0
		Press any key to continue . . .

	Test Case 3: Not Divisible by 3 (Sequence of entries: Number = 1, 8, 49658, 98525, 0)
	Test small and large cases of even and odd, neither divisible by 3.
		Enter a positive integer or '0' to quit: 1
		Number does not work.
		Enter a positive integer or '0' to quit: 8
		Number does not work.
		Enter a positive integer or '0' to quit: 49658
		Number does not work.
		Enter a positive integer or '0' to quit: 98525
		Number does not work.
		Enter a positive integer or '0' to quit: 0
		Press any key to continue . . .
*/