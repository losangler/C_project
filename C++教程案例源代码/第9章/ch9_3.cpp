//*********************
//**    ch9_3.cpp    **
//*********************

#include <iostream.h>

void main()
{
  int intOne;
  int& rInt=intOne;

  intOne=5;
  cout <<"intOne:" <<intOne <<endl;
  cout <<"rInt:" <<rInt <<endl;

  cout <<"&intOne:" <<&intOne <<endl;
  cout <<"&rInt:" <<&rInt <<endl;

  int intTwo=8;
  rInt=intTwo;
  cout <<"intOne:" <<intOne <<endl;
  cout <<"intTwo:" <<intTwo <<endl;
  cout <<"rInt:" <<rInt <<endl;

  cout <<"&intOne:" <<&intOne <<endl;
  cout <<"&intTwo:" <<&intTwo <<endl;
  cout <<"&rInt:" <<&rInt <<endl;
}