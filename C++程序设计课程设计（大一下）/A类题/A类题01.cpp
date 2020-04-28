#include <iostream>
using namespace std;
/*
A19.	
编写程序，从键盘输入两个整数分别赋值给变量a和b，
将两个变量的值互换并输出
例如：a=1;b=2;  将变量值交换，使得a=2;b=1; 然后输出
*/ 
int main(){
	cout<<"请输入两个整数："<<endl;
	int a,b;
	cin>>a>>b;
	cout<<"------变量值互换------"<<endl;
	cout<<"a="<<a<<"\n"<<"b="<<b<<endl;
	cout<<"互换前："<<"a="<<a<<"\t"<<"b="<<b<<endl;
/*如果是针对题目而言而非逻辑
  直接可以：
	cout<<"互换后："<<"a="<<b<<"\t"<<"b="<<a<<endl;
*/
	//逻辑上的真正进行互换：
	int temp=a;
	a=b;
	b=temp; 
	cout<<"互换后："<<"a="<<a<<"\t"<<"b="<<b<<endl;
	
}
