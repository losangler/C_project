//�����������ʽ��.cpp
  #include <cmath>
  #include <iostream>
  #include "���㺯������ʽֵ.cpp"
  #include "���㺯������ʽ��һ��.cpp"
  using namespace std;
//xx      ���̸���ֵ�����ص�����ֵ��
//eps     ���ƾ���Ҫ��
//f       ������˺���f(x)�ĺ�������
  //�������ص���������һ�ε�����������߽�����ʽ��������������20�Ρ�
  int pqroot(double *xx,double eps,double (*f)(double))
  {
	  int j,k,flag;
	  double *x,*y,*b,x0;
	  b=new double[10];
	  x=new double[10];
	  y=new double[10];
      k=0; x0=*xx; flag=0;
      while ((k<20)&&(flag==0))
      { 
		  k=k+1; 
		  j=0;
		  x[0]=x0;   y[0]=(*f)(x[0]); 
		  b[0]=x[0];                            //����b[0]
		  j=1;
		  x[1]=x0+0.1;   y[1]=(*f)(x[1]);
          while (j<=7)
          { 
			  funpqj(y,x,b,j);                  //����b[j]
			  x[j+1]=funpqv(y,b,j,0.0);         //����x[j+1]
              y[j+1]=(*f)(x[j+1]);              //����y[j+1]
			  x0=x[j+1];
              if (fabs(y[j+1])>=eps) j=j+1;
			  else 
			  { 
				  cout <<"���һ�ε�������ʽ����=" <<j <<endl;
				  j=10; 
			  }
          }
          if (j==10) flag=1;
	  }
	  *xx = x0;
	  delete[] b; delete[] x; delete[] y;
      return(k);
   }
/*
//�����������ʽ����
  #include <cmath>
  #include <iostream>
//  #include "�����������ʽ��.cpp"
  using namespace std;
  int main()
  { 
	  int k;
	  double x,eps,pqrootf(double);
      eps=0.0000001; x=1.0;
	  k=pqroot(&x,eps,pqrootf);
      cout <<"�������� = " <<k <<endl;
      cout <<"���̸�Ϊ x = " <<x <<endl;
      cout <<endl;
	  cout <<"���龫�� : f(x)=" <<pqrootf(x) <<endl;  //���龫��
	  return 0;
  }
//f(x)
  double pqrootf(double x)
  { 
	  double y;
      y=x*x*(x-1.0)-1.0;
      return(y);
  }
*/
/*
  double pqrootf(double x)
  { 
	  double y;
      y=x*x+x-6.0;
      return(y);
  }
*/
/*
  double pqrootf(double x)
  { 
	  double y;
      y=exp(-x*x*x)-sin(x)/cos(x)+800;
      return(y);
  }
*/