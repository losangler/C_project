//����Walsh�任.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//n        �������еĳ��ȡ�
//k
//p[n]     ��ų���Ϊn�ĸ����������С�
//x[n]     ���ظ����������е�Walsh�任���С�
  void kfwt(int n, int k, double p[], double x[])
  { 
	  int m,l,it,ii,i,j,is;
      double q;
      m =1; l=n; it=2;
      x[0]=1; ii=n/2; x[ii]=2;
      for (i=1; i<=k-1; i++)
      {
		  m=m+m; l=l/2; it=it+it;
          for (j=0; j<=m-1; j++) x[j*l+l/2]=it+1-x[j*l];
      }
      for (i=0; i<=n-1; i++)
      { 
		  ii=(int)(x[i]-1); x[i]=p[ii];
	  }
      l=1;
      for (i=1; i<=k; i++)
      { 
		  m=n/(2*l)-1;
          for (j=0; j<=m; j++)
          { 
			  it=2*l*j;
              for (is=0; is<=l-1; is++)
              { 
				  q=x[it+is]+x[it+is+l];
                  x[it+is+l]=x[it+is]-x[it+is+l];
                  x[it+is]=q;
              }
          }
        l=2*l;
      }
      return;
  }
/*
//����Walsh�任��
  #include <cmath>
  #include <iostream>
//  #include "����Walsh�任.cpp"
  using namespace std;
  int main()
  { 
	  int i;
      double p[8],x[8];
      for (i=0; i<=7; i++) p[i]=i+1;
      kfwt(8,3,p,x);
      for (i=0; i<=7; i++) 
		  cout <<"x(" <<i <<")=" <<x[i] <<endl;
      return 0;
  }
*/