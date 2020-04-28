//15_3

#include <iostream.h>

class Boat;

class Car{
public:
  Car(int j){ size =j; }
  int Get(){ return size; }
protected:
  int size;
};

class Boat{
public:
  Boat(int j){ size =j; }
  int Get(){ return size; }
protected:
  int size;
};

int Leisure(int time, Car& aobj, Boat& bobj)
{
  return time * aobj.Get() * bobj.Get();
}

void main()
{
  Car c1(2);
  Boat b1(3);
  int time =4;
  cout <<Leisure(time,c1,b1);
}
