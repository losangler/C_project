//*********************
//**    ch6_5.cpp    **
//**    Ö÷º¯Êý       **
//*********************

#include <iostream.h>
#include "myarea.h"

void main()
{
  double width,length;
  cout <<"please enter two numbers:\n";
  cin >>width >>length;

  cout <<"area of rectangle is " <<rect(width,length) <<endl;

  double radius;
  cout <<"please enter a radius:\n";
  cin >>radius;

  cout <<"area of circle is " <<circle(radius) <<endl;
}