/*      Program INTTEST.CPP

  Program will test input for inputed integers, loop stops when bad input.

  When running this program from .NET environment you must run by pressing 
  "Ctrl" + F5 keys, or go to Debug then click on "Start Without Debugging"

  Then click on "Ignore" button when the dialog box opens up.

-----------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

void main()
{
  int Number;   // declare a variable, but not initialized

  cout << "Variable \"Number\" has initial garbage value of -->  " << Number << endl;

  do
   {
    cout << "\nEnter an integer --> ";
    cin >> Number;
    cout << "Number is -->  " << Number << endl << endl;
   }
  while (cin.good());   //will continue to loop as long as input is legal or good
 }