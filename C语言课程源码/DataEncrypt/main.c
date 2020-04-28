#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//实现字符串的加密与解密
//加密方式：将字符串中每个字符加上它在字符串中的位置和一个偏移量5
//例如：xuetang9中，第一个字符x在字符串中的位置为0，那么对应的密文是'm'+0+5

#define KEY 5   //偏移量 / 秘钥

/**
 * 加密传入的字符串
 * 参数1：要加密的字符串
 * 返回值：返回加密后的字符串
 */
//char * encrypt(char []);
//char * dencrypt(char[]);
//将传入的字符指针数组排序，count为字符串的个数
//要注意，不能对常量数组排序！！
void my_sort(char * str[], int count)
{
    //直接交换指针，而不是复制字符串
    int i, j;
    char *tempCh;//临时指针变量
    for(i = 0; i < count - 1; i++)
    {
        for(j = 0; j < count - i - 1; j++)
        {
            if(strcmp(str[j], str[j + 1]) > 0)
            {
                tempCh = str[j];
                str[j] = str[j + 1];
                str[j + 1] = tempCh;
            }
        }
    }
}
int main()
{

    int i;
    //二维数组：有5个字符串，每个字符串最大容纳20个字符
    char names1[5][20] = {
        "特朗普", "普京", "卡梅伦", "昂山素季", "朴槿惠"
    };
    //字符指针数组 - 想象成名片盒
    char *names2[5] = {
        "特朗普", "普京", "卡梅伦", "昂山素季", "朴槿惠"
    };
    for(i = 0; i < 5; i++)
    {
        printf("names1[i]=%s\tnames2[i]=%s\n", names1[i], names2[i]);
    }
    printf("names1所占空间大小：%d\n", sizeof(names1));
    //一个指针类型占4个字节，5个指针。。。
    printf("names2所占空间大小：%d\n", sizeof(names2));

    //排序
    my_sort(names2, 5);

    for(i = 0; i < 5; i++)
    {
        printf("%s\n", names2[i]);
    }

















    /*
    //理解字符串和字符指针的区别
    char str1[] = "For The Horde";
    char *str2  = "For The Horde";

    printf("字符串常量的地址：%p\n", "For The Horde");
    printf("字符数组的首地址：%p\n", str1);
    printf("字符指针的取值：%p\n", str2);

    printf("str1的size：%d\n", sizeof(str1));
    printf("str2的size：%d\n", sizeof(str2));
    printf("请输入字符串：");
    //动态分配内存
    str2 = (char *)malloc(20);
    scanf("%s", str2);

    printf("%s\n", str2);
    // str1++; 不能执行！
*/














    /*
    char password[50] = "abcdefg";
    encrypt(password);
    printf("加密后的字符串为：%s\n", password);
    dencrypt(password);
    printf("解密后的字符串为：%s\n", password);
    */
    return 0;
}
char * encrypt(char password[])
{
    int i = 0;
    int count = strlen(password);//字符串的长度
    for(; i < count; i++)
    {
        //将字符串中每个字符加上它在字符串中的位置和一个偏移量5
        password[i] = password[i] + i + KEY;
    }
    return password;
    //字符串最后的\0是否需要替换？-不需要
}
char * dencrypt(char password[])
{
    int i = 0;
    int count = strlen(password);//字符串的长度
    for(; i < count; i++)
    {
        //将字符串中每个字符加上它在字符串中的位置和一个偏移量5
        password[i] = password[i] - i - KEY;
    }
    return password;
    //字符串最后的\0是否需要替换？-不需要
}







