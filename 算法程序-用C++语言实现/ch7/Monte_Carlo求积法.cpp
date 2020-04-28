//Monte_Carlo�����.cpp
  #include <cmath>
  #include <iostream>
  #include "�����������.h"
  using namespace std;
//a          �������ޡ�
//b          �������ޡ�Ҫ��b>a��
//f          ���㱻������ֵf(x)�ĺ�������
  //�������ػ���ֵ��
  double mtcl(double a, double b, double (*f)(double))
  { 
	  int m;
      double d,x,s;
	  RND r(1.0);
      s=0.0; d=65536.0;
      for (m=0; m<=65535; m++)
      { 
		  x=a+(b-a)*r.rnd1();
          s=s+(*f)(x);
      }
      s=s*(b-a)/d;
      return(s);
  }
/*
//Monte_Carlo�������
  #include <cmath>
  #include <iostream>
//  #include "Monte_Carlo�����.cpp"
  using namespace std;
  int main()
  { 
	  double mtclf(double);
      cout <<"s = " <<mtcl(2.5,8.4,mtclf) <<endl;
      return 0;
  }
//���㱻������ֵ
  double mtclf(double x)
  { 
	  double y;
      y=x*x+sin(x);
      return(y);
  }
*/
