#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

typedef struct _myTime
{
    int year;   int month;  int day;
}MyTime;
typedef struct _hero
{
    char name[50];  //英雄名称
    char sex;       //英雄性别
    char job[20];   //英雄职业
    int life;       //英雄生命值
    double speeed;  //攻击速度
    char abillity[20];//英雄的特殊能力
    MyTime pubTime; //英雄的上线时间
}Hero;


#endif // HERO_H_INCLUDED
