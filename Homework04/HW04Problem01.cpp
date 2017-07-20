/*
	Name:			Dan Cassidy
	Date:			2013-09-23
	Homework #:		04
    Problem #:      01
	Source File:	HW04Problem01.cpp
    Class:          C-101 MW 1030
	Action:			This program will determine a person's GPA based on the input of the letter grade
					received and the number of credit hours of two classes.
*/

#include <iostream>
using namespace std;

int main(void)
{
	char LetterGrade1, LetterGrade2;
	int NumCredits1, NumCredits2;

	int NumPoints1, NumPoints2;
	int TotalPoints, TotalCredits;
	float GPA;

	cout << "This program will ask for the letter grade and credit hours for two classes and" << endl;
	cout << "will then calculate your GPA using that information." << endl << endl;

	cout << "Enter letter grade for first class --> ";
	cin >> LetterGrade1;
	cout << "Enter number of credit hours for first class --> ";
	cin >> NumCredits1;

	cout << endl;
	cout << "Enter letter grade for second class --> ";
	cin >> LetterGrade2;
	cout << "Enter number of credit hours for second class --> ";
	cin >> NumCredits2;

	NumPoints1 = ((int)LetterGrade1 - 69) * -1;		// This group of statements leverage the fact that
	if (NumPoints1 < 0)								// char data types are just numbers.  Corrects for
		NumPoints1 = 0;								// 'F' manually.
	NumPoints2 = ((int)LetterGrade2 - 69) * -1;		// 
	if (NumPoints2 < 0)								// Example: LetterGrade1 = 'A'
		NumPoints2 = 0;								// (65 - 69) * -1 == (-4) * -1 == 4

	TotalPoints = NumPoints1 * NumCredits1 + NumPoints2 * NumCredits2;
	TotalCredits = NumCredits1 + NumCredits2;
	GPA = (float)TotalPoints / TotalCredits;

	cout << endl;
	cout << LetterGrade1 << "   " << NumCredits1 << endl;
	cout << LetterGrade2 << "   " << NumCredits2 << endl;
	cout << "Your GPA = " << GPA << endl;

	if (GPA < 2.0)
		cout << "You are doing poorly" << endl;
	else if (GPA >= 3.5)
		cout << "Congratulations, doing good" << endl;

	return 0;
}

/*
	PROGRAM OUTPUT

	Test Case 1: Specific (LetterGrade1 = 'B', NumCredits1 = 3, LetterGrade2 = 'C', NumCredits = 4)
		B   3
		C   4
		Your GPA = 2.42857

	Test Case 2: Specific (LetterGrade1 = 'B', NumCredits1 = 3, LetterGrade2 = 'A', NumCredits = 4)
		B   3
		A   4
		Your GPA = 3.57143
		Congratulations, doing good

	Test Case 3: Specific (LetterGrade1 = 'D', NumCredits1 = 3, LetterGrade2 = 'C', NumCredits = 3)
		D   3
		C   3
		Your GPA = 1.5
		You are doing poorly

	Test Case 4: Special (LetterGrade1 = 'F', NumCredits1 = 3, LetterGrade2 = 'F', NumCredits = 3)
	Tests to make sure that NumPointsX is properly set to 0 when LetterGradeX is 'F'.
		F   3
		F   3
		Your GPA = 0
		You are doing poorly
*/