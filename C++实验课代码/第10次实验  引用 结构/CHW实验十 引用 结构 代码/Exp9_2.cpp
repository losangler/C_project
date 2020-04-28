#include <iostream>
using namespace std;

int & put(int n);//放入数组中  如果函数返回一个int型（别的返回类型也可）的引用，可以作为左值被赋值。
int get(int n);//取出数据 

int vals[10];
int error=-1;//作为越界时的处理 
 
int main()
{
	put(0)=10;
	put(1)=20;
	put(9)=30;
	
	cout<<get(0)<<endl;
	cout<<get(1)<<endl;
	cout<<get(9)<<endl;
	
	put(12)=1;
	
	return 0;
}

int & put(int n)
{
	if(n>=0&&n<10)
		return vals[n];
	else
	{
		cout<<"range error in put() value!"<<endl; 
		return error; 
	}
		
}

int get(int n)
{
	if(n>=0&&n<10)
		return vals[n];
	else
		return error;
}
