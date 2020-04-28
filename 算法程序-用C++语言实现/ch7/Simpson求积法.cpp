//Simpson�����.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//a          �������ޡ�
//b          �������ޡ�Ҫ��b>a��
//eps        ���־���Ҫ��
//f          ���㱻������ֵf(x)�ĺ�������
  //�������ػ���ֵ��
  double simp(double a, double b, double eps, double (*f)(double))
  { 
	  int n,k;
      double h,t1,t2,s1,s2,ep,p,x;
      n=1; h=b-a;
      t1=h*((*f)(a)+(*f)(b))/2.0;
      s1=t1;
      ep=eps+1.0;
      while (ep>=eps)
      { 
		  p=0.0;
          for (k=0;k<=n-1;k++)
          { 
			  x=a+(k+0.5)*h;   p=p+(*f)(x);
          }
          t2=(t1+h*p)/2.0;
          s2=(4.0*t2-t1)/3.0;
          ep=fabs(s2-s1);
          t1=t2; s1=s2; n=n+n; h=h/2.0;
      }
      return(s2);
  }

/*
//Simpson�������
  #include <cmath>
  #include <iostream>
//  #include "Simpson�����.cpp"
  using namespace std;
  int main()
  { 
	  double a,b,eps,t,simpf(double);
      a=0.0; b=1.0; eps=0.000001;
      t=simp(a,b,eps,simpf);
      cout <<"t = " <<t <<endl;
      return 0;
  }
//���㱻������ֵ
  double simpf(double x)
  { 
	  double y;
      y=log(1.0+x)/(1.0+x*x);
      return(y);
  }
*/
