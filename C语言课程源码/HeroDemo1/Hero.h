#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct _myTime
{
    int year;   int month;  int day;
}MyTime;
typedef struct _hero
{
    char *name;  //Ӣ������
    char sex;       //Ӣ���Ա�
    char *job;   //Ӣ��ְҵ
    int life;       //Ӣ������ֵ
    double speed;  //�����ٶ�
    char *abillity;//Ӣ�۵���������
    MyTime pubTime; //Ӣ�۵�����ʱ��
}Hero;

//��ӡ���
//����ƽ������ֵ
void ShowAvg();

void Input();//��̬¼������

void Show();//��ʾӢ�۵���ϸ��Ϣ

#endif // HERO_H_INCLUDED
