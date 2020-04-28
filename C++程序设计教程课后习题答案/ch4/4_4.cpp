#include <iostream.h>

void main()
{
  for(int i=1; i<1000; i++){
    int sum=0;
    for(int j=1; j<=i/2; j++)
      if(i%j==0)
        sum+=j;
    if(sum==i)
      cout <<i<<"ÊÇÍêÊý.\n";
  }
}

