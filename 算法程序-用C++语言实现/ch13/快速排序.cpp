//��������.cpp
    #include <iostream>
    #include <cmath>
    #include "ð������.cpp"
	using namespace std;
    //��ķָ�
    template <class T>
    int split(int n, T p[])
	{ 
		int i,j,k,l;
        T t;
        i=0; j=n-1;
        k=(i+j)/2;
        if ((p[i]>=p[j])&&(p[j]>=p[k])) l=j;
        else if ((p[i]>=p[k])&&(p[k]>=p[j])) l=k;
        else l=i;
        t=p[l];   //ѡȡһ��Ԫ��ΪT
	    p[l]=p[i]; 
        while (i!=j)
		{ 
			while ((i<j)&&(p[j]>=t)) j=j-1; //�𽥼�Сj��ֱ������p[j]<t
            if (i<j)
			{ 
				p[i]=p[j]; i=i+1;
                while ((i<j)&&(p[i]<=t)) i=i+1;//������i��ֱ������p[i]>t
                if (i<j)	{ p[j]=p[i]; j=j-1;}
			}
		}
        p[i]=t;
        return(i);  //���طֽ���λ��
	}
//n         ���������г��ȡ�
//p[n]      ���������С�
	template <class T>
    void qck_sort(int n, T p[])
	{
		int m, i;
        T *s;
        if (n>10)        //�ӱ��ȴ���10���ÿ�������
		{ 
			i=split(n,p);       //�Ա���зָ� 
            qck_sort(i, p);        //��ǰ����ӱ���п�������
	        s=p+(i+1);
            m=n-(i+1);
            qck_sort(m, s);     //�Ժ�����ӱ���п�������
		}
        else  //�ӱ���С��10����ð������
		    bub_sort(n, p);
        return;
	}
/*
//����������
  #include <iomanip>
//  #include "��������.cpp"
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
      qck_sort(70,s);         //��2��8�������ÿ�����������
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