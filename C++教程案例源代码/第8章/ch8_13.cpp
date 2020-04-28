//**********************
//**    ch8_13.cpp    **
//**********************

#include <iostream.h>

void swap(int*,int*);

void main()
{
  int a=3, b=8;
  cout <<"a=" <<a <<", b=" <<b <<endl;
  swap(&a,&b);
  cout <<"after swapping...\n";
  cout <<"a=" <<a <<", b=" <<b <<endl;
}

void swap(int* x,int* y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
