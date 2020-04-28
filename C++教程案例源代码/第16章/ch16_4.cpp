//**********************
//**    ch16_4.cpp    **
//**********************

#include <iostream.h>

class Base{
public:
  virtual void fn(int x)
  {
    cout <<"In Base class, int x = " <<x <<endl;  }
};

class SubClass :public Base{
public:
  virtual void fn(float x)
  {
    cout <<"In SubClass, float x = " <<x <<endl;  }
};

void test(Base& b)
{
  int i =1;
  b.fn(i);
  float f =2.0;
  b.fn(f);
}

void main()
{
  Base bc;
  SubClass sc;
  cout <<"Calling test(bc)\n";
  test(bc);
  cout <<"Calling test(sc)\n";
  test(sc);
}
