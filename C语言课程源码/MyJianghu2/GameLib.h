#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED
/***************************************************
 * �ļ�����GameLib.h
 * ��  ����������Ϸ�г��õĿ���̨����
 * �����ˣ��Ͼ�ѧ�á���ͷ
 * ��  �ڣ�2016-11-10
 * ��  ����1.0
 * ��  ����http://www.xuetang9.com
 * �ٷ�QQ��614940318���Ͼž���
 *
 **************************************************/
#include <windows.h>
#include <time.h>

/* ���ÿ���̨���ڱ��� */
void SetTitle(char * title);
/* 0-��ɫ, 1-��ɫ,   2-��ɫ,      3-ǳ��ɫ,     4-��ɫ,   5-��ɫ,   6-��ɫ,   7-��ɫ,
 * 8-��ɫ, 9-����ɫ, 10-����ɫ,   11-��ǳ��ɫ   12-����ɫ 13-����ɫ 14-����ɫ 15-����ɫ
 */
void SetColor(int, int);

/* ���ݿ�����ÿ���̨���ڵĴ�С */
void SetConsoleWindowSize();

/* ���ù���x��y����-���������� */
void SetPosition(int x, int y);

/* ��̬��ӡ������Ϣ */
void PrintString(const char * msgString);

/* ����fgets, ��ȡ��Ӧ���ȵ��ַ���*/
void Read(char * Str, int BufferSize);

/* �õ��û�����ļ� */
int GetKey();

/* �õ���ǰ����Ϸʱ�䣬����������ʱ���� */
char * GetGameTime();
/*
void Clear(int X, int Y);
void ClearMessage();*/

/* ����ʼ���꿪ʼ����rowCount�� */
void ClearByCoord(int x, int y, int rowCount);

#endif // GAMELIB_H_INCLUDED
