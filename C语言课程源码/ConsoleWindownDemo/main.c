#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

HANDLE winHandle;
//��ʾ��Ӱ��
void ShadowWindownLine(char *str);
//���Ʊ߿�
void DrawBox(int bSigle, SMALL_RECT rect);


int main()
{

    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //���ô���ҳ437  936
    SetConsoleOutputCP(936);
    ShadowWindownLine("��Ҫ�κ���Ƶ������������Դ������Ͼž� QQ��614940318");
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
    //������ʾ���ڴ�С��λ��
    rect.Left = (bcInfo.dwSize.X - len) / 2 - 2;
    rect.Top = 8;
    rect.Right = rect.Left + len + 4;
    rect.Bottom = rect.Top + 4;
    att0 = BACKGROUND_INTENSITY;    //��Ӱ����
    att1 = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE;
    attText = FOREGROUND_RED | FOREGROUND_INTENSITY;
    //������ӰȻ�����
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

    //�ָ�ԭ��������
    SetConsoleTextAttribute(winHandle, bcInfo.wAttributes);
}
/*
    //�豸���-ͨ��������ʶWindows��Դ(�˵������ڡ�ͼ��)���豸�ȶ���
    //��ΪWindowsϵͳ�ڲ��������ֵ��ʹ��
    HANDLE winHandle;
    //�洢������Ϣ
    CONSOLE_SCREEN_BUFFER_INFO screenBuffInfo;
    //��ȡ��׼����豸���
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //��ȡ������Ϣ
    GetConsoleScreenBufferInfo(winHandle, &screenBuffInfo);
    printf("\n���Բ��Բ��Բ���\n���Բ���\n����\n");
    _getch();
    COORD start = {80, 25};
    FillConsoleOutputCharacter(winHandle, ' ', screenBuffInfo.dwSize.X * screenBuffInfo.dwSize.Y, start, NULL);
    CloseHandle(winHandle);
    */
