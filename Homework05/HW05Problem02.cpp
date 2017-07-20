/*
	Name:			Dan Cassidy
	Date:			2013-09-30
	Homework #:		05
    Problem #:      02
	Source File:	HW05Problem02.cpp
    Class:          C-101 MW 1030
	Action:			This program will ask the user for two integers and an operand (+, -, *, /, %) then
					perform the operand on them - e.g. 1 + 2. The program will then display the formula and
					the result and ask the user if they want to do another problem. If the user does not
					say no, the process will repeat.
*/

#include <iostream>
using namespace std;

int main(void)
{
	int Number1, Number2;
	char Operand, Continue;
	int Result;

	cout << "This program will take two integers and an operand and perform said operand on" << endl
		 << "the numbers. For example, Number1 Operand Number2. Valid operands are +, -, *, /"
		 << "and %. Once the operation is performed and results are displayed, you will be" << endl
		 << "asked if you want to do another problem." << endl << endl;

	do
	{
		cout << "Enter the first integer: ";
		cin >> Number1;
		cout << "Enter the second integer: ";
		cin >> Number2;
		cout << "Enter the operand: ";
		cin >> Operand;

		switch(Operand)
		{
		case '+':
			Result = Number1 + Number2;
			cout << Number1 << " " << Operand << " " << Number2 << " = " << Result << endl;
			break;
		case '-':
			Result = Number1 - Number2;
			cout << Number1 << " " << Operand << " " << Number2 << " = " << Result << endl;
			break;
		case '*':
			Result = Number1 * Number2;
			cout << Number1 << " " << Operand << " " << Number2 << " = " << Result << endl;
			break;
		case '/':
			Result = Number1 / Number2;
			cout << Number1 << " " << Operand << " " << Number2 << " = " << Result << endl;
			break;
		case '%':
			Result = Number1 % Number2;
			cout << Number1 << " " << Operand << " " << Number2 << " = " << Result << endl;
			break;
		default:
			cout << "Illegal operand. Valid operands are +, -, *, /, and %." << endl;
		}

		cout << "Would you like to do another problem? Enter 'Y' for Yes or 'N' for No. ";
		cin >> Continue;
	} while (Continue != 'N' && Continue != 'n');

	return 0;
}

/*
	PROGRAM OUTPUT

	Test Case 1: Normal (Number1 = 4, Number2 = -7, Operand = '+', Continue = 'Y')
	Test to make sure positive and negative integers work properly and that the '+' branch functions.
		4 + -7 = -3
		Would you like to do another problem? Enter 'Y' for Yes or 'N' for No. Y
		Enter the first integer:

	Test Case 2: Normal (Number1 = 53, Number2 = 40, Operand = '-', Continue = 'Y')
	Test to make sure that larger integers work properly and that the '-' branch functions.
		0 - 15 = -15
		Would you like to do another problem? Enter 'Y' for Yes or 'N' for No. Y
		Enter the first integer:

	Test Case 3: Normal (Number1 = 594, Number2 = 623, Operand = '*', Continue = 'Y')
	Test to make sure that even larger integers work properly and that the '*' branch functions.
		594 * 623 = 370062
		Would you like to do another problem? Enter 'Y' for Yes or 'N' for No. Y
		Enter the first integer:

	Test Case 4: Normal (Number1 = 1250, Number2 = 250, Operand = '/', Continue = 'Y')
	Test to make sure that the '/' branch functions.
		1250 / 250 = 5
		Would you like to do another problem? Enter 'Y' for Yes or 'N' for No. Y
		Enter the first integer:

	Test Case 5: Normal (Number1 = 10500, Number2 = 499, Operand = '%', Continue = 'Y')
	Test to make sure that the '%' branch functions.
		10500 % 499 = 21
		Would you like to do another problem? Enter 'Y' for Yes or 'N' for No. Y
		Enter the first integer:

	Test Case 6: Bad Operand (Number1 = 5, Number2 = 2, Operand = '^', Continue = 'N')
	Test to make sure that bad operands generate the proper message and that the loop breaks properly.
		Illegal operand. Valid operands are +, -, *, /, and %.
		Would you like to do another problem? Enter 'Y' for Yes or 'N' for No. N
		Press any key to continue . . .
*/