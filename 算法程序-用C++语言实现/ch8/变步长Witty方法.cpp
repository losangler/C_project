//�䲽��Witty����.cpp
  #include <iostream>
  #include <cmath>
  using namespace std;
//t           ������ʼ�㡣
//h           ���ֲ�����
//n           һ��΢�ַ������з��̸�����Ҳ��δ֪����������
//y[n]        ���n��δ֪��������ʼ��t���ĺ���ֵ��
//            ����n��δ֪������t+h���ĺ���ֵ��
//eps         ���ƾ���Ҫ��
//f           ����΢�ַ������и������Ҷ˺���ֵ�ĺ�������
  void witty(double t, double h, int n, double y[], double eps, 
	                   void (*f)(double,double [],int,double []))
  { 
	  int i,j,m;
      double x,hh,p,s,*q,*u,*v,*a,*d;
      q=new double[n];
      u=new double[n];
      v=new double[n];
      a=new double[n];
      d=new double[n];
      for (i=0; i<=n-1; i++)  u[i] = y[i];
	  hh=h; m=1; p=1.0+eps;
	  while(p>=eps)
	  {
		  for (i=0; i<=n-1; i++)
		  {
			  v[i]=y[i]; y[i]=u[i];
		  }
		  (*f)(t,y,n,d);
          for (j=0; j<=m-1; j++)
		  {
			  for (i=0; i<=n-1; i++)
                  a[i]=y[i]+hh*d[i]/2.0;
              x=t+(j+0.5)*hh;
              (*f)(x,a,n,q);
              for (i=0; i<=n-1; i++)
			  { 
				  y[i]=y[i]+hh*q[i];
				  d[i]=2.0*q[i]-d[i];
			  }
		  }
		  p=0.0;
		  for (i=0; i<=n-1; i++)
		  {
			  s = fabs(y[i]-v[i]);
			  if (s>p) p = s;
		  }
		  hh = hh/2.0; m = m + m;
      }
    delete[] a; delete[] d;
    return;
  }

/*
//�䲽��Witty������
  #include <iostream>
  #include <cmath>
  #include <iomanip>
//  #include "�䲽��Witty����.cpp"
  using namespace std;
  int main()
  {  
	  int i,j;
      void wityf(double,double [],int,double []);
      double t,h,eps,y[3];
      y[0]=-1.0; y[1]=0.0; y[2]=1.0;
      t=0.0; h=0.1; eps=0.0000001;
      cout <<"t = " <<t;
      for (i=0; i<=2; i++)
		  cout <<"  y(" <<i <<") = " <<setw(10) <<y[i];
      cout <<endl;
      for (j=1; j<=10; j++)
      { 
		  witty(t,h,3,y,eps,wityf);
          t=t+h;
          cout <<"t = " <<t;
          for (i=0; i<=2; i++)
			  cout <<"  y(" <<i <<") = " <<setw(10) <<y[i];
          cout <<endl;
      }
	  return 0;
  }
//����΢�ַ������и������Ҷ˺���ֵ
  void wityf(double t, double y[], int n, double d[])
  { 
	  t=t; n=n;
      d[0]=y[1]; d[1]=-y[0]; d[2]=-y[2];
      return;
  }
*/