//������ػ��ֵ�Simpson��.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
  //�̶�һ��x���ñ䲽��Simpson������һ����y�Ļ��ֽ���ֵ��
  double simp1(double x, double eps, 
	          void (*s)(double ,double []), double (*f)(double,double))
  { 
	  int n,i;
      double y[2],h,t1,yy,t2,g,ep,g0;
      n=1;
      (*s)(x,y);        //�������������y[1]��y[0]
      h=0.5*(y[1]-y[0]);
      t1=h*((*f)(x,y[0])+(*f)(x,y[1]));
      ep=1.0+eps; g0 = t1;
      while ((ep>eps)&&(h>eps)||(n<16))//�䲽��Simpson�����
      { 
		  yy=y[0]-h;
          t2=0.5*t1;
          for (i=1;i<=n;i++)
          { 
			  yy=yy+2.0*h;
              t2=t2+h*(*f)(x,yy);
          }
          g=(4.0*t2-t1)/3.0;
          ep=fabs(g-g0)/(1.0+fabs(g));
          n=n+n; g0=g; t1=t2; h=0.5*h;
      }
      return(g0);
  }
//a          �������ޡ�
//b          �������ޡ�Ҫ��b>a��
//eps        ���־���Ҫ��
//s          ���������޵ĺ�������
//f          ���㱻������ֵf(x,y)�ĺ�������
  //�������ػ���ֵ��
  double sim2(double a, double b, double eps, 
	          void (*s)(double ,double []), double (*f)(double,double))
  { 
      int n,j;
      double h,s1,s2,t1,x,t2,g,ss,s0,ep;
      n=1; h=0.5*(b-a);
      s1=simp1(a,eps,s,f);   //�̶�x = a
	  s2=simp1(b,eps,s,f);   //�̶�x = b
      t1=h*(s1+s2);
      s0=t1; ep=1.0+eps;
      while ((ep>eps)&&(h>eps)||(n<16))//�䲽��Simpson�����
      { 
		  x=a-h; t2=0.5*t1;
          for (j=1;j<=n;j++)
          { 
			  x=x+2.0*h;
              g=simp1(x,eps,s,f);   //�̶�x = x + h
              t2=t2+h*g;
          }
          ss=(4.0*t2-t1)/3.0;
          ep=fabs(ss-s0)/(1.0+fabs(ss));
          n=n+n; s0=ss; t1=t2; h=h*0.5;
      }
      return(s0);
  }

/*
//������ػ��ֵ�Simpson����
  #include <cmath>
  #include <iostream>
//  #include "������ػ��ֵ�Simpson��.cpp"
  using namespace std;
  int main()
  { 
	  double a,b,eps,s,sim2f(double,double);
      void  sim2s(double,double []);
      a=0.0; b=1.0; eps=0.0000001;
      s=sim2(a,b,eps,sim2s,sim2f);
      cout <<"s = " <<s <<endl;
      return 0;
  }
//����������y1(x)��y0(x)
  void sim2s(double x, double y[2])
  { 
	  y[1]=sqrt(1.0-x*x);
      y[0]=-y[1];
      return;
  }
//���㱻������ֵf(x,y)
  double sim2f(double x, double y)
  { 
	  double z;
      z=exp(x*x+y*y);
      return(z);
  }
*/