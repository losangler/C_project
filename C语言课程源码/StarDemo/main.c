#include <stdio.h>
#include <stdlib.h>

int main()
{
    //��ӡ�Ǻ�ͼ��
    int i, j;
    //���ѭ�� ������(����������)
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j <= 2 - i; j++)
        {
            printf(" ");
        }
        //�ڲ�ѭ�� ������(�������еķ���)
        for(j = 0; j <= 2 * i; j++)
        {
            //�ڿյ�ԭ���ж�ʲôʱ���ӡ�Ǻţ�ʲôʱ���ӡ�ո�
            if(i == 0 || i == 3 || j == 0 || j == 2 * i)
                printf("%c", '*');
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
