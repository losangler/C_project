#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileOp.h"
#include "strtok.h"

typedef struct{
    char **splitStr;
    int count;
}SplitArray;



SplitArray* split1(char *str, char * sep)
{
    SplitArray *splitArray;
    splitArray = (SplitArray*)malloc(sizeof(SplitArray));
    splitArray->count = 0;
    splitArray->splitStr = NULL;
    int count = 0;
    char tempStr[50];
    strcpy(tempStr, str);
    char * temp = strtok(tempStr, sep);
    if(temp)
    {
        count++;
        while(temp = strtok(NULL, sep))
        {
            //printf("temp:%s\n", temp);
            count++;
        }
    }
    printf("%d个元素！", count);
    strcpy(tempStr, str);
    splitArray->splitStr = (char **)malloc(count * sizeof(char *));
    int i = 0;
    for(; i < count; i++)
    {
        splitArray->splitStr[i] = (char *)malloc(50 * sizeof(char));
        if(i == 0){
            //splitArray->splitStr[i] = strtok(tempStr, sep);
            strcpy(splitArray->splitStr[i], strtok(tempStr, sep));
        }else
            //splitArray->splitStr[i] = strtok(NULL, sep);
            strcpy(splitArray->splitStr[i], strtok(NULL, sep));
        splitArray->count++;
    }


    return splitArray;
}

SplitArray split(char *str, char * sep)
{
    SplitArray splitArray;
    //splitArray = (SplitArray*)malloc(sizeof(SplitArray));
    splitArray.count = 0;
    splitArray.splitStr = NULL;
    int count = 0;
    char tempStr[50];
    strcpy(tempStr, str);
    char * temp = strtok(tempStr, sep);
    if(temp)
    {
        count++;
        while(temp = strtok(NULL, sep))
        {
            //printf("temp:%s\n", temp);
            count++;
        }
    }
    printf("%d个元素！\n", count);
    strcpy(tempStr, str);
    splitArray.splitStr = (char **)malloc(count * sizeof(char *));
    int i = 0;
    for(; i < count; i++)
    {
        splitArray.splitStr[i] = (char *)malloc(50 * sizeof(char));
        if(i == 0){
            //splitArray->splitStr[i] = strtok(tempStr, sep);
            strcpy(splitArray.splitStr[i], strtok(tempStr, sep));
        }else
            //splitArray->splitStr[i] = strtok(NULL, sep);
            strcpy(splitArray.splitStr[i], strtok(NULL, sep));
        splitArray.count++;
    }


    return splitArray;
}

int main()
{
    char str[50] = "abc,def|ghi,abc,cbr,aaa";
    char * result;
    //split(str, ",|");
    SplitArray splitArray = split(str, ",|");
    int i = 0;

    for(; i < splitArray.count; i++)
    {
        printf("%s\n", splitArray.splitStr[i]);
    }
//    result = strtok(str, ",|");
//
//
//    result = strtok(str, ",|");
//    printf("%s\n", result);
//    result = strtok(NULL, ",|");
//    printf("%s\n", result);
//    result = strtok(NULL, ",|");
//    printf("%s\n", result);
//    result = strtok(NULL, ",|");
//    if(result == NULL)
//        printf("%s", "null");


    strtokTest();

//    FILE * file = fopen("test.ini", "r");
//    char line[1024];    //文件中单行的内容
//    while(fgets(line, 1024, file))
//    {
//        if(strchr(line, ';') || strchr(line, '#'))
//        {
//            continue;//如果以;号或#号开头，就跳过
//        }
//        //printf("%s\n", line);
//        char * result = strtok(line, "=");
//        printf("%s", result);
//    }
//
//    fclose(file);
    return 0;
}
