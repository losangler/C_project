//�䲽��Gill����.cpp
  #include <iostream>
  #include <cmath>
  using namespace std;
//t           ������ʼ�㡣
//h           ���ֲ�����
//n           һ��΢�ַ������з��̸�����Ҳ��δ֪����������
//y[n]        ���n��δ֪��������ʼ��t���ĺ���ֵ��
//            ����n��δ֪������t+h���ĺ���ֵ��
//eps         ���ƾ���Ҫ��
//q[n]        ����һ�ε��ñ�����ʱq[k]=0(k=0,1...n-1)��
//            �Ժ�ÿ�ε���ʱ��ʹ����һ�ε��ú�ķ���ֵ��
//f           ����΢�ַ������и������Ҷ˺���ֵ�ĺ�������
  void gill(double t, double h, int n, double y[], double eps, double q[],
	               void (*f)(double, double [], int, double []))
  { 
	  int i,j,k,m,ii;
      double x,p,hh,r,s,t0,dt,qq,*d,*u,*v,*g;
      double a[4]={0.5,0.29289321881,
                        1.7071067812,0.166666667};
      double b[4]={2.0,1.0,1.0,2.0};
      double c[4],e[4]={0.5,0.5,1.0,1.0};
      d=new double[n];
      u=new double[n];
      v=new double[n];
      g=new double[n];
      for (i=0; i<=2; i++) c[i]=a[i];
      c[3]=0.5;
      x=t; p=1.0+eps; hh=h; m=1;
      for (j=0; j<=n-1; j++) u[j]=y[j];
      while (p>=eps)
      { 
		  for (j=0; j<=n-1; j++)
          { 
			  v[j]=y[j]; y[j]=u[j]; g[j]=q[j];
		  }
          dt=h/m; t=x;
          for (k=0; k<=m-1; k++)
          { 
			  (*f)(t,y,n,d);
              for (ii=0; ii<=3; ii++)
              { 
				  for (j=0; j<=n-1; j++) d[j]=d[j]*hh;
                  for (j=0; j<=n-1; j++)
                  { 
					  r=(a[ii]*(d[j]-b[ii]*g[j])+y[j])-y[j];
                      y[j]=y[j]+r;
                      s=g[j]+3.0*r;
                      g[j]=s-c[ii]*d[j];
                  }
                  t0=t+e[ii]*hh;
                  (*f)(t0,y,n,d);
              }
              t=t+dt;
          }
          p=0.0;
          for (j=0; j<=n-1; j++)
          { 
			  qq=fabs(y[j]-v[j]);
              if (qq>p) p=qq;
          }
          hh=hh/2.0; m=m+m;
      }
      for (j=0; j<=n-1; j++) q[j]=g[j];
      delete[] g; delete[] d; delete[] u; delete[] v;
      return;
  }

/*
//�䲽��Gill������
  #include <iostream>
  #include <cmath>
  #include <iomanip>
//  #include "�䲽��Gill����.cpp"
  using namespace std;
  int main()
  { 
	  int i,j;
      void  gillf(double,double [],int,double []);
      double t,h,eps;
      double q[3]={0.0,0.0,0.0};
      double y[3]={0.0,1.0,1.0};
      t=0.0; h=0.1; eps=0.0000001;
      cout <<"t = " <<t;
      for (i=0; i<=2; i++)
		  cout <<"  y(" <<i <<") = " <<setw(10) <<y[i];
      cout <<endl;
      for (j=1; j<=10; j++)
      { 
		  gill(t,h,3,y,eps,q,gillf);
          t=t+h;
          cout <<"t = " <<t;
          for (i=0; i<=2; i++)
			  cout <<"  y(" <<i <<") = " <<setw(10) <<y[i];
          cout <<endl;
      }
	  return 0;
  }
//����΢�ַ������и������Ҷ˺���ֵ
  void gillf(double t, double y[], int n, double d[])
  { 
	  t=t; n=n;
      d[0]=y[1]; d[1]=-y[0]; d[2]=-y[2];
      return;
  }
*/