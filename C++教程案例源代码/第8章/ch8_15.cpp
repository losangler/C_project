//**********************
//**    ch8_15.cpp    **
//**********************

#include <iostream.h>
#include <mem.h>

void main()
{
  char src[10]="*********";
  char dest[10];
  char* pc=(char*)memcpy(dest,src,10);
  cout <<pc <<endl;
}
