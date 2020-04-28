//编制程序，调用传递引用的参数，实现两个字符串变量的交换 
#include <iostream>
using namespace std;

void change(const char * &a,const char * &b);//是(const char *) &-指针的引用,类比（int） &。&a-引用的是ap,也就是&a是一个ap地址的引用。
int main()
{
	const char *ap="hello";
	const char *bp="how are you?";
	
	cout<<"交换前 \nap:"<<ap<<"\nbp:"<<bp<<endl;
	
	change(ap,bp);	
	cout<<"交换后 \nap:"<<ap<<"\nbp:"<<bp<<endl;
	
	return 0; 
}

void change(const char * &a,const char * &b)
{
	const char *  temp;         //定义要和const char * &a和const char * &b类型一致，否则会报错
	temp=a;
	a=b;
	b=temp; 
} 

