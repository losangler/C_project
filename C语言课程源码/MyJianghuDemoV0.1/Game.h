#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
/***************************************************
 * 文件名：Game.h
 * 描  述：用来定义游戏的一些核心结构和函数
 * 创建人：老九学堂·窖头
 * 日  期：2016-11-10
 * 版  本：1.0
 * 官  网：http://www.xuetang9.com
 * 官方QQ：614940318（老九君）
 *
 **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "GameLib.h"

/*********************  游戏的结构类型定义   *******************************/

//玩家、地图、装备、怪物
/* 游戏地图结构 游戏地图
  编号、名称、介绍、玩家的进入等级 */
typedef struct _map{
    int id;         //地图编号
    char name[50];  //地图名称
    int minLevel;   //玩家进入的最低等级
    //坐标结构
    COORD coord;    //地图的坐标
    char desc[500]; //地图的介绍
}Map;
/* 游戏道具类型枚举 - 武器、道具、消耗品、卡片、碎片 */
typedef enum _proptype{
    Weapon, Armor, Con, card, Frag
}PropType;
/* 游戏道具 - 武器、防具、消耗品、卡片 */
typedef struct _prop{
    int id;         //道具编号
    char name[50];  //道具名称
    int leve;       //道具的级别
    int stock;      //道具的库存或玩家背包中的叠加数量
    double price;   //道具的单价
    PropType type;  //道具的类型
    union{//联合 - 多选1
        int minAttack; //如果是武器，就对应攻击力
        int minDefence;//如果是防具，就对应防御力
        int minPower;  //如果是血瓶等消耗品，就对应增加的能量值
    };
    union{//联合 - 多选1
        int maxAttack; //如果是武器，就对应攻击力
        int maxDefence;//如果是防具，就对应防御力
        int maxPower;  //如果是血瓶等消耗品，就对应增加的能量值
    };
    char desc[200]; //道具的功能描述
}Prop;
/* 门派结构 */
typedef struct _martial{
    int id;
    char name[50];
    char type[50];  //门派类型-正派、邪派
    COORD hqCoord;  //总舵的坐标
    int isOpen;     //门派是否开放
    char desc[1000];//门派描述
}Martial;
typedef struct _player{
    int id;
    char name[50];
    char pass[50];
    int life;       //玩家生命值
    int level;      //玩家级别
    int exp;        //玩家的经验值
    int hp;         //玩家的血量
    int mp;         //玩家的内力值
    int mpMax;      //当前级别玩家的最大内力值
    int gold;       //玩家的金币数量
    Martial martial;//玩家的门派
    COORD coord;    //玩家当前所在地图的坐标
    Prop weapon;    //玩家装备的武器
    Prop armor;     //玩家装备的防具

    //玩家的背包
}Player;
typedef struct _monster{
    int id;
    char name[50];
    int level;       //怪物的级别
    int hp;         //怪物的生命值
    int att;        //怪物的攻击力
    int diff;       //怪物的防御力
    int minMoney;   //杀死怪物后掉落的最少金币值
    int maxMoney;
    int exp;        //杀死怪物后玩家获得的经验值
    //扩展：杀死怪物后，玩家可以获得的道具列表
    int state;      //怪物当前的状态，0表示怪物已死，非0表示怪物活着
    COORD coord;    //怪物的坐标
}Monster;
void Init();//初始化游戏数据
void Show();//显示全局数据

/* 显示游戏的欢迎信息 */
void ShowWelcome();
/* 显示游戏地图 */
void ShowMap();
/* 在信息界面显示当前地图的信息 */
void ShowMapInfo();
/* 显示游戏地图下方的游戏信息 */
void ShowInfomation();
/* 显示游戏的主菜单 */
void ShowMainMenu();
/* 在信息界面显示玩家的个人资料 */
void ShowPlayerInfo();
/* 在信息界面显示当前地图的怪物 */
void ShowMonsters();

/* 处理游戏主菜单的业务 */
void ProcessMainMenu(char key);
/* pk怪物的方法 */
void Fight(int monsterId);
/* 瞬间移动 */
void Move(int x, int y);





#endif // GAME_H_INCLUDED
