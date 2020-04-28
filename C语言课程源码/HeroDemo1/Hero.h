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
    char *name;  //英雄名称
    char sex;       //英雄性别
    char *job;   //英雄职业
    int life;       //英雄生命值
    double speed;  //攻击速度
    char *abillity;//英雄的特殊能力
    MyTime pubTime; //英雄的上线时间
}Hero;

//打印结果
//计算平均生命值
void ShowAvg();

void Input();//动态录入内容

void Show();//显示英雄的详细信息

#endif // HERO_H_INCLUDED
