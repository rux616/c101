/*
	Name:			Dan Cassidy
	Date:			2013-10-16
	Homework #:		07
    Problem #:      02
	Source File:	HW07Problem02.cpp
    Class:          C-101 MW 1030
	Action:			This program asks the user to enter an integer between 1 and 100, quits if anything
					else. The number is tested to see if it is odd or even, and a message is displayed to
					that effect. The sum of all numbers up and including the entered number is then
					calculated and displayed.
*/

#include <iostream>
using namespace std;

bool IsEven(unsigned int N);
int SimpleSummation(int N);

void main()
{
	unsigned int Number;

	cout << "This program will ask you to enter an integer between 1 and 100, tell you\n"
		 << "whether the number is even or odd, then perform a simple summation on the\n"
		 << "number.\n\n";

	cout << "Enter a number from 1 to 100: ";
	cin >> Number;

	while (Number >= 1 && Number <= 100)
	{
		cout << "The number " << Number;

		if (IsEven(Number))
			cout << " is even ";
		else
			cout << " is odd ";

		cout << "and sums to " << SimpleSummation(Number) << ".\n";

		cout << "Enter a number from 1 to 100: ";
		cin >> Number;
	}
}

/******************************* IsEven *****************************************************
Action:			Determines if a number is even or not
Paremeters:		
	IN:			N, integer to be checked
	OUT:		None
Returns:		bool indicating whether even (true) or odd (false)
Precondition:	N is greater than 0
********************************************************************************************/
bool IsEven(unsigned int N)
{
	return !(N % 2);
}

/******************************* SimpleSummation ********************************************
Action:			Performs a simple summation of a given number
Paremeters:		
	IN:			N, integer to be summed with itself
	OUT:		None
Returns:		The simple summation of the number
Precondition:	N is greater than 0
********************************************************************************************/
int SimpleSummation(int N)
{
	int Summation = 0;

	for (int Index = 1 ; Index <= N ; ++Index)
		Summation += Index;

	return Summation;
}

/*
	PROGRAM OUTPUT

	Test Case 1: Normal Small (Number = 4)
	Tests small numbers and even numbers.
		The number 4 is even and sums to 10.

	Test Case 2: Normal Large (Number = 91)
	Tests large numbers and odd numbers.
		The number 91 is odd and sums to 4186.

	Test Case 2: Limit (Number = 1)
	Tests the limit case of 1.
		The number 1 is odd and sums to 1.

	Test Case 3: Limit (Number = 100)
	Tests the limit case of 100.
		The number 100 is even and sums to 5050.

	Test Case 4: Limit (Number = 0)
	Tests to make sure the program quits at the correct numbers.
		Press any key to continue . . .

	Test Case 5: Limit (Number = 101)
	Tests to make sure the program quits at the correct numbers.
		Press any key to continue . . .
*/