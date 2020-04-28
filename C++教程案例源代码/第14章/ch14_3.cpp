//**********************
//**    ch14_3.cpp    **
//**********************

#include <iostream.h>
#include <string.h>

class Person{
public:
  Person(char* pN)
  {
    cout <<"Constructing " <<pN <<endl;
    pName=new char[strlen(pN)+1];
    if(pName!=0)
      strcpy(pName,pN);
  }

  ~Person()
  {
    cout <<"Destructing " <<pName <<endl;
    pName[0]='\0';
    delete pName;
  }
protected:
  char* pName;
};

void main()
{
  Person p1("Randy");
  Person p2=p1;       //¼´Person p2(p1);
}
