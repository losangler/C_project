//���Խ��߷������׷�Ϸ�.cpp
  #include <iostream>
  #include <cmath>
  using namespace  std;
//b[m]       ����Ϊ��������Խ����������Խ����ϵ�Ԫ�ء�
//n          �����������
//m          ���Խ���3���Խ��ߵ�Ԫ�ظ�����m = 3n - 2��
//d[n]       ��ŷ������Ҷ˵ĳ������������ط�����Ľ�������
  //�������ر�־ֵ����<0���ʾm��ֵ���ԣ���=0���ʾʧ�ܣ���>0���ʾ������
  int trde(double b[], int n, int m, double d[])
  { 
	  int k,j;
      double s;
      if (m!=(3*n-2))   return -2;
      for (k=0;k<=n-2;k++)
      { 
		  j=3*k; s=b[j];
          if (fabs(s)+1.0==1.0)  return 0;
          b[j+1]=b[j+1]/s;
          d[k]=d[k]/s;
          b[j+3]=b[j+3]-b[j+2]*b[j+1];
          d[k+1]=d[k+1]-b[j+2]*d[k];
      }
      s=b[3*n-3];
      if (fabs(s)+1.0==1.0)  return 0;
      d[n-1]=d[n-1]/s;
      for (k=n-2;k>=0;k--)  d[k]=d[k]-b[3*k+1]*d[k+1];
      return(2);
  }

/*
  #include <iostream>
  #include <cmath>
//  #include "���Խ��߷������׷�Ϸ�.cpp"
  using namespace  std;
  int main()
  { 
	  int i;
      double b[13]={13.0,12.0,11.0,10.0,9.0,8.0,7.0,
                         6.0,5.0,4.0,3.0,2.0,1.0};
      double d[5]={3.0,0.0,-2.0,6.0,8.0};
      if (trde(b,5,13,d)>0)
      for (i=0;i<=4;i++)
        cout <<"x(" <<i <<") = " <<d[i] <<endl;
	  return 0;
  }
*/
