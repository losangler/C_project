//���㺯������ʽ��һ��.cpp
  //x   ��Ž��ֵx[0]��x[j]
  //y   ��Ž�㺯��ֵy[0]��y[j]
  //b   �������ʽ�еĲ���b[0]��b[j-1]������ʱ������b[j]��
  //j   ����ʽ���ӵĽںš������������������ӵ�b[j]��
  void funpqj(double x[],double y[],double b[],int j)
  { 
	  int k,flag=0;
      double u;
	  u=y[j];
	  for (k=0; (k<j)&&(flag==0); k++)
	  {
		  if ((u-b[k])+1.0==1.0) flag=1;
		  else
			  u=(x[j] - x[k])/(u-b[k]);
	  }
      if (flag==1) u=1.0e+35;
	  b[j]=u;
      return;
  }
