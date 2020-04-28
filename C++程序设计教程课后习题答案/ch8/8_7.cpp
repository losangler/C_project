//8_7

#include <iostream.h>

int strcmp(const char* str1, const char* str2);

void main(int argc, char*argv[])
{
  if(argc!=3){
    cout <<"usage: c:>8_7 string1  string2\n";
    return;
  }
  int result = strcmp(argv[1],argv[2]);
  char c='=';
  if(result>0) c='>';
  if(result<0) c='<';
  
  cout <<argv[1] <<c <<argv[2] <<endl;
}

int strcmp(const char* str1, const char* str2)
{
  char* p1=(char*)str1;
  char* p2=(char*)str2;
  while(*p1 && *p1==*p2){
    p1++; p2++;
  }
  return *p1 - *p2;
}