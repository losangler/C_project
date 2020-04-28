//让用户输入一行字符（空格分隔的多个单词），然后输出每一个单词（每行一个单词）。
#include <iostream>
#include <cstring>
using namespace std;

int main()
{

/*	//算法1 
	char ch;             
    while(cin.get(ch))     
	//while(cin.get(ch) && ch != '\n')          //用cin>>不识别回车，\n等于用回车结束循环。 
	{
		if(ch==' ')	
		{
			cout<<endl;
			continue; //若是空格就结束本次循环，不输出空格，然后继续进入下一次while循环 
		}			
		cout<<ch;		
	}
	//*/
	
	
	//算法2 
	char ch[100];
	cout<<"请输入字符串："<<endl;
	//cin>>ch;                      //cin不识别空格       
	cin.getline(ch,100); 
	cout<<ch<<endl;                 // 字符串可以直接cout.因为字符串是以\0结束的，不是以空格结束，所以可以输出空格 
	cout<<strlen(ch)<<endl;          // strlen函数是库函数，对应库函数 cstring
		
	for(int i=0;i<strlen(ch);i++)    
	{
		if(ch[i]==' ')
		{
			cout<<endl;			
			continue;//结束本次循环体，直接进入for循环的i++;目的：空格不输出，所以i加1，获取空格后面的字符继续。 
		}			
		cout<<ch[i];		
	}
	
	
	/*
	//算法3 类 
	string s;            // 
	getline(cin,s);	
	
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==' ')//if(s.at(i)==' ')
		{
			cout<<endl;
			continue;
		}			
		cout<<s[i];//s.at(i);
	} 
	cout<<endl;	
	*/

	return 0; 
}
