//�������newton��.cpp
  #include <iostream>
  #include <cmath>
  using namespace std;
//x          ��ŷ��̸��ĳ�ֵ�����ص�����ֵ��
//eps        ���ƾ���Ҫ��
//f          ������˺���f(x)�ĺ�������         
//df         ������˺���f(x)һ�׵���������
  //�������ص��������������� -1 �����ʾ����df/dx=0���������������������Ϊ500��
  int newt(double *x, double eps, double (*f)(double), double (*df)(double))
  { 
	  int k, interation;
      double y, dy, d, p, x0, x1;
	  interation = 500;         //����������
      k = 0; x0 = *x; 
      y = (*f)(x0); dy = (*df)(x0);
      d=eps+1.0;
      while ((d>=eps)&&(k!=interation))
      { 
		  if (fabs(dy)+1.0==1.0)     //����df(x)/dx=0
          { 
			  cout <<"dy == 0 !";  return(-1);
		  }
         x1 = x0 - y/dy;            //����
         y = (*f)(x1); dy = (*df)(x1);
         d=fabs(x1-x0); p=fabs(y);
         if (p>d) d=p;
         x0 = x1; k = k + 1;
      }
      *x = x0;
      return(k);
  }
/*
//�������newton����
  #include <cmath>
  #include <iostream>
//  #include "�������newton��.cpp"
  using namespace std;
  int main()
  { 
	  int k;
      double x,eps;
	  double newtf(double x), newtdf(double x);
      eps=0.000001;  x=1.5;
      k=newt(&x,eps,newtf,newtdf);
      if (k>=0)
	  {
		  cout <<"�������� = " <<k <<endl;
		  cout <<"������ֵ x = " <<x <<endl;
	  }
      return 0;
  }
//f(x)
  double newtf(double x)
  { 
	  return(x*x*(x-1.0)-1.0);
  }
//df(x)/dx
  double newtdf(double x)
  {
	  return(3.0*x*x - 2.0*x);
  }
*/