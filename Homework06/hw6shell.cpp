/******************************************************************
Name :                         and Matt Holloway
Date :
Homework # :  Homework #6 Problem #1
Source  :    
Action  :  Menu is displayed allows user to calculate
		   Miles per Gallon, Total minutes and seconds
		   and determine if number is a prime number or not

Notes  :
********************************************************************/
#include <iostream>
#include <stdlib.h>      // this header file requires the .h
using namespace std;

void DisplayMenu(void);
void FindMilesPerGallon(void);

// some prototypes have been left out you need to put rest in 

void main()
{
  int Choice;

  system("cls");	// this clears the output screen

  DisplayMenu();
  cin >> Choice;
  while (Choice != 4)
    {
      switch (Choice)
        {
	      case 1: FindMilesPerGallon();
			      break;
		  
          default : cout << "Sorry illegal choice, Please try again\n\n";
        }
      DisplayMenu();
      cin >> Choice;

    }
}

/*********************  DisplayMenu  ************************************
Action  :  This just displays the menu to the screen
Parameters  : none
returns     : nothing
***********************************************************************/
void DisplayMenu()
{
  cout << "\n\nDo you want to:\n";
  cout << "   1) Find miles per gallon\n";
  cout << "   2) Convert total seconds to minutes and seconds\n";
  cout << "   3) Determine if number is a prime number or not\n";
  cout << "   4) QUIT\n\n";
  cout << "  CHOICE --> ";
}

/********************  FindMilesPerGallon  ******************************
Action  : Ask user to input number of miles traveled and number of
          gallons used then display the miles per gallon obtained.
Parameters : none
returns    : nothing
------------------------------------------------------------------------*/
void FindMilesPerGallon(void)
{
  float Miles, Gallons;

}

/******************** ConvertTotalSeconds *********************
Action  : Ask user to input a given total number of seconds and then
          displays the corresponding number of minutes and seconds
Parameters : none
returns    : nothing
-------------------------------------------------------------------------*/



/*********************** IsPrimeNumber()****************************
Action  : Ask user to input positive integer and will determine if number
          is a prime number or not.
Parameters  : none
Returns     : nothing
-------------------------------------------------------------------*/
