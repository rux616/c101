/*
	Name:			Dan Cassidy
	Date:			2013-09-23
	Homework #:		04
    Problem #:      02
	Source File:	HW04Algorithm02.cpp
    Class:          C-101 MW 1030
	Action:			This program outputs the first 40 Fibonacci numbers six to a line, each with a width of
					10.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	const int SEQUENCE_LENGTH = 40;
	const int COLUMN_WIDTH = 10;
	const int COLUMNS_PER_ROW = 6;

	int NSubX = 0, NSubXMinus1 = 0, NSubXMinus2 = 0;

	cout << "This program displays the first 40 Fibonacci numbers." << endl;

	for (int SequenceCount = 1; SequenceCount <= SEQUENCE_LENGTH; SequenceCount++)
	{
		cout << setw(COLUMN_WIDTH) << NSubX;

		NSubXMinus2 = NSubXMinus1;
		NSubXMinus1 = NSubX;
		NSubX = NSubXMinus1 + NSubXMinus2;

		if (NSubX == 0)								// Adds special case when starting the Fibonacci
			NSubX = 1;								// number sequence.

		if (SequenceCount % COLUMNS_PER_ROW == 0)
			cout << endl;
	}

	cout << endl;

	return 0;
}

/*
	PROGRAM OUTPUT

	Test Case 1: Specific
				 0         1         1         2         3         5
				 8        13        21        34        55        89
			   144       233       377       610       987      1597
			  2584      4181      6765     10946     17711     28657
			 46368     75025    121393    196418    317811    514229
			832040   1346269   2178309   3524578   5702887   9227465
		  14930352  24157817  39088169  63245986
*/