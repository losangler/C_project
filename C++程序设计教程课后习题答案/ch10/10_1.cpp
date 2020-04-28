//10_1

#include <iostream.h>
struct Student{
  int mathmidterm;
  int mathfinal;
};

void main()
{
  Student s;
  cout <<"please input midterm and final math\n"
       <<"grade of a student:\n";
  cin >>s.mathmidterm >>s.mathfinal;

  cout <<"the average grade of midterm and final math is "
       <<(s.mathmidterm + s.mathfinal)/2.0 <<endl;
}
