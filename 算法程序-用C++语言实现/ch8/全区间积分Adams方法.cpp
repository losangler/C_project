//ȫ�������Adams����.cpp
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
  void adams(double t, double h, int n, double y[], double eps, int k, 
	           double z[], void (*f)(double,double [],int,double []))
  { 
	  int i,j,m;
      double a,q,*b,*e,*s,*g,*d;
      b=new double[4*n];
      e=new double[n];
      s=new double[n];
      g=new double[n];
      d=new double[n];
      a=t;
      for (i=0; i<=n-1; i++) z[i*k]=y[i];
      (*f)(t,y,n,d);
      for (i=0; i<=n-1; i++) b[i]=d[i];
      for (i=1; i<=3; i++)
        if (i<=k-1)
        { 
			t=a+i*h;
            runge_kutta(t,h,n,y,eps,f);
            for (j=0; j<=n-1; j++) z[j*k+i]=y[j];
            (*f)(t,y,n,d);
            for (j=0; j<=n-1; j++) b[i*n+j]=d[j];
        }
      for (i=4; i<=k-1; i++)
      { 
		  for (j=0; j<=n-1; j++)
          { 
			  q=55.0*b[3*n+j]-59.0*b[2*n+j];
              q=q+37.0*b[n+j]-9.0*b[j];
              y[j]=z[j*k+i-1]+h*q/24.0;
              b[j]=b[n+j];
              b[n+j]=b[n+n+j];
              b[n+n+j]=b[n+n+n+j];
          }
          t=a+i*h;
          (*f)(t,y,n,d);
          for (m=0; m<=n-1; m++) b[n+n+n+m]=d[m];
          for (j=0; j<=n-1; j++)
          { 
			  q=9.0*b[3*n+j]+19.0*b[n+n+j]-5.0*b[n+j]+b[j];
              y[j]=z[j*k+i-1]+h*q/24.0;
              z[j*k+i]=y[j];
          }
          (*f)(t,y,n,d);
          for (m=0; m<=n-1; m++) b[3*n+m]=d[m];
      }
      delete[] b; delete[] e; delete[] s; delete[] g; delete[] d;
      return;
  }
/*
//ȫ�������Adams������
  #include <iostream>
  #include <cmath>
  #include <iomanip>
//  #include "ȫ�������Adams����.cpp"
  using namespace std;
  int main()
  { 
	  int i,j;
      void  adamsf(double,double [],int,double []);
      double y[3],z[3][11];
      double t,h,eps;
      t=0.0; h=0.1; eps=0.0000001;
      y[0]=0.0; y[1]=1.0; y[2]=1.0;
      adams(t,h,3,y,eps,11,&z[0][0],adamsf);
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
  void adamsf(double t, double y[], int n, double d[])
  { 
	  t=t; n=n;
      d[0]=y[1]; d[1]=-y[0]; d[2]=-y[2];
      return;
  }
*/