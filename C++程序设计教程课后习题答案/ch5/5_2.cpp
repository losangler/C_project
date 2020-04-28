//5_2

#include <iostream.h>
#include <iomanip.h>
#include <math.h>

double f(double x);
double integral(double a, double b);
const double eps = 1e-8;

void main()
{
  double a=0, b=1;
  cout <<"the integral of f(x) from "
       <<a <<" to " <<b <<" is \n"
       <<setiosflags(ios::fixed)
       <<setprecision(8)
       <<setw(8) <<integral(a,b) <<endl;
}

double f(double x)
{
  return exp(x)/(1+x*x);
}

double integral(double a, double b)
{
  int n=1;
  double h,tn,t2n,i2n,in=0;
  h = b-a;
  t2n = i2n = h*(f(a)+f(b))/2;
  while(fabs(i2n-in)>=eps){
    tn = t2n;
    in = i2n;
    double sigma = 0.0;
    for(int k=0; k<n; k++){
      double x = a+(k+0.5)*h;
      sigma += f(x);
    }
    t2n = (tn+h*sigma)/2.0;   //变步长梯形
    i2n = (4*t2n-tn)/3.0;     //辛普生公式
    n *= 2;
    h /= 2;
  }
  return i2n;
}

