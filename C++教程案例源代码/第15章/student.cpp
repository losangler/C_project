//***********************
//**    student.cpp    **
//***********************

#include <iostream.h>
#include <string.h>
#include "student.h"
int Student::noOfStudents = 0;      //在此分配空间和初始化
Student::Student(char* pName)
{
  cout <<"create one student\n";
  strncpy(name, pName, 40);
  name[39] = '\0';
  noOfStudents++;                   //静态成员:每创建一个对象,学生人数增1
  cout <<noOfStudents <<endl;
}
Student::~Student()
{
  cout <<"destruct one student\n";
  noOfStudents--;                   //每析构一个对象,学生人数减1
  cout <<noOfStudents <<endl;
}

int Student::number()        //静态成员函数
{
  return noOfStudents;
}
