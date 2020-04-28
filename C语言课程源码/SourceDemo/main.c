#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    1、system("pause");	冻结屏幕，便于观察程序的执行结果
2、system("cls");	清屏操作
3、system("color 4E");	修改背景色及前景色
4、system("shutdown /r /t 180");

    return 0;
}

    /*
    int num[] = {[1]=98, 12, 45, 66};
    int i, temp;
    //数组逆序
    int * ptr_num_start = num;
    int * ptr_num_end = num + 4;
    while(ptr_num_start != ptr_num_end)
    {
        temp = *ptr_num_start;
        *ptr_num_start = *ptr_num_end;
        *ptr_num_end = temp;
        ptr_num_start++;
        ptr_num_end--;
    }
    printf("数组逆序后：\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d\n", num[i]);
    }

    */
    /*
    int num1 = 1024;
    int num2 = 2048;
    int * ptr1, * ptr2;
    ptr1 = &num1;
    ptr2 = &num2;
    printf("num1的值是%d\tnum1的地址是：%p\n", num1, ptr1);
    printf("num2的值是%d\tnum2的地址是：%p\n", num2, ptr2);
    //ptr2 = ptr1;
    *ptr2 = *ptr1;
    printf("重新赋值后：\n");
    printf("num2的值是%d\tnum2的地址是：%p\n", num2, ptr2);
    */

    /*
    int num = 1024; //整型变量
    int *ptr_num;   //整型指针变量
    ptr_num = &num; //取num的地址赋值给ptr_num变量
    printf("num的值为：%d\n", num);
    printf("num的内存地址为：%p\n", &num);
    printf("ptr_num的值为：%p\n", ptr_num);
    printf("ptr_num的内存地址为：%p\n", &ptr_num);
    printf("*ptr_num指向的值为：%d\n", *ptr_num);
    */
    /*
    return 0;
}*/
