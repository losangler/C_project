#include <iostream.h>

void main()
{
  int x;
  cout <<"please input x:\n";
  cin >>x;

  if(x<=-1)
    cout <<(x-1) <<endl;
  if(x>-1 && x<=2)
    cout <<2*x <<endl;
  if(2<x && x<=10)
    cout <<x*(x+2);
}
