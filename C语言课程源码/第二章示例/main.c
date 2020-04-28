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
    //calloc作用与molloc类似
    //1.不需要强转，直接返回数组
    //2.两个参数，默认初始化数组元素
    num = calloc(5, sizeof(int));
    //realloc()
    num[4] = 9;
    for(i = 0; i < 5; i++)
    {
        printf("%d\n", num[i]);
    }
    free(num);//用完释放内存
    //printf("结果：%d\n", result);
    /*
    int i, j, k;
    i = 3;
    j = (++i) + (++i);
    printf("%d\n", j);
    */
/*
    int num = 1024; //整型变量
    int *ptr_num;   //整型指针变量
    ptr_num = &num; //取num的地址赋值给ptr_num变量
    printf("num的值为：%d\n", num);
    printf("num的内存地址为：%p\n", &num);
    printf("ptr_num的值为：%p\n", ptr_num);
    printf("ptr_num的内存地址为：%p\n", &ptr_num);
    printf("*ptr_num指向的值为：%d\n", *ptr_num);
*/







    /*
        某游戏中近战武器的实际伤害计算公式为：
        武器实际最大伤害 = 武器最大伤害 * (玩家力量 + 100) / 100
        现有如下武器，武器最大伤害256，要求输入玩家的力量，打印武器实际最大伤害
    */
    //1、需要定义几个变量？ -- 武器实际最大伤害，玩家的力量，武器最大伤害
    //2、对应什么数据类型呢？  double              int        double
/*
    double factShangHai;    //武器实际最大伤害
    int strength;           //玩家力量
    double maxShangHai = 256;   //武器最大伤害


    printf("请玩家输入当前角色的力量：");
    //&取地址
    scanf("%d", &strength);
    //套用公式
    factShangHai = maxShangHai * (strength + 100) / 100;
    printf("武器实际伤害是：%.2lf", factShangHai);
*/
    return 0;
}
