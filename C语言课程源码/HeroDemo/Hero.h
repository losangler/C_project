#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

typedef struct _myTime
{
    int year;   int month;  int day;
}MyTime;
typedef struct _hero
{
    char name[50];  //Ӣ������
    char sex;       //Ӣ���Ա�
    char job[20];   //Ӣ��ְҵ
    int life;       //Ӣ������ֵ
    double speeed;  //�����ٶ�
    char abillity[20];//Ӣ�۵���������
    MyTime pubTime; //Ӣ�۵�����ʱ��
}Hero;


#endif // HERO_H_INCLUDED
