//15_1_2

#include <iostream.h>
#include "class.h"

void main()
{
  Class* ap=new Class(5);
  Class* bp=new Class(80);
  Class* cp=new Class(20);
  cout <<ap->Get() <<endl
       <<bp->Get() <<endl
       <<cp->Get() <<endl
       <<Class::staticV <<endl;
  delete ap;
  cout <<Class::staticV <<endl;
  delete bp;
  cout <<Class::staticV <<endl;
  delete cp;
  cout <<Class::staticV <<endl;
}

