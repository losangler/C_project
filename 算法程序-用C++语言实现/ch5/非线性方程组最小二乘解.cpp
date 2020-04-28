//�����Է�������С���˽�.cpp
  #include <cmath>
  #include <iostream>
  #include "������С��������Ĺ����淨.cpp"
  using namespace std;
//m          �����Է������з��̸�����
//n          �����Է�������δ֪��������m>=n��
//eps1       ������С���˽�ľ���Ҫ��
//eps2       ����ֵ�ֽ��еĿ��ƾ���Ҫ��
//x[n]       ��ų�ʼ����ֵ��������С���˽⣬��m=nʱ��Ϊ�����Է�����Ľ⡣
//f          ��������Է������������˺���ֵ�ĺ�������
//s          �����ſɱȾ���ĺ�������
  //�������ص�������������������������Ϊ100������������<0���ʾ����ֵ�ֽ�ʧ�ܡ�
  int ngin(int m, int n, double eps1, double eps2, double x[],
	      void (*f)(int, int, double[], double[]), void (*s)(int, int, double[], double[]))
  { 
	  int i,j,k,l,kk,jt,interation,ka;
      double y[10],b[10],alpha,z,h2,y1,y2,y3,y0,h1;
      double *p,*d,*pp,*dx,*u,*v,*w;
      p = new double[m*n];
      d = new double[m];
      pp = new double[n*m];
      dx = new double[n];
      u = new double[m*m];
      v = new double[n*n];
      w = new double[m+1];
	  interation = 100;        //����������
	  ka = m + 1;
      l=0; alpha=1.0;
      while (l<interation)
      { 
		  (*f)(m,n,x,d);              //��������Է������������˺���ֵ
		  (*s)(m,n,x,p);              //�����ſɱȾ���
          jt=gmiv(p,m,n,d,dx,pp,eps2,u,v,ka);   //�������
          if (jt<0)
          { 
			  delete[] p; delete[] d; delete[] pp; delete[] w;
              delete[] dx; delete[] u; delete[] v;
			  return(-1);
          }
          j=0; jt=1; h2=0.0;
          while (jt==1)
          { 
			  jt=0;
              if (j<=2) z=alpha+0.01*j;
              else z=h2;
              for (i=0; i<=n-1; i++) w[i]=x[i]-z*dx[i];
              (*f)(m,n,w,d);        //��������Է������������˺���ֵ
              y1=0.0;
              for (i=0; i<=m-1; i++) y1=y1+d[i]*d[i];
              for (i=0; i<=n-1; i++)  w[i]=x[i]-(z+0.00001)*dx[i];
              (*f)(m,n,w,d);       //��������Է������������˺���ֵ
              y2=0.0;
              for (i=0; i<=m-1; i++) y2=y2+d[i]*d[i];
              y0=(y2-y1)/0.00001;
              if (fabs(y0)>1.0e-10)
              { 
				  h1=y0; h2=z;
                  if (j==0) { y[0]=h1; b[0]=h2;}
                  else
                  { 
					  y[j]=h1; kk=0; k=0;
                      while ((kk==0)&&(k<=j-1))
                      { 
						  y3=h2-b[k];
                          if (fabs(y3)+1.0==1.0) kk=1;
                          else h2=(h1-y[k])/y3;
                          k=k+1;
                      }
                      b[j]=h2;
                      if (kk!=0) b[j]=1.0e+35;
                      h2=0.0;
                      for (k=j-1; k>=0; k--) h2=-y[k]/(b[k+1]+h2);
                      h2=h2+b[0];
                  }
                  j=j+1;
                  if (j<=7) jt=1;
                  else z=h2;
              }
          }
          alpha=z; y1=0.0; y2=0.0;
          for (i=0; i<=n-1; i++)
          { 
			  dx[i]=-alpha*dx[i];
              x[i]=x[i]+dx[i];
              y1=y1+fabs(dx[i]);
              y2=y2+fabs(x[i]);
          }
          if (y1<eps1*y2)
          { 
			  delete[] p; delete[] d; delete[] pp; delete[] w;
              delete[] dx; delete[] u; delete[] v;
			  return(l);
          }
          l = l + 1;
      }
	  delete[] p; delete[] d; delete[] pp; delete[] w;
      delete[] dx; delete[] u; delete[] v;
	  return(l);
  }
/*
//�����Է�������С���˽���1
  #include <cmath>
  #include <iostream>
//  #include "�����Է�������С���˽�.cpp"
  using namespace std;
  int main()
  { 
	  int m,n,i;
      double eps1,eps2;
      void nginf(int,int,double [],double []);
      void ngins(int,int,double [],double []);
      double x[2]={0.5,-1.0};
      m=2; n=2;  eps1=0.000001; eps2=0.000001;
      i=ngin(m,n,eps1,eps2,x,nginf,ngins);
	  if (i>0)
	  {
		  cout <<"�������� = " <<i <<endl;
          for (i=0; i<=1; i++)  cout <<"x(" <<i <<") = " <<x[i] <<endl;
      }
      return 0;
  }
//��������Է������������˺���ֵ
  void nginf(int m, int n, double x[], double d[])
  { 
	  m=m; n=n;
      d[0]=x[0]*x[0]+10.0*x[0]*x[1]+4.0*x[1]*x[1]+0.7401006;
      d[1]=x[0]*x[0]-3.0*x[0]*x[1]+2.0*x[1]*x[1]-1.0201228;
    return;
  }
//�����ſɱȾ���
  void ngins(int m, int n, double x[], double p[])
  { 
	  m=m;
      p[0*n+0] = 2.0*x[0]+10.0*x[1];     //p[0][0]
      p[0*n+1] = 10.0*x[0]+8.0*x[1];     //p[0][1]
      p[1*n+0] = 2.0*x[0]-3.0*x[1];      //p[1][0]
      p[1*n+1] = -3.0*x[0]+4.0*x[1];     //p[1][1]
      return;
  }
*/
/*
//�����Է�������С���˽���2
  #include <cmath>
  #include <iostream>
//  #include "�����Է�������С���˽�.cpp"
  using namespace std;
  int main()
  { 
	  int m,n,i;
      double eps1,eps2;
      void nginf(int,int,double [],double []);
      void ngins(int,int,double [],double []);
      double x[2]={1.0,-1.0};
      m=3; n=2; eps1=0.000001; eps2=0.000001;
      i = ngin(m,n,eps1,eps2,x,nginf,ngins);
	  if (i>0)
	  {
		  cout <<"�������� = " <<i <<endl;
          for (i=0; i<=1; i++)  cout <<"x(" <<i <<") = " <<x[i] <<endl;
      }
      return 0;
  }
//��������Է������������˺���ֵ
  void nginf(int m, int n, double x[], double d[])
  { 
	  m=m; n=n;
      d[0] = x[0]*x[0]+7.0*x[0]*x[1]+3.0*x[1]*x[1]+0.5;
      d[1] = x[0]*x[0]-2.0*x[0]*x[1]+x[1]*x[1]-1.0;
      d[2] = x[0]+x[1]+1.0;
      return;
  }
//�����ſɱȾ���
  void ngins(int m, int n, double x[], double p[])
  { 
	  m=m;
      p[0*n+0] = 2.0*x[0]+7.0*x[1];      //p[0][0]
      p[0*n+1] = 7.0*x[0]+6.0*x[1];      //p[0][1]
      p[1*n+0] = 2.0*x[0]-2.0*x[1];      //p[1][0]
      p[1*n+1] = -2.0*x[0]+2.0*x[1];     //p[1][1]
      p[2*n+0] = 1.0;                    //p[2][0]
      p[2*n+1] = 1.0;                    //p[2][1]
      return;
  }
*/