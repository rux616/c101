#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void DetermineIfSame(int, int);

void main()
{
	const int RAND_OFFSET = 1;
	const int RAND_RANGE = 3;

	int UserNumber, RandNumber;
	char Continue;

	srand(time(NULL));

	do
	{
		cout << "\nEnter a number between 1 and 3: ";
		cin >> UserNumber;

		RandNumber = RAND_OFFSET + rand() % RAND_RANGE;
		cout << "Computer picked number: " << RandNumber << "\n";

		DetermineIfSame(UserNumber, RandNumber);

		cout << "Continue? Y or N: ";
		cin >> Continue;
	} while (Continue == 'Y' || Continue == 'y');
}

void DetermineIfSame(int Num1, int Num2)
{
	if (Num1 == Num2)
		cout << "The numbers are the same.\n";
	else
		cout << "The numbers are not the same.\n";
}