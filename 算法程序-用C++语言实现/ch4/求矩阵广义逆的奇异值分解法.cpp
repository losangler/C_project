//���������������ֵ�ֽⷨ.cpp
  #include <cmath>
  #include <iostream>
  #include "ʵ���������ֵ�ֽ�.cpp"
  using namespace std;
//a[m]n]     ���m��n��ʵ����A��
//           ����ʱ��Խ��߸�������ֵ���Էǵ����������У�������Ԫ�ؾ�Ϊ0��
//aa[n][m]   ����A�Ĺ�����  ��
//eps        �����ľ���Ҫ��
//u[m][m]    ��������������U��
//v[n][n]    ��������������V��
//ka         ��ֵΪmax(m��n)��1��
  //�������ر�־ֵ����С��0�����ʾʧ�ܣ�������0�����ʾ������
  int ginv(double a[],int m,int n,double aa[],double eps,double u[],double v[],int ka)
  { 
	  int i,j,k,l,t,p,q,f;
      i=muav(a,m,n,u,v,eps,ka);
      if (i<0) return(-1);
      j=n;
      if (m<n) j=m;
      j=j-1;
      k=0;
      while ((k<=j)&&(a[k*n+k]!=0.0)) k=k+1;
      k=k-1;
      for (i=0; i<=n-1; i++)
      for (j=0; j<=m-1; j++)
      { 
		  t=i*m+j; aa[t]=0.0;
          for (l=0; l<=k; l++)
          {
			  f=l*n+i; p=j*m+l; q=l*n+l;
              aa[t]=aa[t]+v[f]*u[p]/a[q];
          }
      }
      return(1);
  }
/*
  #include <cmath>
  #include <iostream>
//  #include "���������������ֵ�ֽⷨ.cpp"
  using namespace std;
  int main()
  { 
	  int m,n,ka,i,j;
      double a[5][4]={ {1.0,2.0,3.0,4.0},
                  {6.0,7.0,8.0,9.0},{1.0,2.0,13.0,0.0},
                  {16.0,17.0,8.0,9.0},{2.0,4.0,3.0,4.0}};
      double aa[4][5],c[5][4],u[5][5],v[4][4];
      double eps;
      m=5; n=4; ka=6; eps=0.000001;
      cout <<"MAT A IS:\n";
      for (i=0; i<=4; i++)
      { 
		  for (j=0; j<=3; j++)  cout <<a[i][j] <<"    ";
          cout <<endl;
      }
      i=ginv(&a[0][0],m,n,&aa[0][0],eps,&u[0][0],&v[0][0],ka);
      if (i<0)  return 0;
	  cout <<"MAT A+ IS:\n";
	  for (i=0; i<=3; i++)
      { 
		  for (j=0; j<=4; j++)  cout <<aa[i][j] <<"    ";
          cout <<endl;
      }
      i=ginv(&aa[0][0],n,m,&c[0][0],eps,&v[0][0],&u[0][0],ka);
      if (i<0)  return 0;
      cout <<"MAT A++ IS:\n";
      for (i=0; i<=4; i++)
      { 
		  for (j=0; j<=3; j++)  cout <<c[i][j] <<"    ";
          cout <<endl;
      }
      return 0;
  }
*/