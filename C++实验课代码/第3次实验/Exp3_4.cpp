//3.1

#include <iostream>
//#include <cmath>
#include <math.h>
using namespace std;

int main()
{
	double x,a,c,y1,y2,y3;
	const double pi=3.1415;
	
	cout<<"please input x:"<<endl;
	cin>>x;
	if(pow(sin(x),2.5)>=0)
		y1=sqrt(pow(sin(x),2.5));	//幂指数原型
	cout<<"y1="<<y1<<endl;

	cout<<"please input x,a:"<<endl;
	cin>>x>>a;
	y2=(a*x+(a+x)/(4*a))/2;//优先级 相乘用*
	cout<<"y2="<<y2<<endl;

	cout<<"please input x,c:"<<endl;
	cin>>x>>c;
	y3=pow(c,x*x)/sqrt(2*pi);//常量的定义与初始化
	cout<<"y3="<<y3<<endl;
	
	return 0;
}
