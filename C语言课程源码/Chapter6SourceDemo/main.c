#include <stdio.h>
#include <stdlib.h>
#define N 5 //宏定义，并不是必须的
int main()
{
    int i, j;
    //使用二维数组表示学生的成绩表
    //四个学生的3门课成绩 - 4行 3列
    double scores[4][3] = {
        {98, 67, 89},
        {89, 67, 88},
        {99, 77, 55},
        {78, 99, 67}
    };
    printf("语文\t英语\t数学\n");
    //使用循环打印每个数组元素
    for(i = 0; i < 4; i++)//外层循环控制有几个学生
    {
        for(j = 0; j < 3; j++)
        {
            printf("%-8.2lf", scores[i][j]);
        }
        printf("\n");
    }

















    /*
    删除的逻辑
    12 34 23 67 9
    12 34 67 9 9
    1、查找要删除数字的下标 2
    2、从下标开始，后面一个覆盖前面一个数字
    3、数组的总长度-1
    */
    /*
    int count = 5;      //表示数组元素的个数
    double powers[] = {42322, 45771, 40907, 41234, 40767};
    int test;
    double deletePower; //用户要删除的战力值
    int deleteIndex = -1;//要删除战力值的下标,给一个不可能的初值，方便判断
    int i;              //循环变量
    double insertPower; //新插入的战力值
    printf("请输入要删除的战力值：");
    scanf("%lf", &deletePower);
    for(i = 0; i < count; i++)
    {
        if(deletePower == powers[i])
        {
            //记录下当前的下标
            deleteIndex = i;
            break;//找到了要删除的战力值，直接跳出循环，提升效率
        }
    }
    //根据判断（是否找到），执行后续的操作
    if(-1 == deleteIndex)
    {
        printf("很遗憾，没有找到要删除的战力值，删除失败！\n");
    }
    else
    {
        //从下标开始，后面一个覆盖前面一个数字
        for(i = deleteIndex; i < count - 1; i++)
        {
            powers[i] = powers[i + 1];
        }
        //删除完毕后，一定记得数组的总长度-1  障眼法要做到底
        count--;
    }
    printf("删除后的结果为：\n");
    for(i = 0; i < count; i++)
    {
        printf("%.2lf\t", powers[i]);
    }
    //删除之后进行插入
    printf("请输入新战力值：");
    scanf("%lf", &insertPower);
    powers[count] = insertPower;//注意进行理解
    //插入操作完毕后，记得数组总长度+1
    count++;
    printf("插入后的结果为：\n");
    test = 123456;
    for(i = 0; i < count; i++)
    {
        printf("%.2lf\t", powers[i]);
    }
    //如果想让战力值数组有序，直接使用冒泡排序即可

*/



    /*
    16  25  9  90 23
    降序排列 - 从大到小
    冒泡排序的基础原理：遍历和交换
    第一轮循环：
    某个数字小于后面的数字，那么就交换
    1    25 16 9 90 23
    2    25 16 9 90 23
    3    25 16 90 9 23
    4    25 16 90 23 9 最小的数字就冒到了最后
    1、需要比较多轮 (数组长度 - 1) 轮
    2、每一轮比较的次数比上一轮-1次
       (数组长度 - 1) - 当前的轮数
    */
    /*
    int i, j;   //循环变量
    int temp;   //用来交换的临时变量
    int nums[N] = {16,  25,  9,  90, 23};
    //外层循环控制 轮数
    for(i = 0; i < N - 1; i++)
    {
        //内层循环控制 每轮的比较次数
        for(j = 0; j < N - i - 1; j++)
        {
            //如果当前值小于后面一个值，就交换
            if(nums[j] < nums[j + 1])
            {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }

        }
    }
    printf("排序后的结果是：\n");
    for(i = 0; i < N; i++)
    {
        printf("%d\t", nums[i]);
    }
    for(i = 0; i < N - 1; i++)
    {
        //内层循环控制 每轮的比较次数
        for(j = 0; j < N - i - 1; j++)
        {
            //如果当前值小于后面一个值，就交换
            if(nums[j] > nums[j + 1])
            {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }

        }
    }
    printf("逆序后的结果是：\n");
    for(i = 0; i < N; i++)
    {
        printf("%d\t", nums[i]);
    }
*/

















    /*
    //战力数组
    double powers[N] = {45771, 34565, 12345, 89765, 45213};
    int i, j;            //循环变量
    double tempPower;    //用来交换的临时变量
    int deleteIndex = -1;//要删除元素的下标
    double deletePower;     //要删除的战力值
    int count = N;       //表示当前的元素总数
    //1.降序排列并打印
    for(i = 0; i < N - 1; i++)
    {
        for(j = 0; j < N - i - 1; j++)
        {
            if(powers[j] < powers[j + 1])
            {
                tempPower = powers[j];
                powers[j] = powers[j + 1];
                powers[j + 1] = tempPower;
            }
        }
    }
    printf("排序后：\n");
    for(i = 0; i < N; i++)
    {
        printf("%.2lf\t", powers[i]);
    }




    printf("请输入要删除的战力值：");
    scanf("%lf", &deletePower);
    //1、查找要删除数字下标
    for(i = 0; i < count; i++)
    {
        if(deletePower == powers[i])
        {
            //找到了要删除的元素，记录元素的下标
            deleteIndex = i;
            break;
        }
    }
    //2、从找到的下标开始，后面一个覆盖前面一个元素
    if(deleteIndex == -1)
    {
        printf("没有找到要删除的元素！\n");
    }
    else
    {
        //注意这里的总长度要-1
        for(i = deleteIndex; i < count - 1; i++)
        {
            powers[i] = powers[i + 1];
        }
    }
    //3、障眼法：数组总长度-1
    count--;
    printf("删除后：\n");
    for(i = 0; i < count; i++)
    {
        printf("%.2lf\t", powers[i]);
    }

*/




    /*
    int i, j;
    int temp;//用来交换的临时变量
    int nums[5] = {33, 44, 22, 11, 78};
    //外循环负责比较的轮数
    for(i = 0; i < 5 - 1; i++)
    {
        //内循环负责每次比较并交换
        for(j = 0; j < 5 - i - 1; j++)
        {
            //前面一个比后面一个大，就交换
            if(nums[j] < nums[j + 1])
            {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    printf("排序后的数组为：\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d\t", nums[i]);
    }
*/




    /*
    //定义一个整型数组，赋值后求出奇数个数和偶数个数
    int array[N];
    int i;
    int count1 = 0, count2 = 0;//分别表示奇数的个数和偶数的个数
    int searchNum;  //要查找的元素
    int searchIndex = -9999;//要查找元素的下标（要设定一个不可能的值）
    //使用循环录入
    for(i = 0; i < N; i++)
    {
        printf("请输入第%d个数字：", i + 1);
        scanf("%d", &array[i]);
    }
    //使用另外一个循环统计个数
    for(i = 0; i < N; i++)
    {
        if(array[i] % 2 == 0)//如果数组中的某个元素为偶数
        {
            count2++;
        }
        else
        {
            count1++;
        }
    }
    printf("奇数有%d个，偶数有%d个\n", count1, count2);

    printf("请输入要查找的元素：");
    scanf("%d", &searchNum);
    //通过for循环查找
    for(i = 0; i < N; i++)
    {
        if(searchNum == array[i])
        {
            searchIndex = i;//将找到的数组下标保存到searchIndex变量中
            break;//找到后，就没有必要再继续查找了，跳出循环
        }
    }
    if(searchIndex == -9999)//如果searchIndex变量的值是初值-1，证明没有找到元素
    {
        printf("没有找到%d这个元素！\n", searchNum);
    }
    else
    {
        printf("找到了，元素的下标为：%d\n", searchIndex);
    }
*/











    /*
    //int nums[] = {8, 0, 0, 99, 2, 1, 23, 344, 12};
    int nums[] = {8, [3]=99, 2, 1, 23, 344, 12};//C99之后支持
    int i;
    //求最大值
    int max = nums[0];//我们假设数组中的第一个元素最大
    int min = nums[0];
    //通过循环来比较，max就相当于擂台，谁大，就留在擂台上
    for(i = 0; i < N; i++)
    {
        if(max < nums[i])//相当于武将pk，我认为最大值，还没有擂台上的大
        {//最大的这个值就上擂台
            max = nums[i];
        }
        if(min > nums[i])
        {
            min = nums[i];
        }
    }
    printf("数组中的最大值是：%d\t最小值是：%d\n", max, min);
    */
    /*
    有一个数列：8，4，2，1，23，344，12
        循环输出数列的值
        求数列中所有数值的和及平均值
        猜数游戏：从键盘中任意输入一个数据，判断数列中是否包含此数
    */
    /*
    int i;          //循环变量
    int sum = 0;    //求和
    double avg;     //求平均
    int searchNum;  //要查找的数字
    //1.定义数组，并初始化
    int nums[N] = {8, 4, 2, 1, 23, 344, 12};
    //2.循环输出
    printf("输出数组元素：\n");
    for(i = 0; i < N; i++)
    {
        printf("%d\t", nums[i]);
    }
    printf("\n*****************************\n");
    //3.求和和求平均值
    for(i = 0; i < N; i++)
    {
        sum += nums[i];//经典累加
    }
    avg = sum / 7.0;
    //4.查找数字
    printf("请输入要查找的数字：");
    scanf("%d", &searchNum);
    for(i = 0; i < N; i++)
    {
        //一个一个元素进行对比
        //如果我要查找的数字跟数组中的某个元素相同
        if(searchNum == nums[i])
        {
            //找到了
            printf("猿粪啊，找到了相同的元素！\n");
            //找到后，记得跳出循环
            break;
        }
    }
    //结束循环后，我们如何判断是否找到了呢？？？？
    //通过观察，循环正常退出时，i的值应该为7
    if(i == 7){
        printf("茫茫人海，没有找到合意的数字！\n");
    }
*/









    /*
    //动态录入
    double score[N];
    int i;  //循环变量
    //使用循环操作数组时，要注意：一个循环尽量只做一件事
    for(i = 0; i < N; i++)
    {
        printf("请输入第%d位同学的成绩：", i + 1);
        scanf("%lf", &score[i]);
    }
    //下面的循环用来打印数组元素
    for(i = 0; i < N; i++)
    {
        printf("第%d位同学的成绩是：%.2lf\n", i + 1, score[i]);
    }

*/
    return 0;
}
