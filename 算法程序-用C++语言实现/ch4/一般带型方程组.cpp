//һ����ͷ�����.cpp
  #include <iostream>
  #include <cmath>
  using namespace  std;
//b[n][il]       ��Ŵ��;�������ڵ�Ԫ�أ�����ʱ�����ƻ���
//d[n][m]        ��ŷ������Ҷ�m�鳣�����������ط������m���������
//n              �����������
//l              ϵ������İ����
//il             ϵ������Ĵ���Ӧ���� il = 2l + 1��
//m              �������Ҷ˳���������������
  //�������ر�־ֵ����<0���ʾ����������ֵ���ԣ���=0���ʾʧ�ܣ���>0���ʾ������
  int band(double b[], double d[], int n, int l, int il, int m)
  { 
	  int ls,k,i,j,is,u,v;
      double p,t;
      if (il!=(2*l+1)) return(-2);
      ls=l;
      for (k=0;k<=n-2;k++)
      { 
		  p=0.0;
          for (i=k;i<=ls;i++)
          { 
			  t=fabs(b[i*il]);
              if (t>p) {p=t; is=i;}
          }
          if (p+1.0==1.0)  return(0);
          for (j=0;j<=m-1;j++)
          { 
			  u=k*m+j; v=is*m+j;
              t=d[u]; d[u]=d[v]; d[v]=t;
          }
          for (j=0;j<=il-1;j++)
          { 
			  u=k*il+j; v=is*il+j;
              t=b[u]; b[u]=b[v]; b[v]=t;
          }
          for (j=0;j<=m-1;j++)
          { 
			  u=k*m+j; d[u]=d[u]/b[k*il];
		  }
          for (j=1;j<=il-1;j++)
          { 
			  u=k*il+j; b[u]=b[u]/b[k*il];
		  }
          for (i=k+1;i<=ls;i++)
          { 
			  t=b[i*il];
              for (j=0;j<=m-1;j++)
              { 
				  u=i*m+j; v=k*m+j; d[u]=d[u]-t*d[v];
              }
              for (j=1;j<=il-1;j++)
              { 
				  u=i*il+j; v=k*il+j;  b[u-1]=b[u]-t*b[v];
              }
              u=i*il+il-1; b[u]=0.0;
		  }
          if (ls!=(n-1)) ls=ls+1;
      }
      p=b[(n-1)*il];
      if (fabs(p)+1.0==1.0)  return(0);
      for (j=0;j<=m-1;j++)
      {
		  u=(n-1)*m+j; d[u]=d[u]/p;
	  }
      ls=1;
      for (i=n-2;i>=0;i--)
      { 
		  for (k=0;k<=m-1;k++)
          { 
			  u=i*m+k;
              for (j=1;j<=ls;j++)
              { 
				  v=i*il+j; is=(i+j)*m+k;
                  d[u]=d[u]-b[v]*d[is];
              }
          }
          if (ls!=(il-1)) ls=ls+1;
      }
      return(2);
  }

/*
  #include <iostream>
  #include <cmath>
  #include <iomanip>
//  #include "һ����ͷ�����.cpp"
  using namespace  std;
  int main()
  { 
	  int i, j;
      double b[8][5]={ {3.0,-4.0,1.0,0.0,0.0},
	  {-2.0,-5.0,6.0,1.0,0.0},
	  {1.0,3.0,-1.0,2.0,-3.0},
	  {2.0,5.0,-5.0,6.0,-1.0},
	  {-3.0,1.0,-1.0,2.0,-5.0},
	  {6.0,1.0,-3.0,2.0,-9.0},
	  {-4.0,1.0,-1.0,2.0,0.0},
	  {5.0,1.0,-7.0,0.0,0.0}};
      double d[8][3]={ {13.0,29.0,-13.0},
	  {-6.0,17.0,-21.0},{-31.0,-6.0,4.0},{64.0,3.0,16.0},
	  {-20.0,1.0,-5.0},{-22.0,-41.0,56.0},{-29.0,10.0,-21.0},
	  {7.0,-24.0,20.0}};
      i=band(&b[0][0], &d[0][0],8,2,5,3);
	  if (i>0)
      for (i=0; i<=7; i++)
	  {
		  cout <<"x(" <<i << ") = ";
		  for (j=0; j<=2; j++)
			  cout <<setw(15) <<d[i][j];
		  cout <<endl;
	  }
	  return 0;
  }
*/
