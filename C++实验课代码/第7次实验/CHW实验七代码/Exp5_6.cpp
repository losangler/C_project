//5.6

#include <iostream>
using namespace std;

double p(int n,double x);

int main()
{
	int nn;
	double xx,result;

	cout<<"请确定求几阶(n)勒让德多项式的值，并输入一个数(x)： \n";
	cin>>nn>>xx;

	while(nn<0)
	{
		cout<<"阶数(n)必须大于0，请重新输入："<<endl;
		cin>>nn;
	}

	result=p(nn,xx);

	cout<<xx<<"的"<<nn<<"阶勒让德多项式的值为："<<result<<endl;
	
	return 0;
}

double p(int n,double x)
{	
	if (n==0)
		return 1;
	if (n==1)
		return x;
	return ((2*n-1)*x*p(n-1,x)-(n-1)*p(n-2,x))/n;	       
}
//n=2 x=3
//((2*2-1)*3*p(1,3)-1*p(0,3))/2=(9*3-1)/2=13
