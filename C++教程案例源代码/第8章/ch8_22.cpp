//**********************
//**    ch8_22.cpp    **
//**********************

#include <iostream.h>

void main(int argc,char* argv[])
{
  int iCount=0;
  while(iCount<argc){
    cout <<"arg " <<iCount <<": " <<argv[iCount] <<endl;
    iCount++;
  }
}
