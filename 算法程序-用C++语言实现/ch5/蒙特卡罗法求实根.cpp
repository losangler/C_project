//���ؿ��޷���ʵ��.cpp
  #include <cmath>
  #include <iostream>
  #include "�����������.h"
  using namespace std;
//z          ���ĳ�ֵ��
//b          ���ȷֲ�������Ķ˵��ֵ��
//m          ���Ƶ���b�Ĳ�����
//eps        ���ƾ���Ҫ��
//f          ���㷽����˺���ֵ�ĺ�������
  //�������ظ�����ֵ��
  //��������ʾ��b������100�Σ� �����������������������b��m��ֵ���ԡ�
  double metcalo(double z, double b,int m, double eps, double (*f)(double))
  { 
	  RND r(1.0);
	  int flag, k;
	  double x, z1, zz, zz1;
      k=0;  flag = 0;
	  zz = (*f)(z);
      while (flag <= 100)
      {
		  k = k + 1;
		  x = -b+2.0*b*(r.rnd1()); 
		  z1 = z + x;
          zz1 = (*f)(z1);
          if (fabs(zz1)>=fabs(zz))
          { 
			  if (k == m) 
			  {
				  k = 0; flag = flag + 1; b = b/2.0; 
			  }
		  }
          else
          { 
			  k = 0;
			  z = z1; zz = zz1;
              if (fabs(zz)<eps)  return(z);
          }
      }
	  cout <<"b������100�Σ� ������������" <<endl;
      return(z);
  }

/*
//���ؿ��޷���ʵ����
  #include <cmath>
  #include <iostream>
//  #include "���ؿ��޷���ʵ��.cpp"
  using namespace std;
  int main()
  { 
	  int m;
      double b,eps;
	  double z, x, mtclf(double);
      b=1.0; m=10; eps=0.00001;
	  x = 0.5;
      z = metcalo(x,b,m,eps,mtclf);
      cout <<"z = " <<z <<endl;
	  cout <<"���� : f(z) = " <<mtclf(z) <<endl;
      return 0;
  }
//ʵ��������
  double mtclf(double x)
  { 
	  double  y;
	  y = exp(-x*x*x) - sin(x)/cos(x) + 800.0;
      return(y);
  }
*/