#ifndef FGETCANDFPUTCDEMO_H_INCLUDED
#define FGETCANDFPUTCDEMO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ReadFileByFGetc()
{
    //1.打开文件
    FILE * file = fopen("xajh.txt", "r");
    char ch;//临时变量
    //2.使用固定的代码结构读取文件（循环）
    while((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }
    //3.打印读取的结果
    //4.关闭文件
    fclose(file);
}

void WriteFileByFPutc()
{
    FILE * file1 = fopen("xajh12.txt", "r");
    //if(file1 == NULL)
    if(!file1)
    {
        //打开失败
        //printf("文件打开失败，请检查文件路径！");
        fputs("文件打开失败，请检查文件路径！", stderr);
        exit(EXIT_FAILURE);
    }

    FILE * file = fopen("xajh.txt", "a+");
    char * str = "你好，老九君，我想给你生猴子！balbalbal....";
    int i;
    for(i = 0; i < strlen(str); i++)
    {
        fputc(str[i], file);
    }
    fclose(file);
}


#endif // FGETCANDFPUTCDEMO_H_INCLUDED
