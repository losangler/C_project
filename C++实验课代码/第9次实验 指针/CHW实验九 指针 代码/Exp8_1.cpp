//8.1

#include <iostream>
using namespace std;

int* findmax(int * array, int size, int* index);  //返回了一个int型的指针。int * array=int array[] 

int main()
{
	int a[]={33,91,54,67,82,37,85,63,19,68};
	int *maxaddr;//存放最大元素的地址
	int idx;//元素下标

	maxaddr=findmax(a,sizeof(a)/sizeof(*a),&idx); //常用的二种计算数组长度的写法 

	cout<<"the index of maximum element is "<<idx<<endl
		<<"the address of it is "<<maxaddr<<endl
		<<"the value of it is "<<a[idx]<<endl
		<<&a[1]<<endl;//用于检测maxaddr输出结果是否正确 
	
	return 0;
}

int * findmax(int *array, int size, int* index)
{
	
  //方法1
	*index=0;                       //单独使用*是取值的意思。把0这个序号赋值给地址index指向的空间。 
	for(int i=1;i<size;i++)
		if(array[i]>array[*index])
			*index=i;             
	return &array[*index];/**/   

//  方法2
	/*int max=array[0];
	*index=0;
	for(int i=1;i<size;i++)
	{
		if(array[i]>max)
		{
			max=array[i];
			*index=i;
		}
	}
	//return &max;//错             //max和array的地址不一样。max是一个新的地址，虽然存放的值是一样的，但是地址不一样 
	return &array[*index];*/
}
