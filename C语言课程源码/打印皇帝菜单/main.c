#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num = 123456789;
    //将4位数的每一位都取出来
    printf("个位：%d\n", num % 10);
    printf("十位：%d\n", num / 10 % 10);
    printf("百位：%d\n", num / 100 % 10);
    printf("千位：%d\n", num / 1000 % 10);

    exit(0);//退出系统


    //规律：除10再模10
    int temp;   //临时变量
    while(num > 0)
    {
        printf("%d\n", num % 10);
        num /= 10;//取出个位数字后，立即去掉个位数字
    }






    /*
    int choice;     //用户的选择
    while(1)
    {
        //打印游戏菜单
        printf("性格测试：\n");
        printf("如果您是一位君王，对于身旁的伴侣您希望？\n");
        printf("1、只要有一位真爱的妻子\n");
        printf("2、可以两位以上的爱人\n");
        printf("3、拥有三千佳丽\n");
        do{//如果输入错误，将会一直循环输入
            printf("请选择:");
            scanf("%d", &choice);
            if(choice <= 0 || choice > 3)
            {
                printf("只能输入1-3之间的数字！请重新输入：\n");
            }
        }while(choice <= 0 || choice > 3);//思考：choice为什么值的时候，执行循环?
        //如果执行到了这里，证明用户的输入是正确的，在1-3之间
        switch(choice)
        {
        case 1:
            printf("您选择了生命中的唯一，然而老九君已看穿了一切！\n");
            break;
        case 2:
            printf("你个花心大萝卜！\n");
            break;
        case 3:
            printf("金哥金哥，10元/包，江浙沪包邮！\n");
            break;
        }
    }*/
    return 0;
}




