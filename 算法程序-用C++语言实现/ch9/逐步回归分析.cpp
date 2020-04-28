//�𲽻ع����.cpp
  #include <iostream>
  #include <cmath>
  using namespace std;
//n           �Ա���x�ĸ�����
//k           �۲����ݵĵ�����
//x[k][n+1]   ǰn�д���Ա�������x��k�ι۲�ֵ��
//            ���һ�д�������y�Ĺ۲�ֵ��
//f1          ��ѡ������ʱ�����Լ����F-�ֲ�ֵ��
//f2          ���޳�����ʱ�����Լ����F-�ֲ�ֵ��
//eps         ��ֹϵ����ؾ����˻����оݡ�
//xx[n+1]     ǰn����������n���Ա������ӵ�����ƽ��ֵ��
//            ���һ���������������y������ƽ��ֵ��
//b[n+1]      ���ػع鷽���и����ӵĻع�ϵ����
//v[n+1]      ǰn���������ظ����ӵ�ƫ�ع�ƽ���ͣ�
//            ���һ���������زв�ƽ���͡�
//s[n+1]      ǰn���������ظ����ӻع�ϵ���ı�׼ƫ�
//            ���һ���������ع��Ƶı�׼ƫ�
//dt[2]       dt[0]���ظ����ϵ����dt[1]����F-����ֵ��
//ye[k]       ���ض�Ӧ��k���۲�ֵ���������������ֵ��k������ֵ��
//yr[k]       �����������k���۲�ֵ�Ĳв
//r[n+1][n+1] �������յĹ�񻯵�ϵ����ؾ���
  void sqt3(int n, int k, double x[], double f1, double f2, double eps,
	        double xx[], double b[], double v[], double s[], double dt[2],
			double ye[], double yr[], double r[])
  { 
	  int i,j,ii,m,imi,imx,l,it;
      double z,phi,sd,vmi,vmx,q,fmi,fmx;
      m=n+1; q=0.0;
      for (j=0; j<=n; j++)
      { 
		  z=0.0;
          for (i=0; i<=k-1; i++) z=z+x[i*m+j]/k;
          xx[j]=z;
      }
      for (i=0; i<=n; i++)
      for (j=0; j<=i; j++)
      { 
		  z=0.0;
          for (ii=0; ii<=k-1; ii++)
            z=z+(x[ii*m+i]-xx[i])*(x[ii*m+j]-xx[j]);
          r[i*m+j]=z;
      }
      for (i=0; i<=n; i++) ye[i]=sqrt(r[i*m+i]);
      for (i=0; i<=n; i++)
      for (j=0; j<=i; j++)
      { 
		  r[i*m+j]=r[i*m+j]/(ye[i]*ye[j]);
          r[j*m+i]=r[i*m+j];
      }
      phi=k-1.0;
      sd=ye[n]/sqrt(k-1.0);
      it=1;
      while (it==1)
      { 
		  it=0;
          vmi=1.0e+35; vmx=0.0;
          imi=-1; imx=-1;
          for (i=0; i<=n; i++)
          { 
			  v[i]=0.0; b[i]=0.0; s[i]=0.0;
		  }
          for (i=0; i<=n-1; i++)
            if (r[i*m+i]>=eps)
            { 
				v[i]=r[i*m+n]*r[n*m+i]/r[i*m+i];
                if (v[i]>=0.0)
                { 
					if (v[i]>vmx)  { vmx=v[i]; imx=i;}
                }
                else
                { 
					b[i]=r[i*m+n]*ye[n]/ye[i];
                    s[i]=sqrt(r[i*m+i])*sd/ye[i];
                    if (fabs(v[i])<vmi)
                    { 
						vmi=fabs(v[i]); imi=i;
					}
                }
            }
          if (phi!=n-1.0)
          { 
			  z=0.0;
              for (i=0; i<=n-1; i++) z=z+b[i]*xx[i];
              b[n]=xx[n]-z; s[n]=sd; v[n]=q;
          }
          else  { b[n]=xx[n]; s[n]=sd;}
          fmi=vmi*phi/r[n*m+n];
          fmx=(phi-1.0)*vmx/(r[n*m+n]-vmx);
          if ((fmi<f2)||(fmx>=f1))
          { 
			  if (fmi<f2) { phi=phi+1.0; l=imi;}
              else { phi=phi-1.0; l=imx;}
              for (i=0; i<=n; i++)
              if (i!=l)
                for (j=0; j<=n; j++)
                  if (j!=l)
                    r[i*m+j]=r[i*m+j]-(r[l*m+j]/r[l*m+l])*r[i*m+l];
              for (j=0; j<=n; j++)
                if (j!=l)  r[l*m+j]=r[l*m+j]/r[l*m+l];
              for (i=0; i<=n; i++)
                if (i!=l) r[i*m+l]=-r[i*m+l]/r[l*m+l];
              r[l*m+l]=1.0/r[l*m+l];
              q=r[n*m+n]*ye[n]*ye[n];
              sd=sqrt(r[n*m+n]/phi)*ye[n];
              dt[0]=sqrt(1.0-r[n*m+n]);
              dt[1]=(phi*(1.0-r[n*m+n]))/((k-phi-1.0)*r[n*m+n]);
              it=1;
          }
      }
      for (i=0; i<=k-1; i++)
      { 
		  z=0.0;
          for (j=0; j<=n-1; j++) z=z+b[j]*x[i*m+j];
          ye[i]=b[n]+z; yr[i]=x[i*m+n]-ye[i];
      }
      return;
  }

/*
//�𲽻ع������
  #include <iostream>
  #include <cmath>
  #include <iomanip>
//  #include "�𲽻ع����.cpp"
  using namespace std;
  int main()
  { 
	  int i,j,k;
      double eps,xx[5],b[5],v[5],s[5],ye[13],yr[13];
      double r[5][5],dt[2];
      double x[13][5]={ 
                  {7.0,26.0,6.0,60.0,78.5},
                  {1.0,29.0,15.0,52.0,74.3},
                  {11.0,56.0,8.0,20.0,104.3},
                  {11.0,31.0,8.0,47.0,87.6},
                  {7.0,52.0,6.0,33.0,95.9},
                  {11.0,55.0,9.0,22.0,109.2},
                  {3.0,71.0,17.0,6.0,102.7},
                  {1.0,31.0,22.0,44.0,72.5},
                  {2.0,54.0,18.0,22.0,93.1},
                  {21.0,47.0,4.0,26.0,115.9},
                  {1.0,40.0,23.0,34.0,83.8},
                  {11.0,66.0,9.0,12.0,113.3},
                  {10.0,68.0,8.0,12.0,109.4}};
      double f1[3]={1.46,4.75,9.33};
      double f2[3]={1.45,4.67,9.07};
      eps=1.0e-30;
      for (k=0; k<=2; k++)
      { 
		  sqt3(4,13,&x[0][0],f1[k],f2[k],eps,xx,b,v,s,dt,ye,yr,&r[0][0]);
          cout <<"f1 = " <<f1[k] <<"  f2 = " <<f2[k] <<endl;
          cout <<"�۲�ֵ :" <<endl;
          for (i=0; i<=12; i++)
          { 
			  for (j=0; j<=3; j++)
                cout <<"   x(" <<j <<")=" <<setw(5) <<x[i][j];
              cout <<"   y(" <<i <<")=" <<x[i][4] <<endl;
          }
          cout <<"ƽ��ֵ : " <<endl;
          for (i=0; i<=3; i++)
             cout <<"  x(" <<i <<")=" <<xx[i];
          cout <<"    y = "  <<xx[4] <<endl;
          cout <<"�ع�ϵ�� :" <<endl;
          for (i=0; i<=4; i++)  cout <<"b(" <<i <<")=" <<b[i] <<endl;
		  cout <<"�����ӵ�ƫ�ع�ƽ����" <<endl;
          for (i=0; i<=3; i++)  cout <<"v(" <<i <<")=" <<v[i] <<endl;
          cout <<"�в�ƽ���� = " <<v[4] <<endl;
          cout <<"�����ӻع�ϵ���ı�׼ƫ�� : " <<endl;
          for (i=0; i<=3; i++)  cout <<"s(" <<i <<")=" <<s[i] <<endl;
          cout <<"���Ƶı�׼ƫ�� = " <<s[4] <<endl;
          cout <<"�����ϵ�� = " <<dt[0] <<endl;
          cout <<"F-����ֵ = " <<dt[1] <<endl;
          cout <<"�������������ֵ�Ĺ���ֵ�Լ��۲�ֵ�Ĳв� :" <<endl;
          for (i=0; i<=12; i++)
             cout <<"ye(" <<i <<")=" <<ye[i] 
			      <<"    yr(" <<i <<")=" <<yr[i] <<endl;
          cout <<"ϵ����ؾ��� :" <<endl;
          for (i=0; i<=4; i++)
          { 
			  for (j=0; j<=4; j++)  cout <<setw(11) <<r[i][j];
              cout <<endl;
          }
		  cout <<endl;
      }
	  return 0;
  }
*/