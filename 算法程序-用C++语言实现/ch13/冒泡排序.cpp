//ð������.cpp
    #include <iostream>
    #include <cmath>
	using namespace std;
//n         ���������г��ȡ�
//p[n]      ���������С�
	template <class T>
    void bub_sort(int n, T p[])
	{ 
		int m,k,j,i;
        T d;
        k=0; m=n-1;
        while (k<m)
		{ 
			j=m-1; m=0;
            for (i=k; i<=j; i++)       //��ǰ����ɨ��
              if (p[i]>p[i+1])         //˳�򲻶ԣ�����
			  { 
				  d=p[i]; p[i]=p[i+1]; p[i+1]=d; 
				  m=i;
			  }
            j=k+1; k=0;
            for (i=m; i>=j; i--)       //�Ӻ���ǰɨ��
              if (p[i-1]>p[i])         //˳�򲻶ԣ�����
			  {
				  d=p[i]; p[i]=p[i-1]; p[i-1]=d;
				  k=i;
			  }
		}
        return;
	}
/*
//ð��������
  #include <iomanip>
//  #include "ð������.cpp"
  #include "�����������.h"
  int main()
  { 
	  RND r(5);
	  int i,j;
      double p[70],*s;
	  for (i=0; i<70; i++)  //����70��0��1֮��������
		  p[i] = r.rnd1();
      for (i=0; i<70; i++)   //ת����0��999֮��������
		  p[i]=0.0+999.0*p[i];
	  cout <<"����ǰ:" <<endl;
      for (i=0; i<10; i++)    //��10��
      { 
		  for (j=0; j<7; j++)  //һ��7��
            cout <<setw(10) <<p[7*i+j];
          cout <<endl;
      }
      s = p+7; 
      bub_sort(49,s);         //��2��8��������ð�ݷ�����
	  cout <<"�����:" <<endl;
      for (i=0; i<10; i++)
      { 
		  for (j=0; j<7; j++)
            cout <<setw(10) <<p[7*i+j];
          cout <<endl;
      }
      return 0;
  }
*/