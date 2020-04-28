#include <iostream.h>

class Complex{
public:
  Complex(double r=0, double v=0):real(r),virt(v){}
  friend Complex operator+(Complex a, Complex b);
	friend ostream& operator<<(ostream& out, Complex& a);
private:
  double real;
  double virt;
};

ostream& operator<<(ostream& out, Complex& a){ return out <<a.real <<"+" <<a.virt <<"i\n"; }

Complex operator+(Complex a, Complex b)
{
  return Complex(a.real+b.real, a.virt+b.virt);
}


void main()
{
  Complex a(2,5), b(7,8), c(0,0);
  c = a + b;
  cout <<c;
  c = 4.1 + a;
  cout <<c;
  c = b + 5.6;
  cout <<c;
}

     

