//��������Ƿֽ�.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//a[n][n]        ���n�׾���A������ʱ���Q����
//l[n][n]        ����ʱ��������Ǿ���L��
//u[n][n]        ����ʱ��������Ǿ���U��
  //�������ر�־ֵ����Ϊ0�����ʾʧ�ܣ�����Ϊ0�����ʾ������
  int lluu(double a[],int n,double l[],double u[])
  { 
	  int i,j,k,w,v,ll;
      for (k=0; k<=n-2; k++)
      { 
		  ll=k*n+k;
	      if (fabs(a[ll])+1.0==1.0)   //���½�������a[k][k]=0
		  { 
			  cout <<"����ʧ�ܣ�\n"; return 0;
		  }
          for (i=k+1; i<=n-1; i++)
		  { 
			  w=i*n+k; a[w]=a[w]/a[ll];
		  }
          for (i=k+1; i<=n-1; i++)
		  {
			  w=i*n+k;
              for (j=k+1; j<=n-1; j++)
			  {
				  v=i*n+j; a[v]=a[v]-a[w]*a[k*n+j]; 
			  }
		  }
	  }
      for (i=0; i<=n-1; i++)
      { 
		  for (j=0; j<i; j++)      //L-I
		  { 
			  w=i*n+j; l[w]=a[w]; u[w]=0.0;
		  }
          w=i*n+i;
          l[w]=1.0; u[w]=a[w];
          for (j=i+1; j<=n-1; j++)    //U
          { 
			  w=i*n+j; l[w]=0.0; u[w]=a[w];
		  }
      }
      return 1;
  }

/*
  #include <cmath>
  #include <iostream>
//  #include "��������Ƿֽ�.cpp"
  using namespace std;
  int main()
  { 
	  int i,j;
      double l[4][4],u[4][4];
      double q[4][4],a[4][4]={ {2.0,4.0,4.0,2.0},
                            {3.0,3.0,12.0,6.0},
                            {2.0,4.0,-1.0,2.0},
                            {4.0,2.0,1.0,1.0}};
      for (i=0; i<=3; i++)
		  for (j=0; j<=3; j++)  q[i][j]=a[i][j];
	  i=lluu(&q[0][0],4,&l[0][0],&u[0][0]);
	  if (i==0) return 0;
	  cout <<"MAT Q=L+U-I:\n";
      for (i=0; i<=3; i++)
      {
		  for (j=0; j<=3; j++)  cout <<q[i][j] <<"    ";
          cout <<endl;
      }
	  cout <<"MAT L:\n";
      for (i=0; i<=3; i++)
      {
		  for (j=0; j<=3; j++)  cout <<l[i][j] <<"    ";
          cout <<endl;
      }
      cout <<"MAT U:\n";
      for (i=0; i<=3; i++)
      { 
		  for (j=0; j<=3; j++)  cout <<u[i][j] <<"    ";
          cout <<endl;
      }
	  return 0;
  }
*/