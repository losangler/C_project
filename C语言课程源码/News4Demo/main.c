#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USER_NAME "admin"
#define PASSWORD  "admin"

//��װfgets������ȥ����β��\n
//����1�������յ����ַ������浽�����������
//����2�������յ��ַ�����
char * MyFgets(char [], int);

/**
 * ��֤������û����������Ƿ���ȷ
 * ����1����Ҫ��֤���û���
 * ����2����Ҫ��֤������
 * ���أ� ����û���������Ϸ�������1�����򷵻�0
 */
int login(char [], char []);

int main()
{
    //��ʾ�ַ���������
    char str1[100] = "��ã��й���";
    char str2[20]  = "��Ҳ�ã�����";
    //�ַ�������
    strcat(str1, str2);
    printf("str1:%s\tstr2:%s", str1, str2);


    /*
    char userName[50];
    char password[50];

    printf("�������û�����");
    MyFgets(userName, 50);
    printf("���������룺");
    MyFgets(password, 50);
    if(login(userName, password) == 1)
    {
        printf("��ϲ����¼ϵͳ�ɹ���\n");
    }
    else
    {
        printf("���ź����û����������������������¼�룡\n");
    }
    */
    return 0;
}

int login(char userName[], char password[])
{
    int result = 0;

    if(strcmp(USER_NAME, userName) == 0 && strcmp(password, PASSWORD) == 0)
    {
        //��֤�Ϸ�
        result = 1;
    }
    return result;
}
char * MyFgets(char * str, int maxLen)
{
    fgets(str, maxLen, stdin);
    //ȥ�����һλ�ո�
    //�ҵ����һλ��
    //��ѧ�߿��ܱȽ�ϲ��ѭ���ķ�ʽ
    int count = 0;
    while(str[count] != '\n')
    {
        if(str[count] == '\n')
            break;
        count++;
    }
    //ѭ����Ϻ�count�������һ��\n���±�
    str[count] = '\0';//�����һλ�޸�Ϊ���ַ�
}








