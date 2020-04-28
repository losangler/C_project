#ifndef FGETCANDFPUTCDEMO_H_INCLUDED
#define FGETCANDFPUTCDEMO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ReadFileByFGetc()
{
    //1.���ļ�
    FILE * file = fopen("xajh.txt", "r");
    char ch;//��ʱ����
    //2.ʹ�ù̶��Ĵ���ṹ��ȡ�ļ���ѭ����
    while((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }
    //3.��ӡ��ȡ�Ľ��
    //4.�ر��ļ�
    fclose(file);
}

void WriteFileByFPutc()
{
    FILE * file1 = fopen("xajh12.txt", "r");
    //if(file1 == NULL)
    if(!file1)
    {
        //��ʧ��
        //printf("�ļ���ʧ�ܣ������ļ�·����");
        fputs("�ļ���ʧ�ܣ������ļ�·����", stderr);
        exit(EXIT_FAILURE);
    }

    FILE * file = fopen("xajh.txt", "a+");
    char * str = "��ã��Ͼž���������������ӣ�balbalbal....";
    int i;
    for(i = 0; i < strlen(str); i++)
    {
        fputc(str[i], file);
    }
    fclose(file);
}


#endif // FGETCANDFPUTCDEMO_H_INCLUDED
