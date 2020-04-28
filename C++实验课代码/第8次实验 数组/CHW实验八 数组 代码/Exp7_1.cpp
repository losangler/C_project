#include <iostream>
using namespace std;

int findmin(int[],int);

int main()
{
	int a[]={34,91,83,56,29,93,56,12,88,72};
	int size=sizeof(a)/sizeof(int);
	
	int index=findmin(a,size);
	
	cout<<"最小数为："<<a[index]<<", "
		<<"其下标为："<<index<<endl; 
	
	return 0;	
}

int findmin(int array[],int len)
{
	/*
	//算法1 
	int index=0;
	for(int i=1;i<len;i++)	
		if(array[index]>array[i])
			index=i;
	return index;
	*/
	
	///*
	//算法2 
	int min=array[0];
	int index=0;
	for(int i=1;i<len;i++)
	{
		if(min>array[i])
		{
			min=array[i];
			index=i;
		}
	}
	return index;
	//*/	
}
