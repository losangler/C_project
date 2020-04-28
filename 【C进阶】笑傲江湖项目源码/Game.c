#include "Game.h"
#include "Player.h"
#define GAME_NAME "笑傲江湖之精忠报国 C语言版"
#define WIN_WIDTH 121    //控制台窗口的宽（单位：字符）
#define WIN_HEIGHT 26    //控制台窗口的高（单位：字符）
#define MARGIN_X   15    //游戏界面默认的左边距（单位：字符）
#define GAME_WIDTH 78    //游戏界面的默认宽度（单位：字符）
#define GAME_WELCOME_START_Y 0  //欢迎信息的起始Y坐标（第0行）
#define GAME_MAP_START_Y 3      //游戏地图的起始Y坐标（第3行）
#define GAME_MAP_END_Y 11       //游戏地图的结束Y坐标（第11行）
#define GAME_MSG_START_Y 12     //游戏信息的起始Y坐标（第12行）
#define GAME_MSG_END_Y   19     //游戏信息的结束Y坐标（第18行）
#define GAME_MENU_START_Y 20    //游戏菜单选项的起始Y坐标
#define GAME_MENU_END_Y 29      //游戏菜单选项的结束Y坐标
//游戏界面的分割线，默认78个-号
#define GAME_SEP "------------------------------------------------------------------------------"

/* 已注册玩家总数 */
int RegistedPlayerCount = 2;
/* 当前已登录的玩家 */
Player *currPlayer;
/* 用户按下的键 */
int LastKey = 0;
/* 当前游戏状态,默认为欢迎界面 */
GameStatus GameState = GameSplashScreen;


extern char Maps[8][8][10];
extern Player players[5];
extern Martial martials[20];
extern Prop props[20];
extern Map mapArray[8][8];
extern Monster monsters[31];
void InitGame()
{
    players[0].martial = martials[5];
    players[0].weapon = props[8];
    players[0].armor = props[16];
    players[0].bag.propMax = 8;
}
/**
 * 游戏的核心逻辑
 * 主要处理 GameSplashScreen,GameStartMenu,GameMainMenu,GameRunning和GameExit几个状态
 * GameLogin,GameRegister放在ProcessGameStartMenu中处理
 * GameShowPlayer,Fighting,Won,Lost,Move和Trade放在ProcessGameRunning中处理
 */
void Process()
{
    if(GameState == GameSplashScreen)
    {
        Show();
    }
    //当用户的按键不为0时
    fflush(stdin);
    //if(LastKey = getch())
    if(LastKey = GetKey())
    {
        fflush(stdin);
        //接收到用户按下的键后，根据当前游戏状态处理不同的游戏业务
        switch(GameState)
        {
        case GameSplashScreen:
            ProcessSplash();//设置下一个游戏状态/游戏屏
            break;
        case GameStartMenu://在开始菜单中处理登录和注册
            ProcessGameStartMenu();
            break;
        case GameRunning:
            ProcessGameRunning();
            break;
        case GameExit:
            break;
        }
    }
    //处理完游戏业务后，重新显示游戏界面
    Show();
}
void ProcessSplash()
{
    //处理欢迎界面的目的：设置欢迎界面下一个显示界面
    //如果用户按下了键，移动登录或注册界面
    if(LastKey)
    {
        GameState = GameStartMenu;
    }

}
void ProcessGameStartMenu()
{
    //处理游戏主菜单的业务逻辑
    switch(LastKey)
    {
    case '3'://选3或esc游戏退出
    case VK_ESCAPE:
        GameState = GameExit;
        break;
    case '1'://登录
        GameState = GameLogin;
        break;
    case '2'://注册
        GameState = GameRegister;
        break;
    }
}
void ProcessGameRunning()//处理游戏的运行逻辑
{
    switch(LastKey)
    {
    case VK_UP://修改坐标，刷新地图和信息区
    //case 38:
        currPlayer->currCoord.Y--;
        if(currPlayer->currCoord.Y < 0) currPlayer->currCoord.Y = 7;
        GameState = GameRunning;
        break;
    case VK_RIGHT:
    //case 39:
        currPlayer->currCoord.X++;
        if(currPlayer->currCoord.X > 7) currPlayer->currCoord.X = 0;
        GameState = GameRunning;
        break;
    case VK_DOWN:
    //case 40:
        currPlayer->currCoord.Y++;
        if(currPlayer->currCoord.Y > 7) currPlayer->currCoord.Y = 0;
        GameState = GameRunning;
        break;
    //case 37:
    case VK_LEFT:
        currPlayer->currCoord.X--;
        if(currPlayer->currCoord.X < 0) currPlayer->currCoord.X = 7;
        GameState = GameRunning;
        break;
    case '1':
    case '3':
    case '2':
    case '4':
    case '5':
    case '6':
    case '7':
        GameState = GameMainMenu;
        ProcessGameMainMenu();
        break;
    }
    //ShowMap();
}
void ProcessGameMainMenu()
{
    switch(LastKey)
    {
    case '1'://自我欣赏
        //GameState = GameShowPlayer;
        ShowPlayerInfo();//可以在Process方法中更改游戏状态，在Show方法中调用相应的show方法
        break;
    case '2'://探查地形（打怪）
        ShowMonster();
        break;
    case '3'://回总舵
        Move(currPlayer->martial.hqCoord.X, currPlayer->martial.hqCoord.Y);
        break;
    case '4'://购买装备
        //GameState = GameTrade;
        ShowTrade();
        break;
    case '5'://举目四望（随机剧情或任务npc）
        break;
    case '6'://到此一游（留言）
        break;
    case '7':
        ShowExit();
        GameState = GameExit;
        return;
    }
    GameState = GameRunning;
}
void Show()
{
    //设置背景颜色、文字颜色
    //清屏
    //system("cls");
    ShowWelcome();
    ShowMap();
    if(GameState != GameSplashScreen)
        ShowMenu();
    switch(GameState)
    {
    case GameSplashScreen://显示游戏开始的欢迎界面
        ShowGameSplash();
        break;
    case GameRunning:
        ShowGameRunning();
        break;
    case GameMainMenu:
        //ShowMenu();
        break;
    case GameShowPlayer:
        //printf("在信息显示区显示玩家个人资料\n");
        break;
    case GameMove:
        ShowMap();
        break;
    case GameStartMenu://显示游戏开始菜单
        ShowGameSplash();
        ShowMenu();
        break;
    case GameLogin:
        ShowLogin();
        break;
    case GameRegister:
        ShowRegister();
        break;
    case GameTrade:
        ShowTrade();
        break;
    default:
        break;
    }
}
void ShowWelcome()//显示屏幕开头的欢迎信息
{
    SetPosition(MARGIN_X, GAME_WELCOME_START_Y);
    printf("%s", GAME_SEP);
    SetPosition(MARGIN_X, GAME_WELCOME_START_Y + 1);
    printf("|");
    printf("\t\t 欢迎来到 《%s》", GAME_NAME);
    SetPosition(MARGIN_X + GAME_WIDTH - 1, GAME_WELCOME_START_Y + 1);
    printf("|");
    SetPosition(MARGIN_X, GAME_WELCOME_START_Y + 2);
    printf("%s", GAME_SEP);
}
void ShowGameSplash()
{
    ClearByCoord(MARGIN_X, GAME_MSG_START_Y, 7);
    //游戏信息最多允许显示7行
    char * msgs[7] = {
        "欢迎来到大型网络角色扮演游戏 - 《笑傲江湖之精忠报国》",
        "本游戏内容不涉及政治、文化、经济、教育等严肃话题",
        "请以玩游戏的娱乐心态看待本游戏",
        "本游戏拒绝中小学生访问！",
        "请在下面的游戏菜单中选择："
    };
    int i = 0;
    for(i = 0; i < 7; i++)
    {
        SetPosition(MARGIN_X, GAME_MSG_START_Y + i);
        printf("|");
        SetPosition(MARGIN_X + GAME_WIDTH - 1, GAME_MSG_START_Y + i);
        printf("|");
        SetPosition(MARGIN_X + 10, GAME_MSG_START_Y + i);
        if(msgs[i] == NULL)
            continue;
        //PrintString(msgs[i]);
        printf("%s", msgs[i]);
    }
    SetPosition(MARGIN_X, GAME_MSG_END_Y);
    printf(GAME_SEP);
    SetPosition(MARGIN_X + 30, GAME_MENU_START_Y);
    printf("按任意键继续！");
}
void ShowMap()
{
    int i = 0, j = 0;
    //清空地图
    //ClearByCoord(MARGIN_X, GAME_MAP_START_Y, 8);
    if(GameState == GameSplashScreen || GameState == GameStartMenu || GameState == GameExit || currPlayer == NULL)
    //if(GameState != GameRunning)//未进入游戏就显示默认游戏地图
    {
        for(i = 0; i < 8; i++)
        {
            SetPosition(MARGIN_X, GAME_MAP_START_Y + i);
            printf("|");
            SetPosition(MARGIN_X + 4, GAME_MAP_START_Y + i);
            for(j = 0; j < 8; j++)
            {
                //printf("%-9s", Maps[i][j]);
                printf("%-9s", mapArray[j][i].name);
            }
            SetPosition(MARGIN_X + GAME_WIDTH - 1, GAME_MAP_START_Y + i);
            printf("|");
        }
        SetPosition(MARGIN_X, GAME_MAP_END_Y);
        printf(GAME_SEP);
        return;
    }

    for(i = 0; i < 8; i++)
    {
        SetPosition(MARGIN_X, GAME_MAP_START_Y + i);
        printf("|");
        SetPosition(MARGIN_X + 4, GAME_MAP_START_Y + i);
        for(j = 0; j < 8; j++)
        {
            if(j == currPlayer->currCoord.X && i == currPlayer->currCoord.Y)
                SetColor(13, 15);//如果玩家在当前地图
            else
                SetColor(10, 0);
            printf("%-9s", Maps[i][j]);
            SetColor(10, 0);
        }
        SetPosition(MARGIN_X + GAME_WIDTH - 1, GAME_MAP_START_Y + i);
        printf("|");
    }
    SetPosition(MARGIN_X, GAME_MAP_END_Y);
    printf(GAME_SEP);

    ShowMapInfo(currPlayer->currCoord.X, currPlayer->currCoord.Y);
}
void ShowMapInfo(int x, int y)
{
    //在信息区显示地图介绍
    ClearByCoord(MARGIN_X, GAME_MSG_START_Y, 7);
    //char * martialIntro = NULL;//门派介绍
    Martial *currMartial = NULL;
    int i = 0, j = 0;
    for(i = 0; i < 20; i++)
    {
        if(x == martials[i].hqCoord.X && y == martials[i].hqCoord.Y)
        {
            currMartial = &martials[i];
            break;
        }
    }
    SetPosition(MARGIN_X, GAME_MSG_START_Y);
    for(i = 0; i < 8; i++)//信息区有8行
    {
        SetPosition(MARGIN_X, GAME_MSG_START_Y + i);
        for(j = 0; j < GAME_WIDTH; j++)
        {
            if(i == 7){
                printf("-");
            }else if(j == 0 || j == GAME_WIDTH - 1){
                printf("|");
            }
            else{
                printf(" ");
            }
        }
    }
    if(currMartial == NULL){//如果当前坐标不是某个门派的总舵

        SetPosition(MARGIN_X + 20, GAME_MSG_START_Y);
        printf("当前所在地：<%s>", mapArray[currPlayer->currCoord.Y][currPlayer->currCoord.X].name);
        SetPosition(MARGIN_X + 10, GAME_MSG_START_Y + 2);
        char * desc = mapArray[currPlayer->currCoord.Y][currPlayer->currCoord.X].desc;
        int descLen = strlen(desc);
        int k = 0;
        for(k = 0; k < descLen; k++)
        {
            if(k != 0 && k % 50 == 0)//控制每行打印的文字数量
                SetPosition(MARGIN_X + 10, GAME_MSG_START_Y + 2 + k / 50);
            printf("%c", desc[k]);
        }
    }
    else
    {
        SetPosition(MARGIN_X + 15, GAME_MSG_START_Y);
        printf("<%s> -- %s 总舵", Maps[y][x], currMartial->name);
        SetPosition(MARGIN_X + 5, GAME_MSG_START_Y + 2);
        char * desc = currMartial->description;
        int descLen = strlen(desc);
        int k = 0;
        for(k = 0; k < descLen; k++)
        {
            if(k != 0 && k % 70 == 0)//控制每行打印的文字数量
                SetPosition(MARGIN_X + 5, GAME_MSG_START_Y + 2 + k / 70);
            printf("%c", desc[k]);
        }
    }

}
void ShowMenu()
{
    //菜单最多有9行
    SetPosition(MARGIN_X, GAME_MENU_START_Y - 1);
    printf("%s", GAME_SEP);
    ClearByCoord(MARGIN_X, GAME_MENU_START_Y, 9);
    if(GameState == GameExit) return;//如果游戏已处于退出状态，就不需要再显示菜单了
    SetPosition(MARGIN_X, GAME_MENU_START_Y);
    printf("游戏菜单：");
    if(GameState == GameSplashScreen || GameState == GameStartMenu)
    {
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 1);
        printf("1、老玩家回归（登录）");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 2);
        printf("2、新玩家加入（注册）");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 3);
        printf("3、退出游戏");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 4);
        printf("请选择：");
    }
    else
    {
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 1);
        printf("1、自我欣赏");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 2);
        printf("2、探查地形（打怪）");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 3);
        printf("3、回总舵");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 4);
        printf("4、购买装备");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 5);
        printf("5、举目四望（待完成）");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 6);
        printf("6、到此一游（待完成）");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 7);
        printf("7、退出游戏");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 8);
        printf("或输入四方向移动：");
    }
}

void ShowLogin()
{
    ClearByCoord(MARGIN_X, GAME_MSG_START_Y, 7);
    ClearByCoord(MARGIN_X, GAME_MENU_START_Y-1, 10);//清空下面的菜单
    char nickName[50];
    char password[50];
    int i = 0;
    int isSuccess = 0;
    //在信息显示区输入用户名和密码
    do{
        SetPosition(MARGIN_X, GAME_MSG_START_Y + 1);
        printf("请输入侠客昵称：");
        scanf("%s", nickName);
        SetPosition(MARGIN_X, GAME_MSG_START_Y + 2);
        printf("请输入侠客密码：");
        i = 0;
        while((password[i++] = getch()) != '\r');
        password[--i] = '\0';
        //验证用户名和密码
        for(i = 0; i < RegistedPlayerCount; i++){
            if(strcmp(nickName, players[i].name) == 0 && strcmp(password, players[i].pass) == 0)
            {
                isSuccess = 1;
                currPlayer = &players[i];
                GameState = GameRunning;
                break;
            }
        }
        ClearByCoord(MARGIN_X, GAME_MSG_START_Y, 7);
        if(!isSuccess)
        {
            SetPosition(MARGIN_X, GAME_MSG_START_Y);
            printf("请重新输入用户名密码");
        }
    }while(!isSuccess);
    GameState = GameRunning;
}

void ShowRegister()
{
    ClearByCoord(MARGIN_X, GAME_MSG_START_Y, 8);
    ClearByCoord(MARGIN_X, GAME_MENU_START_Y, 9);
    SetPosition(MARGIN_X, GAME_MSG_START_Y);
    if(RegistedPlayerCount == sizeof(players) / sizeof(Player))
    {
        printf("服务器人满为患，大侠请转战其他游戏大区吧！");
        system("pause");
        //getch();//让用户按任意键
        GameState = GameSplashScreen;//让用户返回游戏欢迎界面
        return;
    }
    //执行注册
    int i = 0, choice;
    char password[50];
    printf("请输入玩家注册信息：");
    SetPosition(MARGIN_X, GAME_MSG_START_Y + 1);
    printf("大侠昵称：");
    scanf("%s", players[RegistedPlayerCount].name);
    SetPosition(MARGIN_X, GAME_MSG_START_Y + 2);
    printf("密码：");
    while((password[i++] = getch()) != '\r');
    password[--i] = '\0';
    strcpy(players[RegistedPlayerCount].pass, password);
    SetPosition(MARGIN_X, GAME_MSG_START_Y + 3);
    printf("请选择门派：");
    SetPosition(MARGIN_X + 3, GAME_MSG_START_Y + 4);
    for(i = 0; i < 20; i++)
    {
        printf("%-2d.%-12s", i + 1, martials[i].name);
        if((i + 1) % 5 == 0)
            SetPosition(MARGIN_X + 3, GAME_MSG_START_Y + i / 5  + 5);
    }
    scanf("%d", &choice);//省略验证：必须输入1-20之间的整数
    players[RegistedPlayerCount].martial = martials[choice - 1];
    players[RegistedPlayerCount].life = 100;
    players[RegistedPlayerCount].mp = 100;
    //玩家默认出生在总舵坐标
    players[RegistedPlayerCount].currCoord = martials[choice - 1].hqCoord;
    players[RegistedPlayerCount].exp = 0;
    players[RegistedPlayerCount].gold = 1000;
    players[RegistedPlayerCount].id = RegistedPlayerCount + 1;
    players[RegistedPlayerCount].weapon = props[0];
    players[RegistedPlayerCount].armor = props[9];

    currPlayer = &players[RegistedPlayerCount];
    RegistedPlayerCount++;
    //注册完毕后，显示玩家信息
    //ClearByCoord(MARGIN_X, GAME_MENU_START_Y, 9);
    SetPosition(MARGIN_X + 3, GAME_MSG_START_Y + 9);
    printf("注册成功！");
    system("pause");
    GameState = GameRunning;
}

void ShowGameRunning()
{
    //ShowWelcome();
    //ShowMap();
    //显示主菜单
    //ShowMenu();
}
void ShowPlayerInfo()
{
    ClearByCoord(MARGIN_X, GAME_MSG_START_Y, 7);
    SetPosition(MARGIN_X, GAME_MSG_START_Y);
    int i, j;
    for(i = 0; i < 8; i++)//信息区有8行
    {
        SetPosition(MARGIN_X, GAME_MSG_START_Y + i);
        for(j = 0; j < GAME_WIDTH; j++)
        {
            if(i == 7){
                printf("-");
            }else if(j == 0 || j == GAME_WIDTH - 1){
                printf("|");
            }
            else{
                printf(" ");
            }
        }
    }
    SetPosition(MARGIN_X + 20, GAME_MSG_START_Y);
    printf("自我欣赏-大侠《%s》的个人资料如下：", currPlayer->name);
    SetPosition(MARGIN_X  + 8, GAME_MSG_START_Y + 1);
    printf("编号：%d\t姓名：%s\t级别：%d\t\t经验值：%d", currPlayer->id, currPlayer->name, currPlayer->level, currPlayer->exp);
    SetPosition(MARGIN_X  + 8, GAME_MSG_START_Y + 2);
    printf("门派：%s\tH  P：%d\t内力：%d\t金币：%d", currPlayer->martial.name, currPlayer->hp, currPlayer->mp, currPlayer->gold);
    SetPosition(MARGIN_X  + 8, GAME_MSG_START_Y + 3);
    printf("武器：%s(%d级/攻击%d)\t", currPlayer->weapon.name, currPlayer->weapon.level, currPlayer->weapon.attack);
    printf("防具：%s(%d级/防御%d)\t", currPlayer->armor.name, currPlayer->armor.level, currPlayer->armor.defense);
    SetPosition(MARGIN_X  + 8, GAME_MSG_START_Y + 4);
    printf("-------------------    背包信息：    -----------------------");

    if(currPlayer->bag.propCount == 0)
    {
        SetPosition(MARGIN_X  + 18, GAME_MSG_START_Y + 6);
        printf("当前背包空荡荡的，行走江湖要小心哦0^0");
        //return;
    }
    SetPosition(MARGIN_X  + 8, GAME_MSG_START_Y + 5);
    for(i = 0; i < currPlayer->bag.propCount; i++)
    {
        if(i != 0 && i % 4 == 0 )
        {
            SetPosition(MARGIN_X  + 8, GAME_MSG_START_Y + 5 + i / 4);
        }
        printf("%-12s(%-2d)", currPlayer->bag.props[i].name, currPlayer->bag.props[i].stock);
    }
    ClearByCoord(MARGIN_X, GAME_MENU_START_Y, 9);
    SetPosition(MARGIN_X + 27, GAME_MENU_START_Y + 1);
    printf("按任意键继续。。。");
    getch();
}
void ShowMonster()
{

    int SEP = 10;
    int i;
    //对应9级怪物的级别别称
    char * levelNames[9] = {"乳臭未干", "初出茅庐", "粗通皮毛", "青年才俊", "略有小成", "心领神会", "出类拔萃", "所向无敌", "天人合一"};
    //遍历怪物数组，找到所有跟玩家坐标相同的怪物
    int monsterCount = sizeof(monsters)/ sizeof(Monster);
    int monsterIndex[9];//最多9个怪物
    int currCount = 0;//当前地图的怪物总数
    int choice;
    do{
        currCount = 0;
        ClearByCoord(MARGIN_X, GAME_MSG_START_Y, 7);
        ClearByCoord(MARGIN_X, GAME_MSG_END_Y + 1, 9);
        //将光标定位到信息显示区的开始
        SetPosition(MARGIN_X + 20, GAME_MSG_START_Y);
        printf("当前地图的怪物：");
        SetPosition(MARGIN_X, 14);
        for(i = 0; i < monsterCount; i++)
        {
            if(currPlayer->currCoord.X == monsters[i].mCoord.X && currPlayer->currCoord.Y == monsters[i].mCoord.Y && monsters[i].state != 0)
            {
                //显示怪物
                printf("%d.%s(%s)\t\t", currCount + 1, monsters[i].name, levelNames[monsters[i].level - 1]);
                monsterIndex[currCount] = i;
                currCount++;
                if(currCount == 9) break;
                if(currCount % 3 == 0)
                {
                    SetPosition(MARGIN_X, 14 + currCount / 3);
                }
            }
        }
        if(currCount == 0)
        {
            SetPosition(MARGIN_X + SEP, 14);
            printf("真是鸡不生蛋鸟不拉屎的地方，这里没有其他人，到下个地图去吧。");
            SetPosition(MARGIN_X + SEP, GAME_MSG_END_Y + 2);
            printf("按任意键继续。。。");
            getch();
            return;
        }


    //do{
        SetPosition(MARGIN_X, 18);
        printf("请选择要攻击的对象(按0返回):");
        scanf("%d", &choice);
        if(choice < 0 || choice > currCount){//用户输入错误时清空本行
            SetPosition(MARGIN_X, 18);
            printf("                                          ");
        }
        if(choice == 0)
        {
            GameState = GameRunning;
            return;
        }
        if(choice > currCount)
        {
            continue;
        }
        SetPosition(MARGIN_X, 18);
        Fight(&monsters[monsterIndex[choice-1]]); //调用攻击函数，显示战斗结果
    }while(currPlayer->hp > 0);
    GameState = GameRunning;
}
void Fight(Monster *monster)
{
    SetPosition(MARGIN_X, 18);
    printf("                                          ");
    SetPosition(MARGIN_X, 18);
    int count = 0;
    do
    {
        //玩家每次攻击需要耗费10*攻击力点内力值
        monster->hp -= currPlayer->weapon.attack;
        currPlayer->hp -= monster->att;

        currPlayer->mp -= 10 * currPlayer->weapon.attack;
        if(currPlayer->mp <= 0)
        {
            SetPosition(MARGIN_X, 18);
            printf("                                                           ");
            SetPosition(MARGIN_X, 18);
            printf("当前内力已透支，还是逃命要紧！");
            return;
        }
        SetPosition(MARGIN_X, 18);
        printf("                                          ");
        SetPosition(MARGIN_X, 18);
        printf("战斗第%d轮：%sHP-%d\t%sHP-%d",currPlayer->weapon.attack, currPlayer->name, currPlayer->hp, monster->name, monster->hp);
        count++;
        usleep(1000 * 100);//100毫秒
    }while(currPlayer->hp > 0 && monster->hp > 0 && currPlayer->mp > 0);
    SetPosition(MARGIN_X, 18);
    printf("                                          ");
    SetPosition(MARGIN_X, 18);
    if(currPlayer->hp <= 0)
    {
        printf("江湖快讯：大侠《%s》在与《%s》的战斗中壮烈牺牲！", currPlayer->name, monster->name);
        SetPosition(MARGIN_X + 20, GAME_MSG_END_Y + 2);
            printf("按任意键继续。。。");
        getch();
        GameState = GameRunning;
        return;
    }
    currPlayer->exp += monster->exp;
    currPlayer->gold += monster->maxMoney;
    monster->state = 0;
    printf("经过艰苦的战斗，%s被您杀死，获得%d经验，%d金币！", monster->name, monster->exp, monster->maxMoney);
}
void Move(int x, int y)
{
    currPlayer->currCoord.X = x;
    currPlayer->currCoord.Y = y;
    GameState = GameRunning;
}
void ShowTrade()
{
    ClearByCoord(MARGIN_X, GAME_MSG_START_Y, 17);

    //在信息区打印商店的商品
    int propCount = sizeof(props) / sizeof(Prop) >= 15 ? 15 : sizeof(props) / sizeof(Prop);
    int i;
    SetPosition(MARGIN_X, 12);
    printf("欢迎进入《%s》道具店：", Maps[currPlayer->currCoord.Y][currPlayer->currCoord.X]);
    SetPosition(MARGIN_X + 4, 14);
    for(i = 0; i < propCount; i++)
    {
        if(i % 3 == 0)
        {
            SetPosition(MARGIN_X + 4, 14 + i / 3);
        }
        printf("%-3d.%-10s(%-2d)%-4c", props[i].id, props[i].name, props[i].stock, ' ');
    }
    //用户选择进行交易
    SetPosition(MARGIN_X, 20);
    printf("请输入购买的道具编号：(按0退出)");
    int tradeId;
    scanf("%d", &tradeId);
    if(tradeId == 0)
    {
        //ShowMap();
        GameState = GameRunning;
        return;
    }
    //根据判断，扣除库存及玩家金钱
    //更新玩家背包
    SetPosition(MARGIN_X, 18);
    Trade(currPlayer, tradeId);
    ShowTrade();
}
int Trade(Player *player, int propId)
{
    int i;
    //需要判断：商品的库存，玩家余额够不够，玩家背包空间够不够
    Prop *tradeProp = NULL;//要购买的商品指针
    int propCount = sizeof(props) / sizeof(Prop);
    for(i = 0; i < propCount; i++)
    {
        if(propId == props[i].id){
            tradeProp = &props[i];//tradeProp = props + i;
            break;
        }
    }
    SetPosition(MARGIN_X, 21);
    if(i == propCount)
    {
        printf("商品编号输入错误，请重新输入！");
        system("pause");
        return 0;
    }
    if(tradeProp->stock <= 0)
    {
        printf("地主家都没有余粮！商店都被买空啦！");
        system("pause");
        return 0;
    }
    if(player->gold < tradeProp->price)
    {
        printf("钱包都是瘪的，这里可是看钱的社会！！");
        system("pause");
        return 0;
    }
    if(player->bag.propCount >= player->bag.propMax && player->bag.propCount != 0)
    {
        printf("背包已满，交易失败！");
        system("pause");
        return 0;
    }
    //满足交易条件，执行交易的业务操作
    //1、商品库存-1
    tradeProp->stock--;
    //2、玩家金币-商品单价
    player->gold -= tradeProp->price;
    //*3、玩家背包道具增加
    //判断玩家背包中是否已有该商品

    //如果有该商品，背包中的该商品总数+1
    for(i = 0; i < player->bag.propCount; i++)
    {
        //如果要购买的商品id 跟 背包中的某个商品id相同
        if(propId == player->bag.props[i].id)
        {
            player->bag.props[i].stock++;
            break;
        }
    }
    if(i == player->bag.propCount)//如果没有该商品，该商品添加到背包中即可
    {
        //向背包中创建一个商品-复制一份要交易的商品信息到背包中
        int newIndex = player->bag.propCount;
        player->bag.props[newIndex].id = tradeProp->id;
        player->bag.props[newIndex].price = tradeProp->price;
        player->bag.props[newIndex].stock = 1;
        strcpy(player->bag.props[newIndex].name, tradeProp->name);
        strcpy(player->bag.props[newIndex].desc, tradeProp->desc);
        player->bag.propCount++;
	    player->bag.proMax = 8;
    }
    return 1;
}
void ShowExit()
{
    ClearByCoord(MARGIN_X, GAME_MSG_START_Y, 7);
    SetPosition(MARGIN_X + 30, GAME_MSG_START_Y + 3);
    PrintString("游戏已退出，欢迎再来！");
}

