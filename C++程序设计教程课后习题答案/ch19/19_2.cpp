//19_2.cpp

#include <iostream.h>
#include <iomanip.h>

class RMB{
public:
  RMB(double v =0.0):yuan(v){ jf =(v-yuan)*100+0.5; }
  operator double(){  return yuan+jf/100.0; }
  void display(ostream& out)
  {
    int n=1;   //为了用两字节的￥符号,得先求整数部分位数...
		for(int x=yuan; x/10; x/=10)	n++;
		
		if(n>5){ out <<"*******.**"; return; }
    double t=yuan+jf/100.0;
		out <<setw(7-n) <<"￥" <<setiosflags(ios::fixed)
		    <<setprecision(2) <<setw(n+3) <<t;
	}
protected:
  unsigned int yuan;
  unsigned int jf;
};

ostream& operator <<(ostream& oo, RMB& d)
{
  d.display(oo);
  return oo;
}

void main()
{
  RMB rmb(1.5);
  cout <<"Initially rmb = " <<rmb <<"\n";
  rmb =2.0*rmb;
  cout <<"then rmb = " <<rmb <<"\n";
}
