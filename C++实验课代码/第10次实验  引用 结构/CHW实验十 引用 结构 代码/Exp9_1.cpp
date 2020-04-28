#include <iostream>
using namespace std;

const int asize=10;

void findmax(int *a, int num, int i, int *pk);
void findmax(int *a,int num,int &index); 

int main()
{
	int a[asize];
	int index=0;             //下标 
	int count=0; 
	cout<<"please input "<<asize<<" data:\n";	 
	
//	for(int i=0;i<size;i++)	
//		cin>>a[i];//可通过ctrl+z终止输入		
//	
//	//findmax(a,size,0,&index); //原题 
//	findmax(a,size,index);	
	
	///*
	for(int i=0;i<asize&&cin>>a[i];i++)//以回车终止输入
		count++;//输入少于10个
		
	
	findmax(a,asize,index);	//findmax(a,count,index);
    //*/findmax(a, asize, 0, &index);
	
	cout<<"the maximum is "<<a[index]<<endl
		<<"It's index is "<<index<<endl;//保存最大值下标
	
	return 0; 
}

void findmax(int *a, int num, int i, int *pindex)  //num=asize,i=0,*pk存放最大元素的下标
{
	if(i<num)//i下标从0起，num元素总个数
	{
		if(a[i]>a[*pindex])
			*pindex=i;
		findmax(a,num,i+1,&(*pindex));
	}
}

void findmax(int *a,int num,int &index) //&index本质上是址传递和传递的参数是同一个地址，不需要返回。如果不用引用，用的是值传递，地址是不一样的。
{
	for(int i=0;i<num;i++)
		if(a[i]>a[index])
			index=i;
}
