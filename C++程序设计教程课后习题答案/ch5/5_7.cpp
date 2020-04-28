//5_7

#include <iostream.h>
#include <math.h>

void main()
{
  double x, y;
  x = 3.14159/4;
  do{
    y = x;
    //x-=(cos(x)-x)/(sin(x)-1);
    x = cos(x);
  }while(fabs(x-y)>1e-6);
  cout <<x <<endl;
}
//´ð°¸Îª: 0.739085
