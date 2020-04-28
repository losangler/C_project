//从小到大输出3个数

#include<iostream>
using namespace std;

int main()
{
	int a,b,c,temp;
	
	cout<<"please input three numbers;\n";
	cin>>a>>b>>c;
	
	if(a>b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	if(a>c)
	{
		temp=a;
		a=c;
		c=temp;
	}
	if(b>c)
	{
		temp=b;
		b=c;
		c=temp;
	}
	
	cout<<"the result is:"<<a<<" "<<b<<" "<<c<<endl;
	
	return 0;	
}
 
