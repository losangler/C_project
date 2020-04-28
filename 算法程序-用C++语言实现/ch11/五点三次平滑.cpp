//�������ƽ��.cpp
  #include <cmath>
  #include <iostream>
  using namespace std;
//n          �Ⱦ�۲������
//y[n]       ���n���Ⱦ�۲���ϵĹ۲����ݡ�
//yy[n]      ����n���Ⱦ�۲���ϵ�ƽ�������
  void kspt(int n, double y[], double yy[])
  { 
	  int i;
      if (n<5)
      { 
		  for (i=0; i<=n-1; i++) yy[i]=y[i];
	  }
      else
      { 
		  yy[0]=69.0*y[0]+4.0*y[1]-6.0*y[2]+4.0*y[3]-y[4];
          yy[0]=yy[0]/70.0;
          yy[1]=2.0*y[0]+27.0*y[1]+12.0*y[2]-8.0*y[3];
          yy[1]=(yy[1]+2.0*y[4])/35.0;
          for (i=2; i<=n-3; i++)
          { 
			  yy[i]=-3.0*y[i-2]+12.0*y[i-1]+17.0*y[i];
              yy[i]=(yy[i]+12.0*y[i+1]-3.0*y[i+2])/35.0;
          }
          yy[n-2]=2.0*y[n-5]-8.0*y[n-4]+12.0*y[n-3];
          yy[n-2]=(yy[n-2]+27.0*y[n-2]+2.0*y[n-1])/35.0;
          yy[n-1]=-y[n-5]+4.0*y[n-4]-6.0*y[n-3];
          yy[n-1]=(yy[n-1]+4.0*y[n-2]+69.0*y[n-1])/70.0;
      }
      return;
  }
/*
//�������ƽ����
  #include <cmath>
  #include <iostream>
  #include <iomanip>
//  #include "�������ƽ��.cpp"
  using namespace std;
  int main()
  { 
	  int i;
      double y[9]={54.0,145.0,227.0,359.0,401.0,
                        342.0,259.0,112.0,65.0};
      double yy[9];
      kspt(9,y,yy);
      for (i=0; i<=8; i++)  
		  cout <<"y(" <<i <<")=" <<setw(6) <<y[i]
		       <<"          yy(" <<i <<")=" <<setw(10) <<yy[i] <<endl;
      return 0;
  }
*/