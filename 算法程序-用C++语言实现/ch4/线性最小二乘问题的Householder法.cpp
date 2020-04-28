//������С���������Householder��.cpp
  #include <iostream>
  #include <cmath>
  #include "ʵ�����QR�ֽ�.cpp"
  using namespace  std;
//a[m][n]        �����������ϵ�����󣬷���ʱ���QR�ֽ�ʽ�е�R����
//m              ���̸�����Ҳ��ϵ������������
//n              δ֪��������Ҳ��ϵ�������������Ҫ�� m>=n ��
//b[m]           ��ŷ������Ҷ˵ĳ�������������ʱǰn��������ŷ��������С���˽⡣
//q[m][m]        ����QR�ֽ�ʽ�е���������Q��
  //�������ر�־ֵ����=0���ʾʧ�ܣ������ʾ������
  int gmqr(double a[], int m, int n, double b[], double q[])
  { 
	  int i,j;
      double d,*c;
      c=new double[n];
      i=maqr(a,m,n,q);
      if (i==0) 
	  { 
		  delete[] c; return(0);
	  }
      for (i=0; i<=n-1; i++)
      { 
		  d=0.0;
          for (j=0; j<=m-1; j++) d=d+q[j*m+i]*b[j];
          c[i]=d;
      }
      b[n-1]=c[n-1]/a[n*n-1];
      for (i=n-2; i>=0; i--)
      { 
		  d=0.0;
          for (j=i+1; j<=n-1; j++) d=d+a[i*n+j]*b[j];
          b[i]=(c[i]-d)/a[i*n+i];
      }
      delete[] c; return(1);
  }

/*
  #include <iostream>
  #include <iomanip>
  #include <cmath>
//  #include "������С���������Householder��.cpp"
  using namespace  std;
  int main()
  { int i,j,m,n;
    double a[4][3]={ {1.0,1.0,-1.0},{2.0,1.0,0.0},
                            {1.0,-1.0,0.0},{-1.0,2.0,1.0}};
    double b[4]={2.0,-3.0,1.0,4.0};
    double q[4][4];
    m=4; n=3;
    i=gmqr(&a[0][0],m,n,b,&q[0][0]);
    if (i!=0)
    { 
		cout <<"��С���˽� :" <<endl;
		for (i=0; i<=2; i++)
            cout <<"x(" <<i <<") = " <<b[i] <<endl;
        cout <<"��������Q :" <<endl;
        for (i=0; i<=3; i++)
		{
			for (j=0; j<=3; j++)
				cout <<setw(15) <<q[i][j];
            cout <<endl;
		}
        cout <<"����R :" <<endl;
        for (i=0; i<=3; i++)
		{
			for (j=0; j<=2; j++)
				cout <<setw(15) <<a[i][j];
            cout <<endl;
		}
	}
	return 0;
  }
*/
