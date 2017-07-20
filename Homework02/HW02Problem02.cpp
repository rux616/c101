/*
	Name:			Dan Cassidy
	Date:			2013-09-10
	Homework #:		02
	Problem #:		02
	Source File:	HW02Problem02.cpp
	Class:			C-101 MW 1030
	Action:			This program will calculate and display both the area and circumference of a circle
					given the radius.
*/

#include <iostream>
using namespace std;

int main(void)
{
	const float PI = 3.14159;
	float Radius;
	float Area, Circumference;

	cout << "This program will calculate the area and circumference of a circle when given" << endl;
	cout << "the radius." << endl;
	cout << endl;

	cout << "Enter radius: ";
	cin >> Radius;

	cout << endl;

	if (Radius > 0)
	{
		Area = PI * Radius * Radius;
		Circumference = 2 * PI * Radius;

		cout << "Area: " << Area << endl;
		cout << "Circumference: " << Circumference << endl;
	}
	else
	{
		cout << "Sorry, the radius must be greater than 0." << endl;
	}
	return 0;
}

/*
	PROGRAM OUTPUT

	Test Case 1: Normal (Radius = 3)
		Area: 28.2743
		Circumference: 18.8495

	Test Case 2: Decimal (Radius = 3.14159)
		Area: 31.0062
		Circumference: 19.7392

	Test Case 3: <= Zero (Radius = 0)
	Tests to make sure that the logic check works
		Sorry, the radius must be greater than 0.

*/