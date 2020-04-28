//20_1.cpp

#include <iostream.h>
#include <string.h>

template<class T>
T min(T& a, T& b)
{
  return a>b?b:a;
}

char* min(char* a, char* b)
{
  return (strcmp(a, b)>0 ? b: a);
}

void main()
{
  cout <<min("Hello", "Good") <<endl;
  cout <<min(3,8) <<endl;
}
