#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
//�ṹ�壺Ӣ�ۡ�ְҵ��Ӣ��������ʱ��
typedef struct _job
{
    int id;
    char * name;    //ְҵ����
    char * desc;    //ְҵ������
}Job;
typedef struct _abillity
{
    int id;
    char * name;    //������������
    char * intro;   //����������˵��
}Abillity;
typedef struct _pubTime
{
    int year;
    int month;
    int day;
}PubTime;
typedef struct _hero
{
    int id;
    char * name;    //Ӣ������
    char sex;       //�Ա�
    Job job;        //Ӣ�۵�ְҵ
    double hp;      //Ӣ�۵�����ֵ
    double speed;   //�����ٶ�
    Abillity abillity;//��������
    PubTime pubTime;//����ʱ��
}Hero;

//Job job;//�򻯽ṹ���ʹ��

//��������Ӣ�۵�ֵ
void InputHero();

void ShowHero();


#endif // HERO_H_INCLUDED
