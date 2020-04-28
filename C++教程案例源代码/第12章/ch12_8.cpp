//**********************
//**    ch12_8.cpp    **
//**********************

#include <iostream.h>

class Tdate{
public:
  Tdate(int m=4,int d=15,int y=1995)
  {
    month=m;  day=d;  year=y;
    cout <<month <<"/" <<day <<"/" <<year <<endl;  }
  //其他公共成员
protected:
  int month;
  int day;
  int year;
};

void main()
{
  Tdate aday;
  Tdate bday(2);
  Tdate cday(3,12);
  Tdate dday(1,2,1998);
}