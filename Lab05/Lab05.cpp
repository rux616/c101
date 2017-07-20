/*
	Name:			Dan Cassidy
	Date:			2013-10-02
	Homework #:		Lab
    Problem #:      05
	Source File:	Lab05.cpp
    Class:          C-101 MW 1030
	Action:			
*/

#include <iostream>
using namespace std;

int main(void)
{
	char Ch;
	int NumVowels = 0, NumSpaces = 0;

	cout << "Please enter a sentence:" << endl;
	Ch = cin.get();

	while (Ch != '\n')
	{
		switch(Ch)
		{
			case 'A': case 'a':
			case 'E': case 'e':
			case 'I': case 'i':
			case 'O': case 'o':
			case 'U': case 'u':
				NumVowels++;
				break;
			case ' ':
				NumSpaces++;
				break;
		}
		Ch = cin.get();
	}

	cout << "Vowels = " << NumVowels << endl;
	cout << "Spaces = " << NumSpaces << endl;

	return 0;
}

/*
	PROGRAM OUTPUT

	Test Case 1: Normal (Sentence = "This is a test.")
		Vowels = 4
		Spaces = 3
*/