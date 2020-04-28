//*********************
//**    ch5_3.cpp    **
//*********************

#include <iostream.h>

int isnumber(char);    //函数声明

void main()
{
  char c;
  while((c=cin.get())!='\n')
    if( isnumber(c) )      //调用一个小函数
      cout <<"you entered a digit\n";
    else
      cout <<"you entered a non_digit\n";
}

int isnumber(char ch)      //函数定义
{
  return (ch>='0' && ch<='9')? 1:0;
}