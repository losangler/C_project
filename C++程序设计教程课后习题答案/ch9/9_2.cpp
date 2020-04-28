//9_2

#include <iostream.h>
#include <stdlib.h>ª¥ª¤

int& put(int n);      //put value into the arrayª¤
int get(int n);       //obtain a value from the arrayª¥ª¤

int vals[10];
int error=-1;

void main()
{
  put(0)=10;      //put values into the array
  put(1)=20;
  //...
  put(9)=30;

  cout <<get(0) <<endl;
  cout <<get(1) <<endl;
  //...
  cout <<get(9) <<endl;

  put(12)=1;      //out of range
  //...
}

int& put(int n)
{
  if(n>=10){
    cerr <<"range error in put value!\n";
    exit(1);
  }
  return vals[n];
}

int get(int n)
{
  if(n>=10){
    cerr <<"range error in get value!\n";
    exit(1);
  }
  return vals[n];
}

