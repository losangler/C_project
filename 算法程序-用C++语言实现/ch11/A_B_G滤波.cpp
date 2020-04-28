//A_B_G�˲�.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//n         �������ݵ�����
//x[n]      n���ȼ�����ϵ�����ֵ��
//t         �������ڡ�
//a         �˲����ṹ����Alpha��
//b         �˲����ṹ����Beta��
//c         �˲����ṹ����Gamma��
//y[n]      ����n���ȼ�����ϵ��˲���ֵ��
  void kabg(int n, double x[], double t, double a, double b, double c, double y[])
  { 
	  int i;
      double s1,ss,v1,vv,a1,aa;
      aa=0.0; vv=0.0;ss=0.0;
      for (i=0; i<=n-1; i++)
      { 
		  s1=ss+t*vv+t*t*aa/2.0;
          v1=vv+t*aa; 
		  a1=aa;
          ss=s1+a*(x[i]-s1); 
		  y[i]=ss;
          vv=v1+b*(x[i]-s1);
          aa=a1+2.0*c*(x[i]-s1)/(t*t);
      }
      return;
  }
/*
//A_B_G�˲���
  #include <cmath>
  #include <iostream>
  #include <iomanip>
  #include "�����������.h"
//  #include "A_B_G�˲�.cpp"
  using namespace std;
  int main()
  { 
	  int i;
      double x[150],y[150],z[150];
      double a,b,c,dt,t;
	  RND p;
      a=0.271; b=0.0285; c=0.0005; dt=0.04;
	  p = RND(0);
      for (i=0; i<150; i++) //����150����ֵΪ0������Ϊ0.25�ĸ�˹������
		  y[i]= p.rndg(0.0,0.5);
      for (i=0; i<=149; i++)
      { 
		  t=(i+1)*dt;
          z[i]=3.0*t*t-2.0*t+5.0;
          x[i]=z[i]+y[i];
      }
      kabg(150,x,dt,a,b,c,y);
      for (i=0; i<=149; i=i+5)
      { 
		  t=(i+1)*dt;
		  cout <<"t=" <<t <<"  x(t)=" <<setw(10) <<x[i] <<"  y(t)=" 
			     <<setw(10) <<y[i] <<"  z(t)=" <<setw(10) <<z[i] <<endl;
      }
      return 0;
  }
*/