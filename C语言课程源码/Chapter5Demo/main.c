#include <stdio.h>
#include <stdlib.h>
/**
 * ��ӡ�Ǻ�����
 */
int main()
{
    printf(" X |\t1\t2\t3\t4");
    int i, j;
    for(i = 1; i <= 9; i++)
    {
        printf(" %d |  ", i);
        for(j = 1; j <= 9; j++)
        {
            printf("%4d", j);
        }
        printf("\n");
    }
    /*
    //�� 1 + 2! + 3! + �� + 10!�ĺ�
    int sum = 0;    //�ۼ���
    int f = 1;      //�۳���
    int i, j;          //ѭ������
    for(i = 1; i <= 10; i++)
    {
        j = 1;//ÿ����ѭ��֮ǰ���ǵý��׳�ֵ����Ϊ1��
        //ÿ����ѭ����Ҫ������ѭ���Ľ׳�
        for(j = 1; j <= i; j++)
        {
            f *= j;//ÿ�ε��۳�ֵ
        }
        sum += f;
    }
    printf("result = %d\n", sum);
*/











    /*
    //1.��ӡ�Ǻ�����
    //2.���Ǻ��滻����������
    int i, j;
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j <= 4 - i; j++)
        {
            printf("%d", 5 - i);
        }
        printf("\n");
    }
*/











    /*
    int i, j;   //ѭ������
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j <= 2 - i; j++)
        {
            printf(" ");
        }
        //�ڲ�ѭ��������
        for(j = 0; j <= 2 * i; j++)
        {
            if(j == 0 || j == 2 * i)//�����i��j�ļ�ֵʱ����ӡ�Ǻţ������ӡ�ո�
                printf("*");
            else
                printf(" ");//��ӡ�ո�ʵ���ڿյ�Ч��
        }
        printf("\n");
    }
    //ͼ�ε��°벿��
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j <= i ; j++)
        {
            printf(" ");
        }
        //�ڲ�ѭ��������
        for(j = 0; j <= 4 - 2 * i; j++)
        {
            if(j == 0 || j == 4 - 2 * i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    */
    return 0;
}
