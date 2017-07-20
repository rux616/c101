/*************************************************************************

PROGRAMMER :                   and Matt Holloway
COMPILER   :  Visual C++ .NET
SOURCE FILE:  a13shell.cpp

DESCRIPTION:  A driver program designed to test the following functions:

              void Upcase (char S[ ]);
              void DeleteFirst (char S[ ]);
              void InsertBlank (char S[ ], int  Pos);
              int Position (char Ch, char S[]);
=========================================================================*/
#include <iostream>
#include <ctype.h>
using namespace std;

void Upcase (char S[ ]);
void DeleteFirst (char S[ ]);
void InsertBlank (char S[ ], int  Pos);
int  Position (char Ch, char S[]);

void TestUpcaseFunction();
void TestDeleteFirstFunction();
void TestInsertBlankFunction();
void TestPositionFunction();

const int MAX_LENGTH = 50;

//**************************  main  **************************************

void main()
{
  char MenuChoice;

  do
    {
    cout << "1)  TestUpcaseFunction\n";
    cout << "2)  TestDeleteFirstFunction\n";
    cout << "3)  TestInsertBlankFunction\n";
    cout << "4)  TestPositionFunction\n";
    cout << "5)  EXIT                 \n\n";

    cout << "Choice => ";
    cin  >> MenuChoice;

    switch (MenuChoice)
      {
      case '1':  TestUpcaseFunction();
               break;
      case '2':  TestDeleteFirstFunction();
               break;
      case '3':  TestInsertBlankFunction();
               break;
      case '4':  TestPositionFunction();
               break;
      case '5': cout << "Good Bye!\n\n";
               break;
      default :  cout << "INCORRECT INPUT, PLEASE CHOOSE AGAIN\n\n";
               break;
      }
        }
  while ( MenuChoice != '5' );
}

/*********************  TestUpcaseFunction  ******************************

  Facilitates the testing of the function, Upcase. To exit, the user
  enters a null string, which becomes the final test case.
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void TestUpcaseFunction()
{
  char Str[MAX_LENGTH] = "";

  cout << "\n\n================= Testing Upcase Function ================\n\n";
  cout << "Enter null string to terminate\n";

  cin.ignore(100, '\n');     // Eat newline left over from main() input

  do
    {
    cout << "\nEnter string => ";
    cin.getline(Str, MAX_LENGTH);          // Read string, discard '\n'
    if (Str[0] != 0)                      //if not null string then do
      {
       cout << "\nStr = '" << Str << "'\n";

       Upcase(Str);

       cout << "\nAfter calling Upcase,\n";
       cout << "\nStr = '" << Str << "'\n\n";

       cout << "----------------------------------------------------------\n";
      }
    }
  while ( Str[0] != 0 );                   // While null string not entered.

  cout << endl << endl;
}

/*********************  TestDeleteFirstFunction  *************************

  Facilitates the testing of the function, DeleteFirst.
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void TestDeleteFirstFunction()
{
  char Str[MAX_LENGTH] = "";

  cout << "\n\n========== Testing Delete First Function ================\n\n";
  cout << "Enter null string to terminate\n";

  cin.ignore(100, '\n');     // Eat newline left over from main() input

  do
    {
     cout << "\nEnter string => ";
     cin.getline(Str, MAX_LENGTH);          // Read string, discard '\n'
     if ( Str[0] != 0 )                 // if not null string not entered.
       {
        cout << "\nStr = '" << Str << "'\n";

        DeleteFirst(Str);

        cout << "\nAfter calling DeleteFirst,\n";
        cout << "\nStr = '" << Str << "'\n\n";

        cout << "--------------------------------------------------------\n";
       }
    }
  while (Str[0] != 0);          //while not null string continue

  cout << endl << endl;
}

/*********************  TestInsertBlankFunction  *************************

  Facilitates the testing of the function, InsertBlank.
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void TestInsertBlankFunction()
{
  char Str[MAX_LENGTH] = "";
  int Position;             //Place in string to insert blank

  cout << "\n\n========== Testing Insert Blank Function ===============\n\n";
  cout << "Enter null string to terminate\n";

  cin.ignore(100, '\n');  // Eat newline left over from main() input

  cout << "\nEnter string => ";
  cin.getline(Str, MAX_LENGTH);          // Read string, discard '\n'

  while ( Str[0] != 0 )                 // While null string not entered.
     {
      cout << "\nEnter the position to insert blank ---> ";
      cin >> Position;
      cout << "\nStr = '" << Str << "'\n";

      InsertBlank(Str,Position);

      cout << "\nAfter calling InsertBlank,\n";
      cout << "\nStr = '" << Str << "'\n\n";

      cout << "----------------------------------------------------------\n";
      cout << "\nEnter string => ";
      cin.ignore(100, '\n');               // Gets rid of newline from before
      cin.getline(Str, MAX_LENGTH);        // Read string, discard '\n'
     }

  cout << endl << endl;
}

/*********************  TestPositionFunction  ****************************

  Facilitates the testing of the function, Position.
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void TestPositionFunction()
{
  char Str[MAX_LENGTH] = "";
  char Ch;                     //character to look for

  cout << "\n\n========== Testing Position Function ===============\n\n";
  cout << "Enter null string to terminate\n";

  cin.ignore(100, '\n');  // Eat newline left over from main() input

  cout << "\nEnter string => ";
  cin.getline(Str, MAX_LENGTH);          // Read string, discard '\n'

  while ( Str[0] != 0 )                 // While null string not entered.
     {
      cout << "\nEnter the character to find location in string ---> ";
      cin >> Ch;

      cout << "\nAfter calling Position Function,\n";
      cout << "'" << Ch << "'"<< " is found in " << Position(Ch,Str)
           << " position of string" << "\n\n";

      cout << "----------------------------------------------------------\n";
      cout << "\nEnter string => ";
      cin.ignore(100, '\n');               // Gets rid of newline from before
      cin.getline(Str, MAX_LENGTH);        // Read string, discard '\n'
     }

  cout << endl << endl;

}

/***************************  Upcase  ************************************
DESCRIPTION : This function will accept a character string and convert
              all the characters to uppercase if they are not already.
PARAMETERS  :
  S[]       : Pointer to string address
returns     : nothing
Precondition: none
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void Upcase (char S[ ])
{
	for (int Index = 0; Index < MAX_LENGTH && S[Index]; ++Index)
		S[Index] = toupper(S[Index]);
}

/***************************  DeleteFirst  *******************************
DESCRIPTION : This function will delete the first character of any string
PARAMETERS  :
  S[]       : Pointer to string address
returns     : nothing
Precondition: none
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void DeleteFirst (char S[ ])
{
	for (int Index = 1; Index < MAX_LENGTH && S[Index - 1]; ++Index)
		S[Index - 1] = S[Index];
}

/*************************** InsertBlank  ********************************
DESCRIPTION : This function will insert a blank into a string given
              location specified by the user.  If the position is outside
              the length of the string then nothing happens.
PARAMETERS  :
  S[]       : Pointer to string address
  Pos       : Int holding the position to insert the blank space
returns     : nothing

note      : Pos starts at 1 to be consistent with the Position function
Precondition: Pos needs to be greater than or equal to 1 and less then the
              length of the string.
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
void InsertBlank (char S[ ], int  Pos)
{
	int Length;

	for (Length = 0; Length < MAX_LENGTH && S[Length]; ++Length);

	if (Pos >= 1 && Pos <= Length)
	{
		for (int Index = MAX_LENGTH - 3; Index >= Pos - 1; --Index)
			S[Index + 1] = S[Index];
		S[Pos - 1] = ' ';
	}
}

/*************************** Position  ********************************
DESCRIPTION : This function will tell you what position or location
              a given character is in the string.  If character is not
              found a -1 is returned. Function is case sensitive.
PARAMETERS :
  Ch       : Value parameter that holds the character being sought
  S[]      : Pointer to string address
returns    : Int holding the position of the sought character

note     : my position starts at 1, so "this is fun" and look for "t" then
           found in position 1.
Precondition: None
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
int Position (char Ch, char S[])
{
	int Pos = -1;
	
	for (int Index = 0; Index < MAX_LENGTH && S[Index]; ++Index)
		if (S[Index] == Ch)
		{
			Pos = Index + 1;
			break;
		}

	return Pos;
}

/*
	PROGRAM OUTPUT

	Function Upcase
	---------------
	Test Case 1: Limit (String = "a")
	Tests the lower limit of 1 lowercase character in the string.
		Str = 'A'

	Test Case 2: Limit (String = "A")
	Tests the lower limit of 1 uppercase character in the string.
		Str = 'A'

	Test Case 3: Limit (String = "1")
	Tests the lower limit of 1 digit character in the string.
		Str = '1'

	Test Case 4: Normal (String = "This is test 4.")
	Tests a normal sentence which includes uppercase, lowercase, whitespace, numbers, and punctuation.
		Str = 'THIS IS TEST 4.'

	Function DeleteFirst
	--------------------
	Test Case 1: Limit (String = "a")
	Tests a lower limit of a 1 character string.  It goes back to the main program menu, but this is
	expected behavior due to the do...while loop.
		Str = ''

	Test Case 2: Normal (String = "ab")
	Tests a two character string.
		Str = 'b'

	Test Case 3: Normal (String = "This is test number 3.")
	Tests a full sentence.
		Str = 'his is test number 3.'

	Function InsertBlank
	--------------------
	Note: Normally I don't add testing for Illegal entry to the program output section, but the description
	of the function explicitly states that it should do nothing when Pos is invalid.  Thus I decided to
	demonstrate the fact that my function follows the description.
	--------------------
	Test Case 1: Illegal (String = "a", Pos = 0)
	Tests an illegal case of Position 0 with a 1-character string.
		Str = 'a'

	Test Case 2: Normal/Limit (String = "A", Pos = 1)
	Tests an normal and limit case of Position 1 with a 1-character string.
		Str = ' A'

	Test Case 3: Illegal (String = "1", Pos = 2)
	Tests an illegal case of Position 2 with a 1-character string.
		Str = '1'

	Test Case 4: Illegal (String = "abc123", Pos = 0)
	Tests an illegal case of Position 0 with a 6-character string.
		Str = 'abc123'

	Test Case 5: Limit (String = "def456", Pos = 1)
	Tests a limit case of inserting a blank at the very beginning of a 6-character string.
		Str = ' def456'

	Test Case 6: Normal (String = "ghi789", Pos = 4)
	Tests a normal case of inserting a blank in the middle of a 6-character string.
		Str = 'ghi 789'

	Test Case 7: Limit (String = "jklmno", Pos = 6)
	Tests a limit case of inserting a blank at the end-most (legal) position of a 6-character string.
		Str = 'jklmn o'

	Test Case 8: Illegal (String = "pqstuv", Pos = 7)
	Tests an illegal case of Position 7 with a 6-character string.
		Str = 'pqstuv'
	
	Function Position
	-----------------
	Test Case 1: Limit (Ch = 'a', String = "a")
	Tests a limit case of a 1-character string and a 'found' search.
		'a' is found in 1 position of string

	Test Case 2: Limit (Ch = '1', String = "a")
	Tests a limit case of a 1-character string and a 'not found' search.
		'1' is found in -1 position of string

	Test Case 3: Limit (Ch = 'a', String = "abc123")
	Tests a limit case of a 6-character string and a 'found' search where the found char is at index 0.
		'a' is found in 1 position of string

	Test Case 4: Normal (Ch = 'b', String = "abc123")
	Tests a normal case of a 6-character string and a 'found' search where the found char is at index 1.
		'b' is found in 2 position of string

	Test Case 5: Limit (Ch = '3', String = "abc123")
	Tests a limit case of a 6-character string and a 'found' search where the found char is at index 5.
		'3' is found in 6 position of string

	Test Case 6: Limit (Ch = 'd', String = "abc123")
	Tests a limit case of a 6-character string and a 'not found'.
		'd' is found in -1 position of string
*/