#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
public:
	Employee(const char *n,const char *a,const char *c,const char *p,const char *code);
	void ChangeName(const char *);
	void Display();
	
protected:
	char name[10];
	char address[10];
	char city[10];
	char province[10];
	char postcode[10];
		
};

Employee::Employee(const char *n,const char *a,const char *c,const char *p,const char *code)
{
	strncpy(name,n,sizeof(name));
	strncpy(address,a,sizeof(address));
	strncpy(city,c,sizeof(city));
	strncpy(province,p,sizeof(province));
	strncpy(postcode,code,sizeof(postcode));
	name[sizeof(name)-1]='\0';
	address[sizeof(address)-1]='\0';
	city[sizeof(city)-1]='\0';
	province[sizeof(province)-1]='\0';
	postcode[sizeof(postcode)-1]='\0';	
}

void Employee::ChangeName(const char *n)
{
	strncpy(name,n,sizeof(name));
	name[sizeof(name)-1]='\0';
}

void Employee::Display()
{
	cout<<name
		<<"住在"<<address<<"街"
		<<city<<"市"
		<<province<<"省"
		<<"邮政编码为" <<postcode<<endl;
}

int main()
{
	Employee e("chw","Jilin","Zhuhai","Guangdong","519041");
	e.Display();
	e.ChangeName("CHW");
	e.Display();
}
