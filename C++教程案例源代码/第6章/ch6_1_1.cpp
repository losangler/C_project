//***********************
//**    ch6_1_1.cpp    **
//***********************

extern int n;      //n由另一个源文件定义

void fn2()         //fn2()函数用于另一个源文件
{
  n=8;             //使用n
}