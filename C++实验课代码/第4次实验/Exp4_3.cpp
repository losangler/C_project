//4.3

#include <iostream>
using namespace std;

int main()
{
	for(int i=1;i<=9;i++)//要求求得三位数的水仙花数，因此百位不能为0
		for(int j=0;j<=9;j++)
			for(int k=0;k<=9;k++)
				if(i*i*i+j*j*j+k*k*k == 100*i+10*j+k )
					cout<<"水仙花数是"<<100*i+10*j+k<<endl;
	
	return 0;
}
