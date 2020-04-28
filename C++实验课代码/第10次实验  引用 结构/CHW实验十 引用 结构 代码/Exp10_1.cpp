#include <iostream>
using namespace std;

struct Student
{
	int midScore;              //结构体的成员变量或者结构体的属性。
	int finalScore;	
};

int main()
{
	cout<<"请输入学生的数学期中成绩和期末成绩"<<endl;
	Student stu;   //结构体变量stu
	cin>>stu.midScore>>stu.finalScore;
	
	cout<<"平均成绩为："<<(stu.midScore+stu.finalScore)/2.0<<endl; 
	
	return 0;
}

