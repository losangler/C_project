//�����������.cpp
  #include <iostream>
  #include <cmath>
  using namespace std;
//n            ���ݵ�����
//x[n],y[n]    ���n�����ݵ㡣x,y>0��
//a[2]         a[0]�����ݺ���ǰ��ϵ��b;a[1]�����ݺ����е�ָ��a��
//dt[5]        dt[0]ƫ��ƽ���͡�
//             dt[1]����ƽ����׼ƫ�
//             dt[2]�������ƫ�
//             dt[3]������Сƫ�
//             dt[4]����ƫ��ƽ��ֵ��
  void log2(int n, double x[], double y[], double a[2], double dt[5])
  { 
	  int i;
      double xx,yy,dx,dxy;
      xx=0.0; yy=0.0;
      for (i=0; i<=n-1; i++)
      { 
		  xx=xx+log(x[i])/n; 
          yy=yy+log(y[i])/n;
      }
      dx=0.0; dxy=0.0;
      for (i=0; i<=n-1; i++)
      { 
		  dt[0]=log(x[i])-xx; dx=dx+dt[0]*dt[0];
          dxy=dxy+dt[0]*(log(y[i])-yy);
      }
      a[1]=dxy/dx; a[0]=yy-a[1]*xx;
      a[0]=exp(a[0]);
      dt[0]=0.0; dt[4]=0.0; dt[2]=0.0; dt[3]=1.0e+30;
      for (i=0; i<=n-1; i++)
      { 
		  dt[1]=a[1]*log(x[i]); dt[1]=a[0]*exp(dt[1]);
          dt[0]=dt[0]+(y[i]-dt[1])*(y[i]-dt[1]);
          dx=fabs(y[i]-dt[1]);
          if (dx>dt[2]) dt[2]=dx;
          if (dx<dt[3]) dt[3]=dx;
          dt[4]=dt[4]+dx/n;
      }
      dt[1]=sqrt(dt[0]/n);
      return;
  }

/*
//�������������
  #include <iostream>
  #include <cmath>
//  #include "�����������.cpp"
  using namespace std;
  main()
  { 
	  int n;
      double a[2],dt[5];
      double x[10]={0.1,1.0,3.0,5.0,8.0,10.0,
                             20.0,50.0,80.0,100.0};
      double y[10]={0.1,0.9,2.5,4.0,6.3,7.8,
                              14.8,36.0,54.0,67.0};
      n=10;
      log2(n,x,y,a,dt);
      cout <<"���ϵ�� :" <<endl;
      cout <<"a = " <<a[1] <<"   b = " <<a[0] <<endl;
      cout <<"ƫ��ƽ���� = " <<dt[0] <<endl;
	  cout <<"ƽ����׼ƫ�� = " <<dt[1] <<endl;
	  cout <<"���ƫ�� = " <<dt[2] <<endl;
	  cout <<"��Сƫ�� = " <<dt[3] <<endl;
	  cout <<"ƫ��ƽ��ֵ = " <<dt[4] <<endl;
      return 0;
  }
*/