/*
	Name:			Dan Cassidy
	Date:			2013-11-05
	Homework #:		10
    Problem #:      01
	Source File:	HW10Problem01.cpp
    Class:          C-101 MW 1030
	Action:			This program is a basic version of the 'cin >>' function.  It will loop and ask the
					user to enter an unsigned short with a max value of 65535, read the input itself, and
					will follow the same basic rules as 'cin >>', including skipping leading whitespace,
					first character found must be numeric or an error is generated, numeric characters are
					processed one at a time, and stops processing when a non-numeric character is found.
*/

#include <iostream>
#include <ctype.h>
using namespace std;

unsigned short ReadInt(unsigned short &);

void main()
{
	unsigned short Number, Status;
	char Continue;

	cout << "This program asks you to input a number between 0 and 65535. It will then\n"
		 << "process that number, ignoring leading white space, but throwing an error on\n"
		 << "leading non-digits and numbers greater than 65535. Once the number is done\n"
		 << "being read, it will be displayed.\n";

	do
	{
		cout << "\nEnter a number between 0 and 65535: ";
		Status = ReadInt(Number);

		switch (Status)
		{
			case 1:
				cout << "Error: Illegal Entry: Non-numeric, non-whitespace leading character entered";
				break;

			case 2:
				cout << "Error: Overflow: Number entered is too large";
				break;

			default:
				cout << "The number entered was: " << Number;
		}

		cout << "\nContinue? Y or N: ";
		cin >> Continue;
	} while (Continue != 'N' && Continue != 'n');
}

/****************************** ReadInt *******************************************************************
Action:			Reads an unsigned short integer into a variable Number from user-entered information.

Paremeters:		
	IN:			None
	OUT:		unsigned short Number, holds the number entered

Returns:		Unsigned short that holds the error code of the function. 0 if none, 1 if illegal entry, 2
				if overflow.

Precondition:	None
**********************************************************************************************************/
unsigned short ReadInt(unsigned short &Number)
{
	const short CHAR_OFFSET = 48;
	const unsigned short MAX_NUMBER = 65535;

	char Ch;
	bool FirstDigitFound = false, ExitLoop = false;
	unsigned short TempNumber, ErrorCode;

	do
	{
		// Using cin.peek() here because if using cin.get() and the last character in the input stream is
		// read ('\n'), the cin.ignore(100, '\n') at the end of the function will cause the user to have to
		// hit enter again unnecessarily.

		Ch = cin.peek();

		if (isdigit(Ch))
		{
			Ch = cin.get();
			if (!FirstDigitFound)
			{
				FirstDigitFound = true;
				TempNumber = Ch - CHAR_OFFSET;
			}
			else
				if (TempNumber * 10 + (Ch - CHAR_OFFSET) > MAX_NUMBER)
				{
					ErrorCode = 2;
					ExitLoop = true;
				}
				else
					TempNumber = TempNumber * 10 + (Ch - CHAR_OFFSET);
		}
		else
			if (FirstDigitFound)
			{
				ErrorCode = 0;
				ExitLoop = true;
			}
			else
			{
				if (isspace(Ch))
					cin.ignore(1);
				else
				{
					ErrorCode = 1;
					ExitLoop = true;
				}
			}
	} while (!ExitLoop);

	cin.ignore(100, '\n');
	if (!ErrorCode)
		Number = TempNumber;
	return ErrorCode;
}

/*
	PROGRAM OUTPUT

	Test Case 0: Limit (Input Stream = 0, \n)
	Tests that the program responds properly to the limit value of 0 and shows the full output of the
	program. Further tests will use abbreviated output in the interest of saving space.
		This program asks you to input a number between 0 and 65535. It will then
		process that number, ignoring leading white space, but throwing an error on
		leading non-digits and numbers greater than 65535. Once the number is done
		being read, it will be displayed.

		Enter a number between 0 and 65535: 0
		The number entered was: 0
		Continue? Y or N: n
		Press any key to continue . . .

	Test Case 1: Limit (Input Stream = 6, 5, 5, 3, 5, \n)
	Tests that the program reads the max number of 65535 correctly.
		The number entered was: 65535

	Test Case 2: Special (Input Stream = \n, <space>, 5, 4, 3, \n)
	Tests that the program properly ignores leading white space.
		The number entered was: 543

	Test Case 3: Special (Input Stream = \n, <space>, d, 4, 8, 1, 5, \n)
	Tests that the program properly ignores leading white space but still errors out when encountering a
	non-digit leading character.
		Error: Illegal Entry: Non-numeric, non-whitespace leading character entered

	Test Case 4: Special (Input Stream = \n, 7, 0, 0, 0, 0, \n)
	Tests that the program properly outputs an error when the input value is too large.
		Error: Overflow: Number entered is too large

	Test Case 5: Special (Input Stream = \n, 1, 2, 3, 4, z, \n)
	Tests that the program will stop reading the number when a non-numeric character (other than '\n') is
	encountered.
		The number entered was: 1234
*/