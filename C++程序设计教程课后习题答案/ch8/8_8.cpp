//8_8

#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>

void transpose(int* a, int size);   //降维处理

void main()
{
  int A[5][5];
  randomize();
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++)
      cout <<setw(7) <<(A[i][j]=rand());
    cout <<endl;
  }

  transpose((int*)A,5);

  cout <<"\n转置之后:\n";
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++)
      cout <<setw(7) <<A[i][j];
    cout <<endl;
  }
}

void transpose(int* a, int size)
{
  for(int i=1; i<size; i++)
    for(int j=0; j<i; j++){
      int temp=a[i*size+j];
      a[i*size+j]=a[j*size+i];
      a[j*size+i]=temp;
    }
}


