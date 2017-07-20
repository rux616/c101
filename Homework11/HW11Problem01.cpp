/*
	Name:			Dan Cassidy
	Date:			2013-11-18
	Homework #:		11
    Problem #:      01
	Source File:	HW11Problem01.cpp
    Class:          C-101 MW 1030
	Action:			This program adds two integers of very large size (20 digits).  It first asks the user
					to enter the numbers, then adds them together, then displays the result, along with the
					original numbers.
*/

#include <iostream>
#include <cctype>
using namespace std;

// Function prototypes
void ZeroArray(int [], const int);
void GetVBInt(int []);
void SumVBInt(const int [], const int [], int []);
void DisplayResults(const int [], const int [], const int []);
void ShowArray(const int [], const int);

// Global constants
const int SIZE = 20;

void main()
{
	int Num1[SIZE], Num2[SIZE], Sum[SIZE];
	char Continue;

	cout << "This program will add two very big integers together.\n\n";

	do
	{
		ZeroArray(Num1, SIZE);
		ZeroArray(Num2, SIZE);
		ZeroArray(Sum, SIZE);

		cout << "Enter the first number: ";
		GetVBInt(Num1);
		cout << "Enter the second number: ";
		GetVBInt(Num2);

		SumVBInt(Num1, Num2, Sum);

		DisplayResults(Num1, Num2, Sum);

		cout << "\nContinue? Y or N: ";
		cin >> Continue;
		cout << "\n\n";

		cin.ignore(100, '\n');	//Clears the input stream so it doesn't break GetVBInt if user continues

	} while (Continue == 'Y' || Continue == 'y');
}

/****************************** ZeroArray *****************************************************************
Action:			Zeroes the passed array 'Array' with 'Size' number of elements

Paremeters:		
	IN:			int Size, holds the number of elements in the array 'Array'
	OUT:		int Array[], holds the pointer to the array that has been zeroed

Returns:		Nothing

Precondition:	Size should be the number of elements, not the max index
**********************************************************************************************************/
void ZeroArray(int Array[], const int Size)
{
	for (int Index = 0; Index < Size; ++Index)
		Array[Index] = 0;
}

/****************************** GetVBInt ******************************************************************
Action:			Gets user input for the specified array

Paremeters:		
	IN:			None
	OUT:		int N[], holds the pointer to the array which contains the number the user entered

Returns:		None

Precondition:	None
**********************************************************************************************************/
void GetVBInt(int N[])
{
	const int CHAR_OFFSET = 48;

	int Temp[SIZE] = {0}, Index = 0, IndexOffset;
	char Ch;

	cin.get(Ch);
	while (isdigit(Ch) && Index < SIZE)
	{
		Temp[Index++] = Ch - CHAR_OFFSET;
		cin.get(Ch);
	}

	IndexOffset = SIZE - Index;

	for (Index = Index - 1; Index >= 0; --Index)
		N[Index + IndexOffset] = Temp[Index];
}

/****************************** SumVBInt ******************************************************************
Action:			Adds two very big integers together

Paremeters:		
	IN:			int Num1[], holds the pointer to the first array whose elements will be added together
	IN:			int Num2[], holds the pointer to the second array whose elements will be added together
	OUT:		int Sum[], holds the pointer to the array that contains the sum of the first two arrays

Returns:		None

Precondition:	All numbers should be >= 0
**********************************************************************************************************/
void SumVBInt(const int Num1[], const int Num2[], int Sum[])
{
	for (int Index = SIZE - 1, Carry = 0; Index >= 0; --Index)
	{
		Sum[Index] = (Num1[Index] + Num2[Index] + Carry) % 10;
		Carry = (Num1[Index] + Num2[Index] + Carry) / 10;
	}
}

/****************************** DisplayResults ************************************************************
Action:			Displays the three arrays in order, with a separator line between the last two

Paremeters:		
	IN:			int Num1[], holds the pointer to the first array to be displayed
	IN:			int Num2[], holds the pointer to the second array to be displayed
	IN:			int Sum[], holds the pointer to the third array to be displayed
	OUT:		None

Returns:		None

Precondition:	All elements should be >= 0 and <= 9 or output will be off
**********************************************************************************************************/
void DisplayResults(const int Num1[], const int Num2[], const int Sum[])
{
	ShowArray(Num1, SIZE);
	cout << "\n";

	ShowArray(Num2, SIZE);
	cout << "\n";

	for (int Count = 0; Count < SIZE; ++Count)
		cout << "-";
	cout << "\n";

	ShowArray(Sum, SIZE);
	cout << "\n";
}

/****************************** ShowArray *****************************************************************
Action:			Displays the passed array 'Array' with 'Size' number of elements

Paremeters:		
	IN:			int Array[], holds the pointer to the array to be displayed
	IN:			int Size, the number of elements in array 'Array'
	OUT:		None

Returns:		Nothing

Precondition:	Size should be the number of elements, not the max index
**********************************************************************************************************/
void ShowArray(const int Array[], const int Size)
{
	for (int Index = 0; Index < Size; ++Index)
		cout << Array[Index];
}

/*
	PROGRAM OUTPUT

	Test Case 1: Limit (Num1 = 0, Num2 = 1)
	Tests to make sure that the program handles small numbers well.  This case presents the full output,
	but will be scaled back in the future in the interest of saving space.
		Enter the first number: 0
		Enter the second number: 1
		00000000000000000000
		00000000000000000001
		--------------------
		00000000000000000001

		Continue? Y or N: Y

	Test Case 2: Limit (Num1 = 11111111112222222222, Num2 = 33333333334444444444)
	Tests to make sure that two numbers of max length will add properly.
		11111111112222222222
		33333333334444444444
		--------------------
		44444444446666666666

	Test Case 3: Special (Num1 = 19999999999999999999, Num2 = 1)
	Tests to make sure that addition will carry the one properly and fully.
		19999999999999999999
		00000000000000000001
		--------------------
		20000000000000000000

	Test Case 4: Normal (Num1 = 123654, Num2 = 852147)
	Tests to make sure the addition works with normal non-limit numbers.
		00000000000000123654
		00000000000000852147
		--------------------
		00000000000000975801
*/