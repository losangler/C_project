#ifndef GZDEMO_H_INCLUDED
#define GZDEMO_H_INCLUDED
//ʹ�ú���������С�������ɼǡ��еĻ�������¼�뼰������
//�������ԣ����������������������¡�����
#include <iostream>
using namespace std;

//��������
void input(int [], int);
void print(const int *, int);
//�������ɾ�����޸�����Ԫ��


//����ʵ��
void input(int values[], int len)
{
    if(len > 5)
    {
        cout << "���鳤��ֻ����5���ڣ�����"<< endl;
        return;//�˳�����ֵΪvoid�ĺ���
    }
    string valueNames[] = {"����", "����", "����", "����", "����"};
    for(int i = 0; i < len; i++)
    {
        cout << valueNames[i] << "��" ;
        cin >> values[i];
    }
}

void print(const int * values, int len)
{
    string valueNames[] = {"����", "����", "����", "����", "����"};
    for(int i = 0; i < len; i++)
    {
        cout << valueNames[i] << "��" << values[i] << endl;
    }
}


#endif // GZDEMO_H_INCLUDED
