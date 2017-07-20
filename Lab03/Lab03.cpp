#include <iostream>
using namespace std;

int main(void)
{
	int Number;

	cout << "Please enter a number: ";
	cin >> Number;

	if (Number >= 0)
	{
		cout << "Positive" << endl;
	}
	else if (Number <= 0)
	{
		cout << "Negative" << endl;
	}
	else
	{
		cout << "Zero" << endl;
	}
}