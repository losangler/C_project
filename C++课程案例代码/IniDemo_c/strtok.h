#ifndef STRTOK_H_INCLUDED
#define STRTOK_H_INCLUDED

//char *strtok(char *s, char *delim) 分解字符串为一组字符串。
//s为要分解的字符，delim为分隔符字符（如果传入字符串，则传入的字符串中每个字符均为分割符）。
//首次调用时，s指向要分解的字符串，之后再次调用要把s设成NULL。
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * 在不改变源字符串的情况下，取出指定分隔符的第index个子字符串，放到目标变量(des)中返回
 */
char * strSplit(char *, char *, char *, int);

void strtokTest()
{
    char str[15] = "abc,def|ghi";
    char des[11];
    //作用是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法
    //如果不初始化，使用strlen(des)会出现错误的长度
    memset(des, 0, sizeof(des));



}

char * strSplit(char * str, char * des, char * sep, int index)
{
    char * token = NULL;    //分隔符
    char temp[32];          //用来进行临时操作的字符数组
    strcpy(temp, str);      //将真实字符串赋值到临时数组中以便操作
    //如果不指定32个字节，自己申请内存，需要用到下面的步骤：
    //+1的原因是字符串的结尾还有一个\0
//    char * ptrTemp = (char *)malloc(strlen(str) + 1);
//    memccpy(ptrTemp, str, strlen(str) + 1); //把最后的\0也拷贝过来
//    free(ptrTemp);
    token = strtok(temp, sep);
    while(token != NULL)
    {
        if(index-- <= 0) break;
        token = strtok(NULL, sep);
    }
    if(index <= 0 && token != NULL)
    {
        strcpy(des, token);
    }else
    {
        strcpy(des, "");
    }
    return des;

}

#endif // STRTOK_H_INCLUDED
