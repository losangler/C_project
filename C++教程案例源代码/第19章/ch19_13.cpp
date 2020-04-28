//***********************
//**    ch19_13.cpp    **
//***********************

#include <fstream.h>
#include <iostream.h>

void main(int argc, char** argv )
{
  ifstream in(argv[1]);
  if(in.fail()){
    cerr <<"Error opening the file: " <<argv[1] <<endl;    return;
  }
  while(!in.eof())
    cout.put(char(in.get()));
  in.close();
}
