//�������aitken������.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//x          ��ŷ��̸��ĳ�ֵ�����ص�����ֵ��
//eps        ���ƾ���Ҫ��
//f          �򵥵�����ʽ�Ҷ˺�����(x)�ĺ�������         
  //�������ص�����������������������Ϊ500��
  int atkn(double *x, double eps, double (*f)(double))
  { 
	  int flag, k, interation;
      double u, v, x0;
	  interation = 500;         //����������
      k = 0; x0 = *x; flag = 0;
      while ((flag==0)&&(k!=interation))
      { 
		  k = k + 1; 
          u = (*f)(x0); v = (*f)(u);
          if (fabs(u-v)<eps) 
		  { 
			  x0 = v; flag = 1; 
		  }
          else 
			  x0 = v-(v-u)*(v-u)/(v-2.0*u+x0);
      }
      *x = x0; 
      return(k);
  }

/*
//�������aitken��������
  #include <cmath>
  #include <iostream>
//  #include "�������aitken������.cpp"
  using namespace std;
  int main()
  { 
	  int k;
      double x,eps,atknf(double);
      eps = 0.0000001;  x = 0.0;
      k = atkn(&x,eps,atknf);
      cout <<"�������� = " <<k <<endl;
      cout <<"������ֵ x = " <<x <<endl;
      return 0;
  }
//��(x)
  double atknf(double x)
  { 
	  return(6.0-x*x);
  }
*/
