//���ؿ��޷��������Է�����.cpp
  #include <iostream>
  #include <cmath>
  #include "�����������.h"
  using namespace std;
//x[n]       ���ʵ�����ֵ��
//n          ���������
//b          ���ȷֲ�������Ķ˵��ֵ��
//m          ���Ƶ���b�Ĳ�����
//eps        ���ƾ���Ҫ��
//f          ���㷽����ģ����ֵ�ĺ�������
  //��������ʾ��b������100�Σ������������������������b��m��ֵ���ԡ�
  void nmtc(double x[], int n, double b, int m, double eps, double (*f)(double [], int))
  { 
	  int k,i,flag;
      double *y,z,z1;
	  RND  r(1.0);
      y = new double[n];
      k=0;   flag = 0;
	  z=(*f)(x,n);
      while (flag <= 100)
      {
		  k = k + 1;
		  for (i=0; i<=n-1; i++)    //����һ�������
              y[i]=-b+2.0*b*(r.rnd1()) + x[i];
          z1=(*f)(y,n);
          if (z1>=z)
		  { 
			  if (k == m)  
			  { 
				  flag = flag + 1; k = 0; b = b/2.0;
			  }
		  }
          else
          { 
			  k = 0;
              for (i=0; i<=n-1; i++) x[i]=y[i];
              z=z1;
              if (z<eps)  {delete[] y; return;}
          }
      }
	  cout <<"b������100�Σ�������������" <<endl;
      delete[] y; return;
  }

/*
//���ؿ��޷��������Է�������
  #include <iostream>
  #include <cmath>
//  #include "���ؿ��޷��������Է�����.cpp"
  using namespace std;
  int main()
  { 
	  int i,n,m;
      double nmtcf(double [],int);
      double b,eps,x[3]={0.0,0.0,0.0};
      b=2.0; m=50; n=3; eps=0.000001;
      nmtc(x,n,b,m,eps,nmtcf);
      for (i=0; i<=2; i++)  
		  cout <<"x(" <<i <<") = " <<x[i] <<endl;
	  cout <<"��֤: |F| = " <<nmtcf(x,n) <<endl;
      return 0;
  }
//���㷽����ģ
  double nmtcf(double x[], int n)
  { 
	  double f,f1,f2,f3;
      n=n;
      f1=3.0*x[0]+x[1]+2.0*x[2]*x[2]-3.0;
      f2=-3.0*x[0]+5.0*x[1]*x[1]+2.0*x[0]*x[2]-1.0;
      f3=25.0*x[0]*x[1]+20.0*x[2]+12.0;
      f=sqrt(f1*f1+f2*f2+f3*f3);
      return(f);
  }
*/