//4/8(1)
#include <iostream>
using namespace std;

int main()
{
	for(int n=1;n<=10;n++)//控制输出十行符号
	{
		for(int i=1;i<=10-n;i++)
			cout<<" ";
		for(int j=1;j<=2*n-1;j++)
			cout<<"#";
		cout<<endl;//每输出完一行要换行，进行下一行的输出
	}
		
	return 0;
}
