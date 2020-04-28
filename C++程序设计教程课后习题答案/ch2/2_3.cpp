#include <iostream.h>
#include <iomanip.h>

const double e = 2.718281828;

void main()
{
  cout <<setprecision(10) <<e <<endl
       <<setiosflags(ios::fixed) <<setprecision(8) <<e <<endl
       <<setiosflags(ios::scientific) <<e <<endl;
}


