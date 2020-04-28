//**********************
//**    ch9_10.cpp    **
//**********************

#include <iostream.h>

double& fn(const double& pd)
{
  static double ad=32;
  ad+=pd;
  cout <<"fn being called...the value is: " <<pd <<endl;
  return ad;
}

void main()
{
  double a=345.6;
  double& pa=fn(a);
  cout <<pa <<endl;
  a=55.5;
  pa = fn(a);
  cout <<pa <<endl;
}
