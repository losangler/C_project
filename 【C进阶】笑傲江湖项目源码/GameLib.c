/***************************************************
 * �ļ�����GameLib.c
 * ��  ����GameLib.h��ʵ���ļ�
 * �����ˣ��Ͼ�ѧ�á���ͷ
 * ��  �ڣ�2016-11-10
 * ��  ����1.0
 * ��  ����http://www.xuetang9.com
 * �ٷ�QQ��614940318���Ͼž���
 *
 **************************************************/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include "GameLib.h"

#define WIN_SIZE_WIDTH 120
#define WIN_SIZE_HEIGHT 35
#define GAME_WIDTH 78    //��Ϸ�����Ĭ�Ͽ�ȣ���λ���ַ���

/* ���ÿ���̨���ڱ��� */
void SetTitle(char * title){
    SetConsoleTitle(title);
}
/* 0-��ɫ, 1-��ɫ,   2-��ɫ,      3-ǳ��ɫ,     4-��ɫ,   5-��ɫ,   6-��ɫ,   7-��ɫ,
 * 8-��ɫ, 9-����ɫ, 10-����ɫ,   11-��ǳ��ɫ   12-����ɫ 13-����ɫ 14-����ɫ 15-����ɫ*/
void SetColor(int ForeColor, int BackGroundColor){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);                    //��ȡ��ǰ���ھ��
    SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//������ɫ
    //CloseHandle(handle);
}
/* ���ݿ�����ÿ���̨���ڵĴ�С */
void SetConsoleWindowSize(){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ÿ���̨���ڵĻ�������С
	COORD size = {WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT};
	SetConsoleScreenBufferSize(handle, size);
	//���ÿ���̨���ڴ�С,��������ǻ�������С-1
	SMALL_RECT rect = {0, 0, WIN_SIZE_WIDTH - 1, WIN_SIZE_HEIGHT - 1};
	SetConsoleWindowInfo(handle, 1, &rect);
	//CloseHandle(handle);
}
void SetPosition(int x, int y){
    COORD cursorPosition;   //��������
    HANDLE handle;          //��ǰ���ھ��
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPosition.X = x;   //����x��y����
    cursorPosition.Y = y;
    SetConsoleCursorPosition(handle, cursorPosition);
    //CloseHandle(handle);
}
void PrintString(const char * msgString){
    int length = strlen(msgString);
    int i = 0;
    for(; i < length; i++)
    {
        char tempChar = msgString[i];
        printf("%c", tempChar);
        usleep(1000 * 20);//20����
        fflush(stdout);
    }
}
void Read(char * Buffer, int BufferSize){
    DWORD Read;
    HANDLE handle;          //��ǰ���ھ��
    handle = GetStdHandle(STD_INPUT_HANDLE);
    ReadConsole(handle, Buffer, BufferSize, &Read, NULL);
    //CloseHandle(handle);
}
int GetKey()
{
    HANDLE handle;          //��ǰ���ھ��
    handle = GetStdHandle(STD_INPUT_HANDLE);
    DWORD Read;
    INPUT_RECORD Event;
    //�õ�����̨������
    ReadConsoleInput(handle, &Event, 1, &Read);
    //��������¼���һ�������¼����ͽ����жϣ����ذ��¼����������
    if(Event.EventType == KEY_EVENT)
    {
        if(Event.Event.KeyEvent.bKeyDown)//����ֵΪtrue����ʾ�м�������
        {
             return Event.Event.KeyEvent.wVirtualKeyCode;//���ذ��¼����������
        }
    }
    return 0;
}
char * GetGameTime(){

    time_t rawtime;
    struct tm * timeinfo;
    static char buffer [128];

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer,sizeof(buffer),"%Y-%m-%d %H:%M:%S", timeinfo);
    return buffer;
}
/*
void Clear(int X, int Y){
    DWORD written;
    COORD start;    //��ʼ����
    HANDLE handle;  //��ǰ���ھ��
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    start.X = X;
    start.Y = Y;
    FillConsoleOutputAttribute(handle, 15, 80*25, start, &written);
    FillConsoleOutputCharacter(handle, ' ', 80*25, start, &written);
    SetConsoleCursorPosition(handle, start);
}
void ClearMessage(){
    //�����Ϣ��ʾ��
    COORD coordStart = {0, 12};
    DWORD written;
    HANDLE handle;  //��ǰ���ھ��
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    FillConsoleOutputAttribute(handle, 15, 120*7, coordStart, &written);
    FillConsoleOutputCharacter(handle, ' ', 120*7, coordStart, &written);
    SetConsoleCursorPosition(handle, coordStart);
}*/
/**
 * ����ʼ���꿪ʼ����rowCount��,ÿ�����GAME_WIDTH(78)���ַ�
 */
void ClearByCoord(int x, int y, int rowCount)
{
    COORD coordStart = {x, y};
    int i = 0;
    DWORD written;
    HANDLE handle;                              //��ǰ���ھ��
    CONSOLE_SCREEN_BUFFER_INFO bInfo;           //������Ϣ�ṹ
    handle = GetStdHandle(STD_OUTPUT_HANDLE);   //��ñ�׼����豸���
    GetConsoleScreenBufferInfo(handle, &bInfo);  //��ô�����Ϣ

    for(i = 0; i < rowCount; i++)
    {
        SetPosition(coordStart.X, coordStart.Y);
        FillConsoleOutputCharacter(handle, ' ', GAME_WIDTH, coordStart, &written);
        coordStart.Y++;
    }



    //CloseHandle(handle);
    //SetConsoleCursorPosition(handle, coordStart);
    /*
    int i, j;
    x = 0;
    SetPosition(x, y);
    //SetConsoleCursorPosition(handle, coordStart);
    for(i = 0; i < WIN_SIZE_WIDTH * rowCount; i++)
    {
        printf(" ");
    }*/
}
