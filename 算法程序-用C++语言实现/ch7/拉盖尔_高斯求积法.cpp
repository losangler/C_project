//���Ƕ�_��˹�����.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//f          ���㱻������ֵf(x)�ĺ�������
  //�������ػ���ֵ��
  double lags(double (*f)(double))
  { 
	  int i;
      double x,g;
      double t[5]={0.26355990,1.41340290,
            3.59642600,7.08580990,12.64080000};
      double c[5]={0.6790941054,1.638487956,
             2.769426772,4.315944000,7.104896230};
      g=0.0;
      for (i=0; i<=4; i++)
      { 
		  x=t[i]; g=g+c[i]*(*f)(x); 
	  }
      return(g);
  }
/*
//���Ƕ�_��˹�������
  #include <cmath>
  #include <iostream>
//  #include "���Ƕ�_��˹�����.cpp"
  using namespace std;
  int main()
  { 
	  double lagsf(double);
      cout <<"g = " <<lags(lagsf) <<endl;
      return 0;
  }
//���㱻������ֵ
  double lagsf(double x)
  { 
	  return(x*exp(-x));
  }
*/