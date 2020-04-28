//jacobi��.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//a[n][n]        ʵ�Գƾ��󡣶Խ���Ԫ�ط�������ֵ��
//v[n][n]        ������������
//eps            ����Ҫ��
  //�����󲻶Գƣ�����ʾ������Ϣ���ҷ���0��־ֵ�����򷵻ص���������
  //������������200�Ρ�
  int jacobi(double a[],int n,double v[],double eps)
  { 
	  int i,j,p,q,u,w,t,s,count;
      double fm,cn,sn,omega,x,y,d;
      for (i=0; i<n; i++)
		  for (j=i+1; j<n; j++)
			  if (a[i*n+j]!=a[j*n+i])
			  {
				  cout <<"���󲻶Գƣ�" <<endl;  return 0;
			  }
      for (i=0; i<=n-1; i++)
      { 
		  v[i*n+i]=1.0;
          for (j=0; j<=n-1; j++)
            if (i!=j) v[i*n+j]=0.0;
      }
	  count=1;
      while (count<=200)
      { 
		  fm=0.0;
          for (i=1; i<=n-1; i++)
          for (j=0; j<=i-1; j++)
          { 
			  d=fabs(a[i*n+j]);
              if ((i!=j)&&(d>fm))  { fm=d; p=i; q=j;}
          }
          if (fm<eps)   return(count);
          count=count+1;
          u=p*n+q; w=p*n+p; t=q*n+p; s=q*n+q;
          x=-a[u]; y=(a[s]-a[w])/2.0;
          omega=x/sqrt(x*x+y*y);
          if (y<0.0) omega=-omega;
          sn=1.0+sqrt(1.0-omega*omega);
          sn=omega/sqrt(2.0*sn);
          cn=sqrt(1.0-sn*sn);
          fm=a[w];
          a[w]=fm*cn*cn+a[s]*sn*sn+a[u]*omega;
          a[s]=fm*sn*sn+a[s]*cn*cn-a[u]*omega;
          a[u]=0.0; a[t]=0.0;
          for (j=0; j<=n-1; j++)
          if ((j!=p)&&(j!=q))
          { 
			  u=p*n+j; w=q*n+j;
              fm=a[u];
              a[u]=fm*cn+a[w]*sn;
              a[w]=-fm*sn+a[w]*cn;
          }
          for (i=0; i<=n-1; i++)
          if ((i!=p)&&(i!=q))
          { 
			  u=i*n+p; w=i*n+q;
              fm=a[u];
              a[u]=fm*cn+a[w]*sn;
              a[w]=-fm*sn+a[w]*cn;
          }
          for (i=0; i<=n-1; i++)
          { 
			  u=i*n+p; w=i*n+q;
              fm=v[u];
              v[u]=fm*cn+v[w]*sn;
              v[w]=-fm*sn+v[w]*cn;
          }
      }
      return(count);
  }

/*
  #include <cmath>
  #include <iostream>
//  #include "jacobi��.cpp"
  using namespace std;
  int main()
  { 
	  int i,j;
      double eps, v[3][3];
      double a[3][3]={ {2.0,-1.0,0.0},
	  {-1.0,2.0,-1.0},
      {0.0,-1.0,2.0}};
      eps=0.000001;
      i=jacobi(&a[0][0],3,&v[0][0],eps);
	  cout <<"��������= " <<i <<endl;
      if (i>0)
      { 
		  cout <<"����ֵ:" <<endl;
		  for (i=0; i<=2; i++)  cout <<a[i][i] <<"    ";
          cout <<endl;
		  cout <<"��������:" <<endl;
          for (i=0; i<=2; i++)
          { 
			  for (j=0; j<=2; j++)  cout <<v[i][j] <<"    ";
              cout <<endl;
          }
      }
      return 0;
  }
*/
/*
  #include <cmath>
  #include <iostream>
//  #include "jacobi��.cpp"
  using namespace std;
  int main()
  { 
	  int i,j;
      double eps, v[5][5];
      double a[5][5]={ {10,1,2,3,4},
	  {1,9,-1,2,-3},
      {2,-1,7,3,-5},
	  {3,2,3,12,-1},
	  {4,-3,-5,-1,15}};
      eps=0.000001;
      i=jacobi(&a[0][0],5,&v[0][0],eps);
	  cout <<"��������= " <<i <<endl;
      if (i>0)
      { 
		  cout <<"����ֵ:" <<endl;
		  for (i=0; i<=4; i++)  cout <<a[i][i] <<"    ";
          cout <<endl;
		  cout <<"��������:" <<endl;
          for (i=0; i<=4; i++)
          { 
			  for (j=0; j<=4; j++)  cout <<v[i][j] <<"    ";
              cout <<endl;
          }
      }
      return 0;
  }
*/