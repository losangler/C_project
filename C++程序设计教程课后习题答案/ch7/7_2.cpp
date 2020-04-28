#include <iostream.h>

int insert(int a[], int n, int value);

void main()
{
  int array[]={12,29,34,56,72,83,88,91};
  int size=sizeof(array)/sizeof(*array);
  cout <<"插入前的数组:\n";
  for(int i=0; i<size; i++)
    cout <<array[i] <<" ";

  int aValue;
  cout <<"\nplease input a number :\n";
  cin >>aValue;

  int max=insert(array,size,aValue);

  cout <<"\n最大数: " <<max <<endl;
  cout <<"插入后的数组:\n";
  for(int i=0; i<size; i++)
    cout <<array[i] <<" ";
}

int insert(int a[], int n, int value)
{
  if(a[n-1]<=value)
    return value;
  int retValue = a[n-1];
  int i;
  for(i=n-2; i>=0&&a[i]>value; i--)
    a[i+1]=a[i];

  a[i+1]=value;
  return retValue;
}

