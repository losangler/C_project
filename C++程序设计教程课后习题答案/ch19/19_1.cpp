#include <iostream.h>
#include <fstream.h>

void main()
{
  char str[128];
	int count=0;
	ifstream fin("19_1.cpp");
	fin.getline(str,sizeof(str));
  while(!fin.eof()){
		count++;
		fin.getline(str,sizeof(str));
	}
	cout <<"the amount of lines of file 19_1.cpp is " <<count <<endl;
}
