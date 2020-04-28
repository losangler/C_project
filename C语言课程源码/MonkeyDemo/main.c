#include <stdio.h>
#include <stdlib.h>

int main()
{
    int value1 = 44;
    int arr[4];
    int value2 = 88;
    int i;

    printf("value1 = %d, value2 = %d\n", value1, value2);
    arr[-1] = 9;
//    for(i = -1; i <= 4; i++){
//        arr[i] = 2 * i + 1;
//    }
    /*
    for(i = -1; i < 7; i++){
        printf("%d\t%d\n", i, arr[i]);
    }*/
    printf("\n");
    printf("value1 = %d, value2 = %d\n", value1, value2);

    printf("arr[-1]的地址：%p\n", &arr[-1]);
    printf("arr[9]的地址：%p\n", &arr[4]);
    printf("value1的地址：%p\n", &value1);
    printf("value2的地址：%p\n", &value2);

    /*
    int age;
    int i;
    int count = 0;//计数器
    for(i = 0; i < 5; i++)
    {
        printf("请输入玩家年龄：");
        scanf("%d", &age);
        if(age >= 0)//正确
        {
            continue;//跳过正确的情况
        }
        count++;
    }
    printf("输入错误%d次！\n", count);
*/













    /*
    int price = 7890;   //要用户猜的商品价格，也可以使用随机函数生成
    int guessPrice;     //用户猜测的商品价格
    int count = 0;      //用来记录猜的次数
    srand(time(NULL));
    price = rand() % 10000;
    printf("%d", price);
    for(;;)
    {
        printf("请输入猜测的商品价格：");
        scanf("%d", &guessPrice);
        if(guessPrice > price)
        {
            printf("大了！\n");
        }
        else if(guessPrice < price)
        {
            printf("小了！\n");
        }
        else//否则
        {
            printf("恭喜，猜对啦！\n");
            count++;
            break;//如果猜对了，就跳出循环
        }
        count++;

    }

    printf("您一共猜了%d次\n", count);
    if(count <= 5)
    {
        printf("精彩，您简直是天才！\n");
    }

*/









    /*
    //循环输入玩家的年龄，如果年龄为负则停止输入，提示输入错误
    int age;    //玩家的年龄
    //for(;;)
    //while(1)
    for(;;)
    {
        printf("请输入玩家年龄：");
        scanf("%d", &age);
        //判断
        if(age < 0)
        {
            printf("年龄不能为负数！程序强制退出！\n");
            break;
        }
    }
    */
    //













/*
    //打印简易加法表
    //1、打印纯的加法表
    int num;
    int i;  //循环变量
    printf("请输入一个数字：");
    scanf("%d", &num);
    for(i = 0; i < num; i++)
    {
        //0 + 8 = 8
        printf("%d + %d = %d", i, (num - i), num);
        //这里需要探讨：什么情况打印\t什么情况打印\n
        //结论：我们需要通过判断循环变量的值，确定打印的符号
        if(i % 2 == 0)//当i是偶数的情况（0,2,4,6)
        {
            printf("\t");
        }
        else//奇数的情况
        {
            printf("\n");
        }

    }
*/










    /*
    int y = 1;//第十天桃子的数量
    int i = 0;//控制循环的次数 - 9次循环
    while(i < 9)
    {
        y = (y + 1) * 2;
        i++;
    }
    printf("第一天的桃子数量是：%d\n", y);
    */
    return 0;
}
