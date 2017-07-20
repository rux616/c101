/*
	Name:			Dan Cassidy
	Date:			2013-09-16
	Homework #:		03
    Problem #:      03
	Source File:	HW03Problem03.cpp
    Class:          C-101 MW 1030
	Action:			This program will ask the user for any two integers between -180 and 180, then give the
					product, quotient, and remainder.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	int Number1, Number2;
	int Product, Quotient, Remainder;

	cout << "This program will ask you for any two integers between -180 and 180, then give" << endl;
	cout << "the product, quotient, and remainder." << endl << endl;

	cout << "Enter two integers between -180 and 180 --> ";
	cin >> Number1 >> Number2;

	if (Number1 < -180 || Number1 > 180 || Number2 < -180 || Number2 > 180)
		return 1;

	Product = Number1 * Number2;
	Quotient = Number1 / Number2;
	Remainder = Number1 % Number2;

	cout << endl;
	cout << "  " << setw(4) << Number1 << "         " << setw(4) << Quotient << " R " << Remainder << endl;
	cout << "x " << setw(4) << Number2 << "        _____" << endl;
	cout << "------    " << setw(4) << Number2 << ")" << setw(4) << Number1 << endl;
	cout << setw(6) << Product << endl;

	return 0;
}

/*
	PROGRAM OUTPUT

	Test Case 1: Specific (Number1 = 125, Number2 = 34)
		   125            3 R 23
		x   34        _____
		------      34) 125
		  4250
  
	Test Case 2: Specific (Number1 = 157, Number2 = 16)
		   157            9 R 13
		x   16        _____
		------      16) 157
		  2512

	Test Case 3: Limit (Number1 = -180, Number2 = -180)
		  -180            1 R 0
		x -180        _____
		------    -180)-180
		 32400

	Test Case 4: Limit (Number1 = -180, Number2 = 180)
		  -180           -1 R 0
		x  180        _____
		------     180)-180
		-32400

	Test Case 5: Limit (Number1 = 180, Number2 = -180)
		   180           -1 R 0
		x -180        _____
		------    -180) 180
		-32400

	Test Case 6: Limit (Number1 = 180, Number2 = 180)
		   180            1 R 0
		x  180        _____
		------     180) 180
		 32400
*/