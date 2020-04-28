//*********************
//**    tdate.cpp    **
//*********************
#include <iostream.h>
#include "tdate.h"

void Tdate::Set(int m,int d,int y)
{
  month=m;  day=d;  year=y;
}

int Tdate::IsLeapYear()
{
  return (year%4==0&&year%100!=0)||(year%400==0);
}

void Tdate::Print()
{
  cout <<month <<"/" <<day <<"/" <<year <<endl;}
