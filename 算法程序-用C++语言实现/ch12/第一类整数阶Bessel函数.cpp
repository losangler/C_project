//第一类整数阶Bessel函数.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//n     阶数。要求n>0。
//x     自变量值。
  //函数返回第一类整数阶Bessel函数值。
  double bessel_1(int n, double x)
  { 
	  int i,m;
      double t,y,z,p,q,s,b0,b1;
      double a[6]={ 57568490574.0,-13362590354.0,651619640.7,
		           -11214424.18,77392.33017,-184.9052456};
      double b[6]={ 57568490411.0,1029532985.0,9494680.718,
		            59272.64853,267.8532712,1.0};
      double c[6]={ 72362614232.0,-7895059235.0,242396853.1,
		           -2972611.439,15704.4826,-30.16036606};
      double d[6]={ 144725228443.0,2300535178.0,18583304.74,
		            99447.43394,376.9991397,1.0};
      double e[5]={ 1.0,-0.1098628627e-02,0.2734510407e-04,
		            -0.2073370639e-05,0.2093887211e-06};
      double f[5]={ -0.1562499995e-01,0.1430488765e-03,-0.6911147651e-05,
                     0.7621095161e-06,-0.934935152e-07};
      double g[5]={ 1.0,0.183105e-02,-0.3516396496e-04,
		            0.2457520174e-05,-0.240337019e-06};
      double h[5]={ 0.4687499995e-01,-0.2002690873e-03,0.8449199096e-05,
                    -0.88228987e-06,0.105787412e-06};
      t=fabs(x);
      if (n<0) n=-n;
      if (n!=1)
      { 
		  if (t<8.0)
          { 
			  y=t*t; p=a[5]; q=b[5];
	          for (i=4; i>=0; i--)
              { 
				  p=p*y+a[i]; q=q*y+b[i];
			  }
              p=p/q;
          }
          else
          { 
			  z=8.0/t; y=z*z;
              p=e[4]; q=f[4];
              for (i=3; i>=0; i--)
              { 
				  p=p*y+e[i]; q=q*y+f[i];
			  }
              s=t-0.785398164;
              p=p*cos(s)-z*q*sin(s);
              p=p*sqrt(0.636619772/t);
          }
      }
      if (n==0) return(p);
      b0=p;
      if (t<8.0)
      { 
		  y=t*t; p=c[5]; q=d[5];
          for (i=4; i>=0; i--)
          { 
			  p=p*y+c[i]; q=q*y+d[i];
		  }
          p=x*p/q;
      }
      else
      { 
		  z=8.0/t; y=z*z;
          p=g[4]; q=h[4];
          for (i=3; i>=0; i--)
          { 
			  p=p*y+g[i]; q=q*y+h[i];
		  }
          s=t-2.356194491;
          p=p*cos(s)-z*q*sin(s);
          p=p*x*sqrt(0.636619772/t)/t;
      }
      if (n==1) return(p);
      b1=p;
      if (x==0.0) return(0.0);
      s=2.0/t;
      if (t>1.0*n)
      { 
		  if (x<0.0) b1=-b1;
          for (i=1; i<=n-1; i++)
          { 
			  p=s*i*b1-b0; b0=b1; b1=p;
		  }
      }
      else
      { 
		  m=(n+(int)sqrt(40.0*n))/2;
          m=2*m;
          p=0.0; q=0.0; b0=1.0; b1=0.0;
          for (i=m-1; i>=0; i--)
          { 
			  t=s*(i+1)*b0-b1;
              b1=b0; b0=t;
              if (fabs(b0)>1.0e+10)
              { 
				  b0=b0*1.0e-10; b1=b1*1.0e-10;
                  p=p*1.0e-10; q=q*1.0e-10;
              }
              if ((i+2)%2==0) q=q+b0;
              if ((i+1)==n) p=b1;
          }
          q=2.0*q-b0; p=p/q;
      }
      if ((x<0.0)&&(n%2==1)) p=-p;
      return(p);
  }
/*
//第一类整数阶Bessel函数例
  #include <cmath>
  #include <iostream>
  #include <iomanip>
//  #include "第一类整数阶Bessel函数.cpp"
  using namespace std;
  int main()
  { 
	  int n,i;
      double x,y;
      for (n=0; n<=5; n++)
      { 
		  x=0.05;
          for (i=1; i<=4; i++)
          { 
			  y=bessel_1(n,x);
			  cout <<"n=" <<n <<"   x=" <<setw(5) <<x 
			       <<"    J(n, x)=" <<y <<endl;
              x=x*10.0;
          }
      }
      return 0;
  }
*/