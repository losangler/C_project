//*********************
//**    ch8_1.cpp    **
//*********************

#include <iostream.h>

void main()
{
  int* iPtr;
  int iCount=18;
  iPtr=&iCount;

  cout <<*iPtr <<endl;    //间接引用指针
}
