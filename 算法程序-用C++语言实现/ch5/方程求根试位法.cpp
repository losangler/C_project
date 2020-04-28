//���������λ��.cpp
  #include <iostream>
  #include <cmath>
  using namespace std;
//a          ���������˵㡣
//b          ��������Ҷ˵㡣
//eps        ���ƾ���Ҫ��
//f          ������˺���f(x)�ĺ�������
//x          ��ŷ��̸��ĳ�ֵ�����ص�����ֵ��
  //�������ص�����������Ϊ-1���ʾf(a)f(b)>0��
  int fals(double a, double b, double eps, double (*f)(double), double *x)
  {
	  int m;
	  double fa, fb, y;
	  m = 0;
	  fa = (*f)(a);  fb = (*f)(b);
	  if (fa*fb > 0)  return(-1);
	  do
	  {
		  m = m + 1;
		  *x = (a*fb - b*fa)/(fb - fa);
          y = (*f)(*x);
		  if (y*fa < 0) { b = *x; fb = y; }
		  else  { a = *x; fa = y; }
	  } while (fabs(y) >= eps);
      return(m);
  }

/*
//���������λ����
  #include <iostream>
  #include <cmath>
//  #include "���������λ��.cpp"
  using namespace std;
  int main ()      //������
  {
	  int k;
	  double x, func(double);
	  k = fals(1.0, 3.0, 0.000001, func, &x);   //ִ����λ��
	  cout <<"�������� = " <<k <<endl;
	  cout <<"һ��ʵ�� x = " <<x <<endl;
	  return 0;
  }
//f(x)
  double func(double x)    //���㷽����˺���f(x)ֵ
  {
	  double y;
	  y = x*x*x - 2*x*x + x - 2;
	  return y;
  }
*/

