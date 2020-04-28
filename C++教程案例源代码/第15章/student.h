//*********************
//**    student.h    **
//*********************
#ifndef STUDENT
#define STUDENT

class Student{
public:
  Student(char* pName ="no name");
 ~Student();
  static int number();     //¾²Ì¬³ÉÔ±º¯Êý
protected:
  static int noOfStudents;
  char name[40];
};

#endif
