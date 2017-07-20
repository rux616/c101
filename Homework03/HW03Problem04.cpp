/*
	Name:			Dan Cassidy
	Date:			2013-09-16
	Homework #:		03
    Problem #:      04
	Source File:	HW03Problem04.cpp
    Class:          C-101 MW 1030
	Action:			This program asks the user how many shirts they wish to buy, then calculates the price
					per shirt, the price of all shirts, the sales tax at 6%, and the total price.  It then
					displays all the information.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	const float SALES_TAX = 0.06;
	
	int NumberOfShirts;
	float PricePerShirt;
	float PriceOfShirts, SalesTax, TotalPrice;

	cout << "This program will ask you how many shirts you wish to buy.  It will then" << endl;
	cout << "calculate the price of the shirts, the sales tax at " << SALES_TAX * 100 << "%, and the total"
		 << " price." << endl << endl;

	cout << "Please enter the number of shirts you wish to buy: ";
	cin >> NumberOfShirts;

	if (NumberOfShirts < 4)
		PricePerShirt = 15.75;
	else if (NumberOfShirts <= 10)
		PricePerShirt = 12.5;
	else
		PricePerShirt = 8;

	PriceOfShirts = NumberOfShirts * PricePerShirt;
	SalesTax = PriceOfShirts * SALES_TAX;
	TotalPrice = PriceOfShirts + SalesTax;

	cout << endl;
	cout << "Number of shirts purchased:  " << setw(6) << NumberOfShirts << endl;
	cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);
	cout << "Price of shirts:            $" << setw(6) << PriceOfShirts << endl;
	cout << "Sales tax:                  $" << setw(6) << SalesTax << endl;
	cout << "Total price:                $" << setw(6) << TotalPrice << endl;
	cout << endl;

	return 0;
}

/*
	PROGRAM OUTPUT

	Test Case 1: Normal (NumberOfShirts = 1)
		Number of shirts purchased:       1
		Price of shirts:            $ 15.75
		Sales tax:                  $  0.94
		Total price:                $ 16.69

	Test Case 2: Specific (NumberOfShirts = 9)
		Number of shirts purchased:       9
		Price of shirts:            $112.50
		Sales tax:                  $  6.75
		Total price:                $119.25

	Test Case 3: Limit (NumberOfShirts = 3)
	Tests the lower side of the price break for 4 to 10 shirts.
		Number of shirts purchased:       3
		Price of shirts:            $ 47.25
		Sales tax:                  $  2.84
		Total price:                $ 50.08

	Test Case 4: Limit (NumberOfShirts = 4)
	Tests the upper side of the price break for 4 to 10 shirts.
		Number of shirts purchased:       4
		Price of shirts:            $ 50.00
		Sales tax:                  $  3.00
		Total price:                $ 53.00

	Test Case 5: Limit (NumberOfShirts = 10)
	Tests the lower side of the price break for more than 10 shirts.
		Number of shirts purchased:      10
		Price of shirts:            $125.00
		Sales tax:                  $  7.50
		Total price:                $132.50

	Test Case 6: Limit (NumberOfShirts = 11)
	Tests the upper side of the price break for more than 10 shirts.
		Number of shirts purchased:      11
		Price of shirts:            $ 88.00
		Sales tax:                  $  5.28
		Total price:                $ 93.28
*/