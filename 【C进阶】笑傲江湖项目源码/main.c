#include <stdio.h>
#include <stdlib.h>
#include "GameLib.h"
#include "Game.h"

extern GameStatus GameState;
int main()
{
    SetTitle("笑傲江湖之精忠报国C语言版 v0.1 :: 更多资料请加QQ:614940318");
    SetConsoleWindowSize(121, 35);
    SetColor(10, 0);
    InitGame();
    while(GameState != GameExit)
    {
        Process();
    }

    return 0;
}
