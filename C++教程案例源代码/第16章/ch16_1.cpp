//**********************
//**    ch16_1.cpp    **
//**********************

#include<iostream.h>
#include<string.h>

class Advisor{
  int noOfMeeting;
};

class Student{
public:
  Student(char* pName ="no name")
  {
    strncpy(name, pName, sizeof(name));
    average =semesterHours = 0;
  }

  void addCourse(int hours, float grade)
  {
    average =(semesterHours*average+grade);      //总分
    semesterHours +=hours;                       //总修学时
    average /=semesterHours;                     //平均分
  }

  int getHours(){return semesterHours;}
  float getAverage(){return average;}

  void display()
  {
    cout <<"name = \"" <<name <<"\""<<", hours = " <<semesterHours         <<", average = " <<average <<endl;
  }
protected:
  char name[40];
  int semesterHours;
  float average;
};

class GraduateStudent :public Student{
public:
  getQualifier(){ return qualifierGrade; }
protected:
  Advisor advisor;
  int qualifierGrade;
};

void main()
{
  Student ds("Lo lee undergrade");
  GraduateStudent gs;
  ds.addCourse (3, 2.5);
  ds.display();
  gs.addCourse(3, 3.0);
  gs.display();
}
