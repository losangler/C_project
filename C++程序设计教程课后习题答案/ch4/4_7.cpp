#include <iostream.h>
#include <math.h>

void main()
{
  double x, a;
  cout <<"please input a value:\n";
  cin >>a;
  x = a/2;
  while(fabs((x-a/x)/2)>1e-7)
    x=(x+a/x)/2;

  cout <<a <<"的平方根是" <<x <<endl;
}
