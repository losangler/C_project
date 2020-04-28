//���ָ��Է������Gear����.cpp
  #include <iostream>
  #include <cmath>
  #include "ʵ��������.cpp"
  using namespace std;
//a           ����������ʼ�㡣
//b           ���������յ㡣
//hmin        ���ֹ������������С������
//hmax        ���ֹ������������󲽳���
//h           ���ֵ��ⶨ������hmin<<h<hmax��
//eps         �����鳣����
//n           ���̸�����Ҳ��δ֪��������
//y0[n]       n��δ֪��������ʼ�㴦�ĺ���ֵ��
//k           �ⶨ����Ļ��ֵ�����
//t[k]        ����ʵ����Ч����㣨������ʼ�㣩���Ա���ֵ��
//z[n][k]     ����ʵ����Ч����㴦��δ֪����ֵ��
//ss          �����ſɱȾ���ĺ�������
//f           ���㷽�����и������Ҷ˺���ֵ�ĺ�������
  //��������ʵ������Ļ��ֵ������ں�������֮ǰ�������������Ӧ��Ϣ���ο�:
  //ȫ������ֳɹ�������ʱ���������������������������յ�ֵ
  //����С��hmin�����ȴﲻ��������ֹͣ(ǰ�������Ч)
  //�����Ѵ���6������ֹͣ(ǰ�������Ч)
  //����h>hminУ������������������ֹͣ(ǰ�������Ч)
  //����Ҫ��̫�ߣ�����ֹͣ(ǰ�������Ч)
  int gear(double a, double b, double hmin, double hmax, double h, double eps,
	       int n, double y0[], int k, double t[], double z[],
		   void (*ss)(double,double [],int,double []), 
		   void (*f)(double,double [],int,double []))
  { 
	  int kf,jt,nn,nq,i,m,irt1,irt,j,nqd,idb;
      int iw,j1,j2,nt,nqw,l;
      double aa[7],hw,hd,rm,t0,td,r,dd,pr1,pr2,pr3,rr;
      double enq1,enq2,enq3,eup,e,edwn,bnd,r1;
      double pp[7][3]={ {2.0,3.0,1.0},{4.5,6.0,1.0},
           {7.333,9.167,0.5},{10.42,12.5,0.1667},
           {13.7,15.98,0.04133},{17.15,1.0,0.008267},
           {1.0,1.0,1.0}};
      double *d,*p,*s,*s02,*ym,*er,*yy,*y;
      d=new double[n];
      p=new double[n*n];
      s=new double[10*n];
      s02=new double[n];
      ym=new double[n];
      er=new double[n];
      yy=new double[n];
      y=new double[8*n];
      aa[1]=-1.0; jt=0; nn=0; nq=1; t0=a;
      for (i=0; i<=8*n-1; i++) y[i]=0.0;
      for (i=0; i<=n-1; i++) 
      {
		  y[i*8]=y0[i]; yy[i]=y[i*8];
	  }
      (*f)(t0,yy,n,d);
      for (i=0; i<=n-1; i++) y[i*8+1]=h*d[i];
      hw=h; m=2;
      for (i=0; i<=n-1; i++) ym[i]=1.0;
  l20:
      irt=1; kf=1; nn=nn+1;
      t[nn-1]=t0;
      for (i=0; i<=n-1; i++) z[i*k+nn-1]=y[i*8];
      if ((t0>=b)||(nn==k))              //ȫ������ֳɹ�
	  {   
		  cout <<"ȫ������ֳɹ�" <<endl;
		  delete[] d; delete[] p; delete[] s; delete[] s02;
          delete[] ym; delete[] er; delete[] yy; 
          delete[] y; 
		  return(nn);
	  }
      for (i=0; i<=n-1; i++)
        for (j=0; j<=m-1; j++) s[i*10+j]=y[i*8+j];
      hd=hw;
      if (h!=hd)
      { 
		  rm=h/hd; irt1=0;
          rr=fabs(hmin/hd);
          if (rm<rr) rm=rr;
          rr=fabs(hmax/hd);
          if (rm>rr) rm=rr;
	      r=1.0; irt1=irt1+1;
          for (j=1; j<=m-1; j++)
          { 
			  r=r*rm;
              for (i=0; i<=n-1; i++)  y[i*8+j]=s[i*10+j]*r;
          }
          h=hd*rm;
          for (i=0; i<=n-1; i++) y[i*8]=s[i*10];
          idb=m;
      }
      nqd=nq; td=t0; rm=1.0;
      if (jt>0) goto l80;
  l60:
      switch (nq)
      { case 1: aa[0]=-1.0; break;
        case 2: aa[0]=-2.0/3.0; aa[2]=-1.0/3.0; break;
        case 3: aa[0]=-6.0/11.0; aa[2]=aa[0];
                aa[3]=-1.0/11.0; break;
        case 4: aa[0]=-0.48; aa[2]=-0.7; aa[3]=-0.2;
                aa[4]=-0.02; break;
        case 5: aa[0]=-120.0/274.0; aa[2]=-225.0/274.0;
                aa[3]=-85.0/274.0; aa[4]=-15.0/274.0;
                aa[5]=-1.0/274.0; break;
        case 6: aa[0]=-720.0/1764.0; aa[2]=-1624.0/1764.0;
                aa[3]=-735.0/1764.0; aa[4]=-175.0/1764.0;
                aa[5]=-21.0/1764.0; aa[6]=-1.0/1764.0;
                break;
        default: { cout <<"�����Ѵ���6������ֹͣ(ǰ�������Ч)" <<endl;
			       delete[] d; delete[] p; delete[] s; delete[] s02;
                   delete[] ym; delete[] er; delete[] yy; 
                   delete[] y; 
				   return(nn);       //��������6������ֹͣ
                 }
      }
      m=nq+1; idb=m;
      enq2=0.5/(nq+1.0); enq3=0.5/(nq+2.0);
      enq1=0.5/(nq+0.0);
      eup=pp[nq-1][1]*eps; eup=eup*eup;
      e=pp[nq-1][0]*eps; e=e*e;
      edwn=pp[nq-1][2]*eps; edwn=edwn*edwn;
      if (edwn==0.0)      //����Ҫ��̫�ߣ�����ֹͣ
      { 
		  cout <<"����Ҫ��̫�ߣ�����ֹͣ(ǰ�������Ч)" <<endl;
		  delete[] d; delete[] p; delete[] s; delete[] s02;
          delete[] ym; delete[] er; delete[] yy; 
          delete[] y; 
		  return(nn);
      }
      bnd=eps*enq3/(n+0.0);
      iw=1;
      if (irt==2)
      { 
		  r1=1.0;
          for (j=1; j<=m-1; j++)
          { 
			  r1=r1*r;
              for (i=0; i<=n-1; i++)  y[i*8+j]=y[i*8+j]*r1;
          }
          idb=m;
          for (i=0; i<=n-1; i++)
          if (ym[i]<fabs(y[i*8]))  ym[i]=fabs(y[i*8]);
          jt=nq;
          goto l20;
      }
  l80:
      t0=t0+h;
      for (j=2; j<=m; j++)
      for (j1=j; j1<=m; j1++)
      { 
		  j2=m-j1+j-1;
          for (i=0; i<=n-1; i++)
            y[i*8+j2-1]=y[i*8+j2-1]+y[i*8+j2];
	  }
      for (i=0; i<=n-1; i++) er[i]=0.0;
      j1=1; nt=1;
      for (l=0; l<=2; l++)
      { 
		  if ((j1!=0)&&(nt!=0))
          { 
			  for (i=0; i<=n-1; i++) yy[i]=y[i*8];
              (*f)(t0,yy,n,d);
              if (iw>=1)
              { 
				  for (i=0; i<=n-1; i++) yy[i]=y[i*8];
                  (*ss)(t0,yy,n,p);
                  r=aa[0]*h;
                  for (i=0; i<=n-1; i++)
                  for (j=0; j<=n-1; j++)  p[i*n+j]=p[i*n+j]*r;
                  for (i=0; i<=n-1; i++)  p[i*n+i]=1.0+p[i*n+i];
                  iw=-1;
				  j1=inv(p,n);
              }
              if (j1!=0)
              { 
				  for (i=0; i<=n-1; i++)  s02[i]=y[i*8+1]-d[i]*h;
                  for (i=0; i<=n-1; i++)
                  { 
					  dd=0.0;
                      for (j=0; j<=n-1; j++)  dd=dd+s02[j]*p[i*n+j];
                      s[i*10+8]=dd;
                  }
                  nt=n;
                  for (i=0; i<=n-1; i++)
                  { 
					  y[i*8]=y[i*8]+aa[0]*s[i*10+8];
                      y[i*8+1]=y[i*8+1]-s[i*10+8];
                      er[i]=er[i]+s[i*10+8];
                      if (fabs(s[i*10+8])<=(bnd*ym[i]))
                      nt=nt-1;
                  }
              }
          }
      }
      if (nt>0)
      { 
		  t0=td;
          if ((h>(hmin*1.00001))||(iw>=0))
          { 
			  if (iw!=0) rm=0.25*rm;
              iw=1; irt1=2;
              rr=fabs(hmin/hd);
              if (rm<rr) rm=rr;
              rr=fabs(hmax/hd);
              if (rm>rr) rm=rr;
              r=1.0;
              for (j=1; j<=m-1; j++)
              { 
				  r=r*rm;
                  for (i=0; i<=n-1; i++)  y[i*8+j]=s[i*10+j]*r;
              }
              h=hd*rm;
              for (i=0; i<=n-1; i++)  y[i*8]=s[i*10];
              idb=m;
              goto l80;
          }
          cout <<"����h>hminУ������������������ֹͣ(ǰ�������Ч)" <<endl;
		  delete[] d; delete[] p; delete[] s; delete[] s02;
          delete[] ym; delete[] er; delete[] yy; 
          delete[] y; 
		  return(nn);                //h>=hminУ������������,����ֹͣ
      }
      dd=0.0;
      for (i=0; i<=n-1; i++) dd=dd+(er[i]/ym[i])*(er[i]/ym[i]);
      iw=0;
      if (dd<=e)
      { 
		  if (m>=3)
          for (j=2; j<=m-1; j++)
          for (i=0; i<=n-1; i++) y[i*8+j]=y[i*8+j]+aa[j]*er[i];
          kf=1; hw=h;
          if (idb>1)
          { 
			  idb=idb-1;
              if (idb<=1)
              for (i=0; i<=n-1; i++) s[i*10+9]=er[i];
              for (i=0; i<=n-1; i++)
	          if (ym[i]<fabs(y[i*8])) ym[i]=fabs(y[i*8]);
              jt=nq;
              goto l20;
          }
      }
      if (dd>e)
      { 
		  kf=kf-2;
          if (h<=(hmin*1.00001))   //������С��hmin�������ȴﲻ��������ֹͣ
          { 
			  cout <<"����С��hmin,���ȴﲻ��,����ֹͣ(ǰ�������Ч)" <<endl;
		      delete[] d; delete[] p; delete[] s; delete[] s02;
              delete[] ym; delete[] er; delete[] yy; 
              delete[] y; 
			  return(nn);
          }
          t0=td;
          if (kf<=-5)
          { 
			  if (nq==1)
              { 
				  cout <<"����Ҫ��̫�ߣ�����ֹͣ(ǰ�������Ч)" <<endl;
		          delete[] d; delete[] p; delete[] s; delete[] s02;
                  delete[] ym; delete[] er; delete[] yy; 
                  delete[] y; 
		          return(nn);       //Ҫ��ľ���̫��,����ֹͣ
              }
              for (i=0; i<=n-1; i++) yy[i]=y[i*8];
              (*f)(t0,yy,n,d);
              r=h/hd;
              for (i=0; i<=n-1; i++)
              {
				  y[i*8]=s[i*10];
                  s[i*10+1]=hd*d[i];
                  y[i*8+1]=s[i*10+1]*r;
              }
              nq=1; kf=1; goto l60;
          }
      }
      pr2=log(dd/e); pr2=enq2*pr2; pr2=exp(pr2);
      pr2=1.2*pr2;
      pr3=1.0e+20;
      if (nq<7)
      if (kf>-1)
      { 
		  dd=0.0;
          for (i=0; i<=n-1; i++)
          { 
			  pr3=(er[i]-s[i*10+9])/ym[i];
              dd=dd+pr3*pr3;
          }
          pr3=log(dd/eup); pr3=enq3*pr3;
          pr3=exp(pr3); pr3=1.4*pr3;
	  }
      pr1=1.0e+20;
      if (nq>1)
      { 
		  dd=0.0;
          for (i=0; i<=n-1; i++)
          {
			  pr1=y[i*8+m-1]/ym[i];
              dd=dd+pr1*pr1;
          }
          pr1=log(dd/edwn); pr1=enq1*pr1;
          pr1=exp(pr1); pr1=1.3*pr1;
      }
      if (pr2<=pr3)
      { 
		  if (pr2>pr1)
          {
			  r=1.0e+04;
              if (pr1>1.0e-04) r=1.0/pr1;
              nqw=nq-1;
          }
          else
          { 
			  nqw=nq; r=1.0e+04;
              if (pr2>1.0e-04) r=1.0/pr2;
          }
      }
      else
      { 
		  if (pr3<pr1)
          { 
			  r=1.0e+04;
              if (pr3>1.0e-04) r=1.0/pr3;
              nqw=nq+1;
          }
          else
          { 
			  r=1.0e+04;
              if (pr1>1.0e-04) r=1.0/pr1;
              nqw=nq-1;
          }
      }
      idb=10;
      if (kf==1)
      if (r<1.1)
      { 
		  for (i=0; i<=n-1; i++)
          if (ym[i]<fabs(y[i*8])) ym[i]=fabs(y[i*8]);
          jt=nq; goto l20;
      }
      if (nqw>nq)
      for (i=0; i<=n-1; i++)  y[i*8+nqw]=er[i]*aa[m-1]/(m+0.0);
      m=nqw+1;
      if (kf==1)
      { 
		  irt=2; rr=hmax/fabs(h);
          if (r>rr) r=rr;
          h=h*r; hw=h;
          if (nq==nqw)
          { 
			  r1=1.0;
              for (j=1; j<=m-1; j++)
              { 
				  r1=r1*r;
                  for (i=0; i<=n-1; i++)  y[i*8+j]=y[i*8+j]*r1;
              }
              idb=m;
              for (i=0; i<=n-1; i++)
              if (ym[i]<fabs(y[i*8])) ym[i]=fabs(y[i*8]);
              jt=nq; goto l20;
          }
          nq=nqw;
          goto l60;
      }
      rm=rm*r; irt1=3;
      rr=fabs(hmin/hd);
      if (rm<rr) rm=rr;
      rr=fabs(hmax/hd);
      if (rm>rr) rm=rr;
      r=1.0;
      for (j=1; j<=m-1; j++)
      { 
		  r=r*rm;
          for (i=0; i<=n-1; i++) y[i*8+j]=s[i*10+j]*r;
      }
      h=hd*rm;
      for (i=0; i<=n-1; i++) y[i*8]=s[i*10];
      idb=m;
      if (nqw==nq) goto l80;
      nq=nqw; goto l60;
  }

/*
//���ָ��Է������Gear������
  #include <iostream>
  #include <cmath>
  #include <iomanip>
//  #include "���ָ��Է������Gear����.cpp"
  using namespace std;
  int main()
  { 
	  int i,j,k,m;
      void  gearf(double,double [],int,double []);
      void  gears(double,double [],int,double []);
      double a,b,hmax,h,y[3],t[30],z[3][30];
      double hmin[4]={0.0001,0.0001,0.00001,0.00001};
      double eps[4]={0.0001,0.00001,0.00001,0.000001};
      a=0.0; b=1.0; h=0.01; hmax=0.1;
      for (k=0; k<=3; k++)
      { 
		  y[0]=1.0; y[1]=0.0; y[2]=-1.0;
          m=gear(a,b,hmin[k],hmax,h,eps[k],3,y,30,t,&z[0][0],gears,gearf);
          cout <<"h = " <<h <<endl;
          cout <<"hmin = " <<hmin[k] <<endl;
          cout <<"hmax = " <<hmax <<endl;
          cout <<"eps = " <<eps[k] <<endl;
          for (i=0; i<m; i++)
          { 
			  cout <<"t(" <<setw(2) <<i <<")=" <<setw(13) <<t[i];
              for (j=0; j<=2; j++) 
				  cout <<" y(" <<j <<")=" <<setw(13) <<z[j][i];
			  cout <<endl;
          }
		  cout <<endl;
      }
	  return 0;
  }
//���㷽����������Ҷ˺���ֵ
  void gearf(double t, double y[], int n, double d[])
  { 
	  t=t; n=n;     //��������ʱ�ľ�����Ϣ
      d[0]=-21.0*y[0]+19.0*y[1]-20.0*y[2];
      d[1]=19.0*y[0]-21.0*y[1]+20.0*y[2];
      d[2]=40.0*y[0]-40.0*y[1]-40.0*y[2];
      return;
  }
//�����ſɱȾ���
  void gears(double t, double y[], int n, double p[])
  { 
	  t=t;  y[0]=y[0];   //��������ʱ�ľ�����Ϣ
      p[0*n+0]=-21.0;   p[0*n+1]=19.0;      p[0*n+2]=-20.0;
      p[1*n+0]=19.0;    p[1*n+1]=-21.0;     p[1*n+2]=20.0;
      p[2*n+0]=40.0;    p[2*n+1]=-40.0;     p[2*n+2]=-40.0;
      return;
  }
*/