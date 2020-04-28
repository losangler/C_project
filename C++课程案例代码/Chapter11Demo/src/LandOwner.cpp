#include "LandOwner.h"

LandOwner::LandOwner()
{
    SetNickName("Ĭ�ϵ���");
    SetSex("����");
    SetExp(0);
    SetGold(1000);
    cout << "LandOwner()" << endl;
    InitCards();
}

LandOwner::LandOwner(string nickName): m_NickName(nickName)
{
    SetSex("����");
    SetExp(0);
    SetGold(1000);
    cout << "LandOwner(string nickName)" << endl;
    InitCards();
    //����isContains
    cout << "����isContains��" << isContains(13) << endl;
}

LandOwner::LandOwner(string nickName, string sex, int gold, long exp):m_NickName(nickName), m_Sex(sex), m_Gold(gold), m_Exp(exp)
{
    cout << "LandOwner(string nickName, string sex, int gold, long exp)" << endl;
    InitCards();
}

void LandOwner::ShowInfo()
{
    cout << "�ǳƣ�" << GetNickName() << endl;
    cout << "�Ա�" << GetSex() << endl;
    cout << "��ң�" << GetGold() << endl;
    cout << "���飺" << GetExp() << endl;
}

void LandOwner::InitCards()//��ʼ��packCards, surplusCards, currCards
{
    //����Ĭ�ϵ�һ���˿���
    for(int i = 0; i < 54; i++){
        packCards.push_back(i + 1);
        surplusCards.push_back(packCards.at(i));
    }
    currCards.clear();

    ShowCards(packCards);
}

void LandOwner::ShowCards(const vector<int>& cards)
{
    /*C���Ե�ϰ��
    for(int i = 0; i < cards.size(); i++){
        cout << cards[i] << ", ";
    }
    cout << endl;*/
    /*ʹ�õ�����
    for(vector<int>::const_iterator iter = cards.begin(); iter != cards.end(); iter++){
        cout << *iter << ", ";
    }
    cout << endl;*/
    /* ʹ��C++11�������ƶ�
    for(auto iter = cards.begin(); iter != cards.end(); iter++){
        cout << *iter << ", ";
    }
    cout << endl;*/
    //for������� - C++11
    for(auto card : cards){
        cout << card << ":" << getColor(card) << "-" << getValue(card) << ", ";
    }
    cout << endl;
    //ʹ���㷨�ķ�ʽ�������������ݸ��Ƶ�cout�󶨵ĵ�������
    //#include <iterator>       #include <algorithm>
    //copy(cards.cbegin(), cards.cend(), ostream_iterator<int>(cout, ", "));
    //cout << endl;
}

void LandOwner::TouchCard(int cardCount)
{
    srand(time(NULL));  //ʱ������
    //�������һ��ʣ���Ƽ������е��ƣ���ӵ�currCards�����У���surplusCards��ɾ��������
    for(int i = 0; i < cardCount; i++)
    {
        int randIndex = rand() % 54;    //0-53֮����������
        //�жϣ�������ɵ��������Ƿ���ʣ���Ƽ�����
        if(isContains(packCards[randIndex])){
            currCards.push_back(packCards[randIndex]);  //��ģ���Ʒ��뵱ǰ��������
            //��ʣ���Ƽ�����ɾ��������
            deleteCard(surplusCards, packCards[randIndex]);
        }else{
            i--;//��������
        }
    }

    cout << "<��������> - ��ǰ�������£�" << endl;
    ShowCards(currCards);
    cout << "<�������ƺ�> - ʣ���������£�" << endl;
    ShowCards(surplusCards);
}

bool LandOwner::isContains(int cardNum)
{
    //ʹ���㷨����
    vector<int>::iterator iter = find(surplusCards.begin(), surplusCards.end(), cardNum);
    //if(iter == surplusCards.end()){
    //    return false;
    //}
    //return true;
    return iter != surplusCards.end();
    /*  ��ͨ���������
    for(int i = 0; i < surplusCards.size(); i++){
        if(surplusCards[i] == cardNum){
            return true;
        }
    }
    return false;*/
}

void LandOwner::deleteCard(vector<int>& cardVec, int card)
{
    /*��ͨ����������
    for(auto iter = cardVec.begin(); iter != cardVec.end(); ){
        if(*iter == card){//����ҵ�����ɾ��Ԫ��
            iter = cardVec.erase(card); //����ķ���ֵָ����ɾ��Ԫ�ص���һԪ��
        }else{
            ++iter;//�����ж���һ��Ԫ���Ƿ���ͬ
        }
    }*/
    //ʹ���㷨ɾ��
    auto iter = find(cardVec.begin(), cardVec.end(), card);
    if(iter != cardVec.end()){
        cardVec.erase(iter);
    }
}

string LandOwner::getColor(int card)//ע�����card�����±�
{
    if(card == 53) return "С��";
    if(card == 54) return "����";
    string colors[] = {
        "����", "����", "����", "÷��"
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
    cout << GetNickName() << "���ͷţ�" << endl;
}
