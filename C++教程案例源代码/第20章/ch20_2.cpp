//**********************
//**    ch20_2.cpp    **
//**********************

#include <iostream.h>
#include <string.h>

template<class T> T max(T a,T b)
{
  return a>b?a:b;
}

char* max(char* a,char* b)
{
  return (strcmp(a,b)?a:b);
}

void main()
{
  cout <<"Max(\"Hello\",\"Gold\") is "
       << max("Hello","Gold") <<endl;
}
