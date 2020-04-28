//������ػ��ֵ�Monte_Carlo��.cpp
  #include <cmath>
  #include <iostream>
  #include "�����������.h"
  using namespace std;
//n          ����������
//a[n]       ������ֵ����ޡ�
//b[n]       ������ֵ����ޡ�
//f          ���㱻������ֵf(X)�ĺ�������
  //�������ػ���ֵ��
  double mtml(int n, double a[], double b[], double (*f)(int,double []))
  { 
	  int m,i;
      double s,d,*x;
	  RND r(1.0);
      x=new double[n];
      d=65536.0; s=0.0;
      for (m=0; m<=65535; m++)
      { 
		  for (i=0; i<=n-1; i++)
              x[i]=a[i]+(b[i]-a[i])*r.rnd1();
          s=s+(*f)(n,x)/d;
      }
      for (i=0; i<=n-1; i++) s=s*(b[i]-a[i]);
      delete[] x; return(s);
  }

/*
//������ػ��ֵ�Monte_Carlo����
  #include <cmath>
  #include <iostream>
//  #include "������ػ��ֵ�Monte_Carlo��.cpp"
  using namespace std;
  int main()
  { 
	  double a[3]={ 1.0,1.0,1.0};
      double b[3]={ 2.0,2.0,2.0};
      double  mtmlf(int,double []);
      cout <<"s = " <<mtml(3,a,b,mtmlf) <<endl;
      return 0;
  }
//���㱻������ֵ
  double mtmlf(int n, double x[])
  { 
	  int i;
      double f;
      f=0.0;
      for (i=0; i<=n-1; i++) f=f+x[i]*x[i];
      return(f);
  }
*/