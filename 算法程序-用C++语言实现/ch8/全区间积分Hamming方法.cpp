//ȫ�������Hamming����.cpp
  #include <iostream>
  #include <cmath>
  #include "�䲽��Runge_Kutta����.cpp"
  using namespace std;
//t           ������ʼ�㡣
//h           ���ֲ�����
//n           һ��΢�ַ������з��̸�����Ҳ��δ֪����������
//y[n]        ���n��δ֪��������ʼ��t���ĺ���ֵ��
//eps         �䲽��Runge_Kutta���Ŀ��ƾ���Ҫ��
//k           ���ֲ�����������ʼ����һ������
//z[n][k]     ����k�����ֵ㣨������ʼ�㣩�ϵ�δ֪����ֵ��
//f           ����΢�ַ������и������Ҷ˺���ֵ�ĺ�������
  void hamming(double t, double h, int n, double y[], double eps, int k, 
	           double z[], void (*f)(double,double [],int,double []))

  { 
	  int i,j,m;
      double a,q,*b,*d,*u,*v,*w,*g;
      b=new double[4*n];
      d=new double[n];
      u=new double[n];
      v=new double[n];
      w=new double[n];
      g=new double[n];
      a=t;
      for (i=0; i<=n-1; i++) z[i*k]=y[i];
      (*f)(t,y,n,d);
      for (i=0; i<=n-1; i++) b[i]=d[i];
      for (i=1; i<=3; i++)
        if (i<=k-1)
        { 
			t=a+i*h;
            runge_kutta(t,h,n,y,eps,f);
            for (m=0; m<=n-1; m++) z[m*k+i]=y[m];
            (*f)(t,y,n,d);
            for (m=0; m<=n-1; m++) b[i*n+m]=d[m];
        }
      for (i=0; i<=n-1; i++) u[i]=0.0;
      for (i=4; i<=k-1; i++)
      { 
		  for (j=0; j<=n-1; j++)
          { 
			  q=2.0*b[3*n+j]-b[n+n+j]+2.0*b[n+j];
              y[j]=z[j*k+i-4]+4.0*h*q/3.0;
          }
          for (j=0; j<=n-1; j++)  y[j]=y[j]+112.0*u[j]/121.0;
          t=a+i*h;
          (*f)(t,y,n,d);
          for (j=0; j<=n-1; j++)
          { 
			  q=9.0*z[j*k+i-1]-z[j*k+i-3];
              q=(q+3.0*h*(d[j]+2.0*b[3*n+j]-b[n+n+j]))/8.0;
              u[j]=q-y[j];
              z[j*k+i]=q-9.0*u[j]/121.0;
              y[j]=z[j*k+i];
              b[n+j]=b[n+n+j];
              b[n+n+j]=b[n+n+n+j];
          }
          (*f)(t,y,n,d);
          for (m=0; m<=n-1; m++) b[3*n+m]=d[m];
      }
      delete[] b; delete[]d; delete[] u; delete[] v; delete[] w; delete[] g;
      return;
  }
/*
//ȫ�������Hamming������
  #include <iostream>
  #include <cmath>
  #include <iomanip>
//  #include "ȫ�������Hamming����.cpp"
  using namespace std;
  int main()
  { 
	  int i,j;
      void  hamgf(double,double [],int,double []);
      double y[3],z[3][11];
      double t,h,eps;
      t=0.0; h=0.1; eps=0.0000001;
      y[0]=1.0; y[1]=1.0; y[2]=1.0;
      hamming(t,h,3,y,eps,11,&z[0][0],hamgf);
      for (i=0; i<=10; i++)
      { 
		  t=i*h;
          cout <<"t = " <<t;
          for (j=0; j<=2; j++)
			  cout <<"  y(" <<j <<") = " <<setw(10) <<z[j][i];
          cout <<endl;
      }
      return 0;
  }
//����΢�ַ������и������Ҷ˺���ֵ
  void hamgf(double t, double y[], int n, double d[])
  { 
	  t=t; n=n;
      d[0]=y[1]; d[1]=-y[0]; d[2]=y[2];
      return;
  }
*/