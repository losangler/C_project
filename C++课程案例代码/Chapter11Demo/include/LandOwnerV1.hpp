/**
 *
 * @author �Ͼ�ѧ�á���ͷ
 * @version 1.0
 * @copyright �Ͼ�ѧ��
 * @remarks TODO
 *
 */#ifndef LANDOWNERV1_H
#define LANDOWNERV1_H
#include <iostream>

using namespace std;
/**
 *  .hpp�ļ�һ�����ʵ�ֵ���������,ͨ������ģ��������������ʵ�ֹ�������
 * ���飺ֻҪ���Ǵ�ģ�壬һ��ʹ��.h��Ϊͷ�ļ���׺��ʹ��.cpp�ļ���Ϊ������ʵ���ļ�
 */
class LandOwnerV1
{
    private:
        string name;        //����������
        long score;         //�����Ļ���
        int cards[20];      //��������������
    public:
        LandOwnerV1() {}    //ʵ����Ĭ�Ϲ��캯��
        ~LandOwnerV1() {}
        inline void TouchCard(int cardCount)
        {
            //��ʱʡ�Ժ�����ʵ��
            cout << name << "����" << cardCount<< "����" << endl;
        }
        void ShowScore(){
            cout << name << "��ǰ�Ļ���Ϊ��" << score << endl;
        }
};

#endif // LANDOWNERV1_H
