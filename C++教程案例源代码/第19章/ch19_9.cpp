//**********************
//**    ch19_9.cpp    **
//**********************

#include <iostream.h>

void main()
{
  float value =2.345678;
  int prePrecision;
  prePrecision =cout.precision(4);
  cout <<value;
  cout.precision(prePrecision);
  //...
}
