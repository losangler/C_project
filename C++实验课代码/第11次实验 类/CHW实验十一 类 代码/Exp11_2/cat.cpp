//cat.cpp-类实现（成员函数的定义） 
#include "cat.h"

int Cat::GetAge()
{
	return itsAge;
}

void Cat::SetAge(int age)
{
	itsAge=age;
}

void Cat::Meow()
{
	cout<<"Meow.\n";
}
