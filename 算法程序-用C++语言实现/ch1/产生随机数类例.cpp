//�������������.cpp
  #include  <iostream>
  #include  <cmath>
  #include  "�����������.h"
  using namespace std;
  int main()
  {
	  int i, j, r, a, b;
	  double u, g;
	  RND p;
      cout <<"����50��0��1֮������������:" <<endl;
	  r = 5;
      p = RND(r);
	  for (i=0; i<=9; i++)
	  {
		  for (j=0; j<=4; j++)  cout <<p.rnd1() <<"    ";
		  cout <<endl;
	  }

      cout <<"����50��101��200֮��������������:" <<endl;
      r = 1; a = 101; b = 200;
      p = RND(r);
	  for (i=0; i<=4; i++)
	  {
		  for (j=0; j<=9; j++)  cout <<p.rndab(a, b) <<"    ";
		  cout <<endl;
	  }

      cout <<"����50����ֵΪ1.0,����Ϊ1.5*1.5����̬�ֲ������������:" <<endl;
      r = 3; u = 1.0; g = 1.5; 
      p = RND(r);
	  for (i=0; i<=9; i++)
	  {
		  for (j=0; j<=4; j++)  cout <<p.rndg(u, g) <<"    ";
		  cout <<endl;
	  }

      return 0;
  }

