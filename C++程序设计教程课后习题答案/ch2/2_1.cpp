#include <iostream.h>

void main()
{
  //本题原考虑在16位机器上实验目前多为32位机器，故已过时。
  int a = 42486;
  cout <<oct <<a <<endl
       <<hex <<a <<endl;
  unsigned b = 42486;
  cout << dec <<(signed)b <<endl;
}
