#include <stdio.h>
#include <stdlib.h>

int main()
{

    //�ַ�����ʾ
    //char words[] = "�����й��ˣ�";
    //ָ���ﲢû�д���ַ�����
    //p_wordsָ��ָ���� ����- "��Ҳ���й��ˣ����ɣ�" ���ڴ�
    /*char * p_words;// = "��Ҳ���й��ˣ����ɣ�";
    scanf("%s", p_words);
    printf("%s\n", p_words);
    printf("%p\t%s\n", p_words, *p_words);
*/

    //�������һ���ַ�������ָ���ҳ����еĴ�д��ĸ���ո����֣��������ַ��ĸ���
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0; //��ӦҪͳ�Ƶ�4������
    char words[500];
    int i;
    printf("������һ���ַ�����");
    scanf("%s", words);
    for(i = 0; i < 500; i++)
    {
        if(*(words + i) == '\0')
        {
            break;//\0��ʾ�ַ����Ľ�β
        }
        if(*(words + i) >= 'A' && *(words + i) <= 'Z')
        {
            count1++;
        }
    }
    printf("��%d����д��ĸ\n", count1);



















    //����������������׵�ַ��������Ԫ�ص�ַ��
    //��ά�������⣺1-����n��1ά���������
    /*int i, j;
    double score[5][3] = {
        {55, 66, 77},
        {52, 62, 72},
        {15, 26, 37},
        {54, 65, 76},
        {55, 66, 77},
    };
    double (*ptr_score)[3] = score;
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 3; j++)
        {
            //printf("%.2lf\t", score[i][j]);   // score[i] => *(score[i] + i)
            //printf("%.2lf\t", *(score[i] + j));
            printf("%.2lf\t", *(*(ptr_score + i) + j));
        }
        printf("\n");
    }


*/




/*
    //������һ�����ݣ���һ�е�����������score[0]
    for(i = 0; i < 3; i++)
    {
        printf("%.2lf\t", score[0][i]);
    }
    printf("\n");
    //�����ڶ������ݣ�score[1]
    for(i = 0; i < 3; i++)
    {
        printf("%.2lf\t", score[1][i]);
    }

*/














    /*
    int score[5] = {55, 66, 77, 88, 99};
    int * p_score = score;
    int i;
    printf("��������%p\t��Ԫ�ص�ַ��%p\n", score, &score[0]);
    //printf("����ĵ�1��Ԫ�أ�%d\n", *(score + 0)); // score[0]
    //printf("����ĵ�2��Ԫ�أ�%d\n", *(score + 1)); // score[1]
    //printf("����ĵ�3��Ԫ�أ�%d\n", *(score + 2)); // score[2]
    //��������Ԫ��

    for(i = 0; i < 5; i++)
    {
        //printf("%d\n", score[i]);
        printf("%d\n", *(p_score + i)); //score[i]
    }
    printf("%d\n", *p_score);
    */
    return 0;
}
