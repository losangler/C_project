#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int arrayOne[3][3]={5,7,8,2,-2,4,1,1,1};
	int arrayTwo[3][3]={4,-2,3,3,9,4,8,-1,2};
	int result[3][3]={};
	int i,j;
	
	cout<<"两个矩阵分别为："<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cout<<setw(4)<<arrayOne[i][j];
		cout<<endl; 
	}
	cout<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cout<<setw(4)<<arrayTwo[i][j];
		cout<<endl; 
	}
	cout<<endl; 
	
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			result[i][j]=arrayOne[i][j]+arrayTwo[i][j];
	
	cout<<"两个矩阵的和为："<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cout<<setw(4)<<result[i][j];
		cout<<endl; 
	}
	
	/*
	cout<<"两个矩阵的乘积为："<<endl;
	int sum=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			sum=0;
			for(int k=0;k<3;k++) 
				sum+=arrayOne[i][k]*arrayTwo[k][j];
			result[i][j]=sum;	
		}			
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cout<<setw(4)<<result[i][j];
		cout<<endl; 
	}
	*/
	
	return 0;
}
