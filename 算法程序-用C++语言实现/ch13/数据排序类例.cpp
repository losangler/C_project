//������������.cpp
  #include <iomanip>
  #include "����������.h"
  #include "�����������.h"
  using namespace std;
  int main()
  { 
	  int i,j;

	  cout <<"ð��������:" <<endl;
	  RND r(5);
	  DATA_SORT<double> q;
      double p[70];
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
      q.bub_sort(49,p+7);         //��2��8��������ð�ݷ�����
	  cout <<"�����:" <<endl;
      for (i=0; i<10; i++)
      { 
		  for (j=0; j<7; j++)
            cout <<setw(10) <<p[7*i+j];
          cout <<endl;
      }

	  cout <<"����������" <<endl;
	  RND r1(5);
	  DATA_SORT<int> q1;
      int p1[100];
	  for (i=0; i<100; i++)  //����100��1��999֮����������
		  p1[i] = r1.rndab(1,999);
	  cout <<"����ǰ:" <<endl;
      for (i=0; i<10; i++)    //��10��
      { 
		  for (j=0; j<10; j++)  //һ��10��
            cout <<setw(6) <<p1[10*i+j];
          cout <<endl;
      }
      q1.qck_sort(70,p1+10);         //��2��8�������ÿ�����������
	  cout <<"�����:" <<endl;
      for (i=0; i<10; i++)
      { 
		  for (j=0; j<10; j++)
            cout <<setw(6) <<p1[10*i+j];
          cout <<endl;
      }

	  cout <<"ϣ��������" <<endl;
	  RND r2(5);
	  DATA_SORT<int> q2;
      int p2[100];
	  for (i=0; i<100; i++)  //����100��1��999֮����������
		  p2[i] = r2.rndab(1,999);
	  cout <<"����ǰ:" <<endl;
      for (i=0; i<10; i++)    //��10��
      { 
		  for (j=0; j<10; j++)  //һ��10��
            cout <<setw(6) <<p2[10*i+j];
          cout <<endl;
      } 
      q2.shel_sort(70,p2+10);         //��2��8�������ÿ�����������
	  cout <<"�����:" <<endl;
      for (i=0; i<10; i++)
      { 
		  for (j=0; j<10; j++)
            cout <<setw(6) <<p2[10*i+j];
          cout <<endl;
      }

	  cout <<"��������" <<endl;
	  RND r3(5);
	  DATA_SORT<double> q3;
      double p3[70];
	  for (i=0; i<70; i++)  //����70��0��1֮��������
		  p3[i] = r3.rnd1();
      for (i=0; i<70; i++)   //ת����0��999֮��������
		  p3[i]=0.0+999.0*p3[i];
	  cout <<"����ǰ:" <<endl;
      for (i=0; i<10; i++)    //��10��
      { 
		  for (j=0; j<7; j++)  //һ��7��
            cout <<setw(10) <<p3[7*i+j];
          cout <<endl;
      } 
      q3.hap_sort(49,p3+7);            //��2��8�������ö���������
	  cout <<"�����:" <<endl;
      for (i=0; i<10; i++)
      { 
		  for (j=0; j<7; j++)
            cout <<setw(10) <<p3[7*i+j];
          cout <<endl;
      }

      return 0;
  }
