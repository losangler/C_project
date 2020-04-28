/**
 *
 * @author �Ͼ�ѧ�á���ͷ
 * @version 1.0
 * @copyright �Ͼ�ѧ��
 * @remarks ʹ�ù����Զ�����Get/Set����,��ʾ���캯��
 *
 */#ifndef LANDOWNERV4_H
#define LANDOWNERV4_H
#include <iostream>
#include <memory.h>

using namespace std;

class LandOwnerV4
{
    public:
        LandOwnerV4();
        //LandOwnerV4() = default;
        virtual ~LandOwnerV4();

        long Getscore() { return _score; }
        void Setscore(long val)
        {
            if(val < 0) _score = 0;
                        _score = val;
        }
        string Getname() { return _name; }
        void Setname(string name) { _name = name; }
        //int Getcards[20]() { return cards[20]; }
        //void Setcards[20](int val) { cards[20] = val; }

    protected:

    private:
        long _score;
        string _name;
        int cards[20];
};

#endif // LANDOWNERV4_H
