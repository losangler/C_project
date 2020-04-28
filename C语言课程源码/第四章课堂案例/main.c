#include <stdio.h>
#include <stdlib.h>  //标准库
#include <time.h>    //time()
#include <windows.h> //Sleep
int main()
{

    //使用时间作为种子，产生不一样的随机数字
    srand(time(NULL));
    //rand()函数的取值范围是0-32767
    printf("随机数字：%d\n", rand());
    /*
    使用循环模拟实现玩家对战
        双方初始HP均为100
        每次攻击5-15
        HP最先到零或以下的被KO
    */
    int hp1 = 100, hp2 = 100;   //1p和2p的初始血量
    int att1, att2;             //1p和2p每次的攻击
    int i = 0;                  //对战的轮数
    while(hp1 >= 0 && hp2 >= 0)//当两个玩家都或活着的时候，继续进行对战过程
    {
        //默认1p首先攻击
        att1 = rand() % 11 + 5;//5-15之间的攻击力
        if(att1 == 15)//暴击
            att1 *= 2;//让攻击力变为原来的两倍
        att2 = rand() % 11 + 5;
        //玩家1攻击，玩家2掉血
        hp2 -= att1;
        //玩家2攻击，玩家1掉血
        hp1 -= att2;
        //建议两个人打完后，立即使用if判断，血量少于0的，就判定为输
        printf("*******************************************\n");
        printf("第%d轮： \n", i + 1);
        printf("玩家1攻击力：%d,玩家2剩余血量：%d\n", att1, hp2);
        printf("玩家2攻击力：%d,玩家1剩余血量：%d\n", att2, hp1);
        printf("*******************************************\n");
        i++;
        //Sleep(500);//休眠500毫秒
    }
    printf("KO!~游戏结束，玩家1的血量：%d\t玩家2的血量：%d\n", hp1, hp2);












    /*
    //某宝双十一2015年的交易额为800亿，每年递增25%
    //问：按此速度哪年交易额达到2000亿？
    //先声明变量
    int year = 2015;    //年份
    double money = 800; //交易额
    //要使用循环解决
    //循环三要素：
    while(money <= 2000)
    {
        year++;
        //money = money * 1.25;
        money *= 1.25;//循环变量的更新
    }
    printf("按此速度，%d年交易额达到2000亿。\n", year);
*/















    /*
    //使用循环实现三次密码输入错误退出系统
    int i = 0;      //循环变量
    int password;   //密码


    while(i < 3)
    {
        printf("请输入密码：");
        scanf("%d", &password);
        if(123456 != password)
        {
            printf("密码输入错误,当前输入第%d次密码。\n", i);
        }
        //第三次输入错误，就要强制退出系统
        if(i == 2)
        {
            printf("密码输错三次，系统强制退出！\n");
            exit(0);//告诉操作系统，程序正常退出
        }
        i++;

    }


*/










    /*
    int i = 0;
    while(i < 10)//while:if的加强版
    {
        printf("第%d遍\n", i);
        i++;//通过观察发现，可以通过控制i的值，来控制循环的次数
    }*/
    return 0;
}
