#ifndef FSEEKANDFTELLDEMO_H_INCLUDED
#define FSEEKANDFTELLDEMO_H_INCLUDED
#include "stdio.h"
#include "stdlib.h"

void GetFileLength()
{
    char * filePath = "F:\\WorkFoder\\C����ֱ���μ�\\C���Խ���\\�����\\�Ͼ�ѧ��C&C++����1.pptx";
    FILE *file = fopen(filePath, "rb");
    fseek(file, 0L, SEEK_END);      //���ļ�ָ���ƶ����ļ���ĩβ
    long fileLength = ftell(file);  //���ص�ǰ���ļ�ָ��ƫ�������ֽڵ�λ��
    rewind(file);//�����ļ�ָ�� fseek(file, 0L, SEEK_SET);

    printf("�ļ���С��%.2lf\n", fileLength / 1024 / 1024.0);
    fclose(file);
}


#endif // FSEEKANDFTELLDEMO_H_INCLUDED
