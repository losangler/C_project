//14_3

#include <iostream.h>

class X{
public:
  X(int);
  X(X&);
  ~X();
};

X::X(int s){ cout <<"create a X object with " <<s <<endl; }
X::X(X& x){ cout <<"create a X object from other X object\n"; }
X::~X(){ cout <<"erase a object\n"; }

X f(X x)
{
  cout <<"call a func with para X object\n";
  return x;
}

void main()
{
  X a(1);
  X b=f(X(2));
  a=f(a);
}
