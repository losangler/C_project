//4.2
#include <iostream>
using namespace std;

int main()
{
	 int sum=0,temp=1;
	//double sum=0,temp=1;
	int i;

	for (i=1;i<=12;i++)
	{
		temp*=i;
		sum+=temp;
	}
	cout<<"sum="<<sum<<endl;
	
	return 0;
}
