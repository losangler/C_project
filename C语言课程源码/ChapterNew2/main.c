#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//函数原型
void calcCircle();      //计算圆面积
void calcRectangle();   //计算矩形面积
int calcSum();         //求1-100之间的偶数和
/**
 * 计算圆的面积（函数实现)
 */
void calcCircle()
{
    double radius, s;//半径和面积
    printf("请输入圆半径：");
    scanf("%lf", &radius);
    //圆面积=3.14乘以半径的平方
    s = 3.14 * pow(radius, 2);
    printf("半径为%.2lf的圆面积为：%.2lf\n", radius, s);
}
void calcRectangle(void)
{
    double width, height;   //矩形的宽和高
    double s;               //矩形的面积
    printf("请输入矩形的宽和高：");
    scanf("%lf%lf", &width, &height);
    if(width <= 0 || height <= 0)
    {
        printf("宽和高不能为负数，你耍老娘呢！！\n");
        return;
    }
    s = width * height;
    printf("矩形的面积为：%.2lf", s);

}
int calcSum()
{
    //1-100之间的偶数和
    int sum = 0;
    int i = 1;
    for(i = 1; i <= 100; i++)
    {
        if(i % 2 == 0)
            sum++;
    }
    //将计算好的结果返回
    return sum;
}

int main()
{
    //书写函数的步骤：完成函数三要素-返回值类型、函数名称、参数列表
    //误区：不要一开始就去考虑如何完成某个功能


















    /*
    //演示动态分配内存：
    int i;
    int * nums;
    //为前面的指针动态分配了20个字节(5个整型)的空间
    //nums = (int *)malloc(sizeof(int) * 5);
    nums = calloc(5, sizeof(int));
    //double * dNums = (double *)malloc(sizeof(double) * 5);
    //等价于：int nums[999999]
    //为指针动态分配空间后，指针就变成了数组

    nums[3] = 1121;
    nums++;//指针被移动了

    printf("数组元素为：\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d\t", *(nums + i));
    }
    free(nums); //释放动态分配的内存
    nums  = NULL;   //良好的编程习惯










/*
    //1.设置随机种子 - 一般跟时间联用，因为时间每时每刻是不同的
    srand(time(NULL));
    //2.取随机数
    int num = rand();
    printf("%d\n", num);

    exit(0);//0-正常退出应用程序 非零就是不正常退出











    /*&
    //ceil - 进一法    floor - 去尾法
    //如果是负数，规律相反

    printf("%.2lf\n", ceil(98.01));
    printf("%.2lf\n", floor(98.9));

    printf("%.2lf\n", sqrt(9));//求平方根

    printf("%.2lf\n", pow(5, 4));//求第一个数字的第二个数字次幂

    printf("%d\n", abs(-98));    //求绝对值

*/











    /*
    printf("%d\n", isupper('a'));
    printf("%d\n", islower('a'));
    printf("%d\n", isalpha(97));   //返回字符是否为字母
    //如果传入的是数字，表示的是ascii码
    printf("%d\n", isdigit(50));     //返回字符是否为数字
    //转换大小写
    printf("大写：%c", toupper('9'));

    //思考题：如何将用户输入的小写数字转成中文大写？
    //1234   -     壹仟贰佰叁拾肆元整
    int money, count = 0;//count是数字的位数
    int i = 0;
    int moneys[6];//默认支持6位数字
    char unit[10][4] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
    printf("请输入金额：");
    scanf("%d", &money);
    //判断用户输了几位数字？将每一位数字取出来
    while(money != 0)
    {
        moneys[i] = money % 10;
        money /= 10; //去掉最后一位
        i++;
        count++;
    }
    printf("用户输入的数字一共有%d位！\n", count);
    printf("数组中的内容： \n");
    for(i = 0; i < count; i++)
    {
        printf("%d - %s\n", moneys[i], unit[moneys[i]]);
    }

/*
    int i;
    //打印所有的ascii码对应的字符
    for(i = 0; i < 127; i++)
    {
        printf("%c,", i);
    }
*/
    return 0;
}
