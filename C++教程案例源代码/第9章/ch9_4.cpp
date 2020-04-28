//*********************
//**    ch9_4.cpp    **
//*********************

#include <iostream.h>

void swap(int &x,int &y);

void main()
{
  int x=5, y=6;
  cout <<"before swap, x:" <<x <<" ,y:" <<y <<endl;

  swap(x,y);

  cout <<"after swap, x:" <<x <<" ,y:" <<y <<endl;
}

void swap(int &rx,int &ry)
{
  int temp=rx;  rx=ry;  ry=temp;
}