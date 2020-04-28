#include <stdio.h>
#include <stdlib.h>

#define N 5
int main()
{













/*
    int array[N] = {15, 20, 25, 30, 35};
    //实现数组的逆序 - 原理就是数组的首尾元素进行交换
    int temp;   //临时变量
    int i;
    int * ptr_array_start = array;      //指向数组首元素的指针
    int * ptr_array_end = array + 4;    //指向数组末元素的指针
    //array[4] N-1可以代表最大元素的下标 array[N-1]
    while(ptr_array_start != ptr_array_end)
    {
        //首尾交换，指针分别进行更新
        temp = *ptr_array_start;
        *ptr_array_start = *ptr_array_end;
        *ptr_array_end = temp;
        //首元素指针要向后移动
        ptr_array_start++;
        //末元素指针要向前移动
        ptr_array_end--;
    }
    /*
    for(i = 0; i < N / 2; i++)
    {
        //第i个值和第N-i-1个值相交换
        temp = array[i];
        array[i] = array[N - i - 1];
        array[N - i - 1] = temp;
    }*/
    /*
    printf("\n");
    for(i = 0; i < N; i++)
    {
        printf("%d\t", *(array + i));
    }*/

















    /*
    int i;
    int * ptr_array = array;
    //赋值完毕后，就可以使用指针访问数组元素了
    for(i = 0; i < 5; i++)
    {
        //printf("第%d个元素的值为%d\t地址为：%p\n", i + 1, ptr_array[i], &ptr_array[i]);
        //printf("第%d个元素的值为%d\t地址为：%p\n", i + 1,
        //                *(ptr_array + i), ptr_array + i);
        printf("第%d个元素的值为%d\t地址为：%p\n", i + 1, *ptr_array, ptr_array);
        //每次循环都会移动指针的指向，要注意重置
        ptr_array++;
    }
*/















    /*
    //数组名就是数组的首地址
    int i;  //循环变量
    double score[] = {98, 87, 65, 43, 76};
    double * ptr_score = score;
    //使用指针访问数组元素
    printf("数组的首地址：%p\t数组首元素的地址：%p\n", score, &score[0]);
    for(i  = 0; i < 5; i++)
    {
        //printf("%.2lf\n", ptr_score[i]);
        //printf("%.2lf\n", *(ptr_score + i));
        printf("%.2lf\n", *ptr_score++);
    }
    //假设我们希望再次打印数组的每个元素
    printf("***************");
    //重新访问数组元素前，记得重置指针的位置
    ptr_score = score;
    for(i  = 0; i < 5; i++)
    {
        //printf("%.2lf\n", ptr_score[i]);
        //printf("%.2lf\n", *(ptr_score + i));
        printf("%.2lf\n", *ptr_score++);
    }














    /*
    int num = 9;
    //*出现定义语句中，表示指针类型
    int *ptr_num = NULL;
    ptr_num = &num;
    int *ptr_num2 = ptr_num;
    //头疼点：指针的地址
    int * *ptr_num3 = &ptr_num2;

    printf("num的值为：%d\tnum的地址为：%p\n", **ptr_num3, ptr_num);
    //*出现在普通语句中，表示间接运算符（取地址的值）
    *ptr_num2 = 9999;   //顺藤摸瓜

    printf("num的值为：%d\tnum的地址为：%p\n", **ptr_num3, ptr_num2);

    //良好的编程习惯
    ptr_num = NULL;
    ptr_num2 = NULL;
    ptr_num3 = NULL;

















/*
    int num1 = 1024;
    int num2 = 2048;
    int * ptr1;
    int * ptr2;
    ptr1 = &num1;
    ptr2 = &num2;
    printf("num1的值是%d\tnum1的地址是：%p\n", num1, ptr1);
    printf("num2的值是%d\tnum2的地址是：%p\n", num2, ptr2);
    //将变量1的值，赋给变量2
    //num2 = num1;// 等价写法 *ptr2 = *ptr1;
    //直接操作指针
    ptr2 = ptr1;

    printf("重新赋值后：\n");
    printf("num1的值是%d\tnum1的地址是：%p\n", num1, ptr1);
    printf("num2的值是%d\tnum2的地址是：%p\n", num2, ptr2);

    *ptr2 = 111111;
    printf("重新赋值后：\n");
    printf("num1的值是%d\tnum1的地址是：%p\n", num1, ptr1);
    printf("num2的值是%d\tnum2的地址是：%p\n", num2, ptr2);

    ptr1 = NULL;
*/









/*

    int num = 9;
    int * ptr_num = &num;
    //头疼点：指针的地址
    int * *ptr_num2 = &ptr_num;
    //**ptr_num2 = 55;
    printf("\n指针ptr_num的地址：%p, %d\n", *ptr_num2, **ptr_num2);

    //使用指针修改变量值
/*
    *ptr_num = 9999;
    printf("*ptr_num对应的值为：%d\n", num);
*/
    return 0;
}
