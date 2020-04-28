#ifndef STRTOK_H_INCLUDED
#define STRTOK_H_INCLUDED

//char *strtok(char *s, char *delim) �ֽ��ַ���Ϊһ���ַ�����
//sΪҪ�ֽ���ַ���delimΪ�ָ����ַ�����������ַ�����������ַ�����ÿ���ַ���Ϊ�ָ������
//�״ε���ʱ��sָ��Ҫ�ֽ���ַ�����֮���ٴε���Ҫ��s���NULL��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * �ڲ��ı�Դ�ַ���������£�ȡ��ָ���ָ����ĵ�index�����ַ������ŵ�Ŀ�����(des)�з���
 */
char * strSplit(char *, char *, char *, int);

void strtokTest()
{
    char str[15] = "abc,def|ghi";
    char des[11];
    //��������һ���ڴ�������ĳ��������ֵ�����ǶԽϴ�Ľṹ�������������������һ����췽��
    //�������ʼ����ʹ��strlen(des)����ִ���ĳ���
    memset(des, 0, sizeof(des));



}

char * strSplit(char * str, char * des, char * sep, int index)
{
    char * token = NULL;    //�ָ���
    char temp[32];          //����������ʱ�������ַ�����
    strcpy(temp, str);      //����ʵ�ַ�����ֵ����ʱ�������Ա����
    //�����ָ��32���ֽڣ��Լ������ڴ棬��Ҫ�õ�����Ĳ��裺
    //+1��ԭ�����ַ����Ľ�β����һ��\0
//    char * ptrTemp = (char *)malloc(strlen(str) + 1);
//    memccpy(ptrTemp, str, strlen(str) + 1); //������\0Ҳ��������
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
