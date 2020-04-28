//ȫ�������˫�߷�.cpp
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
  void gjfq(double t, double h, int n, double y[], double eps, int k, 
	           double z[], void (*f)(double,double [],int,double []))
  { 
      int i,j;
      double a,qq,*d,*p,*u,*v,*w;
      d=new double[n];
      p=new double[n];
      u=new double[n];
      v=new double[n];
      w=new double[n];
      for (i=0; i<=n-1; i++) 
	  {
		  p[i]=0.0; z[i*k]=y[i];
	  }
      a=t;
      (*f)(t,y,n,d);
      for (j=0; j<=n-1; j++) u[j]=d[j];
      runge_kutta(t,h,n,y,eps,f);
      t=a+h;
      (*f)(t,y,n,d);
      for (j=0; j<=n-1; j++)
      { 
		  z[j*k+1]=y[j]; v[j]=d[j];
	  }
      for (j=0; j<=n-1; j++)
      { 
		  p[j]=-4.0*z[j*k+1]+5.0*z[j*k]+2.0*h*(2.0*v[j]+u[j]);
        y[j]=p[j];
      }
      t=a+2.0*h;
      (*f)(t,y,n,d);
      for (j=0; j<=n-1; j++)
      { 
		  qq=2.0*h*(d[j]-2.0*v[j]-2.0*u[j])/3.0;
          qq=qq+4.0*z[j*k+1]-3.0*z[j*k];
          z[j*k+2]=(p[j]+qq)/2.0;
          y[j]=z[j*k+2];
      }
      for (i=3; i<=k-1; i++)
      { 
		  t=a+(i-1)*h;
          (*f)(t,y,n,d);
          for (j=0; j<=n-1; j++)
          { 
			  u[j]=v[j]; v[j]=d[j];
		  }
          for (j=0; j<=n-1; j++)
          { 
			  qq=-4.0*z[j*k+i-1]+5.0*z[j*k+i-2];
              p[j]=qq+2.0*h*(2.0*v[j]+u[j]);
              y[j]=p[j];
          }
          t=t+h;
          (*f)(t,y,n,d);
          for (j=0; j<=n-1; j++)
          { 
			  qq=2.0*h*(d[j]-2.0*v[j]-2.0*u[j])/3.0;
              qq=qq+4.0*z[j*k+i-1]-3.0*z[j*k+i-2];
              y[j]=(p[j]+qq)/2.0;
              z[j*k+i]=y[j];
          }
      }
      delete[] d; delete[] p; delete[] u; delete[] v; delete[] w;
      return;
  }
/*
//ȫ�������˫�߷���
  #include <iostream>
  #include <cmath>
  #include <iomanip>
//  #include "ȫ�������˫�߷�.cpp"
  using namespace std;
  int main()
  { 
	  int i,j;
      void  gjfqf(double,double [],int,double []);
      double y[2],z[2][11];
      double t,h,eps;
      t=0.0; h=0.1; eps=0.0000001;
      y[0]=1.0; y[1]=0.0;
      gjfq(t,h,2,y,eps,11,&z[0][0],gjfqf);
      for (i=0; i<=10; i++)
      { 
		  t=i*h;
          cout <<"t = " <<t;
          for (j=0; j<=1; j++)
			  cout <<"  y(" <<j <<") = " <<setw(10) <<z[j][i];
          cout <<endl;
      }
      return 0;
  }
//����΢�ַ������и������Ҷ˺���ֵ
  void gjfqf(double t, double y[], int n, double d[])
  { 
	  t=t; n=n;
      d[0]=-y[1]; d[1]=y[0];
      return;
  }
*/