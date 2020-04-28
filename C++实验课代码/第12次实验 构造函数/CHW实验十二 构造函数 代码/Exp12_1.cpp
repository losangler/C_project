//12.1

#include <iostream>
using namespace std;

class MyClass
{
public :
	MyClass();
	MyClass(int);
	~MyClass();
	void Display();
protected:
	int number;
};

MyClass::MyClass()
{
	cout<<"Constructing normally\n";
}

MyClass::MyClass(int m)
{
	number=m;
	cout<<"Constructing with a number: "<<number<<endl;
}

void MyClass::Display()
{
	cout<<"Display a number: "<<number<<endl;
}

MyClass::~MyClass()
{
	cout<<"Destructing\n";
}

int main()
{
	MyClass obj1;//无参构造函数
	MyClass obj2(20);//有参构造函数obj2.number=20;

	obj1.Display();//随机值
	obj2.Display();//20
	return 0;
}//两次析构函数
