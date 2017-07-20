/*-------------------------------------------------------
	Source : Lab2.cpp

    This program is used to help you find syntax errors.
	Find all the errors in the program and get it to run.
---------------------------------------------------------*/
#include <iostream>
using namespace std;

void main()
{
  short int X = 2, Y, Z;
  char Choice;

  cout << "All C++ expressions have a value, lets see some, with X = 2\n\n";
  cout << "Please enter some integer for Y --> ";
  cin >> Y;

  cout << "\nThe value of X is " << X << " and the value of Y is " << Y << endl;
  cout << "The value of X + Y is " << (X + Y) << endl;
  cout << "The value of X - Y is " << (X - Y) << endl;

  cin.ignore(100, '\n');
  cout << "\nAre you have fun yet, I hope so, Press Enter Key to coninue\n";
  Choice = cin.get();

  Z = Y/X;
  cout << "\nThe value of Z or Y/X is " << Z << endl;

  cout << "\nRemember about the largest possible integer being 32,767";
  cout << "\nWell lets add some numbers to this and see what happens ";
  cout << endl << endl;

  X = 32767;
  cout << "\nStart with X = " << X << " This is the maximum positive short int\n\n";
  X = X+1;
  cout << "Now add 1 to X ---------> " << X << endl;
  X = X+1;
  cout << "Now another 1 to X -----> " << X << endl;
  X = X+1;
  cout << "Now another 1 to X -----> " << X << endl << endl;

  cout << "\nLook what is happening to X as you continue to add 1!" << endl;
  cout << "Why does this happen?";
  cin.ignore(1);
}