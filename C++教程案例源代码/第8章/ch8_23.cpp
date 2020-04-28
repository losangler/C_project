//**********************
//**    ch8_23.cpp    **
//**********************

#include <iostream.h>

void main(int argc,char* argv[])
{
  int i=0;
  while(*argv)
    cout <<"arg " <<i++ <<": " <<*argv++<<endl;
}
