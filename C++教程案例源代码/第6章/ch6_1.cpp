//*********************
//**    ch6_1.cpp    **
//*********************

#include <iostream.h>

void fn1();
void fn2();
int n;

void main()
{
  n=3;
  fn1();         //fn1()函数的定义在本文件中
  cout <<n <<endl;
}

void fn1()
{
  fn2();         //fn2()函数的定义不在本文件中
}
