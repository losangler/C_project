//������������.cpp
  #include  <iostream>
  #include  <cmath>
  #include  "����������.h"
  using namespace std;
  int  main ()      //������
  {
	  double a, b, x;
	  complex  c;
	  cin >>a >>b;
      c=complex(a,b);
	  x=c.angle();
	  cout <<"c=";	  c.prt();
	  cout <<"=" <<c.cfabs() <<endl;
	  cout <<"����=" <<c.angle() <<endl;
	  return 0;
  }

