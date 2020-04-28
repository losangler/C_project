//5_9

#include <iostream.h>

long cattle(int n);

void main()
{
  int n;
  cout <<"please input a number:\n";
  cin >>n;
  cout <<cattle(n) <<endl;
}

long cattle(int n)
{
  if(n<=0)
    return 0;
  if(n<=3)
    return 1;

  return cattle(n-1)+cattle(n-3);
}


