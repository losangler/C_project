#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n,i,j;
	cout<<"请确定矩阵规模："<<endl;
	cin>>n;
	
	int **array=new int*[n];   //?
	for(i=0;i<n;i++)	
		array[i]=new int[n];   //?
		
	cout<<"请输入"<<n<<"阶矩阵的具体数据"<<endl;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>array[i][j];
	
	cout<<"输入的"<<n<<"阶矩阵的具体数据为"<<endl;
	for(i=0;i<n;i++)
	{ 
		for(j=0;j<n;j++)
			cout<<setw(6)<<array[i][j];
		cout<<endl; 
	}
	
	//计算两条对角线元素之和
	int sum=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)//左对角线 
				sum+=array[i][j];
			if((i+j)==(n-1))//右对角线 
				sum+=array[i][j];
		}
	}
	
	if(n%2!=0)
		sum-=array[(n-1)/2][(n-1)/2];//若规模为奇数，则交叉点处的数值被重复计算 
	
	cout<<"两条对角线的和为"<<sum<<endl; 
	
	return 0;	
}
