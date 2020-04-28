//9_1

(1)
#include <iostream.h>

const size=10;
void findmax(int* a, int n, int i, int& pk);

void main()
{
  int a[size];
  int n=0;
  cout <<"please input " <<size <<"datas:\n";
  for(int i=0; i<size; i++)
    cin >>a[i];

  findmax(a, size, 0, n);

  cout <<"the maximum is " <<a[n] <<endl
       <<"It's index is " <<n <<endl;
}

void findmax(int* a,int n,int i,int& pk)
{
  if(i<n){
    if(a[i]>a[pk])
      pk=i;
    findmax(a,n,i+1,&pk);
  }
}

(2)
//求数组中最大元素的下标,放入主函数的变量n中.

(3)
#include <iostream.h>

const size=10;
void findmax(int* a, int n, int& pk);

void main()
{
  int a[size];
  int n=0;
  cout <<"please input " <<size <<"datas:\n";
  for(int i=0; i<size; i++)
    cin >>a[i];

  findmax(a,size,n);

  cout <<"the maximum is " <<a[n] <<endl
       <<"It's index is " <<n <<endl;
}

void findmax(int* a,int n,int& pk)
{
  for(int i=1; i<n; i++)
    if(a[i]>a[pk])
      pk=i;
}
