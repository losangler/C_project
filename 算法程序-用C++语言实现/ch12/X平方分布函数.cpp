//Xƽ���ֲ�����.cpp
  #include <iostream>
  #include <cmath>
  #include "����ȫgamma����.cpp"
  using namespace std;
//x     �Ա���ֵ��
//n     ���ɶȡ�
  //����Xƽ���ֲ�����ֵ��
  double chii(double x, int n)
  { 
	  double y;
      if (x<0.0) x=-x;
      y=ingamma(n/2.0,x/2.0);
      return(y);
  }
/*
//Xƽ���ֲ�������
  #include <iostream>
  #include <cmath>
//  #include "Xƽ���ֲ�����.cpp"
  using namespace std;
  int main()
  { 
	  int n;
      double t,y;
      for (n=1; n<=5; n++)
      { 
		  t=0.5; y=chii(t,n);
          cout <<"P(" <<t <<", " <<n <<")=" <<y <<endl;
          t=5.0; y=chii(t,n);
          cout <<"P(" <<t <<", " <<n <<")=" <<y <<endl;
      }
      return 0;
  }
*/