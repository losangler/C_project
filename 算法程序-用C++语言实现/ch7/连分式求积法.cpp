//����ʽ�����.cpp
  #include <cmath>
  #include <iostream>
  #include "���㺯������ʽ��һ��.cpp"
  #include "���㺯������ʽֵ.cpp"
  using namespace std;
//a0          �������ޡ�
//b0          �������ޡ�Ҫ��b0>a0��
//eps         ���־���Ҫ��
//f           ���㱻������ֵf(x)�ĺ�������
  //�������ػ���ֵ��
  double pqinteg(double a0,double b0,double eps,double (*f)(double))
  {
	  int k,j,il,flag,n;
	  double *h,*g,*b,h0,g0,d,s0,s1,x;
	  b=new double[10];
	  h=new double[10];
	  g=new double[10];
      il=0; n=1; h0=(b0-a0)/n; flag=0;
	  g0=h0*((*f)(a0)+(*f)(b0))/2.0;       //���ι�ʽ�����ֵ
      while ((il<20)&&(flag==0))
      { 
		  il=il+1; 
		  h[0]=h0; g[0]=g0;
		  b[0]=g[0];                            //����b[0]
          j=1; s1=g[0];
          while (j<=7)
          { 
			  d=0.0;
			  for (k=0; k<=n-1; k++)
			  {
				  x=a0+(k+0.5)*h[j-1];
				  d=d+(*f)(x);
			  }
			  g[j]=(g[j-1]+h[j-1]*d)/2.0;         //�䲽����������������½���ֵg[j]
			  h[j]=h[j-1]/2.0; n=2*n;
			  funpqj(h,g,b,j);                  //����b[j]
			  s0=s1;
			  s1=funpqv(h,b,j,0.0);             //����ʽ��������ֽ���ֵs1
              if (fabs(s1-s0)>=eps)  j=j+1;
			  else  
			  { 
				  cout <<"���һ�ε�������ʽ����=" <<j <<endl;
				  j=10; 
			  } 
          }
		  h0=h[j-1]; g0=g[j-1];
          if (j==10) flag=1;
       }
	   cout <<"�������� =" <<il <<endl;
	   delete[] b; delete[] h; delete[] g;
       return(s1);
   }
/*
//����ʽ�������
  #include <cmath>
  #include <iostream>
//  #include "����ʽ�����.cpp"
  using namespace std;
  int main()
  { 
	  double d,eps,pqintegf(double);
      eps=0.0000001;
      d=pqinteg(0.0,4.3,eps,pqintegf);
      cout <<"����ֵ s = " <<d <<endl;
	  return 0;
  }
//���㱻������ֵ
  double pqintegf(double x)
  { 
      return(exp(-x*x));
  }
*/