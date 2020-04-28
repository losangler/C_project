//**********************
//**    ch15_2.cpp    **
//**********************

#include "student.h"    //÷ÿ”√Student¿‡
#include <iostream.h>

void fn()
{
  Student s1;
  Student s2;
  cout <<Student::number() <<endl;
}

void main()
{
  fn();
  cout <<Student::number() <<endl;
}
