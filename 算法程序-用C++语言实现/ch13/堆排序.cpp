//������.cpp
    #include <iostream>
    #include <cmath>
	using namespace std;
	//��������
    template <class T>
    void sift(T p[], int i, int n)
	{ 
		int j;
        T t;
        t=p[i]; j=2*(i+1)-1;
        while (j<=n)
		{ 
			if ((j<n)&&(p[j]<p[j+1])) j=j+1;
            if (t<p[j])
			{ 
				p[i]=p[j]; i=j; j=2*(i+1)-1;
			}
            else j=n+1;
		}
        p[i]=t;
        return;
	}
//n         ���������г��ȡ�
//p[n]      ���������С�
	template <class T>
    void hap_sort(int n, T p[])
	{ 
		int i,mm;
        T t;
        mm=n/2;
        for (i=mm-1; i>=0; i--)//�������н���
           sift(p,i,n-1);  
        for (i=n-1; i>=1; i--)
		{
			t=p[0]; p[0]=p[i]; p[i]=t;  //�Ѷ�Ԫ�ػ������
            sift(p,0,i-1);  //��������
		}
        return;
	}
/*
//��������
  #include <iomanip>
//  #include "������.cpp"
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
      hap_sort(49,s);         //��2��8�������ö���������
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