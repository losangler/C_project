#include <stdio.h>
#include <stdlib.h>

//ȫ�ֱ����������򣺵�ǰԴ�ļ�
int whileCount = 0; //ȫ�ֱ�����������whileѭ��ִ�е�����

int main()
{
    int value;      //�Զ�����-ִ��ѭ���Ĵ���
    register int i; //��ѭ����������Ϊ�Ĵ����洢ģʽ
    printf("������ѭ��ִ�еĴ���(��0�˳�)��");
    //�û������valueΪ�������ֲ���ֵ����0ʱ������ѭ��
    while(scanf("%d", &value) == 1 && value > 0)//ʵ��һ��ѭ��¼���Ч��
    {
        whileCount++;   //����++
        for(i = value; i >= 0; i--)//forѭ���ᱻִ��value+1��
        {
            //1��������֪��ѭ��ִ���˶��ٴ�
            //2�����ǻ���֪����counter�����������˶��ٴ�
            counter(i);//ÿ��ѭ������counter����
        }
        printf("������ѭ��ִ�еĴ���(��0�˳�)��");
    }
    return 0;
}
