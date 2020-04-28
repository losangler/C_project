//*********************
//**    ch4_3.cpp    **
//*********************

#include <iostream.h>

void main()
{
  int i,sum=0;

  i=1;
  do{
    sum=sum+i;
    i=i+1;
  }while(i<=100);

  cout <<"sum = " <<sum <<endl;
}
