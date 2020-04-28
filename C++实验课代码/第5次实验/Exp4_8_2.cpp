//4.8(2)
#include <iostream>
using namespace std;

int main()
{
	for(int n=1;n<=8;n++)//控制输出的行数
	{
		for(int i=1;i<=n-1;i++)
			cout<<" ";
		for(int j=1;j<=18-n;j++)
			cout<<"# ";
		cout<<endl;//每完成一行进行换行，进入下一行的输出
	}
	return 0;
}
