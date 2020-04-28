/***************************************************
 * 文件名：GameLib.c
 * 描  述：实现Game.h中定义的操作函数
 * 创建人：老九学堂·窖头
 * 日  期：2016-11-18
 * 版  本：1.0
 * 官  网：http://www.xuetang9.com
 * 官方QQ：614940318（老九君）
 *
 **************************************************/
#include "GameLib.h"

void SetTitle(char * title)
{
    SetConsoleTitle(title);
}
void SetColor(int foreColor, int backColor)
{
    HANDLE winHandle;   //句柄
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置文字颜色
    SetConsoleTextAttribute(winHandle, foreColor + backColor * 0x10);
}
void SetPosition(int x, int y)
{
    HANDLE winHandle;   //句柄
    COORD pos = {x, y};
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置光标的坐标
    SetConsoleCursorPosition(winHandle, pos);
}
/* 从x、y坐标开始，清rowCount行 */
void Clear(int x, int y, int rowCount)
{

    //每行清除78个字符-打印78个空格
    int i, j;
    for(i = 0; i < rowCount; i++)
    {
        SetPosition(x, y + i);
        for(j = 0; j < 78; j++)
        {
            printf(" ");
        }
    }
}







