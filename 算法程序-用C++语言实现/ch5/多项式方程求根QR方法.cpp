//����ʽ�������QR����.cpp
  #include <cmath>
  #include <iostream>
  #include "����H��������ֵ��QR����.cpp"
  using namespace std;
//a[n+1]       ���n�ζ���ʽ��n+1��ϵ����
//n            ����ʽ������
//xr[n]        ����n������ʵ����
//xi[n]        ����n�������鲿��
//eps          ���ƾ���Ҫ��
  //��������������H��������ֵʱ���صı�־ֵ����>0��������
  int qrrt(double a[], int n, double xr[], double xi[], double eps)
  { 
	  int i,j;
      double *q;
      q = new double[n*n];
      for (j=0; j<=n-1; j++) q[j]=-a[n-j-1]/a[n];
      for (j=n; j<=n*n-1; j++) q[j]=0.0;
      for (i=0; i<=n-2; i++) q[(i+1)*n+i]=1.0;
      i=hhqr(q,n,xr,xi,eps);
      delete[] q; return(i);
  }

/*
//����ʽ�������QR������
  #include <cmath>
  #include <iostream>
//  #include "����ʽ�������QR����.cpp"
  using namespace std;
  int main()
  { 
	  int i, n;
      double xr[6],xi[6],eps;
      double a[7]={-30.0,10.5,-10.5,1.5,4.5,-7.5,1.5};
      eps=0.000001;  n=6;
      i=qrrt(a,n,xr,xi,eps);
      if (i>0)
      { for (i=0; i<=5; i++)
          cout <<"x(" <<i <<") = " <<xr[i] <<"   J " <<xi[i] <<endl;
      }
	  return 0;
  }
*/
