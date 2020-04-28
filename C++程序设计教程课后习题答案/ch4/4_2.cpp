#include <iostream.h>

void main()
{
  long sum=0, t=1;
  for(int i=1; i<=15; i++){
    t*=i;
    sum+=t;
  }
  cout <<"sum=" <<sum <<endl;
}
