#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

HANDLE winHandle;
//显示阴影线
void ShadowWindownLine(char *str);
//绘制边框
void DrawBox(int bSigle, SMALL_RECT rect);


int main()
{

    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置代码页437  936
    SetConsoleOutputCP(936);
    ShadowWindownLine("需要课后视频、开发工具与源代码加老九君 QQ：614940318");
    CloseHandle(winHandle);
    return 0;
}
void ShadowWindownLine(char *str)
{
    SMALL_RECT rect;
    CONSOLE_SCREEN_BUFFER_INFO bcInfo;
    int att0, att1, attText;
    int i;
    int len = strlen(str);
    GetConsoleScreenBufferInfo(winHandle, &bcInfo);
    //计算显示窗口大小和位置
    rect.Left = (bcInfo.dwSize.X - len) / 2 - 2;
    rect.Top = 8;
    rect.Right = rect.Left + len + 4;
    rect.Bottom = rect.Top + 4;
    att0 = BACKGROUND_INTENSITY;    //阴影属性
    att1 = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE;
    attText = FOREGROUND_RED | FOREGROUND_INTENSITY;
    //设置阴影然后填充
    COORD posShadow = {rect.Left + 1, rect.Top + 1};
    COORD posText = {rect.Left, rect.Top};
    for(i = 0; i < 5; i++)
    {
        FillConsoleOutputAttribute(winHandle, att0, len + 4, posShadow, NULL);
        posShadow.Y++;
    }
    for(i = 0; i < 5; i++)
    {
        FillConsoleOutputAttribute(winHandle, att1, len + 4, posText, NULL);
        posText.Y++;
    }

    posText.X = rect.Left + 2;
    posText.Y = rect.Top + 2;
    WriteConsoleOutputCharacter(winHandle, str, len, posText, NULL);

    //恢复原来的属性
    SetConsoleTextAttribute(winHandle, bcInfo.wAttributes);
}
/*
    //设备句柄-通常用来标识Windows资源(菜单、窗口、图标)和设备等对象
    //作为Windows系统内部表的索引值来使用
    HANDLE winHandle;
    //存储窗口信息
    CONSOLE_SCREEN_BUFFER_INFO screenBuffInfo;
    //获取标准输出设备句柄
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //获取窗口信息
    GetConsoleScreenBufferInfo(winHandle, &screenBuffInfo);
    printf("\n测试测试测试测试\n测试测试\n测试\n");
    _getch();
    COORD start = {80, 25};
    FillConsoleOutputCharacter(winHandle, ' ', screenBuffInfo.dwSize.X * screenBuffInfo.dwSize.Y, start, NULL);
    CloseHandle(winHandle);
    */
