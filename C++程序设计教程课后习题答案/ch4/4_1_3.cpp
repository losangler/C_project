#include <iostream.h>
#include <math.h>

void main()
{
  double sum=1, t=-1, x;
  cout <<"please input a value:\n";
  cin >>x;

  for(int i=1; fabs(t)>1e-8; i++){
    t*=(-1)*x/i;
    sum+=t;
  }
  cout <<"sum=" <<sum<<endl;
}