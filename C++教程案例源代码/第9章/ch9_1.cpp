//*********************
//**    ch9_1.cpp    **
//*********************

#include <iostream.h>

void main()
{
  int intOne;
  int& rInt=intOne;

  intOne=5;
  cout <<"intOne:" <<intOne <<endl;
  cout <<"rInt:" <<rInt <<endl;

  rInt=7;
  cout <<"intOne:" <<intOne <<endl;
  cout <<"rInt:" <<rInt <<endl;
}