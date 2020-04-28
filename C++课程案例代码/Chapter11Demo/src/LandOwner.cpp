#include "LandOwner.h"

LandOwner::LandOwner()
{
    SetNickName("默认地主");
    SetSex("保密");
    SetExp(0);
    SetGold(1000);
    cout << "LandOwner()" << endl;
    InitCards();
}

LandOwner::LandOwner(string nickName): m_NickName(nickName)
{
    SetSex("保密");
    SetExp(0);
    SetGold(1000);
    cout << "LandOwner(string nickName)" << endl;
    InitCards();
    //测试isContains
    cout << "测试isContains：" << isContains(13) << endl;
}

LandOwner::LandOwner(string nickName, string sex, int gold, long exp):m_NickName(nickName), m_Sex(sex), m_Gold(gold), m_Exp(exp)
{
    cout << "LandOwner(string nickName, string sex, int gold, long exp)" << endl;
    InitCards();
}

void LandOwner::ShowInfo()
{
    cout << "昵称：" << GetNickName() << endl;
    cout << "性别：" << GetSex() << endl;
    cout << "金币：" << GetGold() << endl;
    cout << "经验：" << GetExp() << endl;
}

void LandOwner::InitCards()//初始化packCards, surplusCards, currCards
{
    //生成默认的一副扑克牌
    for(int i = 0; i < 54; i++){
        packCards.push_back(i + 1);
        surplusCards.push_back(packCards.at(i));
    }
    currCards.clear();

    ShowCards(packCards);
}

void LandOwner::ShowCards(const vector<int>& cards)
{
    /*C语言的习惯
    for(int i = 0; i < cards.size(); i++){
        cout << cards[i] << ", ";
    }
    cout << endl;*/
    /*使用迭代器
    for(vector<int>::const_iterator iter = cards.begin(); iter != cards.end(); iter++){
        cout << *iter << ", ";
    }
    cout << endl;*/
    /* 使用C++11的类型推断
    for(auto iter = cards.begin(); iter != cards.end(); iter++){
        cout << *iter << ", ";
    }
    cout << endl;*/
    //for区间遍历 - C++11
    for(auto card : cards){
        cout << card << ":" << getColor(card) << "-" << getValue(card) << ", ";
    }
    cout << endl;
    //使用算法的方式，将容器的内容复制到cout绑定的迭代器中
    //#include <iterator>       #include <algorithm>
    //copy(cards.cbegin(), cards.cend(), ostream_iterator<int>(cout, ", "));
    //cout << endl;
}

void LandOwner::TouchCard(int cardCount)
{
    srand(time(NULL));  //时间种子
    //随机生成一张剩余牌集合中有的牌，添加到currCards集合中，从surplusCards中删除这张牌
    for(int i = 0; i < cardCount; i++)
    {
        int randIndex = rand() % 54;    //0-53之间的随机数字
        //判断：随机生成的这张牌是否在剩余牌集合中
        if(isContains(packCards[randIndex])){
            currCards.push_back(packCards[randIndex]);  //将模的牌放入当前手牌数组
            //在剩余牌集合中删除这张牌
            deleteCard(surplusCards, packCards[randIndex]);
        }else{
            i--;//重新摸牌
        }
    }

    cout << "<地主摸牌> - 当前手牌如下：" << endl;
    ShowCards(currCards);
    cout << "<地主摸牌后> - 剩余牌面如下：" << endl;
    ShowCards(surplusCards);
}

bool LandOwner::isContains(int cardNum)
{
    //使用算法查找
    vector<int>::iterator iter = find(surplusCards.begin(), surplusCards.end(), cardNum);
    //if(iter == surplusCards.end()){
    //    return false;
    //}
    //return true;
    return iter != surplusCards.end();
    /*  普通青年的做法
    for(int i = 0; i < surplusCards.size(); i++){
        if(surplusCards[i] == cardNum){
            return true;
        }
    }
    return false;*/
}

void LandOwner::deleteCard(vector<int>& cardVec, int card)
{
    /*普通青年做法：
    for(auto iter = cardVec.begin(); iter != cardVec.end(); ){
        if(*iter == card){//如果找到，就删除元素
            iter = cardVec.erase(card); //这里的返回值指向已删除元素的下一元素
        }else{
            ++iter;//继续判断下一个元素是否相同
        }
    }*/
    //使用算法删除
    auto iter = find(cardVec.begin(), cardVec.end(), card);
    if(iter != cardVec.end()){
        cardVec.erase(iter);
    }
}

string LandOwner::getColor(int card)//注意这里，card不是下标
{
    if(card == 53) return "小王";
    if(card == 54) return "大王";
    string colors[] = {
        "黑桃", "红心", "方块", "梅花"
    };
    return colors[(card - 1) / 13];
}

string LandOwner::getValue(int card)
{
    if(card == 53) return "Black Joker";
    if(card == 54) return "Red Joker";
    string values[] = {
        "A", "1", "2", "3", "4", "5", "6", "7", "8",
        "9", "10", "J", "Q", "K"
    };
    return values[(card - 1) % 13];
}

LandOwner::~LandOwner()
{
    cout << GetNickName() << "被释放！" << endl;
}
