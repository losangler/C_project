#include "Hero.h"

Hero heros[100] = {
   {"Ӱ��֮����", 'm', "�̿�", 579, 0.644, "λ��", {2012, 8, 15}},
   {"��ɪ��Ů���", 'F', "��ʦ", 482, 0.644, "���١�����", {2010, 9, 20}},
   {"���罣��", 'm', "սʿ", 517, 0.67, "���ܡ�λ��", {2013, 12, 23}}
};
int count = 3;//��ǰ��Ӣ������
void Input()
{
    //����¼������
    //��һ��¼����Ϻ�ѯ���Ƿ����¼�룿
    char answer = 'y';
    do{
        if(count == 100)
        {
            printf("Ӣ�۵���λ�������뵽��Ϸ�̳ǹ���");
            break;
        }
        printf("\n��ǰ¼���%dλӢ�۵���Ϣ��\n", count + 1);
        printf("Ӣ�����ƣ�");
        heros[count].name = (char*)malloc(50);
        scanf("%s", heros[count].name);
        printf("�Ա�");
        fflush(stdin);
        heros[count].sex = getchar();
        fflush(stdin);
        printf("ְҵ��");
        heros[count].job = (char*)malloc(50);
        scanf("%s", heros[count].job);
        heros[count].life = 1000;
        heros[count].speed = 0.655;
        heros[count].abillity = "���졢���";
        heros[count].pubTime.year = 2016;
        heros[count].pubTime.month = 4;
        heros[count].pubTime.day = 9;
        count++;//¼����Ϻ�Ӣ������+1
        printf("�Ƿ����¼��Ӣ�۵���Ϣ��(y/n)");
        answer = getch();//�û����¼������������������䣬���������û��ûس���
        fflush(stdin);
    }while(answer == 'y' || answer == 'Y');
}
void ShowAvg()
{
    int lifeOfSum = 0;
    double avg = 0;
    int i;
    for(i = 0; i < count; i++)
    {
        lifeOfSum += (heros + i)->life;
    }
    //����ƽ��ֵ
    avg = lifeOfSum * 1.0 / count;
    printf("����ֵ��ƽ��ֵΪ��%.2lf\n", avg);
}
void Show()
{
    //���֪���ṹ����Ĵ�С�أ�
    //int len = sizeof(heros) / sizeof(Hero);
    //����Ԫ��ʹ��ָ��ʱ����̬��ֵ��Ҫ���ȷ����ڴ�
    //printf("���������ƣ�");
    //heros[0].name = (char *)malloc(50);//    char name[50]
    //scanf("%s", heros[0].name);
    //printf("�ṹ�����Ԫ�ظ�����%d\n", len);
    int i;
    printf("\n");
    for(i = 0; i < count; i++)
    {
        printf("%s\t%s\t%d-%d-%d\n", (heros + i)->name, heros[i].job, heros[i].pubTime.year, heros[i].pubTime.month, heros[i].pubTime.day);
    }
}
