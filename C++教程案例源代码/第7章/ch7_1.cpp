//*********************
//**    ch7_1.cpp    **
//*********************

#include <iostream.h>

void main()
{
  char chArray[30];
  cin.get(chArray,30);
  for(int i=0; chArray[i]!='\0'; i++)
    cout <<chArray[i];
  cout <<endl;
}