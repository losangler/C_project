//4.9(3) 

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout<<"  *";
	for(int i=1;i<=9;i++)
		cout<<setw(4)<<i;
	cout<<"\n-----------------------------------------\n";

	for(int j=1;j<=9;j++)//控制输出的行，共9行
	{
		cout<<setw(3)<<j;
		int k=1;
	//	/*
		for(;k<j;k++)//控制输出的每一行中的每一项
			cout<<setw(4)<<" ";//第n行，输出n-1个空格，所以继续条件设为k<j
		for(;k<=9;k++)
			cout<<setw(4)<<j*k;
	//	*/

		/*
		if(j!=1)
			cout <<setw(4*j-4) <<" ";//第n行，输出n-1个空格 setw(4) 4倍的n-1
		for (k=j;k<=9;k++)
			cout<<setw(4)<<j*k;
		*/
		cout<<endl;//每输出完一行后，要换行准备输出下一行
	}
	return 0;
}
