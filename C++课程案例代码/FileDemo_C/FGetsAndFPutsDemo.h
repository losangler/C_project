#ifndef FGETSANDFPUTSDEMO_H_INCLUDED
#define FGETSANDFPUTSDEMO_H_INCLUDED

void ReadFileByFGets()
{
    FILE * file = fopen("xajh.txt", "r+");
    //ʡ���ж�
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
    char * str = "�������ˣ������ܣ�";
    int result = fputs(str, file);
    if(result != -1)
    {
        printf("д��ɹ���\n");
    }else{
        printf("д��ʧ�ܣ�\n");
    }
    fclose(file);
}


#endif // FGETSANDFPUTSDEMO_H_INCLUDED
