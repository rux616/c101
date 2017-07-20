/*
	Name:			Dan Cassidy
	Date:			2013-10-21
	Homework #:		08
    Problem #:      01
	Source File:	HW08Problem01.cpp
    Class:          C-101 MW 1030
	Action:			This program adds two fractions together and displays them in either reduced form or as
					a whole number if possible.
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

void ReadData(int &, int &, int &, int &);
void SumFraction(int, int, int, int, int &, int &);
int GCD(int, int);
void DisplayData(int, int, int, int, int, int);
unsigned NumDigits(unsigned);

void main()
{
	int Numerator1, Denominator1,
		Numerator2, Denominator2,
		NumeratorS, DenominatorS;
	char Continue;

	do
	{
		system("cls");

		cout << "This program adds fractions.\n";
		cout << "============================\n";

		ReadData(Numerator1, Denominator1, Numerator2, Denominator2);
		
		SumFraction(Numerator1, Denominator1, Numerator2, Denominator2, NumeratorS, DenominatorS);
		
		cout << endl;
		DisplayData(Numerator1, Denominator1, Numerator2, Denominator2, NumeratorS, DenominatorS);
		cout << endl;

		cout << "----------------------------\n";
		cout << "Continue? Y or N: ";
		cin >> Continue;
	} while (Continue == 'Y' || Continue == 'y');
}

/****************************** ReadData ******************************************************************
Action:			Prompts the user for input and then reads the input into respective variables

Paremeters:		
	IN:			None
	OUT:		int Numerator1, holds the first numerator asked for
	OUT:		int Denominator1, holds the first denominator asked for
	OUT:		int Numerator2, holds the second numerator asked for
	OUT:		int Denominator2, holds the second denominator asked for

Returns:		Nothing, except through reference parameters

Precondition:	None
**********************************************************************************************************/
void ReadData(int &Numerator1, int &Denominator1, int &Numerator2, int &Denominator2)
{
	cout << "Enter numerator 1:   ";
	cin >> Numerator1;
	cout << "Enter denominator 1: ";
	cin >> Denominator1;
	cout << "\n";
	cout << "Enter numerator 2:   ";
	cin >> Numerator2;
	cout << "Enter denominator 2: ";
	cin >> Denominator2;
}

/****************************** SumFraction ***************************************************************
Action:			Adds two fractions together and reduces them to lowest terms

Paremeters:		
	IN:			int Numer1, holds the numerator of the first fraction
	IN:			int Denom1, holds the denominator of the first fraction
	IN:			int Numer2, holds the numerator of the second fraction
	IN:			int Denom2, holds the denominator of the second fraction
	OUT:		int NumeratorS, holds the reduced numerator of the sum fraction
	OUT:		int DenominatorS, holds the reduced denominator of the sum fraction

Returns:		Nothing, except through reference parameters

Precondition:	IN parameters should be non-negative
**********************************************************************************************************/
void SumFraction(int Numer1, int Denom1, int Numer2, int Denom2, int &NumeratorS, int &DenominatorS)
{
	int GCDLocal;

	NumeratorS = (Numer1 * Denom2) + (Denom1 * Numer2);
	DenominatorS = Denom1 * Denom2;

	GCDLocal = GCD(NumeratorS, DenominatorS);
	if (GCDLocal == 0)
		GCDLocal = 1;
	
	NumeratorS /= GCDLocal;
	DenominatorS /= GCDLocal;
}

/****************************** GCD ***********************************************************************
Action:			Uses Euclid's algorithm to return the greatest common divisor of two numbers

Paremeters:		
	IN:			int Num1, integer that holds the first number to analyze
	IN:			int Num2, integer that holds the second number to analyze
	OUT:		None

Returns:		Integer that holds the greatest common divisor of int Num1 and int Num2

Precondition:	None
**********************************************************************************************************/
int GCD(int Num1, int Num2)
{
	int Temp;

	while (Num2 != 0)
	{
		Temp = Num2;
		Num2 = Num1 % Num2;
		Num1 = Temp;
	}

	return Num1;
}

/****************************** DisplayData ***************************************************************
Action:			Displays the fractions and sum nicely

Paremeters:		
	IN:			int Numer1, holds the numerator of the first fraction
	IN:			int Denom1, holds the denominator of the first fraction
	IN:			int Numer2, holds the numerator of the second fraction
	IN:			int Denom2, holds the denominator of the second fraction
	IN:			int NumerS, holds the reduced numerator of the sum fraction
	IN:			int DenomS, holds the reduced denominator of the sum fraction

	OUT:		None

Returns:		Nothing

Precondition:	None
**********************************************************************************************************/
void DisplayData(int Numer1, int Denom1, int Numer2, int Denom2, int NumerS, int DenomS)
{
	// Declare and determine the length of the different numbers -- for use in centering the numbers later
	unsigned N1Length = Numer1 >= 0 ? NumDigits(Numer1) : NumDigits(-Numer1) + 1;
	unsigned D1Length = Denom1 >= 0 ? NumDigits(Denom1) : NumDigits(-Denom1) + 1;
	unsigned N2Length = Numer2 >= 0 ? NumDigits(Numer2) : NumDigits(-Numer2) + 1;
	unsigned D2Length = Denom2 >= 0 ? NumDigits(Denom2) : NumDigits(-Denom2) + 1;
	unsigned NSLength = NumerS >= 0 ? NumDigits(NumerS) : NumDigits(-NumerS) + 1;
	unsigned DSLength = DenomS >= 0 ? NumDigits(DenomS) : NumDigits(-DenomS) + 1;

	unsigned F1Length = N1Length >= D1Length ? N1Length : D1Length;
	unsigned F2Length = N2Length >= D2Length ? N2Length : D2Length;
	unsigned FSLength = NSLength >= DSLength ? NSLength : DSLength;

	// Displays the first line and centers the numbers in their respective fractions with setw
	cout << " ";
	cout << " " << setw( int( (F1Length + N1Length) / 2.0 + 0.5 ) ) << Numer1
				<< setw( int( (F1Length - N1Length) / 2.0 + 1.0 ) ) << " ";
	cout << "   ";
	cout << " " << setw( int( (F2Length + N2Length) / 2.0 + 0.5 ) ) << Numer2
				<< setw( int( (F2Length - N2Length) / 2.0 + 1.0 ) ) << " ";
	cout << "   ";
	if (DenomS != 1 && DenomS != -1)
		cout << " " << setw( int( (FSLength + NSLength) / 2.0 + 0.5 ) ) << NumerS;

	// Displays the middle line
	cout << setfill('-') << "\n ";
	cout << "-" << setw(F1Length) << "-" << "-";
	cout << " + ";
	cout << "-" << setw(F2Length) << "-" << "-";
	cout << " = ";
	if (DenomS != 1 && DenomS != -1)
		cout << "-" << setw(FSLength) << "-" << "-";
	else
		cout << NumerS / DenomS;

	// Displays the third line and centers the numbers in their respective fractions with setw
	cout << setfill(' ') << "\n ";
	cout << " " << setw( int( (F1Length + D1Length) / 2.0 + 0.5 ) ) << Denom1
				<< setw( int( (F1Length - D1Length) / 2.0 + 1.0 ) ) << " ";
	cout << "   ";
	cout << " " << setw( int( (F2Length + D2Length) / 2.0 + 0.5 ) ) << Denom2
				<< setw( int( (F2Length - D2Length) / 2.0 + 1.0 ) ) << " ";
	cout << "   ";
	if (DenomS != 1 && DenomS != 1)
		cout << " " << setw( int( (FSLength + DSLength) / 2.0 + 0.5 ) ) << DenomS;
	cout << "\n";
}

/****************************** NumDigits *****************************************************************
Action:			Recursively determines the number of digits in a number

Credits:		Found at http://stackoverflow.com/a/3068415

Paremeters:		
	IN:			unsigned Num, holds the number whose length is to be determined
	OUT:		None

Returns:		The number of digits of unsigned Num

Precondition:	Num must be non-negative
**********************************************************************************************************/
unsigned NumDigits(unsigned Num)
{
    if (Num < 10)
		return 1;

    return 1 + NumDigits(Num / 10);
}

/*
	PROGRAM OUTPUT

	Test Case 0: Special
	Tests the layout of the program.  Further tests will use only the output of DisplayData in the interest
	of saving space.
		This program adds fractions.
		============================
		Enter numerator 1:   1
		Enter denominator 1: 2

		Enter numerator 2:   3
		Enter denominator 2: 4

		  1     3     5
		 --- + --- = ---
		  2     4     4

		----------------------------
		Continue? Y or N:
		
	Test Case 1: Limit (Numerator1 = 0, Denominator1 = 3, Numerator2 = 5, Denominator2 = 4)
	Tests adding fractions with zeroes and fractions where both numerator and denominator are single
	digits.
		  0     5     5
		 --- + --- = ---
		  3     4     4

	Test Case 2: Normal (Numerator1 = 1, Denominator1 = 10, Numerator2 = 1, Denominator2 = 100)
	Tests adding fractions that can not be reduced.
		   1      1       11
		 ---- + ----- = -----
		  10     100     100

	Test Case 3: Normal (Numerator1 = 1, Denominator1 = 10, Numerator2 = 6, Denominator2 = 20)
	Tests the GCD function to ensure it is working properly.
		   1      6     2
		 ---- + ---- = ---
		  10     20     5

	Test Case 4: Normal (Numerator1 = 3, Denominator1 = 1, Numerator2 = 10, Denominator2 = 1)
	Tests the addition of whole numbers and the DisplayData function's ability to recognize and render a
	whole number as such.
		  3     10
		 --- + ---- = 13
		  1      1

	Test Case 5: Normal (Numerator1 = 5, Denominator1 = 4, Numerator2 = 1, Denominator2 = 2)
	Tests the addition of proper and improper fractions.
		  5     1     7
		 --- + --- = ---
		  4     2     4

	Test Case 6: Special (Numerator1 = 1, Denominator1 = 1000, Numerator2 = 1, Denominator2 = 10000)
	Tests larger numbers and the DisplayData function's ability to center all the numbers.
			1        3         13
		 ------ + ------- = -------
		  1000     10000     10000
*/