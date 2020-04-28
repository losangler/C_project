//8.5

#include <iostream>
using namespace std;

int strcmp(const char * str1,const char * str2);        //const表示char型内容不能改，只能用 

int main()
{
	char *ch1,*ch2;
	int num;
	
	cout<<"第一个字符串的长度："<<endl;
	cin>>num;
	if((ch1=new char[num+1])==NULL)           //ch1是指针，没有分配空间，无法存放被分配的内容，所以new一下，申请分配内存。 
	{
		cout<<"failed!"<<endl;
		exit(1);
	}

	cout<<"请输入第一个字符串："<<endl;
	cin>>ch1;
	//cout<<"输入的是："<<ch1<<endl; 

	cout<<"第二个字符串的长度："<<endl;
	cin>>num;
	if((ch2=new char[num+1])==NULL)
	{
		cout<<"failed!"<<endl;
		exit(1);
	}

	cout<<"请输入第二个字符串："<<endl;
	cin>>ch2;/**/
	//cout<<"输入的是："<<ch2<<endl; 
	
/*
	char *ch1,*ch2;
	//cin>>ch1>>ch2;//不可
	
	ch1="ab";
	ch2="abfde";
*/
	cout<<strcmp(ch1,ch2)<<endl;

	delete [] ch1;
	delete [] ch2;/**/
	
	return 0;
}

int strcmp(const char *str1,const char * str2)//间接引用不得修改
{
	while(*str1&&*str2&&(*str1==*str2))//str1和str2不等于\0时（即\0以外的其他字符）字符相等时，一直循环，直至找到不相等的字符为止；==优先级高于&&；while((*str1!='\0')&&(*str2!='\0')&&(*str1==*str2))
	{                                  //循环结束条件是：不满足三个的任一个 。比较字符串，可以理解为：先比较长度。 
		str1++;
		str2++;
	}
	return *str1-*str2;
	//abc  ad
	//ad   abc
	//abc  ab
	//ab   abc  均不需要判断是否为'\0'
	//ab   ab   则需要判断'\0',否则while循环继续，并且下标会越界
}
