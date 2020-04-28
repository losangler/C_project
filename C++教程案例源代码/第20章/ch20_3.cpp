//**********************
//**    ch20_3.cpp    **
//**********************

#include "listtmp.h"

void main()
{
  List<float> floatList;
  for(int i=1; i<7; i++)
    floatList.Add(*new float(i+0.6));

  floatList.PrintList();
  float b=3.6;
  float* pa=floatList.Find(b);
  if(pa)
    floatList.Remove(*pa);
  floatList.PrintList();
}
