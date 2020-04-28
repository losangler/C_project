//**********************
//**    ch8_10.cpp    **
//**********************

#include <iostream.h>

void mystrcpy(char* dest, const char* source)
{
  while(*dest++ = *source++);
}

void main()
{
  char a[20]="How are you!";
  char b[20];
  mystrcpy(b,a);
  cout <<b <<endl;
}
