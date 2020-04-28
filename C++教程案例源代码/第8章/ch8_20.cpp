//**********************
//**    ch8_20.cpp    **
//**********************

#include <iostream.h>

void Print(char*[],int);

void main()
{
  char* pn[]={"Fred","Barney","Wilma","Betty"};
  int num =sizeof(pn)/sizeof(char*);
  Print(pn,num);
}

void Print(char* arr[], int len)
{
  for(int i=0; i<len; i++)       //Êä³ö¸÷×Ö·û´®
    cout <<(int)arr[i] <<"  "    //Êä³ö×Ö·û´®µØÖ·ª¤
      <<arr[i] <<endl;           //Êä³ö×Ö·û´®
}
