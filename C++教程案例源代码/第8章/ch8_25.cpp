//**********************
//**    ch8_25.cpp    **
//**********************

#include <iostream.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b);

char* list[5]={"cattle","car","cabet","cap","canon"};

void main()
{
  qsort((void*)list,5,sizeof(list[0]),compare);

  for(int i=0; i<5; i++)
    cout <<list[i] <<endl;
}

int compare(const void* a, const void* b)
{
  return strcmp(*(char**)a, *(char**)b);
}
