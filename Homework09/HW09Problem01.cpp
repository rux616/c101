/*
	Name:			Dan Cassidy
	Date:			2013-10-31
	Homework #:		09
    Problem #:      01
	Source File:	HW09Problem01.cpp
    Class:          C-101 MW 1030
	Action:			This program analyzes a loan to calculate the monthly payments by asking a user for
					the Principal, Annual Interest Rate, Years, and Payments per Year of the loan.  It then
					calculates the monthly payments and outputs the results in a table.
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

void ReadLoanInfo(float &, float &, unsigned &, unsigned &);
double MonthlyPayment(float, float, unsigned, unsigned);
void ShowTable(float, float, unsigned, unsigned);

void main()
{
	float Principal, AnnualInterestRate;
	unsigned Years, PaymentsPerYear;
	char Continue;

	do
	{
		system("cls");
		cout << "This program analyzes a loan to determine the monthly payments.\n"
			 << "===============================================================\n";

		ReadLoanInfo(Principal, AnnualInterestRate, Years, PaymentsPerYear);

		cout << "\n";
		ShowTable(Principal, AnnualInterestRate, Years, PaymentsPerYear);

		cout << "\n";
		cout << "===============================================================\n";
		cout << "Continue? Y or N: ";
		cin >> Continue;
	} while (Continue == 'Y' || Continue == 'y');
}

/****************************** ReadLoanInfo **************************************************************
Action:			Prompts the user for input and then reads the input into their respective variables

Paremeters:		
	IN:			None
	OUT:		float Principal, holds the principal value of the loan
	OUT:		float AnnualInterestRate, holds the decimal value of the annual interest rate of the loan
	OUT:		unsigned Years, holds the number of years of the loan
	OUT:		unsigned PaymentsPerYear, holds the number of payments per year of the loan

Returns:		Nothing, except through reference parameters

Precondition:	None
**********************************************************************************************************/
void ReadLoanInfo(float &Principal, float &AnnualInterestRate, unsigned &Years, unsigned &PaymentsPerYear)
{
	cout << "Enter the principal:                       ";
	cin >> Principal;
	cout << "Enter the annual interst rate:             ";
	cin >> AnnualInterestRate;
	cout << "Enter the years:                           ";
	cin >> Years;
	cout << "Enter the number of payments per year:     ";
	cin >> PaymentsPerYear;

	AnnualInterestRate /= 100;
}

/****************************** MonthlyPayment ************************************************************
Action:			Calculates the monthly payment of a loan with the given input values

Paremeters:		
	IN:			float Principal, holds the principal value of the loan
	IN:			float AnnualInterestRate, holds the decimal value of the annual interest rate of the loan
	IN:			unsigned Years, holds the number of years of the loan
	IN:			unsigned PaymentsPerYear, holds the number of payments per year of the loan
	OUT:		None

Returns:		Double that holds the monthly payment of the loan

Precondition:	AnnualInterestRate cannot be 0, PaymentsPerYear cannot be 0, Years cannot be 0
**********************************************************************************************************/
double MonthlyPayment(float Principal, float AnnualInterestRate, unsigned Years, unsigned PaymentsPerYear)
{
	double PeriodicInterestRate = AnnualInterestRate / PaymentsPerYear;
	int TotalPayments = Years * PaymentsPerYear;

	return (Principal * PeriodicInterestRate) / (1 - pow(1 + PeriodicInterestRate, -TotalPayments));
}

/****************************** ShowTable *****************************************************************
Action:			Shows a table displaying the key components of the loan, including the monthly payment

Paremeters:		
	IN:			float Principal, holds the principal value of the loan
	IN:			float AnnualInterestRate, holds the decimal value of the annual interest rate of the loan
	IN:			unsigned Years, holds the number of years of the loan
	IN:			unsigned PaymentsPerYear, holds the number of payments per year of the loan
	OUT:		None

Returns:		Nothing

Precondition:	None
**********************************************************************************************************/
void ShowTable(float Principal, float AnnualInterestRate, unsigned Years, unsigned PaymentsPerYear)
{
	cout << setiosflags(ios::fixed | ios::showpoint);
	cout <<   "Principal:              $" << setprecision(2) << Principal;
	cout << "\nInterest Rate:          " << setprecision(2) << AnnualInterestRate * 100 << "%";
	cout << "\nNumber of Years:        " << Years;
	cout << "\nPayments per Year:      " << PaymentsPerYear;
	cout << "\nNumber of Payments:     " << PaymentsPerYear * Years;
	cout << "\nMonthly Payment:        $" << setprecision(2)
		 << MonthlyPayment(Principal, AnnualInterestRate, Years, PaymentsPerYear);
}

/*
	PROGRAM OUTPUT

	Test Case 1: Specific (Principal = 11000, AnnualInterestRate = 10, Years = 4, PaymentsPerYear = 12)
	Tests the first set of input data and shows the full output of the program.  Further tests will use
	only the output of ShowTable in the interests of saving space.
		This program analyzes a loan to determine the monthly payments.
		===============================================================
		Enter the principal:                       11000
		Enter the annual interst rate:             10
		Enter the years:                           4
		Enter the number of payments per year:     12

		Principal:              $11000.00
		Interest Rate:          10.00%
		Number of Years:        4
		Payments per Year:      12
		Number of Payments:     48
		Monthly Payment:        $278.99
		===============================================================
		Continue? Y or N: Y

	Test Case 2: Specific (Principal = 15500, AnnualInterestRate = 5.7, Years = 5, PaymentsPerYear = 12)
	Tests the second set of input data.
		Principal:              $15500.00
		Interest Rate:          5.70%
		Number of Years:        5
		Payments per Year:      12
		Number of Payments:     60
		Monthly Payment:        $297.50

	Test Case 3: Specific (Principal = 115000, AnnualInterestRate = 7.75, Years = 30,
		PaymentsPerYear = 12)
	Tests the third set of input data.
		Principal:              $115000.00
		Interest Rate:          7.75%
		Number of Years:        30
		Payments per Year:      12
		Number of Payments:     360
		Monthly Payment:        $823.87
*/