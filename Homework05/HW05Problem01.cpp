/*
	Name:			Dan Cassidy
	Date:			2013-09-30
	Homework #:		05
    Problem #:      01
	Source File:	HW05Problem01.cpp
    Class:          C-101 MW 1030
	Action:			This program will ask a user to enter a character, then display that character again,
					that character's ASCII value, and then the next two characters in the ASCII table.  It
					will also keep track of how many upper case, lower case, digit and other characters are
					entered and will display them at the end of the program.  The program operates in a
					that is exited when an input character of '#' is detected.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	char Ch;
	unsigned int NumUpper = 0, NumLower = 0, NumDigit = 0, NumOther = 0;
	cout << setfill('0');

	cout << "This program asks for a character, then displays the character, its ASCII value,"
		 << "and the next two characters in the ASCII table.  It will keep doing this until" << endl
		 << "'#' is entered.  It will then show you how many upper case, lower case, digit," << endl
		 << "and other characters were entered." << endl << endl;

	cout << "Please enter a character or '#' to quit: ";
	cin >> Ch;

	while (Ch != '#')
	{
		cout << "Character '" << Ch << "'   ||   ASCII " << setw(3) << (int)Ch << "   ||   Followed by '"
			 << (char)(Ch + 1) << "' and '" << (char)(Ch + 2) << "'" << endl;

		if (Ch >= '0' && Ch <= '9')
			++NumDigit;
		else if (Ch >= 'A' && Ch <= 'Z')
			++NumUpper;
		else if (Ch >= 'a' && Ch <= 'z')
			++NumLower;
		else
			++NumOther;

		cout << "Please enter a character or '#' to quit: ";
		cin >> Ch;
	}

	cout << "Number of characters entered:" << endl;
	cout << "    Upper Case: " << NumUpper << endl;
	cout << "    Lower Case: " << NumLower << endl;
	cout << "    Digit:      " << NumDigit << endl;
	cout << "    Other:      " << NumOther << endl;

	return 0;
}

/*
	PROGRAM OUTPUT

	Test Case 1: Limits (Sequence of characters = 0, 9, A, Z, a, z, #)
	This test makes sure the limits are working properly.
		Please enter a character or '#' to quit: 0
		Character '0'   ||   ASCII 048   ||   Followed by '1' and '2'
		Please enter a character or '#' to quit: 9
		Character '9'   ||   ASCII 057   ||   Followed by ':' and ';'
		Please enter a character or '#' to quit: A
		Character 'A'   ||   ASCII 065   ||   Followed by 'B' and 'C'
		Please enter a character or '#' to quit: Z
		Character 'Z'   ||   ASCII 090   ||   Followed by '[' and '\'
		Please enter a character or '#' to quit: a
		Character 'a'   ||   ASCII 097   ||   Followed by 'b' and 'c'
		Please enter a character or '#' to quit: z
		Character 'z'   ||   ASCII 122   ||   Followed by '{' and '|'
		Please enter a character or '#' to quit: #
		Number of characters entered:
			Upper Case: 2
			Lower Case: 2
			Digit:      2
			Other:      0

	Test Case 2: Counting (Sequence of characters = 1, B, C, d, e, f, !, @, $, %, #)
	This test makes sure that the counters are counting and being properly referenced.
		Please enter a character or '#' to quit: 1
		Character '1'   ||   ASCII 049   ||   Followed by '2' and '3'
		Please enter a character or '#' to quit: B
		Character 'B'   ||   ASCII 066   ||   Followed by 'C' and 'D'
		Please enter a character or '#' to quit: C
		Character 'C'   ||   ASCII 067   ||   Followed by 'D' and 'E'
		Please enter a character or '#' to quit: d
		Character 'd'   ||   ASCII 100   ||   Followed by 'e' and 'f'
		Please enter a character or '#' to quit: e
		Character 'e'   ||   ASCII 101   ||   Followed by 'f' and 'g'
		Please enter a character or '#' to quit: f
		Character 'f'   ||   ASCII 102   ||   Followed by 'g' and 'h'
		Please enter a character or '#' to quit: !
		Character '!'   ||   ASCII 033   ||   Followed by '"' and '#'
		Please enter a character or '#' to quit: @
		Character '@'   ||   ASCII 064   ||   Followed by 'A' and 'B'
		Please enter a character or '#' to quit: $
		Character '$'   ||   ASCII 036   ||   Followed by '%' and '&'
		Please enter a character or '#' to quit: %
		Character '%'   ||   ASCII 037   ||   Followed by '&' and '''
		Please enter a character or '#' to quit: #
		Number of characters entered:
			Upper Case: 2
			Lower Case: 3
			Digit:      1
			Other:      4
*/