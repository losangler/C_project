#include <iostream>
#include <iomanip>
using namespace std;

int main( )
{
	int a , b, temp;//数据定义部分 
	cout << "a,b = " ;//
	cin >> a >> b;//
	cout<<"a="<<a<<'\t'<<"b="<<b<<endl;
	
	//问题1：操作的部分 
	//temp=a;
	//a=b;
	//b=temp;
	a=b;
	b=a; 
	
	//问题4：'\t'横向制表符setw()，endl换行，用'\n'
	cout<<"a="<<a<<'\t'<<"b="<<b<<endl; 
	//cout<<setiosflags(ios::left)<<"a="<<setw(6)<<a<<"b="<<setw(6)<<b<<endl; 
	//cout<<"1234567812345678"<<endl;
	
	return 0;
}
/*
问题2： 输入3和10，输出结果互换
问题3： 输入3和10，输出结果为a=10,b=10 
*/
 

