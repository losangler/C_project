//�����ױ�ֵ�������䷨.cpp
    #include <iostream>
    #include <cmath>
    #include "�����׳�ֵEuler����.cpp"
    using namespace std;
//n          ��������ȷ���
//a          ����������˵�
//b          ���������Ҷ˵㡣Ҫ��b>a��
//eps        ���ƾ���Ҫ��
//y[n+1]     y[0]�����˵�߽�ֵy(a)��y[n]����Ҷ˵�߽�ֵy(b)��
//           ����n+1���Ⱦ���ɢ���ϵ���ֵ�⡣
//f          ������׳�΢�ַ����Ҷ˺���f(t,y,z)
    //��������y����˵㴦��һ�׵���ֵ
    double  shoot(int n, double a, double b, double eps, double y[],
		          double (*f)(double,double,double))
	{
		int k;
		double h, x, yy, zz, z, zz1, zz2, y0, yn, p;
		h = (b-a)/n; y0 = y[0]; yn = y[n];		
		z = 0.0;  
		yy = y[0]; zz = z;         //ȡ����y�ĳ�ֵ��һ�׵�����ֵ
        for (k=0; k<n; k++)        //����n���Ⱦ���ɢ���ϵ���ֵ��
		{
			x = a + k*h; 
			euler2(x,h,&yy,&zz,eps,f);//Euler�������׳�ֵ�䲽������һ��
            y[k+1] = yy; 
		}
		if (y[n]-yn > 0)    //���յ���ֵ��ֵ>�յ�߽�ֵ
		{
			zz2 = z;
			do
			{
				zz = zz2 - 0.1;	//����y��һ�׵�����ֵ��С		
                yy = y[0];      //����y��ֵ
                for (k=0; k<n; k++)  //����n���Ⱦ���ɢ���ϵ���ֵ��
				{
					x = a + k*h;
					euler2(x,h,&yy,&zz,eps,f);
                    y[k+1] = yy; 
				}
				if (y[n]-yn > 0) zz2 = zz2 - 0.1; //������С���ֵ
			}while (y[n]-yn > 0);
			zz1 = zz2 - 0.1;    //����һ�׵�����ֵ������
		}
		else
		{
			zz1 = z;
			do
			{
				zz = zz1 + 0.1;	//����y��һ�׵�����ֵ����		
                yy = y[0];      //����y��ֵ
                for (k=0; k<n; k++)  //����n���Ⱦ���ɢ���ϵ���ֵ��
				{
					x = a + k*h;
					euler2(x,h,&yy,&zz,eps,f);
                    y[k+1] = yy; 
				}
				if (y[n]-yn < 0) zz1 = zz1 + 0.1; //�������Ӻ��ֵ
			}while (y[n]-yn < 0);
			zz2 = zz1 + 0.1;     //����һ�׵�����ֵ������
		}
		do     //�Է�����
		{
			zz = (zz1 + zz2)/2; 
			z = zz; 			
            yy = y[0];         //����y��ֵ
            for (k=0; k<n; k++)  //����n���Ⱦ���ɢ���ϵ���ֵ��
			{
				x = a + k*h;
				euler2(x,h,&yy,&zz,eps,f);
                y[k+1] = yy; 
			}
			p = fabs(zz1-zz2);
			if (y[n]-yn > 0)  zz2 = z;
			else  zz1 = z;
		}while (p > 0.0000001);
		return(z);		
	}

/*
//�����ױ�ֵ�������䷨��1
    #include <iostream>
    #include <cmath>
//    #include "�����ױ�ֵ�������䷨.cpp"
    using namespace std;
	int main()
	{
		int k;
		double dy0, y[11], f(double,double,double);
		y[0] = 0.0;  y[10] = 1.0;
		dy0 = shoot(10, 0.0, 1.0, 0.0000001, y, f);
		cout <<"��ʼб�� = " <<dy0 <<endl;
		for (k=0; k<11; k++)
			cout <<"x = " <<0.1*k <<"     y = " << y[k] <<endl;
		return 0;
	}
//�������΢�ַ����Ҷ˺���ֵ
    double  f(double t, double y, double z)
	{
		double d;
		d = t + y;
		return(d);
	}
*/
/*
//�����ױ�ֵ�������䷨��2
    #include <iostream>
    #include <cmath>
//    #include "�����ױ�ֵ�������䷨.cpp"
    using namespace std;
	int main()
	{
		int k;
		double dy0, y[11], f(double,double,double);
		y[0] = 1.0;  y[10] = 2.0;
		dy0 = shoot(10, 0.0, 1.0, 0.0000001, y, f);
		cout <<"��ʼб�� = " <<dy0 <<endl;
		for (k=0; k<11; k++)
			cout <<"x = " <<0.1*k <<"     y = " << y[k] <<endl;
		return 0;
	}
//�������΢�ַ����Ҷ˺���ֵ
    double  f(double t, double y, double z)
	{
		double d;
		d = (6*t-3.0+t*z+3*y)/(1.0+t*t);
		return(d);
	}
*/