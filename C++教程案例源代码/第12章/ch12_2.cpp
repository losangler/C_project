//**********************
//**    ch12_2.cpp    **
//**********************

#include <iostream.h>

class Student{
public:
  Student()
  {
    cout <<"constructing student.\n";
    semesHours=100;
    gpa=3.5;
  }
  //其他公共成员
protected:
  int semesHours;
  float gpa;
};

class Teacher{
public:
  Teacher()
  {
    cout <<"constructing teacher.\n";
  }
};

class TutorPair{
public:
  TutorPair()
  {
    cout <<"constructing tutorpair.\n";
    noMeetings=0;
  }
protected:
  Student student;
  Teacher teacher;
  int noMeetings;    //会晤次数
};

void main()
{
  TutorPair tp;
  cout <<"back in main.\n";
}
