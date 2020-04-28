//**********************
//**    ch12_9.cpp    **
//**********************

#include <string.h>

class Student{
public:
  Student(char* pName)
  {
    strncpy(name,pName,sizeof(name));
    name[sizeof(name)-1]='\0';
  }
  Student(){}
protected:
  char name[20];
};

void main()
{
  Student noName;          //ok
  Student ss("Jenny");     //ok
}
