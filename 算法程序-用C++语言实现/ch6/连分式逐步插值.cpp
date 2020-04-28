//����ʽ�𲽲�ֵ.cpp
  #include <cmath>
  #include <iostream>
  #include "���㺯������ʽ��һ��.cpp"
  #include "���㺯������ʽֵ.cpp"
  using namespace std;
//x[n]      ��Ž��ֵx[0]��x[n-1]
//y[n]      ��Ž�㺯��ֵy[0]��y[n-1]
//n         ���ݵ������ʵ�ʲ�ֵʱ���ȡ���ֵ��t����İ˸��㡣
//eps       ����Ҫ��
//t         ��ֵ��ֵ
  //���ز�ֵ��t��������ʽ����ֵ
  double funpq(double x[],double y[],int n,double eps,double t)
  { 
	  int i,j,k,l,m;
      double p,q,u;
	  double b[8],xx[8],yy[8];  //���ȡ���ֵ��t����İ˸���
      p=0.0;
      if (n<1) return(p);              //���������ԣ�����
      if (n==1) { p=y[0]; return(p);}  //ֻ��һ����㣬ȡֵ����
      m=8;                            //���ȡ8����
      if (m>n) m=n;
      if (t<=x[0]) k=1;                //��һ��������ֵ�����
      else if (t>=x[n-1]) k=n;         //���һ��������ֵ�����
      else
      { 
		  k=1; j=n;
          while ((k-j!=1)&&(k-j!=-1))  //���ַ�Ѱ�����ֵ������ĵ�
          { 
			  l=(k+j)/2;
              if (t<x[l-1]) j=l;
              else k=l;
          }
          if (fabs(t-x[l-1])>fabs(t-x[j-1])) k=j;
      }
      j=1; l=0;
      for (i=1;i<=m;i++)          //�����ݱ���ȡm�����
      { 
		  k=k+j*l;
          if ((k<1)||(k>n))
          { 
			  l=l+1; j=-j; k=k+j*l;
		  }
          xx[i-1]=x[k-1]; yy[i-1]=y[k-1];
          l=l+1; j=-j;
      }
      j=0; b[0]=yy[0]; p=b[0];
	  u=1.0+eps;
	  while ((j<m-1)&&(u>=eps))
	  {
		  j=j+1;
		  funpqj(xx,yy,b,j);       //������һ�ڵ�b[j]
          q=funpqv(xx,b,j,t);      //���㺯������ʽ��t���ĺ���ֵ
		  u=(fabs(q-p));
		  p=q;
	  }
      return(p);
  }
/*
//����ʽ�𲽲�ֵ��
  #include <cmath>
  #include <iostream>
//  #include "����ʽ�𲽲�ֵ.cpp"
  using namespace std;
  int main()
  {
	  double t,z;
      double x[10]={-1.0,-0.8,-0.65,-0.4,-0.3,
                         0.0,0.2,0.45,0.8,1.0};
      double y[10]={0.0384615,0.0588236,0.0864865,0.2,0.307692,
                         1.0,0.5,0.164948,0.0588236,0.0384615};
      t=-0.85; z=funpq(x,y,10,0.0000001,t);
      cout <<"t = " <<t <<"      z = " <<z <<endl;
	  t=0.25; z=funpq(x,y,10,0.0000001,t);
      cout <<"t = " <<t <<"      z = " <<z <<endl;
	  return 0;
  }
*/
