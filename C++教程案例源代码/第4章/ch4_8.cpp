//*********************
//**    ch4_8.cpp    **
//*********************

#include <iostream.h>
#include <iomanip.h>
#include <math.h>

int main()
{
  //输入
  long a,b,l=0;
  cout <<"please input two numbers:\n";
  cin >>a >>b;
  cout <<"primes from " <<a <<" to " <<b <<" is:\n";

  //处理
  if(a%2==0)    //若为偶数，则增1
    a++;

  for(long m=a; m<=b; m+=2){   //步长为2
    int sqrtm=sqrt(m);
    int i;
    for(i=2; i<=sqrtm; i++)    //判明素数
      if(m%i==0)
        break;
    //输出
    if(i>sqrtm){    //素数
      if(l++%10==0)
        cout <<endl;
      cout <<setw(5) <<m;
    }
  }
}
