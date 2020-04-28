//8.6

#include <iostream>
using namespace std;

char * my_strcpy(char * dest, const  char * source);

int main()
{
	char ch1[100];//="abczzzzzz";//abc//{'a','b','c','d','e','f'} 
	char ch2[]="eeeee";//也可用cin>>ch2;			

	//char *ch1="abc";
	//char *ch2="abdef";

	cout<<my_strcpy(ch1,ch2)<<endl;
	
	return 0;	
}

char *my_strcpy(char * dest,const char *source)
{
	//char * src=(char *)source;//为防止*source值被改变，可以考虑加这一句			
	char *pdest=dest;//需要保留dest参数中的地址，即ch1的首地址，否则后面dest地址一直自增， 
	                  //返回的地址是复制的最后一个字符后的地址，不能返回所有复制字符
	//while(*pdest && *source)//若dest和source中均不为\0则继续复制，此为优化，防止pdest中溢出   
	while(*source)//但pdest中若没有内容，则要求这样写 
		*(pdest++)=*(source++);	
	
	//while(*pdest)//strcpy是覆盖的效果，因此若从source中获取字符后，dest中还有残留的字符，则用\0替换 
		*pdest='\0';//*pdest++='\0';		
			
	return dest;
}
