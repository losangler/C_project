#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a[10];
    int sum = 0;
    printf("������10�����֣�\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    double average = sum / 10.0;
    printf("ƽ����Ϊ��%lf\n",average);
}
