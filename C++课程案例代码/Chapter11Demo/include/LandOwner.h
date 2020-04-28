/**
 * ������
 * @author �Ͼ�ѧ�á���ͷ
 * @version 1.0
 * @copyright �Ͼ�ѧ��
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
        vector<int> packCards;      //Ĭ�ϵ�һ���ƣ���1-54
        vector<int> surplusCards;   //���ƺ�ʣ�����
        vector<int> currCards;      //��ǰ��ҵ���������
        bool isContains(int);       //ʣ���Ƽ������Ƿ����cardNum�������
        void deleteCard(vector<int>&, int); //ɾ�������е�����
        string getColor(int);       //����ƵĻ�ɫ
        string getValue(int);       //�������
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


        void TouchCard(int);    //����
        void ShowInfo();
        void InitCards();       //��ʼ��packCards, surplusCards, currCards
        void ShowCards(const vector<int>&);       //��ʾ�����е�����

};

#endif // LANDOWNER_H
