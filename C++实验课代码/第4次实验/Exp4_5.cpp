//4.5

#include <iostream>
using namespace std;

int main()
{
	float sum=100,height=50;
	int i,n;
	cout<<"您想了解第几次落地和反弹的情况"<<endl;
	cin>>n;
	if(n==1)
	{
		cout<<"第1次下落经过"<<sum<<"m"<<endl;
		cout<<"第1次反弹"<<height<<"m"<<endl;
	}
	else
	{
		for(i=2;i<=n;i++)
		{
			sum+=2*height;
			height=height/2;
		}
		cout<<"第"<<i-1<<"次下落经过"<<sum<<"m"<<endl;//i-1 用于检验是否计算到了第n次 
		cout<<"第"<<i-1<<"次反弹"<<height<<"m"<<endl;
	}
	
	return 0;
}
