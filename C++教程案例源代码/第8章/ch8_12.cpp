//**********************
//**    ch8_12.cpp    **
//**********************

#include <iostream.h>

void swap(int,int);

void main()
{
  int a=3, b=8;
  cout <<"a=" <<a <<", b=" <<b <<endl;
  swap(a,b);
  cout <<"after swapping...\n";
  cout <<"a=" <<a <<", b=" <<b <<endl;
}

void swap(int x,int y)
{
  int temp=x;        //交换两个形参
  x=y;
  y=temp;
}
