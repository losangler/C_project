//*********************
//**    ch5_1.cpp    **
//*********************

#include <iostream.h>

int func1();
int func2();

void main()
{
  func1();
  cout <<func2() <<endl;
}

int func1()
{
  int n=12345;
  return n;
}

int func2()
{
  int m;
  return m;    //warning:possible use of 'm' before definition
}