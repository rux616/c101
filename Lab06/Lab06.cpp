#include <iostream>
using namespace std;

void ShowPlus(void);
void ShowMinus(void);

int main(void)
{
	int Num1, Num2;
	int Result;

	do
	{
		cout << "Enter the first number: ";
		cin >> Num1;
		cout << "Enter the second number: ";
		cin >> Num2;

		Result = Num1 - Num2;

		if (Result > 0)
			ShowPlus();
		else if (Result < 0)
			ShowMinus();
		else
			break;
	} while (Result != 0);

	return 0;
}

void ShowPlus(void)
{
	cout << "    *\n";
	cout << "    *\n";
	cout << "*********\n";
	cout << "    *\n";
	cout << "    *\n";
}

void ShowMinus(void)
{
	cout << "\n";
	cout << "*********\n";
	cout << "\n";
}