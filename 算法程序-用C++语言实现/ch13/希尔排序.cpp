//ϣ������.cpp
    #include <iostream>
    #include <cmath>
	using namespace std;
//n         ���������г��ȡ�
//p[n]      ���������С�
	template <class T>
    void shel_sort(int n, T p[])
	{ 
		int k,j,i;
        T t;
        k=n/2;
        while (k>0)
		{ 
			for (j=k; j<=n-1; j++)
			{ 
				t=p[j]; i=j-k;
                while ((i>=0)&&(p[i]>t))
				{
					p[i+k]=p[i]; i=i-k;
				}
                p[i+k]=t;
			}
            k=k/2;
		}
        return;
	}
/*
//ϣ��������
  #include <iomanip>
//  #include "ϣ������.cpp"
  #include "�����������.h"
  int main()
  { 
	  RND r(5);
	  int i,j;
      int p[100],*s;
	  for (i=0; i<100; i++)  //����100��1��999֮����������
		  p[i] = r.rndab(1,999);
	  cout <<"����ǰ:" <<endl;
      for (i=0; i<10; i++)    //��10��
      { 
		  for (j=0; j<10; j++)  //һ��10��
            cout <<setw(6) <<p[10*i+j];
          cout <<endl;
      }
      s = p+10; 
      shel_sort(70,s);         //��2��8�������ÿ�����������
	  cout <<"�����:" <<endl;
      for (i=0; i<10; i++)
      { 
		  for (j=0; j<10; j++)
            cout <<setw(6) <<p[10*i+j];
          cout <<endl;
      }
      return 0;
  }
*/