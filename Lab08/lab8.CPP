/*      LAB #8

  source : LAB8.CPP
  Action : Practice in hand tracing through program and using the
	       IDE debugger.

  The comments have purposely been left out

---------------------------------------------------------------------*/


#include <iostream>
using namespace std;

void Just_Peachy(int A, int B, int & N);

void main()
{
  char Ch = 'A';
  int X, Y;

  X = 4.56;
  Y = int(Ch);

  for (int i = 5; i >= 3; i--)
    {
      Just_Peachy(i, X, Y);
      if (char(Y) == 'E')
	    Ch = 'W';
    }
}


/****************************************************/

void Just_Peachy(int A, int B, int & N)
{
  int T, Mod;

  Mod = A % B;
  if (Mod == 0)
    T = 2;
  else
    T = 1;

  N = N + T;
}