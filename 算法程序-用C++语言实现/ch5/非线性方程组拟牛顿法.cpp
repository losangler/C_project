//�����Է�������ţ�ٷ�.cpp
  #include <iostream>
  #include <cmath>
  #include "gauss��ȥ��.cpp"
  using namespace std;
//n        �Ƿ����������
//eps      ���ƾ���Ҫ��
//h        ������ֵ,h>0������ʱ�����ƻ���
//x[n]     ��ų�ֵ�����ط�����ʵ���⡣
//f        ���㷽�����������˺���ֵ�ĺ�������
  //��������ʵ�ʵ�����������<0���ʾ��AZ=B�����beta=0��ʧ�ܡ�����������������Ϊ1000��
  int netn(int n, double eps, double h, double x[], 
	                       void (*f)(double x[],double y[],int n))
  { 
	  int i,j,k,interation;
      double t,ep,z,beta,d,*y,*a,*b;
	  interation = 1000;             //����������
	  t = 0.1;                       //����h��С
      y = new double[n];
      a = new double[n*n];
      b = new double[n];
      k = 0; ep=1.0+eps;
      while (ep>=eps)
      { 
		  (*f)(x,b,n);
          ep=0.0;
          for (i=0; i<=n-1; i++)
          { 
			  z=fabs(b[i]);
              if (z>ep) ep=z;
          }
          if (ep>=eps)
          { 
			  k = k + 1;
              if (k==interation)       //�ﵽ����������δ����
              { 
				  delete[] y; delete[] b; delete[] a; return(k);
              }
              for (j=0; j<=n-1; j++)
              { 
				  z=x[j]; x[j]=x[j]+h;
                  (*f)(x,y,n);
                  for (i=0; i<=n-1; i++) a[i*n+j]=y[i];
                  x[j]=z;
              }
              if (gauss(a,b,n)==0)        //AZ=B����
              { 
				  delete[] y; delete[] b; delete[] a; return(-1);
			  }
              beta=1.0;
              for (i=0; i<=n-1; i++) beta=beta-b[i];
              if (fabs(beta)+1.0==1.0)    //beta=0
              { 
				  delete[] y; delete[] b; delete[] a; return(-1);
              }
              d=h/beta;
              for (i=0; i<=n-1; i++) x[i]=x[i]-d*b[i];
              h=t*h;
          }
      }
      delete[] y; delete[] b; delete[] a; return(k);
  }
/*
//�����Է�������ţ�ٷ���
  #include <iostream>
  #include <cmath>
//  #include "�����Է�������ţ�ٷ�.cpp"
  using namespace std;
  int main()
  { 
	  int i, k;
      void netnf(double [],double [],int);
      double eps, h;
      double x[3]={1.0,1.0,1.0};
      h=0.1; eps=0.0000001; 
      k = netn(3,eps,h,x,netnf);
      cout <<"�������� = " <<k <<endl;
      for (i=0; i<=2; i++)  cout <<"x(" <<i <<") = " <<x[i] <<endl;
      return 0;
  }
//������
  void netnf(double x[], double y[], int n)
  { y[0]=x[0]*x[0]+x[1]*x[1]+x[2]*x[2]-1.0;
    y[1]=2.0*x[0]*x[0]+x[1]*x[1]-4.0*x[2];
    y[2]=3.0*x[0]*x[0]-4.0*x[1]+x[2]*x[2];
    n=n;
    return;
  }
*/