//**********************
//**    ch9_11.cpp    **
//**********************

#include <iostream.h>

bool CircleArea()
{
  double* pd=new double;
  if(!pd){
    cout <<"error memory allocation!";
    return true;
  }
  double& rd=*pd;
  cout <<"the radius is: ";
  cin >>rd;
  cout <<"the area of circle is " <<rd*rd*3.14 <<endl;
  delete &rd;
  return false;
}

void main()
{
  if(CircleArea())
    cout <<"program failed.\n";
  else
    cout <<"program successed.\n";
}
