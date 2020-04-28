//�������.cpp
  #include "����������.h"
  #include <cmath>
  #include <iostream>
  using namespace std;
  double init(double p)       //ʵ����ʼ��
  {   p = 0.0; return(p); }
  complex init(complex p)     //������ʼ��
  {   p = complex(0.0, 0.0);  return(p); }
//a, ma, na       ����A[ma][na]
//b, mb, nb       ����B[mb][nb]
//c, ma, nb       �˻�����C[ma][nb] = A[ma][na] * B[mb][nb]
  template <class  T>     //ģ������TΪ���Ͳ���
  void tmul(T a[], int ma, int na, T b[], int mb, int nb, T c[])
  { 
	  int i,j,k,u;
      if (na!=mb)
	  {
		  cout <<"��������ˣ�" <<endl;
		  return;
	  }
      for (i=0; i<=ma-1; i++)
      for (j=0; j<=nb-1; j++)
      { 
		  u=i*nb+j; 
		  c[u] = init(c[u]);            //�˻�����Ԫ�س�ʼ��
          for (k=0; k<=mb-1; k++)
             c[u]=c[u]+a[i*na+k]*b[k*nb+j];
      }
      return;
  }
/*
//ʵ���������
  #include <cmath>
  #include <iostream>
//  #include "�������.cpp"
  using namespace std;
  int main()
  { 
	  int i,j;
      double a[4][5]={ {1.0,3.0,-2.0,0.0,4.0},
                            {-2.0,-1.0,5.0,-7.0,2.0},
                            {0.0,8.0,4.0,1.0,-5.0},
                            {3.0,-3.0,2.0,-4.0,1.0}};
      double c[4][3],b[5][3]={ {4.0,5.0,-1.0},
                      {2.0,-2.0,6.0},{7.0,8.0,1.0},
                      {0.0,3.0,-5.0},{9.0,8.0,-6.0}};
	  cout <<"ʵ���� A:" <<endl;
      for (i=0; i<=3; i++)
      { 
		  for (j=0; j<=4; j++)  { cout <<a[i][j] <<"  ";  }
          cout <<endl;
       }
	  cout <<"ʵ���� B:" <<endl;
      for (i=0; i<=4; i++)
      { 
		  for (j=0; j<=2; j++)  { cout <<b[i][j] <<"  ";  }
          cout <<endl;
       }
      tmul(&a[0][0],4,5,&b[0][0],5,3,&c[0][0]);
	  cout <<"�˻�����C = AB :" <<endl;
      for (i=0; i<=3; i++)
      { 
		  for (j=0; j<=2; j++)  { cout <<c[i][j] <<"  ";  }
          cout <<endl;
       }
      return 0;
  }
*/ 
/*
//�����������
  #include <cmath>
  #include <iostream>
//  #include "�������.cpp"
  using namespace std;
  int main()
  {  
	  int i,j;
      complex c[3][4];
      complex a[3][4]={ 
		  {complex(1.0,1.0),complex(2.0,-1.0),complex(3.0,2.0),complex(-2.0,1.0)},
		  {complex(1.0,-1.0),complex(5.0,-1.0),complex(1.0,2.0),complex(3.0,0.0)},
		  {complex(0.0,-3.0),complex(4.0,-1.0),complex(2.0,2.0),complex(-1.0,2.0)}};
      complex b[4][4]={
		  {complex(1.0,-1.0),complex(4.0,-1.0),complex(5.0,1.0),complex(-2.0,1.0)},
		  {complex(3.0,2.0),complex(0.0,1.0),complex(2.0,0.0),complex(-1.0,5.0)},
		  {complex(6.0,-3.0),complex(3.0,2.0),complex(1.0,1.0),complex(2.0,-1.0)},
		  {complex(2.0,-1.0),complex(-3.0,-2.0),complex(-2.0,1.0),complex(1.0,-2.0)} };
	  cout <<"������ A:" <<endl;
      for (i=0; i<=2; i++)
      { 
		  for (j=0; j<=3; j++)  { a[i][j].prt();  cout <<"  ";  }
          cout <<endl;
       }
	  cout <<"������ B:" <<endl;
      for (i=0; i<=3; i++)
      { 
		  for (j=0; j<=3; j++)  { b[i][j].prt();  cout <<"  ";  }
          cout <<endl;
       }
      tmul(&a[0][0],3,4,&b[0][0],4,4,&c[0][0]);
	  cout <<"�˻�����C = AB :" <<endl;
      for (i=0; i<=2; i++)
      { 
		  for (j=0; j<=3; j++)  { c[i][j].prt();  cout <<"  ";  }
          cout <<endl;
       }
	  return 0;
  }
*/