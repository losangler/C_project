//����H��������ֵ��QR����.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//a[n][n]      ��H����
//u[n]         ����n������ֵ��ʵ��
//v[n]         ����n������ֵ���鲿
//eps          ����Ҫ��
  //���ڼ���ĳ������ֵʱ��������100�Σ��򷵻�0��־ֵ�����򷵻ط�0��־ֵ��
  int hhqr(double a[],int n,double u[],double v[],double eps) 
  { 
	  int jt=100;        //������������������ʧ��ʱ���޸ĸ�ֵ����һ�ԣ�
	  int m,it,i,j,k,l,ii,jj,kk,ll;
      double b,c,w,g,xy,p,q,r,x,s,e,f,z,y;
      it=0; m=n;
      while (m!=0)
      { 
		  l=m-1;
          while ((l>0)&&(fabs(a[l*n+l-1])>eps*
	             (fabs(a[(l-1)*n+l-1])+fabs(a[l*n+l])))) l=l-1;
          ii=(m-1)*n+m-1; jj=(m-1)*n+m-2;
          kk=(m-2)*n+m-1; ll=(m-2)*n+m-2;
          if (l==m-1)
          {
			  u[m-1]=a[(m-1)*n+m-1]; v[m-1]=0.0;
              m=m-1; it=0;
          }
          else if (l==m-2)
          { 
			  b=-(a[ii]+a[ll]);
              c=a[ii]*a[ll]-a[jj]*a[kk];
              w=b*b-4.0*c;
              y=sqrt(fabs(w));
              if (w>0.0)     //��������ʵ����ֵ
              { 
				  xy=1.0;
                  if (b<0.0) xy=-1.0;
                  u[m-1]=(-b-xy*y)/2.0;
                  u[m-2]=c/u[m-1];
                  v[m-1]=0.0; v[m-2]=0.0;
              }
              else           //���㸴����ֵ
              { 
				  u[m-1]=-b/2.0; u[m-2]=u[m-1];
                  v[m-1]=y/2.0; v[m-2]=-v[m-1];
              }
              m=m-2; it=0;
          }
          else
          {
			  if (it>=jt)               //��������������
              { cout <<"����������������\n"; return 0; }
              it=it+1;
              for (j=l+2; j<=m-1; j++) a[j*n+j-2]=0.0;
              for (j=l+3; j<=m-1; j++) a[j*n+j-3]=0.0;
              for (k=l; k<=m-2; k++)
              { 
				  if (k!=l)
                  {
					  p=a[k*n+k-1]; q=a[(k+1)*n+k-1];
                      r=0.0;
                      if (k!=m-2) r=a[(k+2)*n+k-1];
                  }
                  else
                  { 
					  x=a[ii]+a[ll];
                      y=a[ll]*a[ii]-a[kk]*a[jj];
                      ii=l*n+l; jj=l*n+l+1;
                      kk=(l+1)*n+l; ll=(l+1)*n+l+1;
                      p=a[ii]*(a[ii]-x)+a[jj]*a[kk]+y;
                      q=a[kk]*(a[ii]+a[ll]-x);
                      r=a[kk]*a[(l+2)*n+l+1];
                  }
                  if ((fabs(p)+fabs(q)+fabs(r))!=0.0)
                  { 
					  xy=1.0;
                      if (p<0.0) xy=-1.0;
                      s=xy*sqrt(p*p+q*q+r*r);
                      if (k!=l) a[k*n+k-1]=-s;
                      e=-q/s; f=-r/s; x=-p/s;
                      y=-x-f*r/(p+s);
                      g=e*r/(p+s);
                      z=-x-e*q/(p+s);
                      for (j=k; j<=m-1; j++)
                      { 
						  ii=k*n+j; jj=(k+1)*n+j;
                          p=x*a[ii]+e*a[jj];
                          q=e*a[ii]+y*a[jj];
                          r=f*a[ii]+g*a[jj];
                          if (k!=m-2)
                          {
							  kk=(k+2)*n+j;
                              p=p+f*a[kk];
                              q=q+g*a[kk];
                              r=r+z*a[kk]; a[kk]=r;
                          }
                          a[jj]=q; a[ii]=p;
                      }
                      j=k+3;
                      if (j>=m-1) j=m-1;
                      for (i=l; i<=j; i++)
                      { 
						  ii=i*n+k; jj=i*n+k+1;
                          p=x*a[ii]+e*a[jj];
                          q=e*a[ii]+y*a[jj];
                          r=f*a[ii]+g*a[jj];
                          if (k!=m-2)
                          { 
							  kk=i*n+k+2;
                              p=p+f*a[kk];
                              q=q+g*a[kk];
                              r=r+z*a[kk]; a[kk]=r;
                          }
                          a[jj]=q; a[ii]=p;
                      }
                  }
              }
          }
      }
      return 1;
  }


/*
  #include <cmath>
  #include <iostream>
  #include "Լ��һ��ʵ����Ϊ��H��.cpp"
//  #include "����H��������ֵ��QR����.cpp"
  using namespace std;
  int main()
  { 
	  int i,j;
      double eps=0.000001;
      double u[5],v[5];
      double a[5][5]={ {1.0,6.0,-3.0,-1.0,7.0},
       {8.0,-15.0,18.0,5.0,4.0},
	  {-2.0,11.0,9.0,15.0,20.0},
       {-13.0,2.0,21.0,30.0,-6.0},
	  {17.0,22.0,-5.0,3.0,6.0}};
      cout <<"ԭ���� A:\n";
      for (i=0; i<=4; i++)
      { 
		  for (j=0; j<=4; j++)  cout <<a[i][j] <<"    ";
          cout <<endl;
      }
      hhbg(&a[0][0],5);              //Լ��һ��ʵ����Ϊ��H��
      cout <<"��H���� A:\n";
      for (i=0; i<=4; i++)
      { 
		  for (j=0; j<=4; j++)  cout <<a[i][j] <<"    ";
          cout <<endl;
      }
      i=hhqr(&a[0][0],5,u,v,eps);    //����H��������ֵ
	  if (i==0)  return 0;
	  cout <<"����A������ֵ:" <<endl;
      for (i=0; i<=4; i++)
	  {
		  cout <<u[i] ;
		  if (v[i]!=0)  cout<<" +J" <<v[i];
		  cout <<endl;
	  }
	  return 0;
  }
*/