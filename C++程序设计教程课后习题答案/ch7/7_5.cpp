//7_5

#include <iostream.h>

const int n=5;
int sum(int a[][5], int size);
void main()
{
  int array[n][n]={{3,2,4,1,5},
                   {8,7,2,5,6},
                   {6,9,1,4,3},
                   {5,5,3,6,2},
                   {2,8,1,8,6}};
  cout <<sum(array,n);
}

int sum(int a[][5], int size)
{
  int s=0;
  for(int i=0; i<size; i++)
    s+=a[i][i]+a[i][size-i-1];
  if(size%2==1)
    s-=a[size/2][size/2];
  return s;
}

