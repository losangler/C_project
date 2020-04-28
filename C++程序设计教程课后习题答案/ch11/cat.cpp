//cat.cpp

#include "cat.h"

int Cat::GetAge()
{
  return itsAge;
}

void Cat::SetAge(int age)
{
  itsAge=age;
}

void Cat::Meow()
{
  cout <<"Meow.\n";
}
