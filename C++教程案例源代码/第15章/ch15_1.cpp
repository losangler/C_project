//**********************
//**    ch15_1.cpp    **
//**********************

#include <iostream>
#include <cstring>
using namespace std;
class Student{
public:
  Student(char* pName ="no name")
  {
    cout <<"create one student\n";
    strncpy(name, pName,40);
    name[39]='\0';
    noOfStudents++;            //静态成员：每创建一个对象，学生人数增1
    cout <<noOfStudents <<endl;
  }
  ~Student()
  {
    cout <<"destruct one student\n";
    noOfStudents--;            //每析构一个对象，学生人数减1
    cout <<noOfStudents <<endl;
  }
  static int number()          //静态成员函数
  {
    return noOfStudents;
  }
protected:
  static int noOfStudents;     //若写成noOfStudents=0;则非法
  char name[40];
};
int Student::noOfStudents =0;  //静态数据成员在类外分配空间和初始化

void fn()
{
  Student s1;
  Student s2;
  cout <<Student::number() <<endl;  //调用静态成员函数用类名引导
}
int main()
{
  fn();
  cout <<Student::number() <<endl;  //调用静态成员函数用类名引导
}
