#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ʵ���ַ����ļ��������
//���ܷ�ʽ�����ַ�����ÿ���ַ����������ַ����е�λ�ú�һ��ƫ����5
//���磺xuetang9�У���һ���ַ�x���ַ����е�λ��Ϊ0����ô��Ӧ��������'m'+0+5

#define KEY 5   //ƫ���� / ��Կ

/**
 * ���ܴ�����ַ���
 * ����1��Ҫ���ܵ��ַ���
 * ����ֵ�����ؼ��ܺ���ַ���
 */
//char * encrypt(char []);
//char * dencrypt(char[]);
//��������ַ�ָ����������countΪ�ַ����ĸ���
//Ҫע�⣬���ܶԳ����������򣡣�
void my_sort(char * str[], int count)
{
    //ֱ�ӽ���ָ�룬�����Ǹ����ַ���
    int i, j;
    char *tempCh;//��ʱָ�����
    for(i = 0; i < count - 1; i++)
    {
        for(j = 0; j < count - i - 1; j++)
        {
            if(strcmp(str[j], str[j + 1]) > 0)
            {
                tempCh = str[j];
                str[j] = str[j + 1];
                str[j + 1] = tempCh;
            }
        }
    }
}
int main()
{

    int i;
    //��ά���飺��5���ַ�����ÿ���ַ����������20���ַ�
    char names1[5][20] = {
        "������", "�վ�", "��÷��", "��ɽ�ؼ�", "���Ȼ�"
    };
    //�ַ�ָ������ - �������Ƭ��
    char *names2[5] = {
        "������", "�վ�", "��÷��", "��ɽ�ؼ�", "���Ȼ�"
    };
    for(i = 0; i < 5; i++)
    {
        printf("names1[i]=%s\tnames2[i]=%s\n", names1[i], names2[i]);
    }
    printf("names1��ռ�ռ��С��%d\n", sizeof(names1));
    //һ��ָ������ռ4���ֽڣ�5��ָ�롣����
    printf("names2��ռ�ռ��С��%d\n", sizeof(names2));

    //����
    my_sort(names2, 5);

    for(i = 0; i < 5; i++)
    {
        printf("%s\n", names2[i]);
    }

















    /*
    //����ַ������ַ�ָ�������
    char str1[] = "For The Horde";
    char *str2  = "For The Horde";

    printf("�ַ��������ĵ�ַ��%p\n", "For The Horde");
    printf("�ַ�������׵�ַ��%p\n", str1);
    printf("�ַ�ָ���ȡֵ��%p\n", str2);

    printf("str1��size��%d\n", sizeof(str1));
    printf("str2��size��%d\n", sizeof(str2));
    printf("�������ַ�����");
    //��̬�����ڴ�
    str2 = (char *)malloc(20);
    scanf("%s", str2);

    printf("%s\n", str2);
    // str1++; ����ִ�У�
*/














    /*
    char password[50] = "abcdefg";
    encrypt(password);
    printf("���ܺ���ַ���Ϊ��%s\n", password);
    dencrypt(password);
    printf("���ܺ���ַ���Ϊ��%s\n", password);
    */
    return 0;
}
char * encrypt(char password[])
{
    int i = 0;
    int count = strlen(password);//�ַ����ĳ���
    for(; i < count; i++)
    {
        //���ַ�����ÿ���ַ����������ַ����е�λ�ú�һ��ƫ����5
        password[i] = password[i] + i + KEY;
    }
    return password;
    //�ַ�������\0�Ƿ���Ҫ�滻��-����Ҫ
}
char * dencrypt(char password[])
{
    int i = 0;
    int count = strlen(password);//�ַ����ĳ���
    for(; i < count; i++)
    {
        //���ַ�����ÿ���ַ����������ַ����е�λ�ú�һ��ƫ����5
        password[i] = password[i] - i - KEY;
    }
    return password;
    //�ַ�������\0�Ƿ���Ҫ�滻��-����Ҫ
}







