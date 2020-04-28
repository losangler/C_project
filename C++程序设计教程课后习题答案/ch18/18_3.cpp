//18_3.cpp

#include<iostream.h>

class RMB{
public:
  RMB(unsigned d, unsigned c);
  RMB operator+(RMB&)const;
  RMB& operator++();
  void display()const { cout << (yuan + jf/100.0) << endl; }
	RMB operator*(double d) const;
protected:
  unsigned yuan;
  unsigned jf;
};

RMB::RMB(unsigned d, unsigned c)
{
  yuan = d + c / 100;
  jf = c % 100;
}

RMB RMB::operator+(RMB& s) const
{
  unsigned c = jf + s.jf;
  unsigned d = yuan + s.yuan;
  return RMB(d,c);
}
RMB& RMB::operator++()
{
  yuan+=(jf+1)/100;
  jf=(jf+1)%100;
  return *this;
}

RMB RMB::operator*(double d)const
{
  double temp=(yuan+jf/100.0)*d;
	unsigned y = long(temp);
	unsigned j = ((temp-y)*1000+5)/10;
	return RMB(y,j);
}

RMB operator*(double d, const RMB& r){ return r * d; }

void main()
{
  RMB d1(1, 60);
  RMB d2(2, 50);
  RMB d3(0, 0);
  d3 = d1 + d2;
	d1 = d3 * 30.25;
  d2 = 52.35 * d3;
  d1.display();
	d2.display();
}
