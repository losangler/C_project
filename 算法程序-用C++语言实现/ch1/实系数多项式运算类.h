//ʵϵ������ʽ������.h
  #include  <iostream>
  #include  <fstream>
  #include  <cmath>
  using namespace std;
  class  poly
  {
  private: 
	       int N;         //����ʽ����
		   double  *p;    //����ʽϵ���洢�ռ��׵�ַ
  public:
	       poly(int nn=0, double *pp=NULL)  //���캯��
		   { 
			   N = nn;  p=pp;
		   }
		   void  input ();             //�ɼ����������ʽϵ��
           double poly_value(double);  //����ʽ��ֵ
           void poly_mul(poly&,poly&);  //����ʽ���
           void poly_div(poly&,poly&,poly&);   //����ʽ���
  };

  //�ɼ����������ʽϵ��
  void poly::input () 
  {
	  int  i;
	  cout <<"����ʽϵ��:" <<endl;
      for (i=0; i<N+1; i++)              //�������ʽϵ��
	  {
		  cout <<"p(" <<i <<") = ";
		  cin >>p[i];
	  }
  }

  //����ʽ��ֵp(x)
  double poly::poly_value(double x)
  {
	  int k;
	  double u;
	  u = p[N];
	  for (k=N-1; k>=0; k--)  u = u*x + p[k];
	  return u;
  }

  //����ʽ��� s = p*q
  void poly::poly_mul(poly& q, poly& s)
  {
      int i,j;
      for (i=0; i<=s.N; i++) s.p[i]=0.0;
      for (i=0; i<=N; i++)
      for (j=0; j<=q.N; j++)
          s.p[i+j]=s.p[i+j] + p[i]*q.p[j];
	  return ;
  }

  //����ʽ��� s = p/q �� r
  void poly::poly_div(poly& q, poly& s, poly& r)
  {
	  int i,j,mm,ll;
      for (i=0; i<=s.N; i++) s.p[i]=0.0;
      if (q.p[q.N]+1.0==1.0) return;
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
