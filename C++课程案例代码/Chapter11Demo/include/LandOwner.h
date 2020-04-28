/**
 * 地主类
 * @author 老九学堂·窖头
 * @version 1.0
 * @copyright 老九学堂
 * @remarks TODO
 *
 */#ifndef LANDOWNER_H
#define LANDOWNER_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class LandOwner
{
    private:
        string m_NickName;
        string m_Sex;
        int m_Gold;
        long m_Exp;
        vector<int> packCards;      //默认的一副牌，从1-54
        vector<int> surplusCards;   //摸牌后，剩余的牌
        vector<int> currCards;      //当前玩家的手牌数组
        bool isContains(int);       //剩余牌集合中是否包含cardNum这个牌面
        void deleteCard(vector<int>&, int); //删除集合中的数字
        string getColor(int);       //获得牌的花色
        string getValue(int);       //获得牌面
    public:
        LandOwner();
        LandOwner(string);
        LandOwner(string, string, int, long);
        ~LandOwner();

        string GetNickName() { return m_NickName; }
        void SetNickName(string val) { m_NickName = val; }
        string GetSex() { return m_Sex; }
        void SetSex(string val) { m_Sex = val; }
        int GetGold() { return m_Gold; }
        void SetGold(int val) { m_Gold = val; }
        long GetExp() { return m_Exp; }
        void SetExp(long val) { m_Exp = val; }


        void TouchCard(int);    //摸牌
        void ShowInfo();
        void InitCards();       //初始化packCards, surplusCards, currCards
        void ShowCards(const vector<int>&);       //显示集合中的牌面

};

#endif // LANDOWNER_H
