//��ϵ������ʽ��������.cpp
  #include  <iostream>
  #include  <fstream>
  #include  <cmath>
  #include "��ϵ������ʽ������.h"
  using namespace std;
  int main ()
  {
	  int i;
	  double a, b;
	  complex  p1[4]={complex(2,1),complex(2,1),complex(1,1),complex(2,2)};
	  complex  p2[6]={complex(4,2),complex(-6,3),complex(5,-4),
		              complex(2,1),complex(-1,-1),complex(3,2)};
	  complex  q2[4]={complex(2,1),complex(3,2),complex(-6,-4),complex(2,1)};
	  complex  p3[5]={complex(8,3),complex(-5,4),complex(-3,4),
		              complex(6,-5),complex(3,-1)};
	  complex  q3[3]={complex(1,2),complex(-1,-3),complex(2,2)};
      complex  x, y, s2[9], s3[3], r3[2];
	  com_poly p, q, s, r;
	  cout <<"����x = ";
	  cin >>a >>b;
	  x=complex(a,b);
	  p=com_poly(3,p1);
	  cout <<"����ʽ��ֵ: " <<endl;
	  cout <<"x = "; x.prt(); cout <<endl;
	  cout <<"p(x) = "; y = p.poly_value(x); y.prt();  cout <<endl;
	  p=com_poly(5,p2);
	  q=com_poly(3,q2);
	  s=com_poly(8,s2);
      p.com_poly_mul (q, s);    //����ʽ��� s2 = p2*q2
	  cout <<"�˻�����ʽs2 = p2*q2 :" <<endl;
      for (i=0; i<=8; i++)       //����˻�����ʽs2��ϵ��
	  {
		  cout <<"s2(" <<i <<") = ";  s2[i].prt();  cout <<endl;
	  }
	  p=com_poly(4,p3);
	  q=com_poly(2,q3);
	  s=com_poly(2,s3);
	  r=com_poly(1,r3);
      p.com_poly_div (q, s, r);  //����ʽ��� s3 = p3/q3 �� r3
	  cout <<"p3/q3�̶���ʽs3:" <<endl;
	  for (i=0; i<=2; i++)      //����̶���ʽs3��ϵ��
	  {
		  cout <<"s3(" <<i <<") = ";  s3[i].prt();  cout <<endl;
	  }
	  cout <<"p3/q3�����ʽr3:" <<endl;
	  for (i=0; i<=1; i++)      //��������ʽr3��ϵ��
	  {
		  cout <<"r3(" <<i <<") = ";  r3[i].prt();  cout <<endl;
	  }
	  return 0;
  }
