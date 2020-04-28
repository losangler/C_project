//��ϵ������ʽ������.h
  #include  <iostream>
  #include  <cmath>
  #include  <fstream>
  #include "����������.h"
  using namespace std;
  class  com_poly:public complex //����com_poly�ǻ���complex���������
  {
  private: 
	       int N;              //��ϵ������ʽ����
		   complex  *p;        //��ϵ������ʽ�洢�ռ��׵�ַ
  public:
	       com_poly (int nn=0, complex *pp=NULL)    //���캯��
		   {  N = nn;  p = pp;  }
		   void  input ();                   //�ɼ����������ʽ��ϵ��
           complex poly_value(complex);      //��ϵ������ʽ��ֵ

//		   void com_poly operator + (com_poly&,com_poly&);  //��ϵ������ʽ���
//		   void com_poly operator - (com_poly&,com_poly&);  //��ϵ������ʽ���


           void com_poly_mul(com_poly&,com_poly&);  //��ϵ������ʽ���
           void com_poly_div(com_poly&,com_poly&,com_poly&);  //��ϵ������ʽ���
  };


  //�ɼ����������ʽ��ϵ��
  void com_poly::input ()
  {
	  int  i;
	  double a,b;
	  cout <<"����ʽ��ϵ��:" <<endl;
      for (i=0; i<N+1; i++)              //�������ʽ��ϵ��
	  {
		  cout <<"p(" <<i <<") = ";
		  cin >>a >>b;  p[i]=complex(a, b);
	  }
  }

  //��ϵ������ʽ��ֵp(x)
  complex com_poly::poly_value(complex x)
  {
	  int k;
	  complex u;
	  u = p[N];
	  for (k=N-1; k>=0; k--)  u = u*x + p[k];
	  return u;
  }

  //��ϵ������ʽ��� s = p*q
  void com_poly::com_poly_mul(com_poly& q, com_poly& s)  
  {
      int i,j;
      for (i=0; i<=s.N; i++) s.p[i] = complex(0.0,0.0);
      for (i=0; i<=N; i++)
      for (j=0; j<=q.N; j++)
          s.p[i+j]=s.p[i+j] + p[i]*q.p[j];
	  return ;
  }

  //��ϵ������ʽ��� s = p/q �� r
  void com_poly::com_poly_div(com_poly& q, com_poly& s, com_poly& r)
  {
	  int i,j,mm,ll;
      for (i=0; i<=s.N; i++) s.p[i]=complex(0.0,0.0);
      if ( (q.p[q.N]).cfabs()+1.0==1.0)  return;
      ll=N;
      for (i=(s.N)+1; i>=1; i--)
      { 
		  s.p[i-1]=p[ll]/(q.p[q.N]);
          mm=ll;
          for (j=1; j<=q.N; j++)
          { 
			  p[mm-1]=p[mm-1]-s.p[i-1]*(q.p[(q.N)-j]);
              mm=mm-1;
          }
          ll=ll-1;
      }
      for (i=0; i<=r.N; i++) r.p[i]=p[i];	  
	  return;
  }
