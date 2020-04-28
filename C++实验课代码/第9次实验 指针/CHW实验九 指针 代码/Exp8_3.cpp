//写一个函数，求字符串的长度，在main函数中输入字符串，并输出其长度。 
#include <iostream>
using namespace std;

int length(char *);               //int length(char *c) 不写*c是因为是声明，可以省略。如果是函数定义就不能省略 

int main() 
{
	char ch[100];        //定义一个字符型数组，存放字符。 
	cout<<"请输入字符串："<<endl;
	//cin>>ch;          //以空格来区分各个主体 ，所以，空格以后的字符不计算在长度内。 
	cin.getline(ch,100);//可输入空格 
	
	cout<<"字符串长度为："<<length(ch)<<endl;
	return 0;
}

int length(char *c )          //char c[];   
{
	int count=0;
	while(*c!='\0')         //*c不是结束符的话，进入循环体 
	{
		count++;            //除了结束符以外的字符计数增1 
		c++;                //继续指向下一个地址
	}
		
	return count;
}
