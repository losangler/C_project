#include <stdio.h>
#include <stdlib.h>

#define N 5
int main()
{













/*
    int array[N] = {15, 20, 25, 30, 35};
    //ʵ����������� - ԭ������������βԪ�ؽ��н���
    int temp;   //��ʱ����
    int i;
    int * ptr_array_start = array;      //ָ��������Ԫ�ص�ָ��
    int * ptr_array_end = array + 4;    //ָ������ĩԪ�ص�ָ��
    //array[4] N-1���Դ������Ԫ�ص��±� array[N-1]
    while(ptr_array_start != ptr_array_end)
    {
        //��β������ָ��ֱ���и���
        temp = *ptr_array_start;
        *ptr_array_start = *ptr_array_end;
        *ptr_array_end = temp;
        //��Ԫ��ָ��Ҫ����ƶ�
        ptr_array_start++;
        //ĩԪ��ָ��Ҫ��ǰ�ƶ�
        ptr_array_end--;
    }
    /*
    for(i = 0; i < N / 2; i++)
    {
        //��i��ֵ�͵�N-i-1��ֵ�ཻ��
        temp = array[i];
        array[i] = array[N - i - 1];
        array[N - i - 1] = temp;
    }*/
    /*
    printf("\n");
    for(i = 0; i < N; i++)
    {
        printf("%d\t", *(array + i));
    }*/

















    /*
    int i;
    int * ptr_array = array;
    //��ֵ��Ϻ󣬾Ϳ���ʹ��ָ���������Ԫ����
    for(i = 0; i < 5; i++)
    {
        //printf("��%d��Ԫ�ص�ֵΪ%d\t��ַΪ��%p\n", i + 1, ptr_array[i], &ptr_array[i]);
        //printf("��%d��Ԫ�ص�ֵΪ%d\t��ַΪ��%p\n", i + 1,
        //                *(ptr_array + i), ptr_array + i);
        printf("��%d��Ԫ�ص�ֵΪ%d\t��ַΪ��%p\n", i + 1, *ptr_array, ptr_array);
        //ÿ��ѭ�������ƶ�ָ���ָ��Ҫע������
        ptr_array++;
    }
*/















    /*
    //����������������׵�ַ
    int i;  //ѭ������
    double score[] = {98, 87, 65, 43, 76};
    double * ptr_score = score;
    //ʹ��ָ���������Ԫ��
    printf("������׵�ַ��%p\t������Ԫ�صĵ�ַ��%p\n", score, &score[0]);
    for(i  = 0; i < 5; i++)
    {
        //printf("%.2lf\n", ptr_score[i]);
        //printf("%.2lf\n", *(ptr_score + i));
        printf("%.2lf\n", *ptr_score++);
    }
    //��������ϣ���ٴδ�ӡ�����ÿ��Ԫ��
    printf("***************");
    //���·�������Ԫ��ǰ���ǵ�����ָ���λ��
    ptr_score = score;
    for(i  = 0; i < 5; i++)
    {
        //printf("%.2lf\n", ptr_score[i]);
        //printf("%.2lf\n", *(ptr_score + i));
        printf("%.2lf\n", *ptr_score++);
    }














    /*
    int num = 9;
    //*���ֶ�������У���ʾָ������
    int *ptr_num = NULL;
    ptr_num = &num;
    int *ptr_num2 = ptr_num;
    //ͷ�۵㣺ָ��ĵ�ַ
    int * *ptr_num3 = &ptr_num2;

    printf("num��ֵΪ��%d\tnum�ĵ�ַΪ��%p\n", **ptr_num3, ptr_num);
    //*��������ͨ����У���ʾ����������ȡ��ַ��ֵ��
    *ptr_num2 = 9999;   //˳������

    printf("num��ֵΪ��%d\tnum�ĵ�ַΪ��%p\n", **ptr_num3, ptr_num2);

    //���õı��ϰ��
    ptr_num = NULL;
    ptr_num2 = NULL;
    ptr_num3 = NULL;

















/*
    int num1 = 1024;
    int num2 = 2048;
    int * ptr1;
    int * ptr2;
    ptr1 = &num1;
    ptr2 = &num2;
    printf("num1��ֵ��%d\tnum1�ĵ�ַ�ǣ�%p\n", num1, ptr1);
    printf("num2��ֵ��%d\tnum2�ĵ�ַ�ǣ�%p\n", num2, ptr2);
    //������1��ֵ����������2
    //num2 = num1;// �ȼ�д�� *ptr2 = *ptr1;
    //ֱ�Ӳ���ָ��
    ptr2 = ptr1;

    printf("���¸�ֵ��\n");
    printf("num1��ֵ��%d\tnum1�ĵ�ַ�ǣ�%p\n", num1, ptr1);
    printf("num2��ֵ��%d\tnum2�ĵ�ַ�ǣ�%p\n", num2, ptr2);

    *ptr2 = 111111;
    printf("���¸�ֵ��\n");
    printf("num1��ֵ��%d\tnum1�ĵ�ַ�ǣ�%p\n", num1, ptr1);
    printf("num2��ֵ��%d\tnum2�ĵ�ַ�ǣ�%p\n", num2, ptr2);

    ptr1 = NULL;
*/









/*

    int num = 9;
    int * ptr_num = &num;
    //ͷ�۵㣺ָ��ĵ�ַ
    int * *ptr_num2 = &ptr_num;
    //**ptr_num2 = 55;
    printf("\nָ��ptr_num�ĵ�ַ��%p, %d\n", *ptr_num2, **ptr_num2);

    //ʹ��ָ���޸ı���ֵ
/*
    *ptr_num = 9999;
    printf("*ptr_num��Ӧ��ֵΪ��%d\n", num);
*/
    return 0;
}
