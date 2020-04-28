//4.4

#include <iostream>
using namespace std;

int main()
{
	for(int i=1;i<=1000;i++)
	{
		int sum=0;//sum的初始化很重要
		for(int j=1;j<=i/2;j++)  //j遍历到一半即可。 
		{
				if(i%j==0)
				sum+=j;//sum=sum+j; 
			}
		if(sum == i)
			cout<<i<<"是完数"<<endl;
	}
	
	return 0;	
}
