#ifndef FGETSANDFPUTSDEMO_H_INCLUDED
#define FGETSANDFPUTSDEMO_H_INCLUDED

void ReadFileByFGets()
{
    FILE * file = fopen("xajh.txt", "r+");
    //省略判断
    char * str;
    str = (char*)malloc(50);
    //char str[50];

    //fgets(str, 5, file);
    while(fgets(str, sizeof(str), file) != NULL)
    {
        printf("%s\n", str);
    }
    free(str);

    fclose(file);
}

void WriteFileByFPuts()
{
    FILE * file = fopen("xajh.txt", "a+");
    char * str = "大清亡了？不可能！";
    int result = fputs(str, file);
    if(result != -1)
    {
        printf("写入成功！\n");
    }else{
        printf("写入失败！\n");
    }
    fclose(file);
}


#endif // FGETSANDFPUTSDEMO_H_INCLUDED
