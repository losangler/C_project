//11_2

#include "cat.h"

void main()
{
  Cat frisky;
  frisky.SetAge(5);
  frisky.Meow();
  cout <<"frisky is a cat who is "
       <<frisky.GetAge()
       <<" years old.\n";
  frisky.Meow();
}
