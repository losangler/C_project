//���㺯������ʽֵ.cpp
  //x   ���n�����ֵx[0]��x[n-1]��
  //b   �������ʽ�е�n+1������b[0]��b[n]
  //n   ����ʽ�Ľ�����ע�⣺������b[0]Ϊ��0�ڣ�
  //t   �Ա���ֵ
  //��������t���ĺ�������ʽֵ
  double funpqv(double x[],double b[],int n,double t)
  { 
	  int k;
      double u;
      u=b[n];
      for (k=n-1; k>=0; k--)
      { 
		  if (fabs(u)+1.0==1.0)
			  u=1.0e+35*(t-x[k])/fabs(t-x[k]);
          else
			  u=b[k]+(t-x[k])/u;
      }
      return(u);
  }

