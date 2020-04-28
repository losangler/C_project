//7.6
#include <iostream>
using namespace std;

void max(int score[][4],int pupil,int test);
void fail(int score[][4],int pupil,int test);
void average(int score[],int size);
void average(int score[][4],int pupil,int test);


int main()
{
	/*
	int array[5][4]={{23,98,65,96},
					{76,64,93,100},
					{91,88,99,43},
					{60,90,77,59},
					{32,55,90,70}};
	*/

	///*
	int array[][4]={{23,98,100,96},
					{76,100,93,100},
					{91,88,99,43},
					{60,100,77,59},
					{32,55,90,70}};
	//*/
	max(array,5,4);
	fail(array,5,4);
	//average(array[0],20);
	//average(&array[0][0],20);
	average(array,5,4);
	
	return 0;
}

void max(int score[][4],int pupil,int test)
{	
	int i,j,max=score[0][0];
	for(i=0;i<pupil;i++)
		for(j=0;j<test;j++)
			if(score[i][j]>max)
				max=score[i][j];

	for(i=0;i<pupil;i++)//不止一个学生是最高分
		for(j=0;j<test;j++)
		{
			if(score[i][j]==max)
			{
				cout<<"第"<<i+1<<"学生"<<"，"
					<<"第"<<j+1<<"门成绩"
					<<"是最高分"<<endl;
			}			
		}

	/*//最高分仅有一个的情况：
	int p=0,t=0;
	for(i=0;i<pupil;i++)
		for(j=0;j<test;j++)
			if(score[i][j]>score[p][t])
			{	
				p=i;
				t=j;				
			}*/
	/*
	cout<<"第"<<p+1<<"学生"<<"，"
		<<"第"<<t+1<<"门成绩"
		<<"是最高分";
	*/  	

	cout<<endl;
}

void fail(int score[][4],int pupil,int test)
{
	for(int i=0;i<pupil;i++)
		for(int j=0;j<test;j++)
		{
			if(score[i][j]<60)
			{
				cout<<"不及格的学生编号是"<<i+1<<", "
					<<"ta的4门课成绩为：";
				for(int k=0;k<test;k++)
					cout<<score[i][k]<<",";
				cout<<endl;
				break;//若有一门以上成绩不及格，此语句可避免重复检查
			}		
		}	
}

void average(int score[],int size)//所有课程的总平均分 
{
	int sum=0;
	for(int i=0;i<size;i++)
		sum+=score[i];

	cout<<"平均分为："<<sum/double(size)<<endl;

}

void average(int score[][4],int pupil,int test)
{
	int sum;
	for(int i=0;i<test;i++)//每一门课的平均成绩，需要取出不同学生的某一门课的成绩
	{
		sum=0;
		for(int j=0;j<pupil;j++)
			sum+=score[j][i];
		cout<<"第"<<i+1<<"门课的平均分为："<<sum/double(pupil)<<endl;
	}
		
}

