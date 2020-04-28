//8_9

#include <iostream.h>
#include <alloc.h>

void main()
{
  void* p = malloc(1000000);
  int i=1;
  while(p){
    p = malloc(1000000);
    i++;
  }
  cout <<"¶ÑÈÝÁ¿Îª(M): " <<i <<endl;
}
