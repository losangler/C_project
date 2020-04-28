//��Ԫ���Իع����.cpp
  #include <iostream>
  #include <cmath>
  #include "�Գ������������ƽ������.cpp"
  using namespace std;
//m         �Ա���������
//n         �۲����ݵ�������
//x[m][n]   ÿһ�д��m���Ա����Ĺ��ֵ��
//y[n]      ����������y��n�����ֵ��
//a[m+1]    ���ػع�ϵ����
//dt[4]     �ֱ𷵻�ƫ��ƽ���͡�ƽ����׼ƫ������ϵ����ع�ƽ���͡�
//v[m]      ����m���Ա�����ƫ���ϵ����
  void sqt2(int m, int n, double x[], double y[], 
	        double a[], double dt[4], double v[])
  { 
	  int i,j,k,mm;
      double q,e,u,p,yy,s,r,pp,*b;
      b=new double[(m+1)*(m+1)];
      mm=m+1;
      b[mm*mm-1]=n;
      for (j=0; j<=m-1; j++)
      { 
		  p=0.0;
          for (i=0; i<=n-1; i++)  p=p+x[j*n+i];
          b[m*mm+j]=p;
          b[j*mm+m]=p;
      }
      for (i=0; i<=m-1; i++)
      for (j=i; j<=m-1; j++)
      { 
		  p=0.0;
          for (k=0; k<=n-1; k++)  p=p+x[i*n+k]*x[j*n+k];
          b[j*mm+i]=p;
          b[i*mm+j]=p;
      }
      a[m]=0.0;
      for (i=0; i<=n-1; i++)  a[m]=a[m]+y[i];
      for (i=0; i<=m-1; i++)
      { 
		  a[i]=0.0;
          for (j=0; j<=n-1; j++) a[i]=a[i]+x[i*n+j]*y[j];
      }
      chlk(b,mm,1,a);    //���ع�ϵ��
      yy=0.0;
      for (i=0; i<=n-1; i++)  yy=yy+y[i]/n;
      q=0.0; e=0.0; u=0.0;
      for (i=0; i<=n-1; i++)
      { 
		  p=a[m];
          for (j=0; j<=m-1; j++)  p=p+a[j]*x[j*n+i];
          q=q+(y[i]-p)*(y[i]-p);     //ƫ��ƽ����
          e=e+(y[i]-yy)*(y[i]-yy);
          u=u+(yy-p)*(yy-p);
      }
      s=sqrt(q/n);      //ƽ����׼ƫ��
      r=sqrt(1.0-q/e);  //�����ϵ��
      for (j=0; j<=m-1; j++)
      { 
		  p=0.0;
          for (i=0; i<=n-1; i++)
          { 
			  pp=a[m];
              for (k=0; k<=m-1; k++)
                if (k!=j) pp=pp+a[k]*x[k*n+i];
              p=p+(y[i]-pp)*(y[i]-pp);
          }
          v[j]=sqrt(1.0-q/p);    //���Ա�����ƫ���ϵ��
      }
      dt[0]=q; dt[1]=s; dt[2]=r; dt[3]=u;
      delete[] b; return;
  }
/*
//��Ԫ���Իع������
  #include <iostream>
  #include <cmath>
//  #include "��Ԫ���Իع����.cpp"
  using namespace std;
  int main()
  { 
	  int i;
      double a[4],v[3],dt[4];
      double x[3][5]={ {1.1,1.0,1.2,1.1,0.9},
         {2.0,2.0,1.8,1.9,2.1},{3.2,3.2,3.0,2.9,2.9}};
      double y[5]={10.1,10.2,10.0,10.1,10.0};
      sqt2(3,5,&x[0][0],y,a,dt,v);
	  cout <<"�ع�ϵ�� :" <<endl;
      for (i=0; i<=3; i++)  cout <<"a[" <<i <<"] = " <<a[i] <<endl;
      cout <<"ƫ��ƽ���� = " <<dt[0] <<endl;
	  cout <<"ƽ����׼ƫ�� = " <<dt[1] <<endl;
	  cout <<"�����ϵ�� = " <<dt[2] <<endl;
	  cout <<"�ع�ƽ���� = " <<dt[3] <<endl;
      cout <<"ƫ���ϵ�� :" <<endl;
      for (i=0; i<=2; i++)  cout <<"v[" <<i <<"] = " <<v[i] <<endl;
      return 0;
  }
*/