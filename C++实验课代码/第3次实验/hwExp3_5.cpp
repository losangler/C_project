//3.5

#include <iostream>
using namespace std;

int main()
{
	int a,b,c,t,x;
	cout<<"请输入一个整数："<<endl;
	cin>>x;

	a=x%3==0;
	b=x%5==0;
	c=x%7==0;
	t=100*a+10*b+c;

	///*
	//用if语句
	if(t==0)
		cout<<"不能被3,5,7任一个整除"<<endl;
	if(t==100)
		cout<<"只能被3整除"<<endl;
	if(t==10)
		cout<<"只能被5整除"<<endl;
	if(t==1)
		cout<<"只能被7整除"<<endl;
	if(t==110)
		cout<<"能被3，5整除"<<endl;
	if(t==101)
		cout<<"能被3，7整除"<<endl;
	if(t==11)
		cout<<"能被5，7整除"<<endl;
	if(t==111)
		cout<<"能被3，5，7整除"<<endl;
	//*/

    /*
	//用switch语句
	switch (t)
	{
		case 0:   cout<<"不能被3,5,7任一个整除"<<endl;break;
		case 100: cout<<"只能被3整除"<<endl;break;
		case 10:  cout<<"只能被5整除"<<endl;break;
		case 1:   cout<<"只能被7整除"<<endl;break;
		case 110: cout<<"能被3，5整除"<<endl;break;
		case 101: cout<<"能被3，7整除"<<endl;break;
		case 11:  cout<<"能被5，7整除"<<endl;break;
		case 111: cout<<"能被3，5，7整除"<<endl;break;
	}
	*/		
  
	return 0;
}
