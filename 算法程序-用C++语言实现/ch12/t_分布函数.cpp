//t_�ֲ�����.cpp
  #include <iostream>
  #include <cmath>
  #include "����ȫBeta����.cpp"
  using namespace std;
//t     �������ֵ��Ҫ��t>=0��
//n     ���ɶȡ�
  //����t�ֲ�����ֵ��
  double student(double t, int n)
  { 
	  double y;
      if (t<0.0) t=-t;
      y=1.0-inbeta(n/2.0,0.5,n/(n+t*t));
      return(y);
  }
/*
//t_�ֲ�������
  #include <iostream>
  #include <cmath>
//  #include "t_�ֲ�����.cpp"
  using namespace std;
  int main()
  { 
	  int n;
      double t,y;
      for (n=1; n<=5; n++)
      { 
		  t=0.5; y=student(t,n);
          cout <<"P(" <<t <<", " <<n <<")=" <<y <<endl;
          t=5.0; y=student(t,n);
          cout <<"P(" <<t <<", " <<n <<")=" <<y <<endl;
      }
      return 0;
  }
*/
