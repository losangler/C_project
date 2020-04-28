//���������.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//a          �������ޡ�
//b          �������ޡ�Ҫ��b>a��
//eps        ���־���Ҫ��
//f          ���㱻������ֵf(x)�ĺ�������
  //�������ػ���ֵ��
  double ffts(double a, double b, double eps, double (*f)(double))
  { 
	  int n,k;
      double fa,fb,h,t1,p,s,x,t;
      fa=(*f)(a); fb=(*f)(b);
      n=1; h=b-a;
      t1=h*(fa+fb)/2.0;
      p=eps+1.0;
      while (p>=eps)
      { 
		  s=0.0;
          for (k=0;k<=n-1;k++)
          { 
			  x=a+(k+0.5)*h;  s=s+(*f)(x);
          }
          t=(t1+h*s)/2.0;
          p=fabs(t1-t);
          t1=t; n=n+n; h=h/2.0;
      }
      return(t);
  }

/*
//�����������
  #include <cmath>
  #include <iostream>
//  #include "���������.cpp"
  using namespace std;
  int main()
  { 
	  double a,b,eps,t,fftsf(double);
      a=0.0; b=1.0; eps=0.000001;
      t=ffts(a,b,eps,fftsf);
      cout <<"t = " <<t <<endl;
      return 0;
  }
//���㱻������ֵ
  double fftsf(double x)
  { 
	  return(exp(-x*x));
  }
*/
