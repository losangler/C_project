//*********************
//**    ch8_9.cpp    **
//*********************

#include <iostream.h>
//#include <alloc.h>    //无须头文件

void main()
{
  int arraysize;    //元素个数
  int *array;
  cout <<"please input a number of array:\n";
  cin >>arraysize;

  if((array=new int[arraysize])==NULL){    //分配堆内存
    cout <<"can't allocate more memory, terminating.\n";
    return ;
  }

  for(int count=0; count<arraysize; count++)
    array[count]=count*2;

  for(int count=0; count<arraysize; count++)
    cout <<array[count] <<"  ";

  cout <<endl;
  delete[]array;        //释放堆内存
}
