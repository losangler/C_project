//������С��������Ĺ����淨.cpp
  #include <iostream>
  #include <cmath>
  #include "���������������ֵ�ֽⷨ.cpp"
  using namespace  std;
//a[m][n]        �����������ϵ������A������ʱ��Խ������θ�������ֵ������Ԫ��Ϊ0��
//m              ���̸�����Ҳ��ϵ������������
//n              δ֪��������Ҳ��ϵ�������������Ҫ�� m>=n ��
//b[m]           ��ŷ������Ҷ˵ĳ���������
//x[n]           ����ʱ���������С���˽⡣
//aa[n][m]       ����ϵ������A�Ĺ�����A+��
//eps            ����ֵ�ֽ��еĿ��ƾ���Ҫ��
//u[m][m]        ����A������ֵ�ֽ�ʽ�е�����������U��
//v[n][n]        ����A������ֵ�ֽ�ʽ�е�����������V+��
//ka             ka = max(m,n) + 1��
  //�������ر�־ֵ����<0���ʾʧ�ܣ���>0���ʾ������
  int gmiv(double a[], int m, int n, double b[], double x[],
	         double aa[], double eps, double u[], double v[], int ka)
  { 
	  int i,j;
      i=ginv(a,m,n,aa,eps,u,v,ka);
      if (i<0) return(-1);
      for (i=0; i<=n-1; i++)
      { 
		  x[i]=0.0;
          for (j=0; j<=m-1; j++)  x[i]=x[i]+aa[i*m+j]*b[j];
      }
      return(1);
  }

/*
  #include <iostream>
  #include <cmath>
  #include <iomanip>
//  #include "������С��������Ĺ����淨.cpp"
  using namespace  std;
  int main()
  { 
	  int i,j,m,n,ka;
      double x[3],aa[3][4],u[4][4],v[3][3];
      double a[4][3]={ {1.0,1.0,-1.0},{2.0,1.0,0.0},
                            {1.0,-1.0,0.0},{-1.0,2.0,1.0}};
      double b[4]={2.0,-3.0,1.0,4.0};
      double eps;
      m=4; n=3; ka=5; eps=0.000001;
      i=gmiv(&a[0][0],m,n,b,x,&aa[0][0],eps,&u[0][0],&v[0][0],ka);
      if (i>0)
      { 
		  cout <<"��С���˽� :" <<endl;
		  for (i=0; i<=2; i++)
              cout <<"x(" <<i <<") = " <<x[i] <<endl;
          cout <<"������ A+ :\n";
          for (i=0; i<=2; i++)
		  {
			  for (j=0; j<=3; j++)
				  cout <<setw(15) <<aa[i][j];
			  cout <<endl;
		  }
      }
	  return 0;
  }
*/
