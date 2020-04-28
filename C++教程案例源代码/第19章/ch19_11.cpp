//***********************
//**    ch19_11.cpp    **
//***********************

#include <iostream.h>
#include <ctype.h>

void main()
{
  char letter;

  while(!cin.eof()){
    letter =cin.get();
    letter =toupper(letter);
    if(letter=='Y'){
      cout <<"'Y' be met.";
      break;
    }
    cout <<letter;
  }
}
