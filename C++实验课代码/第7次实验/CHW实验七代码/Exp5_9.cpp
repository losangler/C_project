//5.9

#include <iostream>
using namespace std; 

long count(int);

int main()
{
	int n;
	cout<<"请输入年数： \n";
	cin>>n;

	cout<<"第"<<n<<"年共有母牛："<<count(n)<<"头 \n";
	
	return 0;
}

long count(int year)
{
	if(year<=0)
		return 0;
	if(year<=3)
		return 1;
	return count(year-3)+count(year-1);
}
