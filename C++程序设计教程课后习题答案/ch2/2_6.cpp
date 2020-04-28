//2_6
//  3)

//#include <stdio.h>
#include <iostream.h>
#include <iomanip.h>
#include <math.h>

void main()
{
  float a,b,c,s,area;
  //printf("please input 3 sides of one triangle:\n");
  cout <<"please input 3 sides of one triangle:\n";
  //scanf("%f,%f,%f",&a,&b,&c);  //输入时以逗号作为数据间隔
  cin >>a >>b >>c;   //输入时以空格作为数据间隔

  s=(a+b+c)/2;
  area=sqrt(s*(s-a)*(s-b)*(s-c));

  //printf("a=%7.2f,b=%7.2f,c=%7.2f\n",a,b,c);
  cout <<setiosflags(ios::fixed) <<setprecision(2)
       <<"a=" <<setw(7) <<a
       <<",b=" <<setw(7) <<b
       <<",c=" <<setw(7) <<c <<endl;
  //printf("area of triangle is %10.5f",area);
  cout <<"area of triangle is " <<setw(10)
       <<setprecision(5) <<area <<endl;
}
