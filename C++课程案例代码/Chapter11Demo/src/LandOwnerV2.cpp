#include "LandOwnerV2.h"

LandOwnerV2::LandOwnerV2()
{
    //ctor
}

//实现摸牌方法
void LandOwnerV2::TouchCard(int cardCount)
{
    cout << name << "摸了" << cardCount<< "张牌" << endl;
}

LandOwnerV2::~LandOwnerV2()
{
    //dtor
}
