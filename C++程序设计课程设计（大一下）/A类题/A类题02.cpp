#include <iostream>
using namespace std;
/*
31.
��д���򣬴Ӽ�������������������һ�������
��+��-��*��/��������������Ľ�������
*/
void choice(char symbol); 
    double a,b;
	char symbol;
	bool  isRightSymbol=true;
int main(){
	cout<<"������������"; 
	cin>>a>>b;
	cout<<"�����������+������*��/)��";
    cin>>symbol; 
//    choice(symbol);
//    while(!isRightSymbol){
//    cout<<"δ֪����������������룺" ; 
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
	cout<<"δ֪��������޷��жϼ��㣡";
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
