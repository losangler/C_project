//**********************
//**    ch12_5.cpp    **
//**********************

#include <iostream.h>
#include <string.h>

class Student{
public:
  Student(char* pName, int xHours, float xgpa)
  {
    cout <<"constructing student " <<pName <<endl;    strncpy(name,pName,sizeof(name));
    name[sizeof(name)-1]='\0';
    semesHours=xHours;
    gpa=xgpa;
  }
  ~Student()
  {
    cout <<"destructing " <<name <<endl;
  }
//其他公共成员
protected:
  char name[20];
  int semesHours;
  float gpa;
};

void main()
{
  Student ss("Jenny",22,3.5);
  //...
}
