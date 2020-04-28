//4.10

#include <iostream>
using namespace std;

long cow(int n);

int main()
{
	long x1=1,x2=1,x3=1,sum=0;
	int n;

	cout<<"想了解第几年母牛的情况"<<endl;
	cin>>n;
	
	for(int i=4;i<=n;i++)
	{
		sum=x3+x1;
		x1=x2;
		x2=x3;
		x3=sum;
	}
	
	cout<<"共有母牛"<< x3<<"头"<<endl;//输出x3保证在输出前三年的数值也是正确的 
	cout<<"共有母牛"<<cow(n)<<"头"<<endl;
	return 0;
}
//递归解法 
long cow(int n)
{
	long number;
	if(n==1||n==2||n==3)
		number=1;
	else
		number=cow(n-1)+cow(n-3);
	return number;	
}
