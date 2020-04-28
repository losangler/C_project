//�Գ����������Cholesky�ֽ�.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//a[n][n]       ��ŶԳ���������A��
//              ����ʱ�������ǲ��ִ�ŷֽ�õ�����������L������Ԫ�ؾ�Ϊ0��
  //�������ر�־ֵ��������0�����ʾʧ�ܣ�������0�����ʾ������
  int chol(double a[],int n)
  { int i,j,k,u,l;
    if ((a[0]+1.0==1.0)||(a[0]<0.0))
	{ cout <<"fail!\n"; return(0); }
    a[0]=sqrt(a[0]);
    for (i=1; i<=n-1; i++)
      { u=i*n; a[u]=a[u]/a[0];}
    for (j=1; j<=n-1; j++)
      { l=j*n+j;
        for (k=0; k<=j-1; k++)
          { u=j*n+k; a[l]=a[l]-a[u]*a[u];}
        if ((a[l]+1.0==1.0)||(a[l]<0.0))
		{  cout <<"fail!\n";  return(0); }
        a[l]=sqrt(a[l]);
        for (i=j+1; i<=n-1; i++)
          { u=i*n+j;
            for (k=0; k<=j-1; k++)
              a[u]=a[u]-a[i*n+k]*a[j*n+k];
            a[u]=a[u]/a[l];
          }
      }
    for (i=0; i<=n-2; i++)
    for (j=i+1; j<=n-1; j++) a[i*n+j]=0.0;
    return(1);
  }
/*
  #include <cmath>
  #include <iostream>
//  #include "�Գ����������Cholesky�ֽ�.cpp"
  using namespace std;
  int main()
  { 
	  int i,j;
      double a[4][4]={ {5.0,7.0,6.0,5.0},
                            {7.0,10.0,8.0,7.0},
                            {6.0,8.0,10.0,9.0},
                            {5.0,7.0,9.0,10.0}};
      i=chol(&a[0][0],4);
      if (i>0)
      { 
		  cout <<"MAT L:\n";
          for (i=0; i<=3; i++)
          { 
			  for (j=0; j<=3; j++)  cout <<a[i][j] <<"    ";
              cout <<endl;
          }
      }
	  return 0;
  }
*/