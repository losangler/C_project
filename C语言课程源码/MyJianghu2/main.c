#include <stdio.h>
#include <stdlib.h>
#include "GameLib.h"
#include "Game.h"

extern GameStatus GameState;
int main()
{
    SetTitle("Ц������֮���ұ���C���԰� v0.1 :: �����������QQ:614940318");
    SetConsoleWindowSize(121, 35);
    SetColor(10, 0);
    InitGame();
    while(GameState != GameExit)
    {
        Process();
    }

    return 0;
}
