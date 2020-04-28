#include <stdio.h>


    extern int count;   //引用式声明，外部链接
    static int total = 0;//静态定义，内部链接
    extern int test;
    void counter(int);//函数原型

    void counter(int num)
    {
        printf("%d\n", test);
        //局部静态变量
        static int subTotal = 0;
        if(num <= 0)
        {
            printf("第 %d 轮循环执行完毕\n", count);
            printf("局部静态变量subTotal和全局静态变量total：\n");
            printf("subTotal: %d\ttotal: %d\n", subTotal, total);
            subTotal = 0;//每次内循环结束后重置为0
        }
        else
        {
            subTotal += num;
            total += num;
        }
    }
