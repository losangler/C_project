//��Ԫ��ֵ.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//x[n]         ���n*m��������X����n���������ꡣ
//y[m]         ���n*m��������Y����m���������ꡣ
//z[n][m]      ���n*m����������ϵĺ���ֵ��
//n            �������X���������
//m            �������Y���������
//u,v          ָ����ֵ��X������Y���ꡣ
  //��������ָ����ֵ��(u,v)���ĺ�������ֵ��
  double slgrg(double x[], double y[], double z[], int n, int m, double u, double v)
  { 
	  int ip,ipp,i,j,l,iq,iqq,k;
      double h,w,b[10];
      if (u<=x[0]) { ip=1; ipp=4;}
      else if (u>=x[n-1]) { ip=n-3; ipp=n;}
      else     //X����ȡuǰ��4������
      { 
		  i=1; j=n;
          while (((i-j)!=1)&&((i-j)!=-1))
          { 
			  l=(i+j)/2;
              if (u<x[l-1]) j=l;
              else i=l;
          }
          ip=i-3; ipp=i+4;
      }
      if (ip<1) ip=1;
      if (ipp>n) ipp=n;
      if (v<=y[0]) { iq=1; iqq=4;}
      else if (v>=y[m-1]) { iq=m-3; iqq=m;}
      else    //Y����ȡvǰ��4������
      { 
		  i=1; j=m;
          while (((i-j)!=1)&&((i-j)!=-1))
          { 
			  l=(i+j)/2;
              if (v<y[l-1]) j=l;
              else i=l;
          }
          iq=i-3; iqq=i+4;
      }
      if (iq<1) iq=1;
      if (iqq>m) iqq=m;
      for (i=ip-1;i<=ipp-1;i++)
      { 
		  b[i-ip+1]=0.0;
          for (j=iq-1;j<=iqq-1;j++)
          { 
			  h=z[m*i+j];
              for (k=iq-1;k<=iqq-1;k++)
                if (k!=j) h=h*(v-y[k])/(y[j]-y[k]);
              b[i-ip+1]=b[i-ip+1]+h;
          }
      }
      w=0.0;
      for (i=ip-1;i<=ipp-1;i++)
      { 
		  h=b[i-ip+1];
          for (j=ip-1;j<=ipp-1;j++)
            if (j!=i) h=h*(u-x[j])/(x[i]-x[j]);
          w=w+h;
      }
      return(w);
  }

/*
//��Ԫ��ֵ��
  #include <cmath>
  #include <iostream>
//  #include "��Ԫ��ֵ.cpp"
  using namespace std;
  int main()
  { 
	  int i,j;
      double u,v,w;
      double x[11],y[11],z[11][11];
      for (i=0;i<=10;i++)
      { x[i]=0.1*i; y[i]=x[i];}
      for (i=0;i<=10;i++)
      for (j=0;j<=10;j++)
        z[i][j]=exp(-(x[i]-y[j]));
      u=0.35; v=0.65;
      w=slgrg(x,y,&z[0][0],11,11,u,v);
	  cout <<"x = " <<u <<",   y = " <<v <<"     z(x,y) = " <<w <<endl;
      u=0.45; v=0.55;
      w=slgrg(x,y,&z[0][0],11,11,u,v);
	  cout <<"x = " <<u <<",   y = " <<v <<"     z(x,y) = " <<w <<endl;
      return 0;
  }
*/
