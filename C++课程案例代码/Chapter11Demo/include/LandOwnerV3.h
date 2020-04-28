/**
 *
 * @author �Ͼ�ѧ�á���ͷ
 * @version 1.0
 * @copyright �Ͼ�ѧ��
 * @remarks ������ʾ��װ�Ļ�������
 *
 */#ifndef LANDOWNERV3_H
#define LANDOWNERV3_H
#include <iostream>

using namespace std;

class LandOwnerV3
{
    //ʡ����private
    long score;         //������ֱ���ֵΪ��������ķ���������Ա����score�������ز���װ
    string name;
    int cards[20];
    public:


        LandOwnerV3();
        ~LandOwnerV3();

        void ShowScore();

        //ʹ�÷���/����ʵ�ֶԳ�Ա�����ķ�װGet/Set����
        void SetScore(long lScore){
            if(lScore < 0){
                //�������Ļ����ǷǷ��������ô����Ĭ��Ϊ0
                score = 0;
            }else
            {
                //����Ϊ����ʱ���Ž��и�ֵ���� - �����ͨ�������жϣ���װ��score�ĸ�ֵ����
                score = lScore;
            }
        }
        void SetName(string lName){
            name = lName;
        }
        string GetName(){
            return name;
        }

};

#endif // LANDOWNERV3_H
