//�����׳�ֵ����ʽ��.cpp
  #include <iostream>
  #include <cmath>
  #include "���㺯������ʽ��һ��.cpp"
  #include "���㺯������ʽֵ.cpp"
  using namespace std;
  //�Ľ�ŷ����ʽ��hΪ��������m��
  //t    �Ա������ֵ
  //h    ����
  //y    ��ź�����ֵ�������յ㺯��ֵ��
  //z    ��ź���һ�׵�����ֵ�������յ㺯��һ�׵���ֵ��
  //m    ����
  //f    �������΢�ַ��̵��Ҷ˺���f(t,y,z)��
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

  //����ʽ�������׳�ֵ
  //t    �Ա������ֵ
  //h    ����
  //y    ��ź�����ֵ�������յ㺯��ֵ��
  //z    ��ź���һ�׵�����ֵ�������յ㺯��һ�׵���ֵ��
  //eps  ����Ҫ��
  //f    �������΢�ַ��̵��Ҷ˺���f(t,y,z)��
  using namespace std;
  void pqeuler2(double t,double h,double *y,double *z,double eps,
	           double (*f)(double,double,double))
  {
	  int j,il,flag,m;
	  double yy,zz,*hh,*gy,*gz,*yb,*zb,h0,d,ys0,ys1,zs,y0,z0;
	  yb=new double[10];
	  zb=new double[10];
	  hh=new double[10];
	  gy=new double[10];
	  gz=new double[10];
      yy=*y; zz=*z; 
	  il=0; flag=0;
	  m=1; h0=h;
      euler21(t,h0,&yy,&zz,m,f);      //Euler���������ֵgy[0]��gz[0]
      y0=yy;  z0=zz;
	  while ((il<20)&&(flag==0))
      { 
		  il=il+1; 
		  hh[0]=h0;
		  gy[0]=y0;  gz[0]=z0;
		  yb[0]=gy[0];  zb[0]=gz[0];      //����yb[0]��zb[0]
          j=1; 
		  ys1=gy[0]; 
		  while (j<=7)
          { 
			  yy=*y;  zz=*z;
			  m=m+m; hh[j]=hh[j-1]/2.0;
              euler21(t,hh[j],&yy,&zz,m,f); //Euler���������½���ֵgy[j]��gz[j]
	          gy[j]=yy;  gz[j]=zz;
			  funpqj(hh,gy,yb,j);       //����yb[j]
			  funpqj(hh,gz,zb,j);       //����zb[j]
			  ys0=ys1; 
			  ys1=funpqv(hh,yb,j,0.0);  //����ʽ��������ֽ���ֵys1
              zs=funpqv(hh,zb,j,0.0);   //����ʽ��������ֽ���ֵzs
			  d=fabs(ys1-ys0);
			  if (d>=eps)  j=j+1;
			  else  j=10;
          }
		  h0=hh[j-1]; 
		  y0=gy[j-1]; z0=gz[j-1];
          if (j==10) flag=1;
       }
	    *y=ys1;  *z=zs;
	   delete[] yb; delete[] zb; delete[] hh; delete[] gy; delete[]gz;
       return;
  }
/*
//�����׳�ֵ����ʽ����
  #include <iostream>
  #include <iomanip>
//  #include "�����׳�ֵ����ʽ��.cpp"
  using namespace std;
  int main()
  {
	  int j;
      double t,h,eps,y,z;
      double  pqeuler2f(double, double, double);
      y=0.0; z=0.701836;
      t=0.0; h=0.1; eps=0.0000001;
      cout <<"t = " <<setw(6) <<t;
      cout <<setw(6) <<"y = " <<setw(10) <<y;
      cout <<setw(6) <<"z = " <<setw(10) <<z;
      cout <<endl;
      for (j=1; j<=10; j++)
      { 
		  pqeuler2(t,h,&y,&z,eps,pqeuler2f);
          t=t+h;
		  cout <<"t = " <<setw(6) <<t;
          cout <<setw(6) <<"y = " <<setw(10) <<y;
		  cout <<setw(6) <<"z = " <<setw(10) <<z;
          cout <<endl;
      }	  
	  return 0;
  }
//�������΢�ַ��̵��Ҷ˺���f(t,y,z)
  double pqeuler2f(double t, double y, double z)
  { 
	  double d;
      d=t+y;
      return(d);
  }
*/