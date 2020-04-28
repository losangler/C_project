#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameLib.h"
#include "Player.h"
/*
 * ��Ϸ״̬ö�٣��ֱ��Ӧ������Ϸ״̬��
 * ��ӭ���桢�������С���ʾ������ϡ�����ƶ���ս�������ס�ս��ʧ�ܡ�ս��ʤ������Ϸ��ͣ����Ϸ�˳�
 */
typedef enum _gameStatus
{
    GameSplashScreen,   GameRunning, GameShowPlayer, GameMove,      GameFighting,
    GameTrade,          GameLost,    GameWon,        GamePaused,    GameExit,
    GameMainMenu,       GameLogin,   GameRegister,   GameStartMenu, GameStart
}GameStatus;
void InitGame();
/* ��Ϸ���Ľ��� */
void Process();
/* ������Ϸ��ӭ���� */
void ProcessSplash();
/* ������Ϸ��ʼ�˵��еĵ�¼��ע�� */
void ProcessGameStartMenu();
void ProcessGameRunning();
void ProcessGameMainMenu();

/* ��ʾ��Ϸ������ܷ���������Ϸ��״̬������ȷ�ĺ��� */
void Show();
/* ��ʾ�����Ļ�ӭ��Ϣ */
void ShowWelcome();
/* ��ʾ��Ϸ��ӭ���� */
void ShowGameSplash();
/* ��ʾ��Ϸ��ͼ */
void ShowMap();
void ShowMapInfo(int x, int y);
/* ��ʾ��Ϸ�˵� */
void ShowMenu();

void ShowLogin();
void ShowRegister();
void ShowPlayerInfo();
void ShowMonster();
void ShowGameRunning();
void ShowTrade();//����װ��
void ShowExit();

void Fight(Monster *monster);
void Move(int x, int y);
int Trade(Player *player, int propId);

#endif // GAME_H_INCLUDED
