#include <stdio.h>
#include <stdlib.h>
/**
 * 第三章练习讲解
 */
int main()
{
    //scanf的用法小结
    int num1, num2, num3;
    printf("请输入三个数字：");
    //默认的分隔符是空格
    scanf("%d%d%d", &num1, &num2, &num3);
    //scanf("%d", &num1);
    //scanf("%d", &num2);
    //scanf("%d", &num3);
    printf("输入的三个数字分别为：%d\t%d\t%d\n", num1, num2, num3);
    return 0;
    /*
    1、要求用户输入1-7之间的数字
2、判断是周末还是普通工作日
   6、7           其他情况

int dayNum;//星期几
printf("请输入1-7之间的数字：");
scanf("%d", &dayNum);
//判断是周末还是普通工作日
if(dayNum == 6 || dayNum == 7)
{
	printf("是周末！\n");
}else if(dayNum == 1 || dayNum == 2.....)
{
	printf("是工作日！\n");
}else
{
	printf("用户输入的是非法数字！\n");
}


char op;//运算符
int num1, num2;
printf("请输入第一个操作数：");
scanf("%d", &num1);
printf("请输入运算符：");
scanf("%c", &op);
fflush(stdin);//清空缓冲区
printf("请输入第三个操作数：");
scanf("%d", &num2);
//使用switch结构
switch(op)
{
	case '+':
		printf("%d", num1 + num2);
		break;
	case '-':
		printf("%d", num1 - num2);
		break;
}
    */
}
