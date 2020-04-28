//5.3

#include <iostream>
#include <iomanip>
using namespace std;

void multiTab_full();
void multiTab_left();
void multiTab_right();

int main()
{
	multiTab_full();
	multiTab_left();
	multiTab_right();
	
	return 0;
}

void multiTab_full()
{
	cout<<"  *";
	for(int i=1;i<=9;i++)
		cout<<setw(4)<<i;
	cout<<"\n-----------------------------------------\n";

	for(int j=1;j<=9;j++)//控制输出的行，共9行
	{
		cout<<setw(3)<<j;
		for(int k=1;k<=9;k++)//控制输出的每一行中的每一项
			cout<<setw(4)<<j*k;
		cout<<endl;//每输出完一行后，要换行准备输出下一行
	}
	cout<<endl;
}

void multiTab_left()
{
	cout<<"  *";
	for(int i=1;i<=9;i++)
		cout<<setw(4)<<i;
	cout<<"\n-----------------------------------------\n";

	for(int j=1;j<=9;j++)//控制输出的行，共9行
	{
		cout<<setw(3)<<j;
		for(int k=1;k<=j;k++)//与(1)相比，修改此循环继续条件→第n行，输出n个数；控制输出的每一行中的每一项
			cout<<setw(4)<<j*k;
		cout<<endl;//每输出完一行后，要换行准备输出下一行
	}
	cout<<endl;
}

void multiTab_right()
{
	cout<<"  *";
	for(int i=1;i<=9;i++)
		cout<<setw(4)<<i;
	cout<<"\n-----------------------------------------\n";

	for(int j=1;j<=9;j++)//控制输出的行，共9行
	{
		cout<<setw(3)<<j;
		int k=1;
//		/*
		for(;k<j;k++)//控制输出的每一行中的每一项
			cout<<setw(4)<<" ";//第n行，输出n-1个空格，所以继续条件设为k<j
		for(;k<=9;k++)
			cout<<setw(4)<<j*k;
//		*/

		/*
		if(j!=1)
			cout <<setw(4*j-4) <<" ";//第n行，输出n-1个空格 setw(4) 4倍的n-1
		for (k=j;k<=9;k++)
			cout<<setw(4)<<j*k;
		*/
		cout<<endl;//每输出完一行后，要换行准备输出下一行
	}
	cout<<endl;
}

