//*********************
//**    ch6_4.cpp    **
//*********************

#include <iostream.h>

int id=3;

void main()
{
  int id=5;
  {
    int id;
    id=7;
    cout <<"id=" <<id <<endl;        //Êä³ö7
  }
  cout <<"id=" <<id <<endl;        //Êä³ö5
}