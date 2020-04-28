//����Ӧ���������.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
  //�ݹ麯��
  void ppp(double x0, double x1, double h, double f0, double f1, double t0, 
	       double eps, double *t, double (*ff)(double))
  { 
	  double x,f,t1,t2,p,g,eps1;
      x=x0+h/2.0; f=(*ff)(x);
      t1=h*(f0+f)/4.0; t2=h*(f+f1)/4.0;
      p=fabs(t0-(t1+t2));
      if ((p<eps)||(h<eps))
      { 
		  *t = *t+(t1+t2); return;
	  }
      else
      { 
		  g=h/2.0; eps1=eps/1.4;
          ppp(x0,x,g,f0,f,t1,eps1,t,ff);
          ppp(x,x1,g,f,f1,t2,eps1,t,ff);
          return;
      }
  }
//a          �������ޡ�
//b          �������ޡ�Ҫ��b>a��
//eps        ���־���Ҫ��
//f          ���㱻������ֵf(x)�ĺ�������
  //�������ػ���ֵ��
  double fpts(double a, double b, double eps, double (*f)(double))
  { 
	  double h,t,f0,f1,t0;
      h=b-a; t=0.0;
      f0=(*f)(a); f1=(*f)(b);
      t0=h*(f0+f1)/2.0;
      ppp(a,b,h,f0,f1,t0,eps,&t,f);
      return(t);
  }

/*
//����Ӧ�����������
  #include <cmath>
  #include <iostream>
//  #include "����Ӧ���������.cpp"
  using namespace std;
  int main()
  { 
	  double a,b,eps,t,fptsf(double);
      a=-1.0; b=1.0; eps=0.000001; 
      t=fpts(a,b,eps,fptsf);
      cout <<"t = " <<t <<endl;
      return 0;
  }
//���㱻������ֵ
  double fptsf(double x)
  { 
	  double y;
      y=1.0/(1.0+25.0*x*x);
      return(y);
  }
*/