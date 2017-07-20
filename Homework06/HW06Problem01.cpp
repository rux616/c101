/*************************************************************************
Name:			Dan Cassidy and Matt Holloway
Date:			2013-10-08
Homework #:		Homework #6 Problem #1
Source:			HW06Problem01.cpp
Action:			Menu is displayed allows user to calculate
				Miles per Gallon, Total minutes and seconds
				and determine if number is a prime number or not

Notes:			
*************************************************************************/
#include <iostream>
#include <stdlib.h>      // this header file requires the .h
using namespace std;

void DisplayMenu(void);
void FindMilesPerGallon(void);
void ConvertTotalSeconds(void);
void IsPrimeNumber(void);

void main()
{
	int Choice;

	do
	{
		DisplayMenu();
		cin >> Choice;
		system("cls");
		switch (Choice)
		{
			case 1:
				FindMilesPerGallon();
				break;

			case 2:
				ConvertTotalSeconds();
				break;

			case 3:
				IsPrimeNumber();
				break;

			case 4:
				break;

			default:
				cout << "Sorry, illegal choice. Please hit enter to try again\n\n";
				cin.ignore(1);
		}
	} while (Choice != 4);
}

/*********************  DisplayMenu  *************************************
Action  :  This just displays the menu to the screen
Parameters  : none
returns     : nothing
*************************************************************************/
void DisplayMenu()
{
	system("cls");

	cout << "Do you want to:\n\n";
	cout << "    1) Find miles per gallon\n";
	cout << "    2) Convert total seconds to minutes and seconds\n";
	cout << "    3) Determine if number is a prime number or not\n";
	cout << "    4) QUIT\n\n";
	cout << "    CHOICE --> ";
}

/********************  FindMilesPerGallon  *******************************
Action  : Ask user to input number of miles traveled and number of
		  gallons used then display the miles per gallon obtained.
Parameters : none
returns    : nothing
*************************************************************************/
void FindMilesPerGallon(void)
{
	float Miles, Gallons;
	float MilesPerGallon;

	cout << "This function will ask you for the number of miles and the gallons and then\n"
		 << "determine the miles per gallon.\n\n";

	cout << "Enter miles: ";
	cin >> Miles;
	cout << "Enter gallons: ";
	cin >> Gallons;

	MilesPerGallon = Miles / Gallons;

	cout << "\nMiles per gallon: " << MilesPerGallon;

	cout << "\n\nPress enter to go back to the menu";
	cin.ignore(2);
}

/*******************  ConvertTotalSeconds  *******************************
Action  : Ask user to input a given total number of seconds and then
		  displays the corresponding number of minutes and seconds
Parameters : none
returns    : nothing
*************************************************************************/
void ConvertTotalSeconds(void)
{
	unsigned int TotalSeconds;
	unsigned int Minutes, Seconds;

	cout << "This function will ask you for a number of seconds, then convert those seconds\n"
		 << "to minutes and seconds.\n\n";

	cout << "Enter the total number of seconds: ";
	cin >> TotalSeconds;

	Minutes = TotalSeconds / 60;
	Seconds = TotalSeconds % 60;

	cout << "\n" << Minutes << " minutes, " << Seconds << " seconds";
	
	cout << "\n\nPress enter to go back to the menu";
	cin.ignore(2);
}

/**********************  IsPrimeNumber  **********************************
Action  : Ask user to input positive integer and will determine if number
		  is a prime number or not.
Parameters  : none
Returns     : nothing
*************************************************************************/
void IsPrimeNumber(void)
{
	unsigned int Number;
	unsigned int MaxDivisor;
	bool IsPrime = true;				// Assume a number is prime

	cout << "This funcion will ask you for a numbern then proceed to display whether it is a\n"
		 << "prime number or not.\n\n";

	cout << "Enter a number: ";
	cin >> Number;

	if (Number == 0 || Number == 1)		// Special case for 0 and 1 as the
		IsPrime = false;				// loop will not engage for them

	MaxDivisor = Number / 2;
	for (unsigned int Divisor = 2 ; Divisor <= MaxDivisor ; Divisor++)
	{
		IsPrime = (Number % Divisor) != 0;
		if (!IsPrime)
			break;
	}

	if (IsPrime)
		cout << "\n" << Number << " is a prime";
	else
		cout << "\n" << Number << " is not a prime";

	cout << "\n\nPress enter to go back to the menu";
	cin.ignore(2);
}

/*
	PROGRAM OUTPUT

	Test Case 1: DisplayMenu: Normal
		Do you want to:

			1) Find miles per gallon
			2) Convert total seconds to minutes and seconds
			3) Determine if number is a prime number or not
			4) QUIT

			CHOICE -->

	Test Case 2: FindMilesPerGallon: Normal (Miles = 3, Gallons = 10)
	There are no special cases or (tested) limits for FindMilesPerGallon; just need to make sure that the
	math works.
		Miles per gallon: 0.3

	Test Case 3: ConvertTotalSeconds: Normal (TotalSeconds = 90)
	Again, there are no special cases or (tested) limits for SecondsToMinutes; just need to make sure that
	the math works.
		1 minutes, 30 seconds

	Test Case 4: IsPrimeNumber: Special (Number = 0)
	Tests the special case of 0 is not a prime number
		0 is not a prime

	Test Case 5: IsPrimeNumber: Special (Number = 1)
	Tests the special case of 1 is not a prime number
		1 is not a prime

	Test Case 6: IsPrimeNumber: Limit (Number = 2)
	Tests the smallest prime number
		2 is a prime

	Test Case 7: IsPrimeNumber: Normal (Number = 7)
	Tests a known prime number
		7 is a prime

	Test Case 8: IsPrimeNumber: Normal (Number = 10)
	Tests a known non-prime number
		10 is not a prime
*/