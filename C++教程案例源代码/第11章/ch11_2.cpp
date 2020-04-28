//**********************
//**    ch11_2.cpp    **
//**********************
#include <iostream.h>
#include "tdate.h"
void someFunc(Tdate* pS)
{
  pS->Print();  //pS是s对象的指针
  if(pS->IsLeapYear())
    cout <<"oh oh\n";
  else
    cout <<"right\n";
}
void main()
{
  Tdate s;
  s.Set(2,15,1998);
  someFunc(&s);    //对象的地址传给指针
}
