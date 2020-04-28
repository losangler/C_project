//�����׳�ֵEuler����.cpp
  #include <iostream>
  #include <cmath>
  using namespace std;
  //�Ľ�ŷ����ʽ��hΪ��������m��
  //t    �Ա������ֵ
  //h    ����
  //y    ��ź�����ֵ�������յ㺯��ֵ��
  //z    ��ź���һ�׵�����ֵ�������յ㺯��һ�׵���ֵ��
  //m    ����
  //f    ����΢�ַ����Ҷ˺���f(t,y,z)��
  void euler21(double t,double h,double *y,double *z,int m,
	         double (*f)(double,double,double))
  { 
	  int j;
      double x,yy,zz,yc,zc,yk1,yk2,zk1,zk2;
	  yy=*y; zz=*z;
      for (j=0; j<=m-1; j++)
      {
		  x=t+j*h;
          yk1=zz;               //����yK1
		  zk1=(*f)(x,yy,zz);    //����zK1
		  x=t+(j+1)*h;
		  yc=yy+h*zk1;         //Ԥ��t[j+1]����yֵ
		  zc=zz+h*yk1;         //Ԥ��t[j+1]����zֵ
		  yk2=zc;             //����yK2
		  zk2=(*f)(x,yc,zc);  //����zk2
          yy=yy+h*(yk1+yk2)/2.0;         //����t[j+1]����yֵ
		  zz=zz+h*(zk1+zk2)/2.0;         //����t[j+1]����zֵ
      }
	  *y=yy; *z=zz;
      return;
  }

  //Euler�����䲽������һ�����׳�ֵ����
  //t      �Ա������ֵ
  //h      ����
  //y      ��ź�����ֵ�������յ㺯��ֵ��
  //z      ��ź���һ�׵�����ֵ�������յ㺯��һ�׵���ֵ��
  //eps    ����Ҫ��
  //f      ����΢�ַ����Ҷ˺���f(t,y,z)��
  void euler2(double t, double h, double *y, double *z, double eps,
             double (*f)(double, double , double ))
  { 
	  int m;
      double p,ya,za,yb,zb;
      m=1;
	  p=1.0+eps;
      ya=*y;  za=*z;
	  euler21(t,h,&ya,&za,m,f);          //��һ������
      while (p>eps)
      { 
		  yb=*y;  zb=*z; m=m+m; h=h/2.0;
          euler21(t,h,&yb,&zb,m,f);       //��m������
          p=fabs(yb-ya);                 //ȡ���
          za=zb;  ya=yb;
      }
	  *y=ya;  *z=za;
      return;
  }

/*
//�����׳�ֵEuler������1
  #include <iostream>
  #include <iomanip>
//  #include "�����׳�ֵEuler����.cpp"
  using namespace std;
  int main()
  { 
	  int j;
      double t,h,eps,y,z;
      double  euler2_f(double, double, double);
      y=0.0; z=0.701836;
      t=0.0; h=0.1; eps=0.0000001;
      cout <<"t = " <<setw(6) <<t;
      cout <<setw(6) <<"y = " <<setw(10) <<y;
      cout <<setw(6) <<"z = " <<setw(10) <<z;
      cout <<endl;
      for (j=1; j<=10; j++)
      { 
		  euler2(t,h,&y,&z,eps,euler2_f);
          t=t+h;
		  cout <<"t = " <<setw(6) <<t;
          cout <<setw(6) <<"y = " <<setw(10) <<y;
		  cout <<setw(6) <<"z = " <<setw(10) <<z;
          cout <<endl;
      }
	  return 0;
  }
//�������΢�ַ����Ҷ˺���f(t,y,z)
  double euler2_f(double t, double y, double z)
  { 
	  double d;
      d=t+y;
      return(d);
  }
*/
/*
//�����׳�ֵEuler������2
  #include <iostream>
  #include <iomanip>
//  #include "�����׳�ֵEuler����.cpp"
  using namespace std;
  int main()
  { 
	  int j;
      double t,h,eps,y,z;
      double  euler2_f(double, double, double);
	  y=1.0; z=0.0;
      t=0.0; h=0.1; eps=0.0000001;
      cout <<"t = " <<setw(6) <<t;
      cout <<setw(6) <<"y = " <<setw(10) <<y;
      cout <<setw(6) <<"z = " <<setw(10) <<z;
      cout <<endl;
      for (j=1; j<=10; j++)
      { 
		  euler2(t,h,&y,&z,eps,euler2_f);
          t=t+h;
		  cout <<"t = " <<setw(6) <<t;
          cout <<setw(6) <<"y = " <<setw(10) <<y;
		  cout <<setw(6) <<"z = " <<setw(10) <<z;
          cout <<endl;
      }
	  return 0;
  }
//�������΢�ַ����Ҷ˺���f(t,y,z)
  double euler2_f(double t, double y, double z)
  { 
	  double d;
      d = (6*t-3.0+t*z+3*y)/(1.0+t*t);
      return(d);
  }
*/