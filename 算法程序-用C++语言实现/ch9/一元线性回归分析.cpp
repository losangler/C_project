//һԪ���Իع����.cpp
  #include <iostream>
  #include <cmath>
  using namespace std;
//n            �۲������
//x[n],y[n]    �ֱ���n���۲����Ա���ֵ��۲�ֵ��
//a[2]         ���ػع�ϵ����a[1]Ϊһ����ϵ����a[0]Ϊ�����
//dt[6]        dt[0]����ƫ��ƽ����
//             dt[1]����ƽ����׼ƫ�
//             dt[2]���ػع�ƽ���ͣ�
//             dt[3]�������ƫ�
//             dt[4]������Сƫ�
//             dt[5]����ƫ��ƽ��ֵ��
  void sqt1(int n, double x[], double y[], double a[2], double dt[6])
  { 
	  int i;
      double xx,yy,e,f,q,u,p,umax,umin,s;
      xx=0.0; yy=0.0;
      for (i=0; i<=n-1; i++)
      { 
		  xx=xx+x[i]/n; yy=yy+y[i]/n;
	  }
      e=0.0; f=0.0;
      for (i=0; i<=n-1; i++)
      { 
		  q=x[i]-xx; e=e+q*q;
          f=f+q*(y[i]-yy);
      }
      a[1]=f/e; a[0]=yy-a[1]*xx;
      q=0.0; u=0.0; p=0.0;
      umax=0.0; umin=1.0e+30;
      for (i=0; i<=n-1; i++)
      { 
		  s=a[1]*x[i]+a[0];
          q=q+(y[i]-s)*(y[i]-s);
          p=p+(s-yy)*(s-yy);
          e=fabs(y[i]-s);
          if (e>umax) umax=e;
          if (e<umin) umin=e;
          u=u+e/n;
      }
      dt[1]=sqrt(q/n);
      dt[0]=q; dt[2]=p;
      dt[3]=umax; dt[4]=umin; dt[5]=u;
      return;
  }
/*
//һԪ���Իع������
  #include <iostream>
  #include <cmath>
//  #include "һԪ���Իع����.cpp"
  using namespace std;
  int main()
  { 
    
	  double dt[6],a[2];
      double x[11]={ 0.0,0.1,0.2,0.3,0.4,0.5,
                          0.6,0.7,0.8,0.9,1.0};
      double y[11]={ 2.75,2.84,2.965,3.01,3.20,
                        3.25,3.38,3.43,3.55,3.66,3.74};
      sqt1(11,x,y,a,dt);
      cout <<"�ع�ϵ�� :  " <<"a = " <<a[1] <<"    b = " <<a[0] <<endl;
      cout <<"ƫ��ƽ���� = " <<dt[0] <<endl;
	  cout <<"ƽ����׼ƫ�� = " <<dt[1] <<endl;
	  cout <<"�ع�ƽ���� = " <<dt[2] <<endl;
	  cout <<"���ƫ�� = " <<dt[3] <<endl;
	  cout <<"��Сƫ�� = " <<dt[4] <<endl;
	  cout <<"ƫ��ƽ��ֵ = " <<dt[5] <<endl;
      return 0;
  }
*/