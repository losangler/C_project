#include <stdio.h>


    extern int count;   //����ʽ�������ⲿ����
    static int total = 0;//��̬���壬�ڲ�����
    extern int test;
    void counter(int);//����ԭ��

    void counter(int num)
    {
        printf("%d\n", test);
        //�ֲ���̬����
        static int subTotal = 0;
        if(num <= 0)
        {
            printf("�� %d ��ѭ��ִ�����\n", count);
            printf("�ֲ���̬����subTotal��ȫ�־�̬����total��\n");
            printf("subTotal: %d\ttotal: %d\n", subTotal, total);
            subTotal = 0;//ÿ����ѭ������������Ϊ0
        }
        else
        {
            subTotal += num;
            total += num;
        }
    }
