#include <iostream.h>
#include <math.h>

void main()
{
  double sum=1, t=-1, x;
  cout <<"please input a value:\n";
  cin >>x;
  int i=1;
  while(fabs(t)>1e-8){
    t*=(-1)*x/i;
    sum+=t;
    i++;
  }
  cout <<"sum=" <<sum<<endl;
}