//7.2

#include <iostream>
using namespace std;

int insert(int array[],int size,int insertNum);

int main()
{
	int a[]={15,22,34,43,56,69,72,89,91,102};
	int n=sizeof(a)/sizeof(*a);

	int value;
	cout<<"请输入要插入的数值:";
	cin>>value;

	cout<<"插入前的数组："<<endl;
	int i;
	for(i=0;i<n;i++)
		cout<<"a["<<i<<"]= "<<a[i]<<endl;
	
	cout<<endl;

	cout<<"被挤出的最大数为："<<insert(a,n,value)<<endl;

	cout<<"插入后的数组："<<endl;
	for(i=0;i<n;i++)
		cout<<"a["<<i<<"]= "<<a[i]<<endl;
		
	return 0;
}

int insert(int array[],int size,int insertNum)
{
	if(insertNum>=array[size-1])//当插入的数大于等于数组中的最后一个元素值，则被挤出的最大数为插入数
		return insertNum;

	//若不满足以上情况，则被挤出的最大数为，原数组中的最后一个元素
	int temp=array[size-1];
	int j;	
	for (j=size-2;j>=0 && array[j]>insertNum;j--)//从后向前比较，找出insertNum插入的位置
	{
		array[j+1]=array[j];//大数后移
	}

	array[j+1]=insertNum;

	return temp;
}
