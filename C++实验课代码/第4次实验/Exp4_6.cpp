//4.6

#include <iostream>
using namespace std;

int Peach(int n);

int main()
{
	
	int sum=1;

	for(int i=9;i>=1;i--)
		sum=2*(sum+1);

	cout<<"第一天共摘下"<<sum<<"个桃子"<<endl;
	cout<<"第一天共摘下"<<Peach(1)<<"个桃子"<<endl;
	
	return 0;
}

//递归解法 
int Peach(int n)
{
	if(n==10)
		return 1;
	else
		return 2*(Peach(n+1)+1);
}

