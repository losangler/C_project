//gauss_jordan��ȥ��.cpp
  #include "����������.h"
  #include <cmath>
  #include <iostream>
  using namespace std;
  double init(double p)       //ʵ����ʼ��
  {   p = 0.0; return(p); }
  complex init(complex p)     //������ʼ��
  {   p = complex(0.0, 0.0);  return(p); }
  double ffabs(double p)        //����ʵ���ľ���ֵ
  {
	  double q;
	  q = fabs(p);
	  return(q);
  }
  double ffabs(complex p)      //���㸴����ģ
  {
	  double q;
	  q = p.cfabs();
	  return(q);
  }
//a[n][n]   ϵ�����󡣷���ʱ���ƻ���
//b[n]      �������������ؽ���������ϵ���������죬�򷵻�0������
//n         ���������
  template <class T>        //ģ������TΪ���Ͳ���
  //��ϵ���������죬�������ʾ������Ϣ��������0��־ֵ�����򷵻ط�0��־ֵ��
  int gauss_jordan(T *a, T *b, int n)
  {
	  int *js,k,i,j,is,p,q;
      double d,t;
	  T  s;
      js=new int[n];
      for (k=0;k<=n-1;k++)             //��ȥ����
      { 
		  d=0.0;                       //ȫѡ��Ԫ
          for (i=k;i<=n-1;i++)
          for (j=k;j<=n-1;j++)
          { 
			  t=ffabs(a[i*n+j]);
              if (t>d) { d=t; js[k]=j; is=i;}
            
		  }
          if (d+1.0==1.0)               //ϵ���������죬���ʧ�ܣ�
		  {
			  cout <<"ϵ���������죬���ʧ�ܣ�\n";
			  for (i=0; i<n; i++)  b[i]=init(s);
              delete[]js; 
			  return 0;
		  }
          if (js[k]!=k)                 //�н���
		  { 
			  for (i=0;i<=n-1;i++)
			  { 
				  p=i*n+k; q=i*n+js[k];
                  s=a[p]; a[p]=a[q]; a[q]=s;
			  }
		  }
          if (is!=k)                    //�н���
		  { 
			  for (j=k;j<=n-1;j++)
			  { 
				  p=k*n+j; q=is*n+j;
                  s=a[p]; a[p]=a[q]; a[q]=s;
			  }
              s=b[k]; b[k]=b[is]; b[is]=s;
		  }
          s=a[k*n+k];
          for (j=k+1;j<=n-1;j++)        //��һ��
		  { 
			  p=k*n+j; a[p]=a[p]/s;
		  }
          b[k]=b[k]/s;
          for (i=0;i<=n-1;i++)        //��Ԫ
		  { 
			  if (i!=k)
			  {
				  for (j=k+1;j<=n-1;j++)
				  { 
					  p=i*n+j;
                      a[p]=a[p]-a[i*n+k]*a[k*n+j];
				  }
                  b[i]=b[i]-a[i*n+k]*b[k];
			  }
		  }
	  }
      for (k=n-1;k>=0;k--)       //�ָ�
      if (js[k]!=k)
      { 
		  s=b[k]; b[k]=b[js[k]]; b[js[k]]=s;
	  }
      delete[] js;
      return 1;
  }

/*
  #include <iostream>
//  #include "gauss_jordan��ȥ��.cpp"
  using namespace std;
  int main()
  { 
	  int i,j;
	  double x[4],p[4][4];
      double a[4][4]=
           { {0.2368,0.2471,0.2568,1.2671},
             {0.1968,0.2071,1.2168,0.2271},
             {0.1581,1.1675,0.1768,0.1871},
             {1.1161,0.1254,0.1397,0.1490} };
      double b[4]={1.8471,1.7471,1.6471,1.5471};	  
	  for (i=0; i<4; i++)
	  { 
		  for (j=0; j<4; j++)  p[i][j]=a[i][j];
		  x[i]=b[i];
	  }
      i=gauss_jordan(&p[0][0],x,4);
	  if (i!=0)
      for (i=0;i<4;i++)
        cout <<"x(" <<i <<")=" <<x[i] <<endl;
	  return 0;
  }
*/
/*
  #include <iostream>
//  #include "gauss_jordan��ȥ��.cpp"
  using namespace std;
  int main()
  { 
	  int i, j;
	  complex x[4],p[4][4];
      complex a[4][4]={ 
		  {complex(1.0,3.0),complex(3.0,-2.0),complex(2.0,1.0),
			                                  complex(13.0,6.0)},
          {complex(7.0,-2.0),complex(2.0,7.0),complex(1.0,5.0),
		                                      complex(-2.0,8.0)},
          {complex(9.0,9.0),complex(15.0,-3.0),complex(3.0,15.0),
		                                      complex(-2.0,1.0)},
          {complex(-2.0,-2.0),complex(-2.0,-2.0),complex(11.0,7.0),
		                                      complex(5.0,6.0)}};
      complex b[4]={complex(2.0,1.0),complex(7.0,2.0),
		             complex(3.0,-2.0),complex(9.0,3.0)};
	  for (i=0; i<4; i++)
	  { 
		  for (j=0; j<4; j++)  p[i][j]=a[i][j];
		  x[i]=b[i];
	  }
      i=gauss_jordan(&p[0][0],x,4);
      if (i!=0)
      for (i=0;i<=3;i++)
	  {
		  cout <<"x(" <<i <<") = " ;x[i].prt(); cout <<endl;
	  }
	  return 0;
  }
*/
