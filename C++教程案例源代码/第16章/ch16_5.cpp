//**********************
//**    ch16_5.cpp    **
//**********************

#include <iostream.h>

class Base{
public:
  virtual Base* afn()
  {
    cout <<"This is Base class.\n";
    return this;
  }
};

class SubClass :public Base{
public:
  SubClass* afn()
  {
    cout <<"This is SubClass.\n";
    return this;
  }
};

void test(Base& x)
{
  Base* b;
  b = x.afn();
}

void main()
{
  Base bc;
  SubClass sc;
  test(bc);
  test(sc);
}
