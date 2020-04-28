//**********************
//**    ch12_4.cpp    **
//**********************

#include <iostream.h>
#include <string.h>

class Student{
public:
  Student(char* pName)
  {
    cout <<"constructing student " <<pName <<endl;    strncpy(name,pName,sizeof(name));
    name[sizeof(name)-1]='\0';
  }
  ~Student()
  {
    cout <<"destructing " <<name <<endl;
  }
//其他公共成员
protected:
  char name[20];
};

void main()
{
  Student ss("Jenny");
  //...
}
