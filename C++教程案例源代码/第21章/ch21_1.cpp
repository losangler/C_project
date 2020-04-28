//**********************
//**    ch21_1.cpp    **
//**********************
#include <fstream.h>
#include <iostream.h>
#include <stdlib.h>

void main(int argc, char ** argv)
{
  ifstream source(argv[1]);      //打开文件
  char line[128];
  try{
    if(source.fail())
      throw argv[1];
  }
  catch(char* s)
  {
    cout <<"error opening the file "<<s <<endl;    exit(1);
  }

  while(!source.eof()){
    source.getline(line, sizeof(line));
    cout <<line <<endl;
  }
  source.close();
}