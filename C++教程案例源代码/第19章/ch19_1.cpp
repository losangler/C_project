//**********************
//**    ch19_1.cpp    **
//**********************

#include<iostream.h>

void fn(int a, int b)
{
  if(b==0)
    cerr <<"zero encountered. "
         <<"The message cannot be redirected";
  else
    cout <<a/b <<endl;
}

void main()
{
  fn(20,2);
  fn(20,0);
}
