//11_3

#ifndef DATE
#define DATE

#include <iostream.h>

class Date{
public:
  void Display();
  void AddOneDay();
  void SetDay(int y,int m,int d);
protected:
  bool Legal(int y, int m, int d);
  bool IsLeapYear(int y);
  int year;
  int month;
  int day;
};

void Date::Display()
{
  cout <<day <<"/" <<month <<"/" <<year <<endl;
}

void Date::AddOneDay()
{
  if(Legal(year,month,day+1))
    day++;
  else if(Legal(year,month+1,1))
    month++,day=1;
  else if(Legal(year+1,1,1))
    day=1,month=1,year++;
}

void Date::SetDay(int y, int m, int d)
{
  if(Legal(y,m,d))
    day=d, month=m, year=y;
}

bool Date::Legal(int y, int m, int d)
{
  if(y>9999||y<1||d<1||m<1||m>12)
    return false;

  int dayLimit=31;
  switch(m) case 4: case 6: case 9: case 11: dayLimit--;
  if(m==2) dayLimit = IsLeapYear(y) ? 29 : 28;

  return (d>dayLimit)? false : true;
}

bool Date::IsLeapYear(int y)
{
  return !(y%4)&&(y%100)||!(y%400);
}

#endif
