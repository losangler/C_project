//4.1 第1种解法 

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double sum=1,temp,x;
	cout<<"请输入x的值"<<endl;
	cin>>x;
	
	int n=1;
	double k=x;//分子
	int sign=1;//符号
	double d=1;//分母  若为 int 13!阶乘溢出 存补码 导致temp无限大 double
	temp=x;	
	
	
	/*
	//while语句
	//n=1;
	while(fabs(temp)>1e-8)
	{
		sum+=temp;
		n++;
		k*=x;
		sign*=-1;
		d*=n;
		temp=k*sign/d;				
	}
	*/

	/*
	//do...while语句
	//n=1;
	if(fabs(temp)>1e-8)//防止用户输入进来的x的值小于 1e-8 
	{
		do
		{
			sum+=temp;
			n++;
			k*=x;
			sign*=-1;
			d*=n;
			temp=k*sign/d;
		}while(fabs(temp)>1e-8);
	}		
	*/

	///*
	//for语句	
	for(n=2;fabs(temp)>1e-8;n++)
	{
		sum+=temp;		
		k*=x;
		sign*=-1;
		d*=n;
		temp=k*sign/d;		
	}
	//*/

	cout<<"sum="<<sum<<endl;
	
	return 0;	
}


//	for(int i=1;i<=14;i++)
//	{
//		sign=sign*i;
//		cout<<i<<"!="<<sign<<endl;
//	} 
//	int i=2147483648;12！=479001600 13!=6227020800 
//	cout<<i;
