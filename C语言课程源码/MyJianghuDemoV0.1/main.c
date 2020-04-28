#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "GameLib.h"
#include "Game.h"

extern int X, Y;

int main()
{
    char key;   //接收到的用户按键
    SetTitle("笑傲江湖之精忠报国 老九C语言版");
    SetColor(10, 0);
    Init();
    ShowWelcome();
    ShowMap();
    ShowInfomation();
    ShowMainMenu();
    while(1)
    {
        fflush(stdin);
        //等待用户输入某个键
        key = getch();//无回显接收某个按键 getchar();
        fflush(stdin);
        if(key == '1' || key == '2' || key == '3' || key == '4' || key == '5'){
            //printf("1-5之间的游戏菜单");
            ProcessMainMenu(key);//通过函数去处理用户的菜单选项
            continue;
        }
        else if(key == VK_UP || key == 72)//用户按了上键
        {
            Y--;
        }
        else if(key == 39 || key == 77)//右
        {
            X++;
        }
        else if(key == 40 || key == 80)//下
        {
            Y++;
        }
        else if(key == 37 || key == 75)//左
        {
            X--;
        }
        if(X > 7) X = 0;
        if(X < 0) X = 7;
        if(Y > 7) Y = 0;
        if(Y < 0) Y = 7;
        ShowMap();//重新显示地图
    }
    return 0;
}
