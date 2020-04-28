//**********************
//**    ch7_10.cpp    **
//**********************

#include <iostream.h>

void isort(int* a, int size);

void main()
{
  int array[]={55,2,6,4,32,12,9,73,26,37};
  int len=sizeof(array)/sizeof(int);    //元素个数

  for(int i=0; i<len; i++)    //原始顺序输出
    cout <<array[i] <<",";
  cout <<endl<<endl;

  isort(array, len);    //调用排序函数
}

void isort(int a[],int size)    //插入排序
{
  int inserter,index;
  for(int i=1; i<size; i++){    //共执行size-1轮
    for(index=i-1,inserter=a[i]; index>=0 && inserter<a[index]; index--)
      a[index+1]=a[index];     //后挪一个位置

    a[index+1]=inserter;       //插入

    for(int j=0; j<size; j++)  //比较一轮后就输出
      cout <<a[j] <<((j==i)?"  |  ":",");   //|为已排序与未排序的分界线
    cout <<endl;
  }
}