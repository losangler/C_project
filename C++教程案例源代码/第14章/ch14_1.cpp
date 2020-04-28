//**********************
//**    ch14_1.cpp    **
//**********************

#include <iostream.h>
#include <string.h>

class Student{
public:
  Student(char* pName="no name",int ssId=0)
  {
    strncpy(name,pName,40);
    name[39]='\0';
    id = ssId;
    cout <<"Constructing new student " <<pName <<endl;  }

  Student(Student& s)        //¿½±´¹¹Ôìº¯Êý
  {
    cout <<"Constructing copy of " <<s.name <<endl;    strcpy(name,"copy of ");
    strcat(name,s.name);
    id=s.id;
  }

  ~Student()
  {
    cout <<"Destructing " <<name <<endl;
  }
protected:
  char name[40];
  int id;
};

void fn(Student s)
{
  cout <<"In function fn()\n";
}

void main()
{
  Student randy("Randy",1234);
  cout <<"Calling fn()\n";
  fn(randy);
  cout <<"Returned from fn()\n";
}
