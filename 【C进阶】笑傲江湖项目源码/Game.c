#include "Game.h"
#include "Player.h"
#define GAME_NAME "Ц������֮���ұ��� C���԰�"
#define WIN_WIDTH 121    //����̨���ڵĿ���λ���ַ���
#define WIN_HEIGHT 26    //����̨���ڵĸߣ���λ���ַ���
#define MARGIN_X   15    //��Ϸ����Ĭ�ϵ���߾ࣨ��λ���ַ���
#define GAME_WIDTH 78    //��Ϸ�����Ĭ�Ͽ�ȣ���λ���ַ���
#define GAME_WELCOME_START_Y 0  //��ӭ��Ϣ����ʼY���꣨��0�У�
#define GAME_MAP_START_Y 3      //��Ϸ��ͼ����ʼY���꣨��3�У�
#define GAME_MAP_END_Y 11       //��Ϸ��ͼ�Ľ���Y���꣨��11�У�
#define GAME_MSG_START_Y 12     //��Ϸ��Ϣ����ʼY���꣨��12�У�
#define GAME_MSG_END_Y   19     //��Ϸ��Ϣ�Ľ���Y���꣨��18�У�
#define GAME_MENU_START_Y 20    //��Ϸ�˵�ѡ�����ʼY����
#define GAME_MENU_END_Y 29      //��Ϸ�˵�ѡ��Ľ���Y����
//��Ϸ����ķָ��ߣ�Ĭ��78��-��
#define GAME_SEP "------------------------------------------------------------------------------"

/* ��ע��������� */
int RegistedPlayerCount = 2;
/* ��ǰ�ѵ�¼����� */
Player *currPlayer;
/* �û����µļ� */
int LastKey = 0;
/* ��ǰ��Ϸ״̬,Ĭ��Ϊ��ӭ���� */
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
 * ��Ϸ�ĺ����߼�
 * ��Ҫ���� GameSplashScreen,GameStartMenu,GameMainMenu,GameRunning��GameExit����״̬
 * GameLogin,GameRegister����ProcessGameStartMenu�д���
 * GameShowPlayer,Fighting,Won,Lost,Move��Trade����ProcessGameRunning�д���
 */
void Process()
{
    if(GameState == GameSplashScreen)
    {
        Show();
    }
    //���û��İ�����Ϊ0ʱ
    fflush(stdin);
    //if(LastKey = getch())
    if(LastKey = GetKey())
    {
        fflush(stdin);
        //���յ��û����µļ��󣬸��ݵ�ǰ��Ϸ״̬����ͬ����Ϸҵ��
        switch(GameState)
        {
        case GameSplashScreen:
            ProcessSplash();//������һ����Ϸ״̬/��Ϸ��
            break;
        case GameStartMenu://�ڿ�ʼ�˵��д����¼��ע��
            ProcessGameStartMenu();
            break;
        case GameRunning:
            ProcessGameRunning();
            break;
        case GameExit:
            break;
        }
    }
    //��������Ϸҵ���������ʾ��Ϸ����
    Show();
}
void ProcessSplash()
{
    //����ӭ�����Ŀ�ģ����û�ӭ������һ����ʾ����
    //����û������˼����ƶ���¼��ע�����
    if(LastKey)
    {
        GameState = GameStartMenu;
    }

}
void ProcessGameStartMenu()
{
    //������Ϸ���˵���ҵ���߼�
    switch(LastKey)
    {
    case '3'://ѡ3��esc��Ϸ�˳�
    case VK_ESCAPE:
        GameState = GameExit;
        break;
    case '1'://��¼
        GameState = GameLogin;
        break;
    case '2'://ע��
        GameState = GameRegister;
        break;
    }
}
void ProcessGameRunning()//������Ϸ�������߼�
{
    switch(LastKey)
    {
    case VK_UP://�޸����꣬ˢ�µ�ͼ����Ϣ��
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
    case '1'://��������
        //GameState = GameShowPlayer;
        ShowPlayerInfo();//������Process�����и�����Ϸ״̬����Show�����е�����Ӧ��show����
        break;
    case '2'://̽����Σ���֣�
        ShowMonster();
        break;
    case '3'://���ܶ�
        Move(currPlayer->martial.hqCoord.X, currPlayer->martial.hqCoord.Y);
        break;
    case '4'://����װ��
        //GameState = GameTrade;
        ShowTrade();
        break;
    case '5'://��Ŀ������������������npc��
        break;
    case '6'://����һ�Σ����ԣ�
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
    //���ñ�����ɫ��������ɫ
    //����
    //system("cls");
    ShowWelcome();
    ShowMap();
    if(GameState != GameSplashScreen)
        ShowMenu();
    switch(GameState)
    {
    case GameSplashScreen://��ʾ��Ϸ��ʼ�Ļ�ӭ����
        ShowGameSplash();
        break;
    case GameRunning:
        ShowGameRunning();
        break;
    case GameMainMenu:
        //ShowMenu();
        break;
    case GameShowPlayer:
        //printf("����Ϣ��ʾ����ʾ��Ҹ�������\n");
        break;
    case GameMove:
        ShowMap();
        break;
    case GameStartMenu://��ʾ��Ϸ��ʼ�˵�
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
void ShowWelcome()//��ʾ��Ļ��ͷ�Ļ�ӭ��Ϣ
{
    SetPosition(MARGIN_X, GAME_WELCOME_START_Y);
    printf("%s", GAME_SEP);
    SetPosition(MARGIN_X, GAME_WELCOME_START_Y + 1);
    printf("|");
    printf("\t\t ��ӭ���� ��%s��", GAME_NAME);
    SetPosition(MARGIN_X + GAME_WIDTH - 1, GAME_WELCOME_START_Y + 1);
    printf("|");
    SetPosition(MARGIN_X, GAME_WELCOME_START_Y + 2);
    printf("%s", GAME_SEP);
}
void ShowGameSplash()
{
    ClearByCoord(MARGIN_X, GAME_MSG_START_Y, 7);
    //��Ϸ��Ϣ���������ʾ7��
    char * msgs[7] = {
        "��ӭ�������������ɫ������Ϸ - ��Ц������֮���ұ�����",
        "����Ϸ���ݲ��漰���Ρ��Ļ������á����������໰��",
        "��������Ϸ��������̬��������Ϸ",
        "����Ϸ�ܾ���Сѧ�����ʣ�",
        "�����������Ϸ�˵���ѡ��"
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
    printf("�������������");
}
void ShowMap()
{
    int i = 0, j = 0;
    //��յ�ͼ
    //ClearByCoord(MARGIN_X, GAME_MAP_START_Y, 8);
    if(GameState == GameSplashScreen || GameState == GameStartMenu || GameState == GameExit || currPlayer == NULL)
    //if(GameState != GameRunning)//δ������Ϸ����ʾĬ����Ϸ��ͼ
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
                SetColor(13, 15);//�������ڵ�ǰ��ͼ
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
    //����Ϣ����ʾ��ͼ����
    ClearByCoord(MARGIN_X, GAME_MSG_START_Y, 7);
    //char * martialIntro = NULL;//���ɽ���
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
    for(i = 0; i < 8; i++)//��Ϣ����8��
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
    if(currMartial == NULL){//�����ǰ���겻��ĳ�����ɵ��ܶ�

        SetPosition(MARGIN_X + 20, GAME_MSG_START_Y);
        printf("��ǰ���ڵأ�<%s>", mapArray[currPlayer->currCoord.Y][currPlayer->currCoord.X].name);
        SetPosition(MARGIN_X + 10, GAME_MSG_START_Y + 2);
        char * desc = mapArray[currPlayer->currCoord.Y][currPlayer->currCoord.X].desc;
        int descLen = strlen(desc);
        int k = 0;
        for(k = 0; k < descLen; k++)
        {
            if(k != 0 && k % 50 == 0)//����ÿ�д�ӡ����������
                SetPosition(MARGIN_X + 10, GAME_MSG_START_Y + 2 + k / 50);
            printf("%c", desc[k]);
        }
    }
    else
    {
        SetPosition(MARGIN_X + 15, GAME_MSG_START_Y);
        printf("<%s> -- %s �ܶ�", Maps[y][x], currMartial->name);
        SetPosition(MARGIN_X + 5, GAME_MSG_START_Y + 2);
        char * desc = currMartial->description;
        int descLen = strlen(desc);
        int k = 0;
        for(k = 0; k < descLen; k++)
        {
            if(k != 0 && k % 70 == 0)//����ÿ�д�ӡ����������
                SetPosition(MARGIN_X + 5, GAME_MSG_START_Y + 2 + k / 70);
            printf("%c", desc[k]);
        }
    }

}
void ShowMenu()
{
    //�˵������9��
    SetPosition(MARGIN_X, GAME_MENU_START_Y - 1);
    printf("%s", GAME_SEP);
    ClearByCoord(MARGIN_X, GAME_MENU_START_Y, 9);
    if(GameState == GameExit) return;//�����Ϸ�Ѵ����˳�״̬���Ͳ���Ҫ����ʾ�˵���
    SetPosition(MARGIN_X, GAME_MENU_START_Y);
    printf("��Ϸ�˵���");
    if(GameState == GameSplashScreen || GameState == GameStartMenu)
    {
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 1);
        printf("1������һع飨��¼��");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 2);
        printf("2������Ҽ��루ע�ᣩ");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 3);
        printf("3���˳���Ϸ");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 4);
        printf("��ѡ��");
    }
    else
    {
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 1);
        printf("1����������");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 2);
        printf("2��̽����Σ���֣�");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 3);
        printf("3�����ܶ�");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 4);
        printf("4������װ��");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 5);
        printf("5����Ŀ����������ɣ�");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 6);
        printf("6������һ�Σ�����ɣ�");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 7);
        printf("7���˳���Ϸ");
        SetPosition(MARGIN_X, GAME_MENU_START_Y + 8);
        printf("�������ķ����ƶ���");
    }
}

void ShowLogin()
{
    ClearByCoord(MARGIN_X, GAME_MSG_START_Y, 7);
    ClearByCoord(MARGIN_X, GAME_MENU_START_Y-1, 10);//�������Ĳ˵�
    char nickName[50];
    char password[50];
    int i = 0;
    int isSuccess = 0;
    //����Ϣ��ʾ�������û���������
    do{
        SetPosition(MARGIN_X, GAME_MSG_START_Y + 1);
        printf("�����������ǳƣ�");
        scanf("%s", nickName);
        SetPosition(MARGIN_X, GAME_MSG_START_Y + 2);
        printf("�������������룺");
        i = 0;
        while((password[i++] = getch()) != '\r');
        password[--i] = '\0';
        //��֤�û���������
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
            printf("�����������û�������");
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
        printf("����������Ϊ����������תս������Ϸ�����ɣ�");
        system("pause");
        //getch();//���û��������
        GameState = GameSplashScreen;//���û�������Ϸ��ӭ����
        return;
    }
    //ִ��ע��
    int i = 0, choice;
    char password[50];
    printf("���������ע����Ϣ��");
    SetPosition(MARGIN_X, GAME_MSG_START_Y + 1);
    printf("�����ǳƣ�");
    scanf("%s", players[RegistedPlayerCount].name);
    SetPosition(MARGIN_X, GAME_MSG_START_Y + 2);
    printf("���룺");
    while((password[i++] = getch()) != '\r');
    password[--i] = '\0';
    strcpy(players[RegistedPlayerCount].pass, password);
    SetPosition(MARGIN_X, GAME_MSG_START_Y + 3);
    printf("��ѡ�����ɣ�");
    SetPosition(MARGIN_X + 3, GAME_MSG_START_Y + 4);
    for(i = 0; i < 20; i++)
    {
        printf("%-2d.%-12s", i + 1, martials[i].name);
        if((i + 1) % 5 == 0)
            SetPosition(MARGIN_X + 3, GAME_MSG_START_Y + i / 5  + 5);
    }
    scanf("%d", &choice);//ʡ����֤����������1-20֮�������
    players[RegistedPlayerCount].martial = martials[choice - 1];
    players[RegistedPlayerCount].life = 100;
    players[RegistedPlayerCount].mp = 100;
    //���Ĭ�ϳ������ܶ�����
    players[RegistedPlayerCount].currCoord = martials[choice - 1].hqCoord;
    players[RegistedPlayerCount].exp = 0;
    players[RegistedPlayerCount].gold = 1000;
    players[RegistedPlayerCount].id = RegistedPlayerCount + 1;
    players[RegistedPlayerCount].weapon = props[0];
    players[RegistedPlayerCount].armor = props[9];

    currPlayer = &players[RegistedPlayerCount];
    RegistedPlayerCount++;
    //ע����Ϻ���ʾ�����Ϣ
    //ClearByCoord(MARGIN_X, GAME_MENU_START_Y, 9);
    SetPosition(MARGIN_X + 3, GAME_MSG_START_Y + 9);
    printf("ע��ɹ���");
    system("pause");
    GameState = GameRunning;
}

void ShowGameRunning()
{
    //ShowWelcome();
    //ShowMap();
    //��ʾ���˵�
    //ShowMenu();
}
void ShowPlayerInfo()
{
    ClearByCoord(MARGIN_X, GAME_MSG_START_Y, 7);
    SetPosition(MARGIN_X, GAME_MSG_START_Y);
    int i, j;
    for(i = 0; i < 8; i++)//��Ϣ����8��
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
    printf("��������-������%s���ĸ����������£�", currPlayer->name);
    SetPosition(MARGIN_X  + 8, GAME_MSG_START_Y + 1);
    printf("��ţ�%d\t������%s\t����%d\t\t����ֵ��%d", currPlayer->id, currPlayer->name, currPlayer->level, currPlayer->exp);
    SetPosition(MARGIN_X  + 8, GAME_MSG_START_Y + 2);
    printf("���ɣ�%s\tH  P��%d\t������%d\t��ң�%d", currPlayer->martial.name, currPlayer->hp, currPlayer->mp, currPlayer->gold);
    SetPosition(MARGIN_X  + 8, GAME_MSG_START_Y + 3);
    printf("������%s(%d��/����%d)\t", currPlayer->weapon.name, currPlayer->weapon.level, currPlayer->weapon.attack);
    printf("���ߣ�%s(%d��/����%d)\t", currPlayer->armor.name, currPlayer->armor.level, currPlayer->armor.defense);
    SetPosition(MARGIN_X  + 8, GAME_MSG_START_Y + 4);
    printf("-------------------    ������Ϣ��    -----------------------");

    if(currPlayer->bag.propCount == 0)
    {
        SetPosition(MARGIN_X  + 18, GAME_MSG_START_Y + 6);
        printf("��ǰ�����յ����ģ����߽���ҪС��Ŷ0^0");
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
    printf("�����������������");
    getch();
}
void ShowMonster()
{

    int SEP = 10;
    int i;
    //��Ӧ9������ļ�����
    char * levelNames[9] = {"���δ��", "����é®", "��ͨƤë", "����ſ�", "����С��", "�������", "�������", "�����޵�", "���˺�һ"};
    //�����������飬�ҵ����и����������ͬ�Ĺ���
    int monsterCount = sizeof(monsters)/ sizeof(Monster);
    int monsterIndex[9];//���9������
    int currCount = 0;//��ǰ��ͼ�Ĺ�������
    int choice;
    do{
        currCount = 0;
        ClearByCoord(MARGIN_X, GAME_MSG_START_Y, 7);
        ClearByCoord(MARGIN_X, GAME_MSG_END_Y + 1, 9);
        //����궨λ����Ϣ��ʾ���Ŀ�ʼ
        SetPosition(MARGIN_X + 20, GAME_MSG_START_Y);
        printf("��ǰ��ͼ�Ĺ��");
        SetPosition(MARGIN_X, 14);
        for(i = 0; i < monsterCount; i++)
        {
            if(currPlayer->currCoord.X == monsters[i].mCoord.X && currPlayer->currCoord.Y == monsters[i].mCoord.Y && monsters[i].state != 0)
            {
                //��ʾ����
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
            printf("���Ǽ�����������ʺ�ĵط�������û�������ˣ����¸���ͼȥ�ɡ�");
            SetPosition(MARGIN_X + SEP, GAME_MSG_END_Y + 2);
            printf("�����������������");
            getch();
            return;
        }


    //do{
        SetPosition(MARGIN_X, 18);
        printf("��ѡ��Ҫ�����Ķ���(��0����):");
        scanf("%d", &choice);
        if(choice < 0 || choice > currCount){//�û��������ʱ��ձ���
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
        Fight(&monsters[monsterIndex[choice-1]]); //���ù�����������ʾս�����
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
        //���ÿ�ι�����Ҫ�ķ�10*������������ֵ
        monster->hp -= currPlayer->weapon.attack;
        currPlayer->hp -= monster->att;

        currPlayer->mp -= 10 * currPlayer->weapon.attack;
        if(currPlayer->mp <= 0)
        {
            SetPosition(MARGIN_X, 18);
            printf("                                                           ");
            SetPosition(MARGIN_X, 18);
            printf("��ǰ������͸֧����������Ҫ����");
            return;
        }
        SetPosition(MARGIN_X, 18);
        printf("                                          ");
        SetPosition(MARGIN_X, 18);
        printf("ս����%d�֣�%sHP-%d\t%sHP-%d",currPlayer->weapon.attack, currPlayer->name, currPlayer->hp, monster->name, monster->hp);
        count++;
        usleep(1000 * 100);//100����
    }while(currPlayer->hp > 0 && monster->hp > 0 && currPlayer->mp > 0);
    SetPosition(MARGIN_X, 18);
    printf("                                          ");
    SetPosition(MARGIN_X, 18);
    if(currPlayer->hp <= 0)
    {
        printf("������Ѷ��������%s�����롶%s����ս����׳��������", currPlayer->name, monster->name);
        SetPosition(MARGIN_X + 20, GAME_MSG_END_Y + 2);
            printf("�����������������");
        getch();
        GameState = GameRunning;
        return;
    }
    currPlayer->exp += monster->exp;
    currPlayer->gold += monster->maxMoney;
    monster->state = 0;
    printf("��������ս����%s����ɱ�������%d���飬%d��ң�", monster->name, monster->exp, monster->maxMoney);
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

    //����Ϣ����ӡ�̵����Ʒ
    int propCount = sizeof(props) / sizeof(Prop) >= 15 ? 15 : sizeof(props) / sizeof(Prop);
    int i;
    SetPosition(MARGIN_X, 12);
    printf("��ӭ���롶%s�����ߵ꣺", Maps[currPlayer->currCoord.Y][currPlayer->currCoord.X]);
    SetPosition(MARGIN_X + 4, 14);
    for(i = 0; i < propCount; i++)
    {
        if(i % 3 == 0)
        {
            SetPosition(MARGIN_X + 4, 14 + i / 3);
        }
        printf("%-3d.%-10s(%-2d)%-4c", props[i].id, props[i].name, props[i].stock, ' ');
    }
    //�û�ѡ����н���
    SetPosition(MARGIN_X, 20);
    printf("�����빺��ĵ��߱�ţ�(��0�˳�)");
    int tradeId;
    scanf("%d", &tradeId);
    if(tradeId == 0)
    {
        //ShowMap();
        GameState = GameRunning;
        return;
    }
    //�����жϣ��۳���漰��ҽ�Ǯ
    //������ұ���
    SetPosition(MARGIN_X, 18);
    Trade(currPlayer, tradeId);
    ShowTrade();
}
int Trade(Player *player, int propId)
{
    int i;
    //��Ҫ�жϣ���Ʒ�Ŀ�棬�������������ұ����ռ乻����
    Prop *tradeProp = NULL;//Ҫ�������Ʒָ��
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
        printf("��Ʒ�������������������룡");
        system("pause");
        return 0;
    }
    if(tradeProp->stock <= 0)
    {
        printf("�����Ҷ�û���������̵궼���������");
        system("pause");
        return 0;
    }
    if(player->gold < tradeProp->price)
    {
        printf("Ǯ�����Ǳ�ģ�������ǿ�Ǯ����ᣡ��");
        system("pause");
        return 0;
    }
    if(player->bag.propCount >= player->bag.propMax && player->bag.propCount != 0)
    {
        printf("��������������ʧ�ܣ�");
        system("pause");
        return 0;
    }
    //���㽻��������ִ�н��׵�ҵ�����
    //1����Ʒ���-1
    tradeProp->stock--;
    //2����ҽ��-��Ʒ����
    player->gold -= tradeProp->price;
    //*3����ұ�����������
    //�ж���ұ������Ƿ����и���Ʒ

    //����и���Ʒ�������еĸ���Ʒ����+1
    for(i = 0; i < player->bag.propCount; i++)
    {
        //���Ҫ�������Ʒid �� �����е�ĳ����Ʒid��ͬ
        if(propId == player->bag.props[i].id)
        {
            player->bag.props[i].stock++;
            break;
        }
    }
    if(i == player->bag.propCount)//���û�и���Ʒ������Ʒ��ӵ������м���
    {
        //�򱳰��д���һ����Ʒ-����һ��Ҫ���׵���Ʒ��Ϣ��������
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
    PrintString("��Ϸ���˳�����ӭ������");
}

