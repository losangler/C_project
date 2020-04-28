//����Fourier�任.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//n          ����������
//k          
//pr[n]      ��Ų�������(��任)��ʵ�������ر任(����任)��ģ��
//pi[n]      ��Ų�������(��任)���鲿�����ر任(����任)�ķ��ǡ�
//fr[n]      ���ر任(����任)��ʵ����
//fi[n]      ���ر任(����任)���鲿��
//flag       ��ű�־��flag=0��ʾ���任��flag=1��ʾ����任��
  void kfft(int n, int k, double pr[], double pi[], 
	                     double fr[], double fi[], int flag)
  { 
	  int it,m,is,i,j,nv,kk;
      double p,q,s,vr,vi,poddr,poddi;
      for (it=0; it<=n-1; it++)
      { 
		  m=it; is=0;
          for (i=0; i<=k-1; i++)
          { 
			  j=m/2; is=2*is+(m-2*j); m=j;
		  }
          fr[it]=pr[is]; fi[it]=pi[is];
      }
      pr[0]=1.0; pi[0]=0.0;
      p=6.283185306/(1.0*n);
      pr[1]=cos(p); pi[1]=-sin(p);
      if (flag!=0) pi[1]=-pi[1];      //��任
      for (i=2; i<=n-1; i++)
      { 
		  p=pr[i-1]*pr[1]; q=pi[i-1]*pi[1];
          s=(pr[i-1]+pi[i-1])*(pr[1]+pi[1]);
          pr[i]=p-q; pi[i]=s-p-q;
      }
      for (it=0; it<=n-2; it=it+2)
      { 
		  vr=fr[it]; vi=fi[it];
          fr[it]=vr+fr[it+1]; fi[it]=vi+fi[it+1];
          fr[it+1]=vr-fr[it+1]; fi[it+1]=vi-fi[it+1];
      }
      m=n/2; nv=2;
      for (kk=k-2; kk>=0; kk--)
      { 
		  m=m/2; nv=2*nv;
          for (it=0; it<=(m-1)*nv; it=it+nv)
          for (j=0; j<=(nv/2)-1; j++)
          { 
			  p=pr[m*j]*fr[it+j+nv/2];
              q=pi[m*j]*fi[it+j+nv/2];
              s=pr[m*j]+pi[m*j];
              s=s*(fr[it+j+nv/2]+fi[it+j+nv/2]);
              poddr=p-q; poddi=s-p-q;
              fr[it+j+nv/2]=fr[it+j]-poddr;
              fi[it+j+nv/2]=fi[it+j]-poddi;
              fr[it+j]=fr[it+j]+poddr;
              fi[it+j]=fi[it+j]+poddi;
		  }
      }
      if (flag!=0)      //��任
      for (i=0; i<=n-1; i++)
      { 
		  fr[i]=fr[i]/(1.0*n);
          fi[i]=fi[i]/(1.0*n);
      }
      for (i=0; i<=n-1; i++)     //����任��ģ�����
      { 
		  pr[i]=sqrt(fr[i]*fr[i]+fi[i]*fi[i]);
          if (fabs(fr[i])<0.000001*fabs(fi[i]))
          { 
			  if ((fi[i]*fr[i])>0) pi[i]=90.0;
              else pi[i]=-90.0;
          }
          else  pi[i]=atan(fi[i]/fr[i])*360.0/6.283185306;
      }
      return;
  }
/*
 //����Fourier�任��
  #include <cmath>
  #include <iostream>
  #include <iomanip>
//  #include "����Fourier�任.cpp"
  using namespace std;
  int main()
  { 
	  int i,j;
      double pr[64],pi[64],fr[64],fi[64];
      for (i=0; i<=63; i++)
      { pr[i]=exp(-0.1*(i+0.5)); pi[i]=0.0;}
      cout <<"������������p :" <<endl;
      for (i=0; i<=15; i++)
      { 
		  for (j=0; j<=3; j++) cout <<setw(15) <<pr[4*i+j];
          cout <<endl;
      }
      kfft(64,6,pr,pi,fr,fi,0);
	  cout <<"��������p�ı任��ʵ��fr :" <<endl;
      for (i=0; i<=15; i++)
      { 
		  for (j=0; j<=3; j++) cout <<setw(15) <<fr[4*i+j];
          cout <<endl;
      }
	  cout <<"��������p�ı任���鲿fi :" <<endl;
      for (i=0; i<=15; i++)
      { 
		  for (j=0; j<=3; j++) cout <<setw(15) <<fi[4*i+j];
          cout <<endl;
      }
	  cout <<"��������p�ı任��ģ :" <<endl;
      for (i=0; i<=15; i++)
      { 
		  for (j=0; j<=3; j++) cout <<setw(15) <<pr[4*i+j];
          cout <<endl;
      }
	  cout <<"��������p�ı任�ķ��� :" <<endl;
      for (i=0; i<=15; i++)
      { 
		  for (j=0; j<=3; j++) cout <<setw(15) <<pi[4*i+j];
          cout <<endl;
      }
      kfft(64,6,fr,fi,pr,pi,1);      //��任
	  cout <<"��任��ʵ��pr :" <<endl;
      for (i=0; i<=15; i++)
      { 
		  for (j=0; j<=3; j++) cout <<setw(15) <<pr[4*i+j];
          cout <<endl;
      }
	  cout <<"��任���鲿pi :" <<endl;
      for (i=0; i<=15; i++)
      { 
		  for (j=0; j<=3; j++) cout <<setw(15) <<pi[4*i+j];
          cout <<endl;
      }
	  cout <<"��任��ģ :" <<endl;
      for (i=0; i<=15; i++)
      { 
		  for (j=0; j<=3; j++) cout <<setw(15) <<fr[4*i+j];
          cout <<endl;
      }
	  cout <<"��任�ķ��� :" <<endl;
      for (i=0; i<=15; i++)
      { 
		  for (j=0; j<=3; j++) cout <<setw(15) <<fi[4*i+j];
          cout <<endl;
      }
      return 0;
  }
*/