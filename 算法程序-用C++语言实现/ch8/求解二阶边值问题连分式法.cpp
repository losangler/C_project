//�����ױ�ֵ��������ʽ��.cpp
  #include <iostream>
  #include <cmath>
  #include "�����׳�ֵ����ʽ��.cpp"
  using namespace std;
//n          ��������ȷ���
//a          ����������˵�
//b          ���������Ҷ˵㡣Ҫ��b>a��
//eps        ���ƾ���Ҫ��
//y[n+1]     y[0]�����˵�߽�ֵy(a)��y[n]����Ҷ˵�߽�ֵy(b)��
//           ����n+1���Ⱦ���ɢ���ϵ���ֵ�⡣
//f          ������׳�΢�ַ����Ҷ˺���f(t,y,z)
  //��������y����˵㴦��һ�׵���ֵ
  double pqshoot(int n, double a, double b, double eps, double y[],
		          double (*f)(double,double,double))
  {
	  int i,j,il,flag;
	  double *zz,*yn,*bb,y0,z0,t,h;
	  bb=new double[10];
	  zz=new double[10];
	  yn=new double[10];
	  h=(b-a)/n;
      il=0; z0=0.0; flag=0;
      while ((il<20)&&(flag==0))
      { 
		  il=il+1; 
		  j=0;
          zz[0]=z0; t=a; y0=y[0];
          for (i=1; i<=n; i++)         //����yn[0]
		  { 
			  pqeuler2(t,h,&y0,&z0,eps,f);
              t=t+h;
		  }
          yn[0]=y0;            
		  bb[0]=zz[0];                   //����bb[0]
		  j=1;
          zz[1]=zz[0]+0.1;  z0=zz[1]; t=a;  y0=y[0];
          for (i=1; i<=n; i++)         //����yn[1]
		  { 
			  pqeuler2(t,h,&y0,&z0,eps,f);
              t=t+h;
		  }	  
          yn[1]=y0;
          while (j<=7)
          { 
			  funpqj(yn,zz,bb,j);                  //����bb[j]
			  zz[j+1]=funpqv(yn,bb,j,y[n]);         //����zz[j+1]
              z0=zz[j+1]; t=a;  y0=y[0];
              for (i=1; i<=n; i++)               //����yn[j+1]
			  { 
				  pqeuler2(t,h,&y0,&z0,eps,f);
				  if (i<n) y[i]=y0;
                  t=t+h;
			  }
              yn[j+1]=y0; 
			  z0=zz[j+1];
              if (fabs(yn[j+1]-y[n])>=eps) j=j+1;
			  else j=10;
          }
          if (j==10) flag=1;
       }
	   delete[] bb; delete[] zz; delete[] yn;
       return(z0);
   }

/*
//�����ױ�ֵ��������ʽ����1
    #include <iostream>
    #include <cmath>
//    #include "�����ױ�ֵ��������ʽ��.cpp"
    using namespace std;
	int main()
	{
		int k;
		double dy0, y[11], f(double,double,double);
		y[0] = 0.0;  y[10] = 1.0;
		dy0 = pqshoot(10, 0.0, 1.0, 0.0000001, y, f);
		cout <<"��ʼб�� = " <<dy0 <<endl;
		for (k=0; k<11; k++)
			cout <<"x = " <<0.1*k <<"     y = " << y[k] <<endl;
		return 0;
	}
//�������΢�ַ����Ҷ˺���ֵ
    double  f(double t, double y, double z)
	{
		double d;
		d = t + y;
		return(d);
	}
*/
/*
//�����ױ�ֵ��������ʽ����2
    #include <iostream>
    #include <cmath>
//    #include "�����ױ�ֵ��������ʽ��.cpp"
    using namespace std;
	int main()
	{
		int k;
		double dy0, y[11], f(double,double,double);
		y[0] = 1.0;  y[10] = 2.0;
		dy0 = pqshoot(10, 0.0, 1.0, 0.0000001, y, f);
		cout <<"��ʼб�� = " <<dy0 <<endl;
		for (k=0; k<11; k++)
			cout <<"x = " <<0.1*k <<"     y = " << y[k] <<endl;
		return 0;
	}
//�������΢�ַ����Ҷ˺���ֵ
    double  f(double t, double y, double z)
	{
		double d;
		d = (6*t-3.0+t*z+3*y)/(1.0+t*t);
		return(d);
	}
*/