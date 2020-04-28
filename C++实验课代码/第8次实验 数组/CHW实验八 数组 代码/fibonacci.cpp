#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
	int fib[20]={1,1};
	int i;
	
	for(i=2;i<20;i++)
		fib[i]=fib[i-1]+fib[i-2];
	
	//打印 避免第一行就换行 
	for(i=0;i<20;)
	{
		cout<<setw(6)<<fib[i];
		i++;
		if(i%5==0)
			cout<<endl;
	}
	
	return 0;	
}
