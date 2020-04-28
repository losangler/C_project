#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
//结构体：英雄、职业、英雄能力、时间
typedef struct _job
{
    int id;
    char * name;    //职业名称
    char * desc;    //职业的描述
}Job;
typedef struct _abillity
{
    int id;
    char * name;    //特殊能力名称
    char * intro;   //特殊能力的说明
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
    char * name;    //英雄名称
    char sex;       //性别
    Job job;        //英雄的职业
    double hp;      //英雄的生命值
    double speed;   //攻击速度
    Abillity abillity;//特殊能力
    PubTime pubTime;//上线时间
}Hero;

//Job job;//简化结构体的使用

//用来输入英雄的值
void InputHero();

void ShowHero();


#endif // HERO_H_INCLUDED
