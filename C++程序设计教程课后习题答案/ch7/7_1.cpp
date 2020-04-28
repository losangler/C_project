//7_1

#include <iostream.h>

int findMinIndex(int a[], int n);

void main()
{
  int array[]={34,91,83,56,29,93,56,12,88,72};
  int size=sizeof(array)/sizeof(*array);

  int minIndex = findMinIndex(array, size);

  cout <<"最小数:     " <<array[minIndex] <<endl
       <<"相应的下标: " <<minIndex <<endl;
}

int findMinIndex(int a[], int n)
{
  int index = 0;
  for(int i=1; i<n; i++)
    if(a[index]>a[i])
      index = i;

  return index;
}

