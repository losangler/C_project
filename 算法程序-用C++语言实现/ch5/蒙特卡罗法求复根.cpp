//���ؿ��޷��󸴸�.cpp
  #include <cmath>
  #include <iostream>
  #include "����������.h"
  #include "�����������.h"
  using namespace std;
//z          ���ĳ�ֵ��
//b          ���ȷֲ�������Ķ˵��ֵ��
//m          ���Ƶ���b�Ĳ�����
//eps        ���ƾ���Ҫ��
//f          ���㷽����˺���ֵ�ĺ�������
  //�������ظ�����ֵ��
  //��������ʾ��b������100�Σ������������������������������������b��m��ֵ���ԡ�
  complex mtcl(complex z, double b,int m, double eps, complex (*f)(complex))
  { 
	  RND r(1.0);
	  int flag, k;
      double x1,y1;
	  complex z1, zz, zz1;
      k=0; flag = 0;
	  zz = (*f)(z);
      while (flag<=100)
      {
		  k = k + 1;
		  x1 = -b+2.0*b*(r.rnd1());     //�����������
		  y1 = -b+2.0*b*(r.rnd1());
		  z1 = z + complex(x1,y1);
          zz1 = (*f)(z1);
          if (zz1.cfabs()>=zz.cfabs())
          { 
			  if (k == m) 
			  {
				  k = 0; flag = flag + 1; b = b/2.0; 
			  }
		  }
          else
          { 
			  k = 0;
			  z = z1; zz = zz1;
              if (zz.cfabs()<eps)  return(z);
          }
      }
	  cout <<"b������100�Σ�������������" <<endl;
      return(z);
  }

/*
//ʵ���������󸴸���
  #include <cmath>
  #include <iostream>
//  #include "���ؿ��޷��󸴸�.cpp"
  using namespace std;
  int main()
  { 
	  int m;
      double b,eps;
	  complex z, x, mtclf(complex);
      x=complex(0.5,0.5); 
	  b=1.0; m=10; eps=0.00001;
      z = mtcl(x,b,m,eps,mtclf);
      cout <<"z = "; z.prt(); cout <<endl;
      cout <<"����: f(z) = "; mtclf(z).prt(); cout <<endl;
	  return 0;
  }
//ʵ��������
  complex mtclf(complex x)    //Ҫ��ϵ����Ϊ����
  { 
	  complex z;
      z = x*x - complex(6.0,0.0)*x + complex(13.0,0.0);
      return(z);
  }
*/
/*
//�����������󸴸���
  #include <cmath>
  #include <iostream>
//  #include "���ؿ��޷��󸴸�.cpp"
  using namespace std;
  int main()
  { 
	  int m;
      double b,eps;
	  complex z, x, mtclf(complex);
      x=complex(0.5,0.5); 
	  b=1.0; m=10; eps=0.00001;
      z = mtcl(x,b,m,eps,mtclf);
      cout <<"z = "; z.prt(); cout <<endl;
      cout <<"����: f(z) = "; mtclf(z).prt(); cout <<endl;
	  return 0;
  }
//����������
  complex mtclf(complex x)
  { 
	  complex z;
      z = x*x + x*complex(1.0,1.0) + complex(-2.0,2.0);
      return(z);
  }
*/