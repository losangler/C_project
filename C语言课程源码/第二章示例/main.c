#include <stdio.h>
#include <stdlib.h>
void change(int num)
{
    num++;
}
int main()
{
    int num = 9;
    change(num);
    printf("num = %d\n", num);


    /*
    int * num;
    int i;
    //calloc������molloc����
    //1.����Ҫǿת��ֱ�ӷ�������
    //2.����������Ĭ�ϳ�ʼ������Ԫ��
    num = calloc(5, sizeof(int));
    //realloc()
    num[4] = 9;
    for(i = 0; i < 5; i++)
    {
        printf("%d\n", num[i]);
    }
    free(num);//�����ͷ��ڴ�
    //printf("�����%d\n", result);
    /*
    int i, j, k;
    i = 3;
    j = (++i) + (++i);
    printf("%d\n", j);
    */
/*
    int num = 1024; //���ͱ���
    int *ptr_num;   //����ָ�����
    ptr_num = &num; //ȡnum�ĵ�ַ��ֵ��ptr_num����
    printf("num��ֵΪ��%d\n", num);
    printf("num���ڴ��ַΪ��%p\n", &num);
    printf("ptr_num��ֵΪ��%p\n", ptr_num);
    printf("ptr_num���ڴ��ַΪ��%p\n", &ptr_num);
    printf("*ptr_numָ���ֵΪ��%d\n", *ptr_num);
*/







    /*
        ĳ��Ϸ�н�ս������ʵ���˺����㹫ʽΪ��
        ����ʵ������˺� = ��������˺� * (������� + 100) / 100
        ����������������������˺�256��Ҫ��������ҵ���������ӡ����ʵ������˺�
    */
    //1����Ҫ���弸�������� -- ����ʵ������˺�����ҵ���������������˺�
    //2����Ӧʲô���������أ�  double              int        double
/*
    double factShangHai;    //����ʵ������˺�
    int strength;           //�������
    double maxShangHai = 256;   //��������˺�


    printf("��������뵱ǰ��ɫ��������");
    //&ȡ��ַ
    scanf("%d", &strength);
    //���ù�ʽ
    factShangHai = maxShangHai * (strength + 100) / 100;
    printf("����ʵ���˺��ǣ�%.2lf", factShangHai);
*/
    return 0;
}
