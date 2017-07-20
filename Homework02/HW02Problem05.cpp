/*
	Name:			Dan Cassidy
	Date:			2013-09-10
	Homework #:		02
	Problem #:		03
	Source File:	HW02Problem05.cpp
	Class:			C-101 MW 1030
	Action:			This program will ask a user for an annual salary then compute six month's retroactive
					pay, a new annual salary, and a new monthly salary all based on a 7.6% increase in
					annual pay.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	float OldAnnualSalary;
	float RetroactivePay, NewAnnualSalary, NewMonthlySalary;

	cout << "This program will compute six month's retroactive pay, a new annual salary, and" << endl;
	cout << "a new monthyl salary based on a 7.6% raise in annual pay." << endl;
	cout << endl;

	cout << "Please enter employee's salary --> ";
	cin >> OldAnnualSalary;

	cout << endl;

	if (OldAnnualSalary >= 0)
	{
		NewAnnualSalary = OldAnnualSalary * 1.076;
		NewMonthlySalary = NewAnnualSalary / 12.0;
		RetroactivePay = (NewAnnualSalary - OldAnnualSalary) / 2.0;

		cout << setiosflags(ios::fixed | ios::showpoint | ios::right) << setprecision(2);
		cout << "Retroactive Pay    --> $" << setw(9) << RetroactivePay << endl;
		cout << "New Annual Salary  --> $" << setw(9) << NewAnnualSalary << endl;
		cout << "New Monthly Salary --> $" << setw(9) << NewMonthlySalary << endl;
	}
	else
	{
		cout << "Sorry, you can't have a negative salary." << endl;
	}
}

/*
	PROGRAM OUTPUT

	Test Case 1: Specific (OldAnnualSalary = 35000)
		Retroactive Pay    --> $  1330.00
		New Annual Salary  --> $ 37660.00
		New Monthly Salary --> $  3138.33

	Test Case 2: Specific (OldAnnualSalary = 46500)
		Retroactive Pay    --> $  1767.00
		New Annual Salary  --> $ 50034.00
		New Monthly Salary --> $  4169.50

	Test Case 3: Specific (OldAnnualSalary = 52450)
		Retroactive Pay    --> $  1993.10
		New Annual Salary  --> $ 56436.20
		New Monthly Salary --> $  4703.02
*/