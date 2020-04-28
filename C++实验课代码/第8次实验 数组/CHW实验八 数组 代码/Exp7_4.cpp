//7.4改进冒泡排序，使之在新一轮的比较中若没有发生元素交换，则认为已排序完毕。 
#include <iostream>
#include <iomanip>
using namespace std;
void bubble(int [],int);
int main()
{
	int len,i,j;
	int *array;      
	
	cout<<"要比较多少个数：";
	cin>>len;

	if((array=new int[len])==NULL)
	{
		cout<<"error!"<<endl;
		exit(1);
		//return 1;
	}

	cout<<"请输入要进行排序的数："<<endl;
	
	i=0;

	while(cin>>array[i])
	{
		i++;			
		if (i==len)
			break;					
	}

	cout<<"排序前为："<<endl;
	for(j=0;j<i;j++)
		cout<<setw(3)<<"array["<<j<<"]= "<<array[j]<<endl;

	bubble(array,i);
	delete[]array;
	
	return 0;
}

void bubble(int a[],int size)
{
	int i,temp,flag;

	//for(int pass=1; pass<size&&flag; pass++) //删掉flag==0的判断 
	for(int pass=1;pass<size;pass++)
	{	
		flag=0;
		for(i=0;i<size-pass;i++)
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				flag++;
			}	
			
		if(flag==0)
			break;
			
		cout<<"第"<<pass<<"趟比较结果：";
		for(i=0;i<size;i++)
			cout<<a[i]<<",";
		cout<<endl;		
	}	
}
