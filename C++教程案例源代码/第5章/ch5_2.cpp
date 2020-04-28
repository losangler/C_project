//*********************
//**    ch5_2.cpp    **
//*********************

#include <iostream.h>

void func();
int n=1;    //全局变量

void main()
{
  static int a;    // 静态局部变量
  int b= -10;      // 局部变量
  cout <<"a:" <<a
       <<"  b:" <<b
       <<"  n:" <<n <<endl;
  b+=4;
  func();
  cout <<"a:" <<a
       <<"  b:" <<b
       <<"  n:" <<n <<endl;
  n+=10;
  func();
}

void func()
{
  static int a=2;    // 静态局部变量
  int b=5;           // 局部变量
  a+=2;
  n+=12;
  b+=5;
  cout <<"a:" <<a
       <<"  b:" <<b
       <<"  n:" <<n <<endl;
}