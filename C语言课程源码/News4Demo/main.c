#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USER_NAME "admin"
#define PASSWORD  "admin"

//封装fgets函数，去掉结尾的\n
//参数1：将接收到的字符串保存到传入的数组中
//参数2：最大接收的字符长度
char * MyFgets(char [], int);

/**
 * 验证传入的用户名和密码是否正确
 * 参数1：需要验证的用户名
 * 参数2：需要验证的密码
 * 返回： 如果用户名和密码合法，返回1，否则返回0
 */
int login(char [], char []);

int main()
{
    //演示字符串的连接
    char str1[100] = "你好，中国！";
    char str2[20]  = "你也好，美国";
    //字符串连接
    strcat(str1, str2);
    printf("str1:%s\tstr2:%s", str1, str2);


    /*
    char userName[50];
    char password[50];

    printf("请输入用户名：");
    MyFgets(userName, 50);
    printf("请输入密码：");
    MyFgets(password, 50);
    if(login(userName, password) == 1)
    {
        printf("恭喜，登录系统成功！\n");
    }
    else
    {
        printf("很遗憾，用户名或密码输入错误，请重新录入！\n");
    }
    */
    return 0;
}

int login(char userName[], char password[])
{
    int result = 0;

    if(strcmp(USER_NAME, userName) == 0 && strcmp(password, PASSWORD) == 0)
    {
        //验证合法
        result = 1;
    }
    return result;
}
char * MyFgets(char * str, int maxLen)
{
    fgets(str, maxLen, stdin);
    //去掉最后一位空格
    //找到最后一位：
    //初学者可能比较喜欢循环的方式
    int count = 0;
    while(str[count] != '\n')
    {
        if(str[count] == '\n')
            break;
        count++;
    }
    //循环完毕后，count就是最后一个\n的下标
    str[count] = '\0';//将最后一位修改为空字符
}








