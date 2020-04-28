//����������.h
  #include  <iostream>
  #include  <cmath>
  #include  <fstream>
  using namespace std;
  template <class T>
  class  DATA_SORT
  {
  private: 
		   
		   
  public:
	       
		   void bub_sort(int , T *);             //ð������
		   void qck_sort(int , T *);             //��������
           int split(int ,T []);               //��ָ�
		   void shel_sort(int , T *);            //ϣ������
		   void hap_sort(int , T *);             //������
		   void sift(T *, int , int);         //��������

  };
//ð������
	template <class T>
	void DATA_SORT<T>::bub_sort(int n, T *p)
	{ 
		int m,k,j,i;
        T d;
        k=0; m=n-1;
        while (k<m)
		{ 
			j=m-1; m=0;
            for (i=k; i<=j; i++)       //��ǰ����ɨ��
              if (p[i]>p[i+1])         //˳�򲻶ԣ�����
			  { 
				  d=p[i]; p[i]=p[i+1]; p[i+1]=d; 
				  m=i;
			  }
            j=k+1; k=0;
            for (i=m; i>=j; i--)       //�Ӻ���ǰɨ��
              if (p[i-1]>p[i])         //˳�򲻶ԣ�����
			  {
				  d=p[i]; p[i]=p[i-1]; p[i-1]=d;
				  k=i;
			  }
		}
        return;
	}
//��������
	template <class T>
	void DATA_SORT<T>::qck_sort(int n, T *p)
	{
		int m, i;
        T *s;
        if (n>10)        //�ӱ��ȴ���10���ÿ�������
		{ 
			i=split(n,p);       //�Ա���зָ� 
            qck_sort(i, p);        //��ǰ����ӱ���п�������
	        s=p+(i+1);
            m=n-(i+1);
            qck_sort(m, s);     //�Ժ�����ӱ���п�������
		}
        else  //�ӱ���С��10����ð������
		    bub_sort(n, p);
        return;
	}
    //��ķָ�
    template <class T>
	int DATA_SORT<T>::split(int n, T p[])
	{ 
		int i,j,k,l;
        T t;
        i=0; j=n-1;
        k=(i+j)/2;
        if ((p[i]>=p[j])&&(p[j]>=p[k])) l=j;
        else if ((p[i]>=p[k])&&(p[k]>=p[j])) l=k;
        else l=i;
        t=p[l];   //ѡȡһ��Ԫ��ΪT
	    p[l]=p[i]; 
        while (i!=j)
		{ 
			while ((i<j)&&(p[j]>=t)) j=j-1; //�𽥼�Сj��ֱ������p[j]<t
            if (i<j)
			{ 
				p[i]=p[j]; i=i+1;
                while ((i<j)&&(p[i]<=t)) i=i+1;//������i��ֱ������p[i]>t
                if (i<j)	{ p[j]=p[i]; j=j-1;}
			}
		}
        p[i]=t;
        return(i);  //���طֽ���λ��
	}
//ϣ������
	template <class T>
	void DATA_SORT<T>::shel_sort(int n, T *p)
	{ 
		int k,j,i;
        T t;
        k=n/2;
        while (k>0)
		{ 
			for (j=k; j<=n-1; j++)
			{ 
				t=p[j]; i=j-k;
                while ((i>=0)&&(p[i]>t))
				{
					p[i+k]=p[i]; i=i-k;
				}
                p[i+k]=t;
			}
            k=k/2;
		}
        return;
	}
//������
	template <class T>
	void DATA_SORT<T>::hap_sort(int n, T *p)
	{ 
		int i,mm;
        T t;
        mm=n/2;
        for (i=mm-1; i>=0; i--)//�������н���
           sift(p,i,n-1);  
        for (i=n-1; i>=1; i--)
		{
			t=p[0]; p[0]=p[i]; p[i]=t;  //�Ѷ�Ԫ�ػ������
            sift(p,0,i-1);  //��������
		}
        return;
	}
	//��������
    template <class T>
	void DATA_SORT<T>::sift(T p[], int i, int n)
	{ 
		int j;
        T t;
        t=p[i]; j=2*(i+1)-1;
        while (j<=n)
		{ 
			if ((j<n)&&(p[j]<p[j+1])) j=j+1;
            if (t<p[j])
			{ 
				p[i]=p[j]; i=j; j=2*(i+1)-1;
			}
            else j=n+1;
		}
        p[i]=t;
        return;
	}



