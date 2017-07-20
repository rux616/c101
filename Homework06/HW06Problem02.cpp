/*
	Name:			Dan Cassidy
	Date:			2013-10-11
	Homework #:		06
    Problem #:      02
	Source File:	HW06Problem02.cpp
    Class:          C-101 MW 1030
	Action:			This program demonstrates the fact that if someone starts with 1 penny and doubles it
					every day, the amount would add up to over one million dollars within 30 days.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	const int   MAX_DAYS			=   30,
                COLUMNS_PER_ROW		=   3,		// Helps shorten the output
				COLUMN_SPACING		=	4;
    
	float       Amount				=   0.01;

    cout << "This program demonstrates the fact that if someone gave you a penny and you\n"
		 << "doubled the amount everyday, you would become a millionaire in less than 30\n"
		 << "days.\n\n";

	// Create the first header line
    for (int Count = 1; Count <= COLUMNS_PER_ROW; Count++)
	{
		cout << "Day#     Amount   ";
		if (Count % COLUMNS_PER_ROW != 0)
			for (int Count = 1; Count <= COLUMN_SPACING; Count++)
				cout << " ";
		else
			cout << "\n";
	}

	// Create the second header line
    for (int Count = 1; Count <= COLUMNS_PER_ROW; Count++)
	{
		cout << "----  ------------";
		if (Count % COLUMNS_PER_ROW != 0)
			for (int Count = 1; Count <= COLUMN_SPACING; Count++)
				cout << " ";
		else
			cout << "\n";
	}

	// Output the data
	cout << setiosflags(ios::fixed) << setprecision(2);
    for (int Day = 1; Day <= MAX_DAYS; Day++)
	{
        cout << " " << setw(2) << Day << "   $ " << setw(10) << Amount;
		if (Day % COLUMNS_PER_ROW != 0)
			for (int Count = 1; Count <= COLUMN_SPACING; Count++)
				cout << " ";
		else
			cout << "\n";

		Amount *= 2;
	}
	return 0;
}

/*
	PROGRAM OUTPUT

	Test Case 1: Specific
		Day#     Amount       Day#     Amount       Day#     Amount
		----  ------------    ----  ------------    ----  ------------
		  1   $       0.01      2   $       0.02      3   $       0.04
		  4   $       0.08      5   $       0.16      6   $       0.32
		  7   $       0.64      8   $       1.28      9   $       2.56
		 10   $       5.12     11   $      10.24     12   $      20.48
		 13   $      40.96     14   $      81.92     15   $     163.84
		 16   $     327.68     17   $     655.36     18   $    1310.72
		 19   $    2621.44     20   $    5242.88     21   $   10485.76
		 22   $   20971.52     23   $   41943.04     24   $   83886.08
		 25   $  167772.16     26   $  335544.31     27   $  671088.63
		 28   $ 1342177.25     29   $ 2684354.50     30   $ 5368709.00
*/