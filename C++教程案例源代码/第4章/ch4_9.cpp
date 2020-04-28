//*********************
//**    ch4_9.cpp    **
//*********************

#include <iostream.h>
#include <iomanip.h>
#include <math.h>

double f(double x);

void main()
{
  int n=1;     //初值
  double a=0, b=1;
  double h,Tn,T2n,In,I2n;

  const double eps=1e-8;

  h = b-a;
  T2n=I2n=h*(f(a)+f(b))/2;
  In=0;

  while(fabs(I2n-In)>=eps){    //求积分
    Tn=T2n;
    In=I2n;

    double sigma=0.0;
    for(int k=0; k<n; k++){    //求变步长梯形的和部分
      double x=a+(k+0.5)*h;
      sigma+=f(x);
    }

    T2n=(Tn+h*sigma)/2.0;      //变步长梯形
    I2n=(4*T2n-Tn)/3.0;        //辛普生公式

    n*=2;      //划分
    h/=2;
  }

  cout <<"the integral of f(x) from "
       <<a <<" to " <<b <<" is \n"
       <<setiosflags(ios::fixed)
       <<setprecision(8)
       <<setw(10) <<I2n <<endl;    //输出结果
}

double f(double x)
{
  return exp(x)/(1+x*x);
}