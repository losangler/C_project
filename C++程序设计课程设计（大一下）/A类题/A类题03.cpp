#include<iostream>
using namespace std;
/*
57.	���һ���������¥���ĳ�����������ÿƽ���׵���
    �����ݳ�Ա������¥����������ܼ۵ȹ���
*/
double judge();

int main()
{
	double length,wide,price,area,totalPrice;
	int layers;
	cout<<"������¥���ĳ���";
	cin>>length;
	if(length<=0) length=judge();//��һ���������£� 
	cout<<"������¥���Ŀ�";
	cin>>wide;
	if(wide<=0) wide=judge();
	cout<<"������¥���Ĳ���:";
	cin>>layers;
	if(layers<=0) layers=judge();
	cout<<"������¥���ĵ���:";
	cin>>price;
	if(price<=0) price=judge();
	/*
	������ ���ڴ�����Ϣ��ȡȫ������¼�룺
	�ŵ㣺��ȷ�һ��ֻ��һ�������жϼ��� 
	ȱ�㣺1.��֪���Լ��ĸ����������
	      2.����¼����ȷ�����ݻ�Ҫ�ٴ����룬�������ֿ������ 
	while(length<=0||wide<=0||layers<=0||price<=0){
	cout<<"�������������¼����Ϣ��"
	cout<<"������¥���ĳ���";
	cin>>length;
	cout<<"������¥���Ŀ�";
	cin>>wide;
	cout<<"������¥���Ĳ���:";
	cin>>layers;
	cout<<"������¥���ĵ���:";
	cin>>price;
	}
	*/
	area=length*wide*layers;//¥��������� 
	totalPrice=area*price;//�ܼ�=�����*���� 
	cout<<"--------------------------------"<<endl;
	cout<<"¥�����Ϊ��\t"<<area<<endl;
	cout<<"�ܼ�Ϊ�� \t"<<totalPrice<<endl;
}
 
 /*
 ��һ������judge����
 �ŵ㣺��ȷ�Լ��ĸ�����¼�����ֻ�����¼��������Ϣ����
       ��ȷ�����������ȷ����Ϣ�����ٴ�¼��
 ȱ�㣺ÿ¼��һ����Ϣ��Ҫ����һ���ж�	    
 */ 
 
 double judge(){
	double  rightNum=0;
	while(rightNum<=0){
		cout<<"������¼�����������¼�룺";
		cin>>rightNum; 
	} 
	return rightNum;
}
