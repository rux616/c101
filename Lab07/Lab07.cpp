#include <iostream>
using namespace std;

int MaxByVal(int, int, int);
void MaxByRef(int, int, int, int &);

void main()
{
	int Num1, Num2, Num3, Max;
	char Continue;

	do
	{
		cout << "Enter the first number: ";
		cin >> Num1;
		cout << "Enter the second number: ";
		cin >> Num2;
		cout << "Enter the third number: ";
		cin >> Num3;

		Max = MaxByVal(Num1, Num2, Num3);
		cout << "\nMax by val: " << Max << endl;
		MaxByRef(Num1, Num2, Num3, Max);
		cout << "Max by ref: " << Max << endl;

		cout << "Continue? N to stop: ";
		cin >> Continue;
		cout << "\n\n";
	} while (Continue != 'N' && Continue != 'n');
}

int MaxByVal(int N1, int N2, int N3)
{
	int Max = N1;

	if (N2 > Max)
		Max = N2;
	if (N3 > Max)
		Max = N3;

	return Max;
}

void MaxByRef(int N1, int N2, int N3, int &Max)
{
	Max = N1;

	if (N2 > Max)
		Max = N2;
	if (N3 > Max)
		Max = N3;
}