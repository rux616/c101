#include <iostream>
#include <cctype>
using namespace std;

void ZeroArray(int [], const int);
void ShowArray(const int [], const int);

void main()
{
    const int SIZE = 20;
	const int CHAR_OFFSET = 48;

	int N[SIZE], Temp[SIZE], Index, IndexOffset;
	char Ch;

    do
	{
        // Reset the variables for each run through this loop
        ZeroArray(N, SIZE);
        ZeroArray(Temp, SIZE);
        Index = 0;
        IndexOffset = 0;

        cout << "Please enter a large number: ";
        
        // Read
	    cin.get(Ch);
	    while (isdigit(Ch) && Index < SIZE)
	    {
		    Temp[Index++] = Ch - CHAR_OFFSET;
		    cin.get(Ch);
	    }

	    IndexOffset = SIZE - Index;

	    for (Index = Index - 1; Index >= 0; --Index)
		    N[Index + IndexOffset] = Temp[Index];

        // Display
        cout << "The large number that was entered was:\n";
        ShowArray(N, SIZE);
        cout << "\n\n";

        cout << "Continue? Y or N: ";
        cin >> Ch;
        cout << "\n\n";

        cin.ignore(100, '\n');
	} while(Ch == 'Y' || Ch == 'y');
}

/****************************** ZeroArray *****************************************************************
Action:			Zeroes the passed array 'Array' with 'Size' number of elements

Paremeters:		
	IN:			int Size, holds the number of elements in the array 'Array'
	OUT:		int Array[], holds the pointer to the array that has been zeroed

Returns:		Nothing

Precondition:	Size should be the number of elements, not the max index
**********************************************************************************************************/
void ZeroArray(int Array[], const int Size)
{
	for (int Index = 0; Index < Size; ++Index)
		Array[Index] = 0;
}

/****************************** ShowArray *****************************************************************
Action:			Displays the passed array 'Array' with 'Size' number of elements

Paremeters:		
	IN:			int Array[], holds the pointer to the array to be displayed
	IN:			int Size, the number of elements in array 'Array'
	OUT:		None

Returns:		Nothing

Precondition:	Size should be the number of elements, not the max index
**********************************************************************************************************/
void ShowArray(const int Array[], const int Size)
{
	for (int Index = 0; Index < Size; ++Index)
		cout << Array[Index];
}
