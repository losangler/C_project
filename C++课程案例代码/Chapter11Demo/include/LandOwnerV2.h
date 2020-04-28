/**
 *
 * @author 老九学堂·窖头
 * @version 1.0
 * @copyright 老九学堂
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
        LandOwnerV2();      //构造函数的声明
        ~LandOwnerV2();     //析构函数的声明

        void TouchCard(int);  //声明摸牌方法
        void ShowScore();     //声明的显示积分方法






};

#endif // LANDOWNERV2_H
