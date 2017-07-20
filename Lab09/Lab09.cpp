#include <iostream>
using namespace std;

void EvenOrOdd(int);

void main()
{
	int N;

	cout << "Enter number, 0 to quit: ";
	cin >> N;

	while (N != 0)
	{
		EvenOrOdd(N);
		
		cout << "Enter number, 0 to quit: ";
		cin >> N;
	}
}

void EvenOrOdd(int Number)
{
	static unsigned NumEvens;
	static unsigned NumOdds;
	static unsigned TimesCalled;

	++TimesCalled;

	Number % 2 == 0 ? ++NumEvens : ++NumOdds;

	if (TimesCalled % 3 == 0)
		cout << "Number of evens: " << NumEvens << "\n";
}