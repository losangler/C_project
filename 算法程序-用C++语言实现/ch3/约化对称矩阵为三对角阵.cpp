//Լ���Գƾ���Ϊ���Խ���.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//a[n][n]        ���n��ʵ�Գƾ���A��
//q[n][n]        ���غ�˹�ɶ��±任�ĳ˻�����Q��
//b[n]           ���ضԳ��������е����Խ���Ԫ�ء�
//c[n]           ǰn-1��Ԫ�ط��ضԳ��������еĴζԽ���Ԫ�ء�
  //������ǶԳƣ�����ʾ������Ϣ��������0��־ֵ�����򷵻ط�0��־ֵ��
  int strq(double a[],int n,double q[],double b[],double c[])
  { 
	  int i,j,k,u;
      double h,f,g,h2;
	  for (i=0; i<n; i++)
		  for (j=0; j<i-1; j++)
			  if (a[i*n+j]!=a[j*n+i]) 
			  {
				  cout <<"���󲻶Գƣ�" <<endl;  return 0;
			  }
      for (i=0; i<=n-1; i++)
      for (j=0; j<=n-1; j++)
      { 
		  u=i*n+j; q[u]=a[u];
	  }
      for (i=n-1; i>=1; i--)
      { 
		  h=0.0;
          if (i>1)
          for (k=0; k<=i-1; k++)
          { 
			  u=i*n+k; h=h+q[u]*q[u];
		  }
          if (h+1.0==1.0)
          { 
			  c[i]=0.0;
              if (i==1) c[i]=q[i*n+i-1];
              b[i]=0.0;
          }
          else
          { 
			  c[i]=sqrt(h);
              u=i*n+i-1;
              if (q[u]>0.0) c[i]=-c[i];
              h=h-q[u]*c[i];
              q[u]=q[u]-c[i];
              f=0.0;
              for (j=0; j<=i-1; j++)
              { 
				  q[j*n+i]=q[i*n+j]/h;
                  g=0.0;
                  for (k=0; k<=j; k++) g=g+q[j*n+k]*q[i*n+k];
                  if (j+1<=i-1)
                  for (k=j+1; k<=i-1; k++) g=g+q[k*n+j]*q[i*n+k];
                  c[j]=g/h;
                  f=f+g*q[j*n+i];
              }
              h2=f/(h+h);
              for (j=0; j<=i-1; j++)
              { 
				  f=q[i*n+j];
                  g=c[j]-h2*f;
                  c[j]=g;
                  for (k=0; k<=j; k++)
                  { 
					  u=j*n+k;
                      q[u]=q[u]-f*c[k]-g*q[i*n+k];
                  }
			  }
            b[i]=h;
		  }
	  }
      for (i=0; i<=n-2; i++) c[i]=c[i+1];
      c[n-1]=0.0;
      b[0]=0.0;
      for (i=0; i<=n-1; i++)
      { 
		  if ((b[i]!=0.0)&&(i-1>=0))
          for (j=0; j<=i-1; j++)
          { 
			  g=0.0;
              for (k=0; k<=i-1; k++)  g=g+q[i*n+k]*q[k*n+j];
              for (k=0; k<=i-1; k++)
              { 
				  u=k*n+j;
                  q[u]=q[u]-g*q[k*n+i];
              }
		  }
          u=i*n+i;
          b[i]=q[u]; q[u]=1.0;
          if (i-1>=0)
          for (j=0; j<=i-1; j++)
          { 
			  q[i*n+j]=0.0; q[j*n+i]=0.0;
		  }
      }
      return 1;
  }

/*
  #include <cmath>
  #include <iostream>
//  #include "Լ���Գƾ���Ϊ���Խ���.cpp"
  using namespace std;
  int main()
  { 
	  int i,j;
      double b[5],c[5],q[5][5];
      double a[5][5]={ {10.0,1.0,2.0,3.0,4.0},
        {1.0,9.0,-1.0,2.0,-3.0},
	  {2.0,-1.0,7.0,3.0,-5.0},
        {3.0,2.0,3.0,12.0,-1.0},
	  {4.0,-3.0,-5.0,-1.0,15.0}};
      i=strq(&a[0][0],5,&q[0][0],b,c);
	  if (i==0) return 0;
      cout <<"�Գƾ��� A :\n";
      for (i=0; i<=4; i++)
      { 
		  for (j=0; j<=4; j++)  cout <<a[i][j] <<"    ";
          cout <<endl;
      }
      cout <<"���صĳ˻����� Q :\n";
      for (i=0; i<=4; i++)
      { 
		  for (j=0; j<=4; j++)  cout <<q[i][j] <<"    ";
          cout <<endl;
      }
      cout <<"���ص����Խ���Ԫ�� B :\n";
      for (i=0; i<=4; i++)  cout <<b[i] <<"    ";
      cout <<endl;
      cout <<"���صĴζԽ���Ԫ�� C :\n";
      for (i=0; i<=4; i++)  cout <<c[i] <<"    ";
      cout <<endl;
	  return 0;
  }
*/