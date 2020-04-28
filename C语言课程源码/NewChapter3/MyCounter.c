/**
 * MyCount.c
 * 用来存放计算函数调用次数的函数原型及实现
 */
//引用了外部变量
extern int whileCount;

void counter(int);//用来计算counter函数执行了多少次

void counter(int i)
{
    static int subTotal = 0;    //静态变量

    subTotal++;

    printf("counter函数被调用了%d次\n", subTotal);
    printf("当前是while的第%d轮！\n", whileCount);
    return ;
}
