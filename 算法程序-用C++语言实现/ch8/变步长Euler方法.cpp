//�䲽��Euler����.cpp
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
  void euler(double t, double h, int n, double y[], double eps, 
	                   void (*f)(double,double [],int,double []))
  { 
	  int i,j,m;
      double hh,p,x,q,*a,*b,*c,*d;
      a=new double[n];
      b=new double[n];
      c=new double[n];
      d=new double[n];
      hh=h; m=1; p=1.0+eps;
      for (i=0; i<=n-1; i++) a[i]=y[i];
      while (p>=eps)
      { 
		  for (i=0; i<=n-1; i++)
          { 
			  b[i]=y[i]; y[i]=a[i];
		  }
          for (j=0; j<=m-1; j++)
          { 
			  for (i=0; i<=n-1; i++) c[i]=y[i];
              x=t+j*hh;
              (*f)(x,y,n,d);
              for (i=0; i<=n-1; i++)  y[i]=c[i]+hh*d[i];
              x=t+(j+1)*hh;
              (*f)(x,y,n,d);
              for (i=0; i<=n-1; i++)  d[i]=c[i]+hh*d[i];
              for (i=0; i<=n-1; i++)  y[i]=(y[i]+d[i])/2.0;
          }
          p=0.0;
          for (i=0; i<=n-1; i++)
          { 
			  q=fabs(y[i]-b[i]);
              if (q>p) p=q;
          }
          hh=hh/2.0; m=m+m;
      }
      delete[] a; delete[] b; delete[] c; delete[] d;
      return;
  }

/*
//�䲽��Euler������
  #include <iostream>
  #include <cmath>
  #include <iomanip>
//  #include "�䲽��Euler����.cpp"
  using namespace std;
  int main()
  { 
	  int i,j;
      void eulerf(double,double [],int,double []);
      double t,h,eps,y[3];
      y[0]=-1.0; y[1]=0.0; y[2]=1.0;
      t=0.0; h=0.01; eps=0.0000001;
      cout <<"t = " <<t;
      for (i=0; i<=2; i++)
		  cout <<"  y(" <<i <<") = " <<setw(10) <<y[i];
      cout <<endl;
      for (j=1; j<=10; j++)
      { 
		  euler(t,h,3,y,eps,eulerf);
          t=t+h;
          cout <<"t = " <<t;
          for (i=0; i<=2; i++)
			  cout <<"  y(" <<i <<") = " <<setw(10) <<y[i];
          cout <<endl;
      }
	  return 0;
  }
//����΢�ַ������и������Ҷ˺���ֵ
  void eulerf(double t, double y[], int n, double d[])
  { 
	  t=t; n=n;
      d[0]=y[1]; d[1]=-y[0]; d[2]=-y[2];
      return;
  }
*/