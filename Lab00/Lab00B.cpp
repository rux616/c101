// Lab0B.cpp
// Action : Program has user enter two numbers
//          then displays the product of two

#include <iostream>
using namespace std;

void main()
{
  int X, Y;

  cout << "Enter a number --> ";
  cin >> X;
  cout << "Enter another number --> ";
  cin >> Y;
  cout << "\nThe product is = " << (X*Y) << endl;
  cout << "\n\nPress ENTER key to continue";
  cin.ignore(2);
}