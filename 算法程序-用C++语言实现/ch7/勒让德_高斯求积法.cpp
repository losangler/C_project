//���õ�_��˹�����.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//a          �������ޡ�
//b          �������ޡ�Ҫ��b>a��
//eps        ���־���Ҫ��
//f          ���㱻������ֵf(x)�ĺ�������
  //�������ػ���ֵ��
  double lrgs(double a, double b, double eps, double (*f)(double))
  { 
	  int m,i,j;
      double s,p,ep,h,aa,bb,w,x,g;
      double t[5]={-0.9061798459,-0.5384693101,0.0,
                         0.5384693101,0.9061798459};
      double c[5]={0.2369268851,0.4786286705,0.5688888889,
                        0.4786286705,0.2369268851};
      m=1;
      h=b-a; s=fabs(0.001*h);
      p=1.0e+35; ep=eps+1.0;
      while ((ep>=eps)&&(fabs(h)>s))
      { 
		  g=0.0;
          for (i=1;i<=m;i++)
          { 
			  aa=a+(i-1.0)*h; bb=a+i*h;
              w=0.0;
              for (j=0;j<=4;j++)
              { 
				  x=((bb-aa)*t[j]+(bb+aa))/2.0;
                  w=w+(*f)(x)*c[j];
              }
              g=g+w;
          }
          g=g*h/2.0;
          ep=fabs(g-p)/(1.0+fabs(g));
          p=g; m=m+1; h=(b-a)/m;
      }
      return(g);
  }
/*
//���õ�_��˹�������
  #include <cmath>
  #include <iostream>
//  #include "���õ�_��˹�����.cpp"
  using namespace std;
  int main()
  { 
	  double a,b,eps,g,lrgsf(double);
      a=2.5; b=8.4; eps=0.000001;
      g=lrgs(a,b,eps,lrgsf);
      cout <<"g = " <<g <<endl;
      return 0;
  }
//���㱻������ֵ
  double lrgsf(double x)
  { 
	  double y;
      y=x*x+sin(x);
      return(y);
  }
*/