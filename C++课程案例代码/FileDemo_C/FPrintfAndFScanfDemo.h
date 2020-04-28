#ifndef FPRINTFANDFSCANFDEMO_H_INCLUDED
#define FPRINTFANDFSCANFDEMO_H_INCLUDED
#include "stdio.h"
#include "stdlib.h"

void ReadFileByFScanf()
{
    //读取一个文件，写入到另外一个文件中
    FILE * fileIn = fopen("xajh.txt", "r");
    FILE * fileOut = fopen("xajh111.txt", "w+");
    char str[50];

    while(fscanf(fileIn, "%50s", str) > 0)
    {
        fprintf(fileOut, "%s\n", str);
    }
    //printf("读出的文件内容：%s\n", str);

    fclose(fileIn);
    fclose(fileOut);

}


#endif // FPRINTFANDFSCANFDEMO_H_INCLUDED
