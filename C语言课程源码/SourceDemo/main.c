#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    1��system("pause");	������Ļ�����ڹ۲�����ִ�н��
2��system("cls");	��������
3��system("color 4E");	�޸ı���ɫ��ǰ��ɫ
4��system("shutdown /r /t 180");

    return 0;
}

    /*
    int num[] = {[1]=98, 12, 45, 66};
    int i, temp;
    //��������
    int * ptr_num_start = num;
    int * ptr_num_end = num + 4;
    while(ptr_num_start != ptr_num_end)
    {
        temp = *ptr_num_start;
        *ptr_num_start = *ptr_num_end;
        *ptr_num_end = temp;
        ptr_num_start++;
        ptr_num_end--;
    }
    printf("���������\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d\n", num[i]);
    }

    */
    /*
    int num1 = 1024;
    int num2 = 2048;
    int * ptr1, * ptr2;
    ptr1 = &num1;
    ptr2 = &num2;
    printf("num1��ֵ��%d\tnum1�ĵ�ַ�ǣ�%p\n", num1, ptr1);
    printf("num2��ֵ��%d\tnum2�ĵ�ַ�ǣ�%p\n", num2, ptr2);
    //ptr2 = ptr1;
    *ptr2 = *ptr1;
    printf("���¸�ֵ��\n");
    printf("num2��ֵ��%d\tnum2�ĵ�ַ�ǣ�%p\n", num2, ptr2);
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
    return 0;
}*/
