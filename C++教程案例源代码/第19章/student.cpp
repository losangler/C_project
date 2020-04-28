//***********************
//**    student.cpp    **
//***********************

#include "student.h"
#include <iomanip.h>
#include <iostream.h>

void Student::display(ostream& out)
{
  out <<setiosflags(ios::left) <<setw(20)<<pName      <<uID <<","
      <<setiosflags(ios::right) <<setw(4) <<grade;}

//²åÈë²Ù×÷·û
ostream& operator<<(ostream& out, Student& st)
{
  st.display(out);
  out <<endl;
  return out;
}
