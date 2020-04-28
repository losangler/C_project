//*********************
//**    ch8_4.cpp    **
//*********************

#include <iostream.h>

void main()
{
  int iArray[10];
  int sum=0;
  int* iPtr=iArray;    //用数组名iArray给指针初始化

  for(int i=0;i<10;i++)    //给数组赋值
    iArray[i]=i*2;

  for(int index=0; index <10; index++){    //计算数组元素之和
    sum+= *iPtr;
    iPtr++;
  }
  cout <<"sum is " <<sum <<endl;
}
