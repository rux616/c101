/*
	Name:			Dan Cassidy
	Date:			2013-09-10
	Homework #:		02
	Problem #:		01
	Source File:	HW02Problem01.cpp
	Class:			C-101 MW 1030
	Action:			This program asks the user for the Height, Width, and Length of a box in order to
					compute the volume.
*/

#include <iostream>
using namespace std;

int main(void)
{
	float Height, Width, Length;
	float Volume;

	cout << "This program will compute the volume of a box." << endl;
	cout << "Please enter the height, width, and length as requested." << endl;
	cout << endl;

	cout << "Enter height: ";
	cin >> Height;
	cout << "Enter width: ";
	cin >> Width;
	cout << "Enter length: ";
	cin >> Length;

	cout << endl;

	if (Height > 0 && Width > 0 && Length > 0)
	{
		Volume = Height * Width * Length;
		cout << "Volume: " << Volume << endl;
	}
	else
	{
		cout << "Sorry, all values must be greater than 0." << endl;
	}
	return 0;
}

/*
	PROGRAM OUTPUT
	
	Test Case 1: Normal (Height = 2, Width = 3, Length = 4)
		Volume: 24

	Test Case 2: Decimals (Height = 1.2, Width = 2.3, Length = 3.4)
		Volume: 9.384

	Test Case 3: <= Zero (Height = 0, Width = 0, Length = 0)
	Test to make sure that the logic check is working
		Sorry, all values must be greater than 0.
*/