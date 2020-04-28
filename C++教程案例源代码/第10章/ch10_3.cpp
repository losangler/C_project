//**********************
//**    ch10_3.cpp    **
//**********************

#include <iostream.h>
#include <string.h>

struct Person
{
  char name[20];
  unsigned long id;
  float salary;
};

void main()
{
  Person pr1;
  Person* prPtr;
  prPtr=&pr1;
  strcpy(prPtr->name,"David Marat");
  prPtr->id=987654321;
  prPtr->salary=335.0;
  cout <<prPtr->name <<"    "
       <<prPtr->id <<"    "
       <<prPtr->salary <<endl;
}