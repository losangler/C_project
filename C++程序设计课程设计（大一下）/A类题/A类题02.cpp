#include <iostream>
using namespace std;
/*
31.
编写程序，从键盘输入任意两个数和一个运算符
（+、-、*、/），计算其运算的结果并输出
*/
void choice(char symbol); 
    double a,b;
	char symbol;
	bool  isRightSymbol=true;
int main(){
	cout<<"输入两个数："; 
	cin>>a>>b;
	cout<<"输入运算符（+、—、*、/)：";
    cin>>symbol; 
//    choice(symbol);
//    while(!isRightSymbol){
//    cout<<"未知运算符，请重新输入：" ; 
//	cin>>symbol; 
//    choice(symbol);
//	}
    
	switch(symbol){
	case '+':
	cout<<a<<" + "<<b<<" = "<<a+b<<endl;
	break;	
	case '-':
	cout<<a<<" - "<<b<<" = "<<a-b<<endl;
	break;
	case '*':
	cout<<a<<" * "<<b<<" = "<<a*b<<endl;
	break;	
	case '/':
	cout<<a<<" / "<<b<<" = "<<a/b<<endl;
	break;
	default:
	isRightSymbol=false;
	cout<<"未知运算符！无法判断计算！";
	break;
	}
}
//void choice(char symbol){
//	switch(symbol){
//	case '+':
//	cout<<a<<" + "<<b<<" = "<<a+b<<endl;
//	break;	
//	case '-':
//	cout<<a<<" - "<<b<<" = "<<a-b<<endl;
//	break;
//	case '*':
//	cout<<a<<" * "<<b<<" = "<<a*b<<endl;
//	break;	
//	case '/':
//	cout<<a<<" / "<<b<<" = "<<a/b<<endl;
//	break;
//	default:
//	isRightSymbol=false;
//}
//}
