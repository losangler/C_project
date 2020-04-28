//***********************
//**    ch12_14.cpp    **
//***********************

#include <iostream.h>
#include <string.h>

class SmallOne{
public:
  SmallOne(int sma)
  {
    cout <<"Smallone constructing with a value of"
         <<sma <<endl;
  }
};
void fn(int n)
{
  static SmallOne sm(n);
  cout <<"In function fn with n= " <<n <<endl;
}
void main()
{
  fn(10);
  fn(20);
}
