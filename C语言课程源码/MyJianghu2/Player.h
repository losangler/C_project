#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
/***************************************************
 * �ļ�����Player.h
 * ��  ����������Ϸ���������صĽṹ����������
 * �����ˣ��Ͼ�ѧ�á���ͷ
 * ��  �ڣ�2016-11-10
 * ��  ����1.0
 * ��  ����http://www.xuetang9.com
 * �ٷ�QQ��614940318���Ͼž���
 *
 **************************************************/
 #include <stdio.h>
 #include <stdlib.h>
 #include <windows.h>
/* ��Ϸ��ͼ�ṹ ��Ϸ��ͼ ��š����ơ����ܡ���ҵĽ���ȼ� */
typedef struct _map{
    int id;         //��ͼ���
    char name[50];  //��ͼ����
    int minLevel;   //��ҽ������͵ȼ�
    //����ṹ
    COORD coord;    //��ͼ������
    char desc[500]; //��ͼ�Ľ���
}Map;
/* ���� */
typedef struct _martial{
    int id;         //���ɱ��
    char name[21];  //��������
    char type[11];  //�������ͣ����ɡ�а�ɡ�������а
    COORD hqCoord;  //�ܲ�����
    int isOpen;     //�Ƿ񿪷�
    char description[1000];//��������
}Martial;
//��Ϸ��������ö�٣���Ӧ ���������ߡ��ķ�������Ʒ����Ƭ
typedef enum _propType{
    Weapon, Armor, Book, Consumables, Fragment
} PropType;
/* ��Ϸ���� */
typedef struct _prop{
    int id;
    char name[50];
    int level;
    PropType type;
    union{
        int attack;     //������������Ͷ�Ӧ������
        int defense;    //����Ƿ��ߣ��Ͷ�Ӧ������
        int power;      //�����Ѫƿ������Ʒ����Ӧ���ӵ�����ֵ
    };
    int stock;          //��ǰ���ߵ�����
    double price;
    char desc[200];     //��Ϸ��������
}Prop;
/* ��ұ��� */
typedef struct _bag{
    int playerId;       //������ұ��
    int propCount;      //��ǰ���ߵ�����
    int propMax;        //��������������
    Prop props[8];      //�����еĵ������飬Ĭ��8�����߲��(8�������óɳ���)
}Bag;
/* ��ҽṹ */
typedef struct _player{
    int id;
    char name[50];  //�������
    char pass[50];  //��ҵ�½����
    int life;       //�����������Ĭ��5����������һ��-1
    int level;      //��Ҽ���
    int exp;        //��ҵ�ǰ������ֵ
    int hp;         //��ҵ�ǰѪ��
    int mp;         //�������ֵ
    int gold;       //��ҽ����
    Martial martial;//��������
    Prop weapon;    //��װ��������
    Prop armor;     //��װ���ķ���
    Bag bag;        //��ұ���
    COORD currCoord;//��ҵ�ǰ����
}Player;
/* ���� */
typedef struct _monster{
    int id;
    char name[50];  //��������
    int level;      //���Ｖ��
    int hp;         //��������ֵ
    int att;        //���﹥����
    int deff;       //���������
    int minMoney;   //��������Сֵ
    int maxMoney;   //���������ֵ
    int exp;        //ɱ����������þ���ֵ
    int state;      //����״̬��1-���棬0-����
    COORD mCoord;   //�������ڵ�ͼ����
}Monster;

#endif // PLAYER_H_INCLUDED
