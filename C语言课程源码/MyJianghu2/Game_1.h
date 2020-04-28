#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameLib.h"
#include "Player.h"
/*
 * 游戏状态枚举，分别对应以下游戏状态：
 * 欢迎界面、正常运行、显示玩家资料、玩家移动、战斗、交易、战斗失败、战斗胜利、游戏暂停和游戏退出
 */
typedef enum _gameStatus
{
    GameSplashScreen,   GameRunning, GameShowPlayer, GameMove,      GameFighting,
    GameTrade,          GameLost,    GameWon,        GamePaused,    GameExit,
    GameMainMenu,       GameLogin,   GameRegister,   GameStartMenu, GameStart
}GameStatus;
void InitGame();
/* 游戏核心进程 */
void Process();
/* 处理游戏欢迎界面 */
void ProcessSplash();
/* 处理游戏开始菜单中的登录和注册 */
void ProcessGameStartMenu();
void ProcessGameRunning();
void ProcessGameMainMenu();

/* 显示游戏界面的总方法根据游戏的状态调用正确的函数 */
void Show();
/* 显示顶部的欢迎信息 */
void ShowWelcome();
/* 显示游戏欢迎界面 */
void ShowGameSplash();
/* 显示游戏地图 */
void ShowMap();
void ShowMapInfo(int x, int y);
/* 显示游戏菜单 */
void ShowMenu();

void ShowLogin();
void ShowRegister();
void ShowPlayerInfo();
void ShowMonster();
void ShowGameRunning();
void ShowTrade();//购买装备
void ShowExit();

void Fight(Monster *monster);
void Move(int x, int y);
int Trade(Player *player, int propId);

#endif // GAME_H_INCLUDED
