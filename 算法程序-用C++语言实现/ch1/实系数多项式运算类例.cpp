//ʵϵ������ʽ������.cpp
  #include  <iostream>
  #include  "ʵϵ������ʽ������.h"
  #include  <fstream>
  #include  <cmath>
  using namespace std;
  int main ()      //������
  {
	  int k;
	  double x[6] = { 0.9, 1.1, 1.3, -0.9, -1.1, -1.3 };
      double p1[7] = { -20.0,7.0,-7.0,1.0,3.0,-5.0,2.0 };
	  double p2[6] = { 4.0,-6.0,5.0,2.0,-1.0,3.0 };
	  double q2[4] = { 2.0,3.0,-6.0,2.0 };
	  double p3[5] = { 8.0,-5.0,-3.0,6.0,3.0 };
	  double q3[3] = { 1.0,-1.0,2.0 };
	  double s2[9], s3[3], r3[2];
      poly p, q, s, r;
      p = poly(6,p1);
	  cout <<"����ʽ��ֵ: " <<endl;
	  for (k=0; k<6; k++)
         cout <<"p(" <<x[k] <<") = " <<p.poly_value(x[k]) <<endl;

	  p = poly(5,p2);
	  q = poly(3,q2);
	  s = poly(8,s2);
      p.poly_mul (q, s);    //����ʽ��� s2 = p2*q2
	  cout <<"�˻�����ʽs2 = p2*q2 :" <<endl;
      for (k=0; k<=8; k++)       //����˻�����ʽs2��ϵ��
	  {
		  cout <<"s2(" <<k <<") = " <<s2[k] <<endl; 
	  }
	  p=poly(4,p3);
	  q=poly(2,q3);
	  s=poly(2,s3);
	  r=poly(1,r3);
      p.poly_div(q, s, r);  //����ʽ��� s3 = p3/q3 �� r3
	  cout <<"p3/q3�̶���ʽs3:" <<endl;
	  for (k=0; k<=2; k++)      //����̶���ʽs3��ϵ��
	  {
		  cout <<"s3(" <<k <<") = " <<s3[k] <<endl; 
	  }
	  cout <<"p3/q3�����ʽr3:" <<endl;
	  for (k=0; k<=1; k++)      //��������ʽr3��ϵ��
	  {
		  cout <<"r3(" <<k <<") = " <<r3[k] <<endl; 
	  }
	  return 0;
  }

