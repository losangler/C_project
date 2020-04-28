//cat.h-类定义的头文件 
#include <iostream>
using namespace std;

class Cat
{
public:
	int GetAge();
	void SetAge(int age);
	void Meow();
protected:
	int itsAge;
};
