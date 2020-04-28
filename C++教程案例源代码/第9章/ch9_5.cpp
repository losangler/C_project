//*********************
//**    ch9_5.cpp    **
//*********************

#include <iostream.h>

bool Factor(int, int&, int&);

void main()
{
  int number,squared,cubed;
  bool error;
  cout <<"Enter a number(0бл20): ";
  cin >>number;

  error=Factor(number,squared,cubed);

  if(error)
    cout <<"Error encountered!\n";
  else{
    cout <<"Number: " <<number <<endl;
    cout <<"Squared: " <<squared <<endl;
    cout <<"Cubed: " <<cubed <<endl;
  }
}

bool Factor(int n, int& rSquared, int& rCubed)
{
  if(n>20 || n<0)
    return true;
  rSquared = n*n;
  rCubed = n*n*n;
  return false;
}