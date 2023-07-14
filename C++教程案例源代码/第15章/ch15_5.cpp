//**********************
//**    ch15_5.cpp    **
//**********************

#include <iostream.h>

class Student{
public:
  static int number()
  {
    return noOfStudents;
  }
  //...
protected:
  char name[40];
  static int noOfStudents;
};
int Student::noOfStudents = 1;
void main()
{
  Student s;
  cout <<s.number() <<endl;          //ok 用对象引用静态成员函数  cout <<Student::number() <<endl;   //ok 用类名引导静态成员函数}