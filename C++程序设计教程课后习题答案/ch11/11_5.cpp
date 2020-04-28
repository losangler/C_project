//11_5

#include <iostream.h>
#include "stack.h"

void main()
{
  Stack sta;

  sta.Put(10);
  sta.Put(12);
  sta.Put(14);

  cout <<sta.Get() <<endl;
  cout <<sta.Get() <<endl;
}
