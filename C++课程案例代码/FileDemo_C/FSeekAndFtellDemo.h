#ifndef FSEEKANDFTELLDEMO_H_INCLUDED
#define FSEEKANDFTELLDEMO_H_INCLUDED
#include "stdio.h"
#include "stdlib.h"

void GetFileLength()
{
    char * filePath = "F:\\WorkFoder\\C语言直播课件\\C语言进阶\\补充课\\老九学堂C&C++串讲1.pptx";
    FILE *file = fopen(filePath, "rb");
    fseek(file, 0L, SEEK_END);      //把文件指针移动到文件的末尾
    long fileLength = ftell(file);  //返回当前的文件指针偏移量（字节单位）
    rewind(file);//重置文件指针 fseek(file, 0L, SEEK_SET);

    printf("文件大小：%.2lf\n", fileLength / 1024 / 1024.0);
    fclose(file);
}


#endif // FSEEKANDFTELLDEMO_H_INCLUDED
