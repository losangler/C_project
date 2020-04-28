//***********************
//**    ch6_3_1.cpp    **
//***********************

#include <iostream.h>

static void staticFn();
void fn();

void fn()
{
  staticFn();
  cout <<"this is fn()\n";
}

void staticFn()
{
  cout <<"this is staticFn()\n";
}