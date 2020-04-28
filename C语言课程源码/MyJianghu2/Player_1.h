#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
/***************************************************
 * 文件名：Player.h
 * 描  述：定义游戏中与玩家相关的结构及函数定义
 * 创建人：老九学堂·窖头
 * 日  期：2016-11-10
 * 版  本：1.0
 * 官  网：http://www.xuetang9.com
 * 官方QQ：614940318（老九君）
 *
 **************************************************/
 #include <stdio.h>
 #include <stdlib.h>
 #include <windows.h>
/* 游戏地图结构 游戏地图 编号、名称、介绍、玩家的进入等级 */
typedef struct _map{
    int id;         //地图编号
    char name[50];  //地图名称
    int minLevel;   //玩家进入的最低等级
    //坐标结构
    COORD coord;    //地图的坐标
    char desc[500]; //地图的介绍
}Map;
/* 门派 */
typedef struct _martial{
    int id;         //门派编号
    char name[21];  //门派名称
    char type[11];  //门派类型：正派、邪派、亦正亦邪
    COORD hqCoord;  //总部坐标
    int isOpen;     //是否开放
    char description[1000];//门派描述
}Martial;
//游戏道具类型枚举，对应 武器、防具、心法、消耗品、碎片
typedef enum _propType{
    Weapon, Armor, Book, Consumables, Fragment
} PropType;
/* 游戏道具 */
typedef struct _prop{
    int id;
    char name[50];
    int level;
    PropType type;
    union{
        int attack;     //如果是武器，就对应攻击力
        int defense;    //如果是防具，就对应防御力
        int power;      //如果是血瓶等消耗品，对应增加的能量值
    };
    int stock;          //当前道具的数量
    double price;
    char desc[200];     //游戏道具描述
}Prop;
/* 玩家背包 */
typedef struct _bag{
    int playerId;       //所属玩家编号
    int propCount;      //当前道具的总数
    int propMax;        //背包中最大道具数
    Prop props[8];      //背包中的道具数组，默认8个道具插槽(8可以设置成常量)
}Bag;
/* 玩家结构 */
typedef struct _player{
    int id;
    char name[50];  //玩家名称
    char pass[50];  //玩家登陆密码
    int life;       //玩家生命数，默认5条命，死亡一次-1
    int level;      //玩家级别
    int exp;        //玩家当前级别经验值
    int hp;         //玩家当前血量
    int mp;         //玩家内力值
    int gold;       //玩家金币数
    Martial martial;//所属门派
    Prop weapon;    //所装备的武器
    Prop armor;     //所装备的防具
    Bag bag;        //玩家背包
    COORD currCoord;//玩家当前坐标
}Player;
/* 怪物 */
typedef struct _monster{
    int id;
    char name[50];  //怪物名称
    int level;      //怪物级别
    int hp;         //怪物生命值
    int att;        //怪物攻击力
    int deff;       //怪物防御力
    int minMoney;   //掉落金币最小值
    int maxMoney;   //掉落金币最大值
    int exp;        //杀死后玩家所得经验值
    int state;      //怪物状态，1-生存，0-死亡
    COORD mCoord;   //怪物坐在地图坐标
}Monster;

#endif // PLAYER_H_INCLUDED
