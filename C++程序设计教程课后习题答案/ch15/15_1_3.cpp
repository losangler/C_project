//15_1_3

#include <iostream.h>
#include "clas.h"

void main()
{
  Class* ap=new Class(5);
  Class* bp=new Class(80);
  Class* cp=new Class(20);
  cout <<ap->Get() <<endl
       <<bp->Get() <<endl
       <<cp->Get() <<endl
       <<Class::GetStatic() <<endl;
  delete ap;
  cout <<Class::GetStatic() <<endl;
  delete bp;
  cout <<Class::GetStatic() <<endl;
  delete cp;
  cout <<Class::GetStatic() <<endl;
}

