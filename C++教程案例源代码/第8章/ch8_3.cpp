//*********************
//**    ch8_3.cpp    **
//*********************

#include <iostream.h>

void main()
{
  float f=34.5;
  float* fPtr=&f;         //浮点指针

  int* iPtr=(int*)&f;     //warning: 将浮点变量的地址赋给整型指针

  cout <<f <<endl
       <<"iPtr:" << iPtr <<"=>" <<*iPtr <<endl
       <<"fPtr:" << fPtr <<"=>" <<*fPtr <<endl <<endl;

  *iPtr=*fPtr;            //隐式数据转换

  cout <<f <<endl
       <<*iPtr <<endl
       <<*fPtr <<endl;
  cin.get();
}
