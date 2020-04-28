//*********************
//**    ch2_4.cpp    **
//*********************

#include <iostream.h>
#include <iomanip.h>

void main()
{
  cout <<setiosflags(ios::right)
       <<setw(5) <<1
       <<setw(5) <<2
       <<setw(5) <<3 <<endl;

  cout <<setiosflags(ios::left)
       <<setw(5) <<1
       <<setw(5) <<2
       <<setw(5) <<3 <<endl;
}
