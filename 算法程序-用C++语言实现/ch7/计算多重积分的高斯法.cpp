//������ػ��ֵĸ�˹��.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//n          ����������
//js[n]      js[k]��ʾ��k��������������ֵ������������
//s          ���������������ޣ�Ҫ�����е�����>���ޣ��ĺ�������
//f          ���㱻������ֵf(X)�ĺ�������
  //�������ػ���ֵ��
  double gaus_int(int n, int js[], void (*s)(int,int,double [],double []), 
	                                       double (*f)(int,double []))
  { 
	  int m,j,k,q,l,*is;
      double y[2],p,*x,*a,*b;
      double t[5]={-0.9061798459,-0.5384693101,0.0,
                         0.5384693101,0.9061798459};
      double c[5]={0.2369268851,0.4786286705,0.5688888889,
                        0.4786286705,0.2369268851};
      is=new int[2*(n+1)];
      x=new double[n];
      a=new double[2*(n+1)];
      b=new double[n+1];
      m=1; l=1;
      a[n]=1.0; a[2*n+1]=1.0;
      while (l==1)
      { 
		  for (j=m;j<=n;j++)
          { 
			  (*s)(j-1,n,x,y);     //����j-1����������������y[1]��y[0]
              a[j-1]=0.5*(y[1]-y[0])/js[j-1];  
              b[j-1]=a[j-1]+y[0];
              x[j-1]=a[j-1]*t[0]+b[j-1];   //��˹��
              a[n+j]=0.0;
              is[n+j]=1;     //����j-1����ֵĵ�1��������
			  is[j-1]=1;     //�ĵ�1����˹��
          }
          j=n; q=1;      //�����ڲ���ֿ�ʼ
          while (q==1)
          { 
			  k=is[j-1];       //ȡj-1��������䵱ǰ�������ϵĸ�˹�����
              if (j==n) p=(*f)(n,x);   //�����˹���ϵı�������ֵ
              else p=1.0;
              a[n+j]=a[n+j+1]*a[j]*p*c[k-1]+a[n+j];
              is[j-1]=is[j-1]+1;   //��j-1��������䵱ǰ���������һ����˹�����
              if (is[j-1]>5)    //j-1��������䵱ǰ�������ϵĸ�˹��ȫ��������
			  {
				  if (is[n+j]>=js[j-1])  //j-1�������������������俼����
				  { 
					  j=j-1; q=1;   //����ǰһ��Ļ�������
                      if (j==0)     //�ѵ������
					  { 
						  p=a[n+1]*a[0]; 
						  delete[] is; delete[] x; delete[] a; delete[] b; 
						  return(p);
					  }
				  }
                  else    //j-1��������仹��������
				  { 
					  is[n+j]=is[n+j]+1;    //��j-1������������һ��������
                      b[j-1]=b[j-1]+a[j-1]*2.0;
                      is[j-1]=1; k=is[j-1];    //����j-1��������䵱ǰ������ĵ�1��
                      x[j-1]=a[j-1]*t[k-1]+b[j-1];  //��˹��
                      if (j==n) q=1;   //�������ڲ�
                      else q=0;        //�ⲻ�����ڲ�
				  }
			  }
              else   //����j-1��������䵱ǰ�������ϵ���һ����˹��
              { 
				  k=is[j-1];
                  x[j-1]=a[j-1]*t[k-1]+b[j-1];
                  if (j==n) q=1;   //�������ڲ�
                  else q=0;        //�ⲻ�����ڲ�
              }
          }
          m=j+1;
      }
	  return(0.0);
  }

/*
//������ػ��ֵĸ�˹����
  #include <cmath>
  #include <iostream>
//  #include "������ػ��ֵĸ�˹��.cpp"
  using namespace std;
  int main()
  { 
	  int js[3]={4,4,4};
	  void gauss(int,int,double [],double []);
      double s,gausf(int,double []);
      s=gaus_int(3,js,gauss,gausf);
      cout <<"s = " <<s <<endl;
      return 0;
  }
//����������������
  void gauss(int j, int n, double x[], double y[2])
  { 
	  double q;
      n=n;
      switch (j)
      { 
	    case 0: { y[0]=0.0; y[1]=1.0; break;}
        case 1: { y[0]=0.0; y[1]=sqrt(1.0-x[0]*x[0]); break;}
        case 2: { q=x[0]*x[0]+x[1]*x[1]; y[0]=sqrt(q);
                  y[1]=sqrt(2.0-q); break;
                }
        default: { }
      }
      return;
  }
//���㱻������ֵ
  double gausf(int n, double x[])
  { 
	  double z;
      n=n;
      z=x[2]*x[2];
      return(z);
  }
*/
/*
//������ػ��ֵĸ�˹����
  #include <cmath>
  #include <iostream>
//  #include "������ػ��ֵĸ�˹��.cpp"
  using namespace std;
  int main()
  { 
	  int js[3]={10,10,10};
	  void gauss(int,int,double [],double []);
      double s,gausf(int,double []);
      s=gaus_int(3,js,gauss,gausf);
      cout <<"s = " <<s <<endl;
      return 0;
  }
//����������������
  void gauss(int j, int n, double x[], double y[2])
  { 
      n=n;
      switch (j)
      { 
	    case 0: { y[0]=1.0; y[1]=2.0; break;}
        case 1: { y[0]=1.0; y[1]=2.0; break;}
        case 2: { y[0]=1.0; y[1]=2.0; break;
                }
        default: { }
      }
      return;
  }
//���㱻������ֵ
  double gausf(int n, double x[])
  { 
	  double z;
      n=n;
      z=x[0]*x[0]+x[1]*x[1]+x[2]*x[2];
      return(z);
  }
*/