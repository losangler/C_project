#include "LandOwnerV4.h"

LandOwnerV4::LandOwnerV4()
{
    //一般使用构造函数进行成员变量的初始化
    _name = "默认地主";
    _score = 0;
    //将用户的手牌数组初始化为0
    memset(cards, 0, sizeof(cards));
    cout << "LandOwner4的无参构造函数(默认构造)被调用！" << endl;
    cout << "初始化的结果如下：" << endl;
    cout << "名称：" << _name << endl;
    cout << "积分：" << _score << endl;
    cout << "手牌数组：";
    for(int i = 0; i < sizeof(cards) / sizeof(cards[0]); i++){
        cout << cards[i] << ", ";
    }
    cout << endl;

}

LandOwnerV4::~LandOwnerV4()
{
    //dtor
}
