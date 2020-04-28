#include<iostream>
using namespace std;
/*
57.	设计一个程序根据楼房的长、宽、层数及每平方米单价
    等数据成员，并求楼房的面积及总价等功能
*/
double judge();

int main()
{
	double length,wide,price,area,totalPrice;
	int layers;
	cout<<"请输入楼房的长：";
	cin>>length;
	if(length<=0) length=judge();//法一（解析见下） 
	cout<<"请输入楼房的宽：";
	cin>>wide;
	if(wide<=0) wide=judge();
	cout<<"请输入楼房的层数:";
	cin>>layers;
	if(layers<=0) layers=judge();
	cout<<"请输入楼房的单价:";
	cin>>price;
	if(price<=0) price=judge();
	/*
	法二： 对于错误信息采取全部重新录入：
	优点：相比法一，只需一次整体判断即可 
	缺点：1.不知道自己哪个数据输错了
	      2.对于录入正确的数据还要再次输入，繁琐且又可能输错 
	while(length<=0||wide<=0||layers<=0||price<=0){
	cout<<"输入错误！请重新录入信息："
	cout<<"请输入楼房的长：";
	cin>>length;
	cout<<"请输入楼房的宽：";
	cin>>wide;
	cout<<"请输入楼房的层数:";
	cin>>layers;
	cout<<"请输入楼房的单价:";
	cin>>price;
	}
	*/
	area=length*wide*layers;//楼房的总面积 
	totalPrice=area*price;//总价=总面积*单价 
	cout<<"--------------------------------"<<endl;
	cout<<"楼房面积为：\t"<<area<<endl;
	cout<<"总价为： \t"<<totalPrice<<endl;
}
 
 /*
 法一：调用judge函数
 优点：明确自己哪个数据录入错误，只需更改录入错误的信息即可
       相比法二，对于正确的信息不用再次录入
 缺点：每录入一个信息都要进行一次判断	    
 */ 
 
 double judge(){
	double  rightNum=0;
	while(rightNum<=0){
		cout<<"该数据录入错误！请重新录入：";
		cin>>rightNum; 
	} 
	return rightNum;
}
