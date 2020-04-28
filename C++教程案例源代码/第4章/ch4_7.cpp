//*********************
//**    ch4_7.cpp    **
//*********************

#include <iostream.h>
#include <math.h>

int main()
{
  //输入
  long m;
  cout <<"please input a number:\n";
  cin >>m;

  //处理
  double sqrtm=sqrt(m);    //用到math.h
  int i;
  for(i=2; i<=sqrtm; i++)
    if(m%i==0)
      break;

  //输出
  if(sqrtm<i)
    cout <<m <<" is prime.\n";
  else
    cout <<m <<" isn't prime.\n";
}
