//4.1

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double sum=1,temp,x;
	cout<<"请输入x的值"<<endl;
	cin>>x;
	temp=x;
	int n=1;	
	
	
	///*
	//while语句
	//n=1;
	while(fabs(temp)>1e-8)
	{
		sum+=temp;
		n++;
		temp=temp*(-1)*x/n;		
		
	}
	//*/

	///*
	//do...while语句
	//n=1;
	if(fabs(temp)>1e-8)//防止用户输入进来的x的值小于 1e-8 
	{
		do
		{
			sum+=temp;
			n++;
			temp*=(-1)*x/n;
		}while(fabs(temp)>1e-8);
	}
		
	//*/

	/*
	//for语句
	
	for(n=2;fabs(temp)>1e-8;n++)
	{
		sum+=temp;		
		temp*=(-1)*x/n;		
	}
	*/

	cout<<"sum="<<sum<<endl;
	
	return 0;	
}
