#include "LandOwnerV4.h"

LandOwnerV4::LandOwnerV4()
{
    //һ��ʹ�ù��캯�����г�Ա�����ĳ�ʼ��
    _name = "Ĭ�ϵ���";
    _score = 0;
    //���û������������ʼ��Ϊ0
    memset(cards, 0, sizeof(cards));
    cout << "LandOwner4���޲ι��캯��(Ĭ�Ϲ���)�����ã�" << endl;
    cout << "��ʼ���Ľ�����£�" << endl;
    cout << "���ƣ�" << _name << endl;
    cout << "���֣�" << _score << endl;
    cout << "�������飺";
    for(int i = 0; i < sizeof(cards) / sizeof(cards[0]); i++){
        cout << cards[i] << ", ";
    }
    cout << endl;

}

LandOwnerV4::~LandOwnerV4()
{
    //dtor
}
