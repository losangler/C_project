//**********************
//**    ch11_3.cpp    **
//**********************
#include <iostream.h>
#include "tdate.h"

void someFunc(Tdate& refs)
{
  refs.Print();    //refs是s对象的别名
  if(refs.IsLeapYear())
    cout <<"oh oh\n";
  else
    cout <<"right\n";
}
void main()
{
  Tdate s;
  s.Set(2,15,1998);
  someFunc(s);    //对象的地址传给引用
}
