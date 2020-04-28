//**********************
//**    ch14_2.cpp    **
//**********************

#include <iostream.h>
#include <string.h>

class Student{
public:
  Student(char* pName="no name")
  {
    cout <<"Constructing new student " <<pName <<endl;    strncpy(name,pName,sizeof(name));
    name[sizeof(name)-1]='\0';
  }

  Student(Student& s)
  {
    cout <<"Constructing copy of " <<s.name <<endl;    strcpy(name,"copy of ");
    strcat(name,s.name);
  }

  ~Student()
  {
    cout <<"Destructing " <<name <<endl;
  }
protected:
  char name[40];
};

class Tutor{
public:
  Tutor(Student& s):student(s)
  {
    cout <<"Constructing tutor\n";
  }
protected:
  Student student;
};

void fn(Tutor tutor)
{
  cout <<"In function fn()\n";
}

void main()
{
  Student randy("Randy");
  Tutor tutor(randy);
  cout <<"Calling fn()\n";
  fn(tutor);
  cout <<"Returned from fn()\n";
}
