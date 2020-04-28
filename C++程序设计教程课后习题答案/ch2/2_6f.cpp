//2_6f
#include <iostream.h>
#include <iomanip.h>
#include <math.h>

float area(float a, float b, float c); //函数声明

void main()
{
  float a,b,c;
  cout <<"please input 3 sides of one triangle:\n";
  cin >>a >>b >>c;   //输入时以空格作为数据间隔

  float result = area(a,b,c);          //函数调用

  cout <<setiosflags(ios::fixed) <<setprecision(2)
       <<"a=" <<setw(7) <<a
       <<",b=" <<setw(7) <<b
       <<",c=" <<setw(7) <<c <<endl;
  cout <<"area of triangle is " <<setw(10)
       <<setprecision(5) <<result <<endl;
}

float area(float a, float b, float c)  //函数定义
{
  float s=(a+b+c)/2;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}

