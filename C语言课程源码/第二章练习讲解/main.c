#include <stdio.h>
#include <stdlib.h>

int main()
{
    //杀鸡刀switch结构的用法
    //一般处理数轴中某几个点的情况
    //想知道某个月有多少天
    //逻辑：用户输入月份，根据月份判断当月的天数
    int month;  //用户输入的月份
    printf("请输入月份，我来判断天数：");
    scanf("%d", &month);
    switch(month)
    {
    default:
        printf("当前程序暂时只能判断1-4月的情况！\n");
        break;
    case 1:
        printf("1月有31天！\n");
        printf("1月过完就是年！\n");
        break;
    case 2:
        //最好能够再判断下是否是闰年
        printf("2月有28天！\n");
        printf("本月有传说中的年假！\n");
        break;
    case 3:
        printf("3月有31天！\n");
        printf("烟花三月下扬州！\n");
        break;
    case 4:
        printf("4月有30天！\n");
        break;

    }

















    /*
    double flowerPrice; //鲜花的价格
    //打印剧情
    printf("在一个月黑风高的夜晚\n");
    printf("一个小男生用自己的零花钱给小女生买了一束鲜花\n");
    printf("小女生问小男生鲜花的价格，“这花多少钱?”\n");
    printf("小男生答：");
    //需要录入鲜花的价格
    scanf("%lf", &flowerPrice);
    //下面就是模拟小女生的反应
    if(flowerPrice > 999999)
    {
        printf("小女生直接晕了过去！\n");
    }
    else if(flowerPrice >= 100000 && flowerPrice <= 999999)//10万到999999之间
    {
        printf("明天就结婚！\n");
    }
    else if(flowerPrice >= 10000 && flowerPrice < 100000)
    {
        printf("拉拉手意思意思，明天再约！");
    }
    else
    {
        printf("好吧，我们是普通朋友，你是个好人!\n");
    }
*/













    /*
    //如果总价大于5000就打7折，否则9折
    double price1 = 229.0;
    double price2 = 10240.55;
    double price3 = 2345.3;
    double total = price1 + price2 + price3;
    double zhekou;  //折扣
    //商家更改享受折扣的规则：
    //如果购买的三种商品有一种商品单价大于1000
    //或三种商品总金额大于5000，折扣率为30%，
    //否则没有折扣
    if(price1 > 1000 || price2 > 1000 || price3 > 1000 || total > 5000)
    {
        zhekou = 0.3;
    }
    /*
    if(total > 5000)
    {
        //total *= 0.7;//total = total * 0.7;
        zhekou = 0.7;
    }
    else
    {
        //total *= 0.9;
        zhekou = 0.9;
    }*/
    /*
    total = zhekou * total;//total *= zhekou;
    printf("败家娘们应支付的金额为：%.2lf\n", total);
    */
































    /*
    //判断月份的天数
    int month;
    printf("请输入月份：");
    scanf("%d", &month);
    //if(month == 1 || month == 3 || month == 5)
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    //....
    printf("31天");
    break;
    case 4:
    case 6:
    //.....
    printf("30天");
    break;

    }
    /*
    int choice = 3;//选择
    printf("1、送花\n");
    printf("2、送辆奔驰\n");
    printf("3、送驾F16\n");
    printf("请选择：");
    scanf("%d", &choice);
    switch(choice)
    {
    default:
        printf("骚年，不要捣蛋，认真听讲！\n");
        break;
    case 1:
        printf("成功赠送了一束鲜花！\n");
        break;
    case 2:
        printf("成功赠送了一辆奔驰幻影9000\n");
        break;
    case 3:
        printf("成功赠送了一架F16战机！\n");
        break;

    }
*/












    /*
    char ch1, ch2;
    printf("字符1：");
    ch1 = getchar();
    fflush(stdin);//清空缓冲区-清流
    printf("字符2：");
    ch2 = getchar();

    putchar(ch1);
    putchar(',');
    putchar(ch2);
*/
   /* //使用程序判断用户输入的字符是否是合法的硬盘盘符A-Z
    char hardChar;  //硬盘盘符
    printf("请输入盘符字母：");
    //scanf("%c", &hardChar);
    hardChar = getchar();   //读取用户输入单个字符
    //判断用户输入的字符是否在A-Z之间
    //if('A' <= hardChar <= 'Z')
    if(hardChar >= 'A' && hardChar <= 'Z')
    {
        printf("是正确的盘符！\n");
    }
    else
    {
        printf("不是正确的盘符！");
    }*/








    /*
   //算术运算符 + - * / %
   //关系运算符 > < >= <= == !=
   //逻辑运算符 && || !
   //赋值运算符 = += -= /= *= %=
   int num = 10; //  9<20
   int result = --num < 20 && num++ > 11;//短路运算
   //问题：result=？  num=？
   printf("result=%d\tnum=%d\n", result, num);
*/







    /*
    //演示getchar、putchar的用法
    char ch1, ch2;    //字符型变量
    printf("请输入一个字符：");
    //scanf("%c", &ch); 输入单个字符的等价写法
    ch1 = getchar();// a
    //清空缓冲区  <- 作业中补充的内容，大家可以删除fflush这句观察不同的结果
    fflush(stdin);
    printf("请输入第二个字符：");
    ch2 = getchar();// 回车键\n
    //printf("您输入的字符是：%c, %c\n", ch1, ch2);
    printf("您输入的字符是：");
    putchar(ch1);   //putchar一次只能打印一个字符
    putchar(',');
    putchar(ch2);
    */
    return 0;

}
