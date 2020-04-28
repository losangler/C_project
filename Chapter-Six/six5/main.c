#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a[10];
    int sum = 0;
    printf("请输入10个数字：\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    double average = sum / 10.0;
    printf("平均数为：%lf\n",average);
}
