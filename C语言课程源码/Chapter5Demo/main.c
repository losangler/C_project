#include <stdio.h>
#include <stdlib.h>
/**
 * 打印星号菱形
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
    //求 1 + 2! + 3! + … + 10!的和
    int sum = 0;    //累加器
    int f = 1;      //累乘器
    int i, j;          //循环变量
    for(i = 1; i <= 10; i++)
    {
        j = 1;//每次内循环之前，记得将阶乘值重置为1！
        //每个内循环，要计算外循环的阶乘
        for(j = 1; j <= i; j++)
        {
            f *= j;//每次的累乘值
        }
        sum += f;
    }
    printf("result = %d\n", sum);
*/











    /*
    //1.打印星号三角
    //2.将星号替换成整型数字
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
    int i, j;   //循环变量
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j <= 2 - i; j++)
        {
            printf(" ");
        }
        //内层循环控制列
        for(j = 0; j <= 2 * i; j++)
        {
            if(j == 0 || j == 2 * i)//如果是i、j的极值时，打印星号，否则打印空格
                printf("*");
            else
                printf(" ");//打印空格，实现挖空的效果
        }
        printf("\n");
    }
    //图形的下半部分
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j <= i ; j++)
        {
            printf(" ");
        }
        //内层循环控制列
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
