//F_�ֲ�����.cpp
  #include <iostream>
  #include <cmath>
  #include "����ȫBeta����.cpp"
  using namespace std;
//f      �������ֵ��Ҫ��f>=0��
//n1     ���ɶȡ�
//n2     ���ɶȡ�
  //����F�ֲ�����ֵ��
  double ffff(double f, int n1, int n2)
  { 
	  double y;
      if (f<0.0) f=-f;
      y=inbeta(n2/2.0,n1/2.0,n2/(n2+n1*f));
      return(y);
  }
/*
//F_�ֲ�������
  #include <iostream>
  #include <cmath>
//  #include "F_�ֲ�����.cpp"
  using namespace std;
  int main()
  { 
	  int n1,n2,i;
      double y,f;
      int n[2]={ 2,5};
      int m[2]={ 3,10};
      for (i=0; i<=1; i++)
      { 
		  n1=n[i]; n2=m[i]; f=3.5;
          y=ffff(f,n1,n2);
          cout <<"P(" <<f <<", " <<n1 <<", " <<n2 <<")=" <<y <<endl;
          f=9.0; y=ffff(f,n1,n2);
          cout <<"P(" <<f <<", " <<n1 <<", " <<n2 <<")=" <<y <<endl;
      }
      return 0;
  }
*/
