#ifndef FPRINTFANDFSCANFDEMO_H_INCLUDED
#define FPRINTFANDFSCANFDEMO_H_INCLUDED
#include "stdio.h"
#include "stdlib.h"

void ReadFileByFScanf()
{
    //��ȡһ���ļ���д�뵽����һ���ļ���
    FILE * fileIn = fopen("xajh.txt", "r");
    FILE * fileOut = fopen("xajh111.txt", "w+");
    char str[50];

    while(fscanf(fileIn, "%50s", str) > 0)
    {
        fprintf(fileOut, "%s\n", str);
    }
    //printf("�������ļ����ݣ�%s\n", str);

    fclose(fileIn);
    fclose(fileOut);

}


#endif // FPRINTFANDFSCANFDEMO_H_INCLUDED
