/**
 *
 * @author �Ͼ�ѧ�á���ͷ
 * @version 1.0
 * @copyright �Ͼ�ѧ��
 * @remarks TODO
 *
 */#ifndef LANDOWNERV2_H
#define LANDOWNERV2_H
#include <iostream>

using namespace std;

class LandOwnerV2
{
    public:
        string name;
        long score;
        int cards[20];
    public:
        LandOwnerV2();      //���캯��������
        ~LandOwnerV2();     //��������������

        void TouchCard(int);  //�������Ʒ���
        void ShowScore();     //��������ʾ���ַ���






};

#endif // LANDOWNERV2_H
