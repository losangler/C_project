/*************************************************
 * �ļ�����main.cpp
 * �����ˣ��Ͼ�ѧ�á���ͷ
 * ��  �ڣ�2017-3-16
 * ��  ����C++��һ�׶���Ŀ��С�������ɼǡ�
 * �޸��ˣ�someone
 * ��  �ڣ�someday
 * ��  ����1.0.0
 * Copyright (c) 2006-2017 xuetang9.com
 ************************************************/
 #include <iostream>
 #include <iomanip>
 #include <cstdlib>
 #include <ctime>
 #include <vector>
 #include <array>

using namespace std;

int main()
{
    /** ���׵����� */
    string value_father_name;
    /** Ů�������� */
    string value_daughter_name;
    /** Ů�����յ��·� */
    int value_birth_month = 6;
    /** Ů�����յ����� */
    int value_birth_date = 6;
    /** Ů�������� */
    string value_daughter_constell;
    /** Ů�������������Ϣ�� ���������������������¡�����*/
    array<int, 5> value_array_baseinfo;//��̬�����ڴ������
    /** ������������� */
    array<string, 5> value_array_baseinfo_names = {"����", "����", "����", "����", "����"};
    int value_daughter_gold = 500;
    /** ������ά���� */
    string constell_names[12][2] = {
        {"ɽ����", "ˮƿ��"}, //һ��
        {"ˮƿ��", "˫����"}, //����
        {"˫����", "������"}, //����
        {"������", "��ţ��"}, //����
        {"��ţ��", "˫����"}, //����
        {"˫����", "��з��"}, //����
        {"��з��", "ʨ����"}, //����
        {"ʨ����", "��Ů��"}, //����
        {"��Ů��", "�����"}, //����
        {"�����", "��Ы��"}, //ʮ��
        {"��Ы��", "������"}, //ʮһ��
        {"������", "ɽ����"}  //ʮ����
    };
    int choice, temp1, temp2, temp3;

    cout << "���׵�������";
    cin >> value_father_name;
    cout << "Ů����������" ;
    cin >> value_daughter_name;
    cout << "Ů��������(MM DD)��";
    cin >> value_birth_month >> value_birth_date;
    /** ���·ݵĿ��������� */
    int constell_dates[] {20, 19, 21, 20, 21, 22, 23, 23, 23, 24, 23, 22};
    value_daughter_constell = constell_names[value_birth_month - 1][value_birth_date / constell_dates[value_birth_month-1]];

    cout << "Ů������Ϣ��";
    cout << "������" << value_daughter_name << endl;
    cout << "���գ�1659-" << value_birth_month << "-" << value_birth_date << endl;
    cout << "������" << value_daughter_constell << endl;
    if(value_daughter_constell == "������"){
        value_array_baseinfo[0] = 80;
        value_array_baseinfo[1] = 15;
        value_array_baseinfo[2] = 15;
        value_array_baseinfo[3] = 11;
        value_array_baseinfo[4] = 21;
    }else if(value_daughter_constell == "��ţ��"){
        value_array_baseinfo[0] = 46;  value_array_baseinfo[1] = 30; value_array_baseinfo[2] = 28; value_array_baseinfo[3] = 20; value_array_baseinfo[4] = 29;
    }else if(value_daughter_constell == "˫����"){
        value_array_baseinfo[0] = 50;  value_array_baseinfo[1] = 35; value_array_baseinfo[2] = 23; value_array_baseinfo[3] = 8;  value_array_baseinfo[4] = 20;
    }else if(value_daughter_constell == "��з��"){
        value_array_baseinfo[0] = 40;  value_array_baseinfo[1] = 31; value_array_baseinfo[2] = 33; value_array_baseinfo[3] = 17; value_array_baseinfo[4] = 33;
    }else if(value_daughter_constell == "ʨ����"){
        value_array_baseinfo[0] = 85;  value_array_baseinfo[1] = 9 ; value_array_baseinfo[2] = 11; value_array_baseinfo[3] = 20; value_array_baseinfo[4] = 37;
    }else if(value_daughter_constell == "��Ů��"){
        value_array_baseinfo[0] = 35;  value_array_baseinfo[1] = 28; value_array_baseinfo[2] = 36; value_array_baseinfo[3] = 18; value_array_baseinfo[4] = 40;
    }else if(value_daughter_constell == "�����"){
        value_array_baseinfo[0] = 42;  value_array_baseinfo[1] = 33; value_array_baseinfo[2] = 25; value_array_baseinfo[3] = 32; value_array_baseinfo[4] = 28;
    }else if(value_daughter_constell == "��Ы��"){
        value_array_baseinfo[0] = 50;  value_array_baseinfo[1] = 25; value_array_baseinfo[2] = 40; value_array_baseinfo[3] = 18; value_array_baseinfo[4] = 17;
    }else if(value_daughter_constell == "������"){
        value_array_baseinfo[0] = 57;  value_array_baseinfo[1] = 31; value_array_baseinfo[2] = 15; value_array_baseinfo[3] = 19; value_array_baseinfo[4] = 20;
    }else if(value_daughter_constell == "ɽ����"){
        value_array_baseinfo[0] = 56;  value_array_baseinfo[1] = 21; value_array_baseinfo[2] = 16; value_array_baseinfo[3] = 25; value_array_baseinfo[4] = 23;
    }else if(value_daughter_constell == "ˮƿ��"){
        value_array_baseinfo[0] = 43;  value_array_baseinfo[1] = 43; value_array_baseinfo[2] = 20; value_array_baseinfo[3] = 23; value_array_baseinfo[4] = 17;
    }else if(value_daughter_constell == "˫����"){
        value_array_baseinfo[0] = 41;  value_array_baseinfo[1] = 21; value_array_baseinfo[2] = 29; value_array_baseinfo[3] = 23; value_array_baseinfo[4] = 32;
    }




    //1��Ϊ��Ůȡ����
    //2��ΪŮ��¼���ʼ��Ϣ���ա�����
    //   ����Ů����������������Ϸ�Ļ������������������������������¡����ʣ�
    //3����ʼ��Ϸ��ѭ��
    //��Ϸ��1659��6�¿�ʼ
    for(int year = 1659; year <= 1659 + 7; year++){
        for(int month = (year == 1659) ? 6 : 1; month <= 12; month++){
            //�жϱ����Ƿ���Ů��������
            if(month == value_birth_month){
                cout << "������" << value_daughter_name << "����, Ҫ��Ҫ�������أ�" << endl;
                //�����û�����������ж�

            }
            //��ʾ��Ϸ���˵�
            cout << "\n1���鿴״̬\n2�������г�\n3������̸��\n4���浵\n5������" << endl;
            cin >> choice;
            switch(choice){
            case 1://�鿴״̬
                cout << "Ů������Ϣ��\n";
                cout << "������" << value_daughter_name << endl;
                cout << "���գ�1659-" << value_birth_month << "-" << value_birth_date << endl;
                cout << "������" << value_daughter_constell << endl;
                cout << "��ң�" << value_daughter_gold << endl;
                //��ӡ��������
                cout << left;
                for(int i = 0; i < 5; i++){
                    cout << value_array_baseinfo_names[i] << "��" << setw(6) << value_array_baseinfo[i];
                    //����ʵ�ķ��������
                    int solidCount = value_array_baseinfo[i] / 10;
                    for(int j = 0; j < 10; j++){
                        if(j < solidCount)
                            cout << "��";
                        else
                            cout << "��";
                    }
                    cout << endl;

                }
                break;
            case 2:{//�����г̣�һ������ల�������г�
                string month_parts[] = {"��Ѯ", "��Ѯ", "��Ѯ"};
                for(int i = 0; i < 3; i++){
                    cout << "-- " << month << "�� --" << month_parts[i] << endl;
                    cout << "1��ѧϰ����\n2����˽��\n3��ѧϰ��\n4����������\n5����׬Ǯ" << endl;
                    cout << "��ѡ��";
                    cin >> choice;
                    //����ע�⣬��Ҫ�ж�ûǮ�������ǿ�ƴ�
                    srand(time(NULL));
                    if(choice == 1){//+���� +���� -��Ǯ
                        value_array_baseinfo[0] += temp1 = rand() % 11;
                        value_array_baseinfo[2] += temp2 = rand() % 11;
                        value_daughter_gold -= temp3 = rand() % 51;
                        cout << "ѧϰ���޼ɺð�����������" << endl;
                        cout << "����+" << temp1 << ", ����+" << temp2 << ", ��Ǯ-" << temp3 << endl;
                    }else if(choice == 5){
                        value_daughter_gold += temp3 = rand() % 101;
                        cout << "ͨ��Ŭ���򹤣�׬����" << temp3 << "����ң�" << endl;
                    }

                }
                break;
            }
            case 3:

                break;
            case 4:
                break;
            case 5:
                break;
            default:
                break;
            }
        }
    }




    /*4�����ݸ���������ж���Ϸ���
     Ů��	��������2000����
    ����	��������1800-2000
    Ů����	��������1600-1800
    �ʼ�ѧԺ�ܲ�	��������1200-1600��������ߣ�������>����
    ����	��������1200-1600��������ߣ�������>����
    ������ʿ�ų�	��������1200-1600��������ߣ�������>����
    �߼�����	��������1200-1600��������ߣ�������>����
    �����ĳ���	��������1200-1600��������ߣ�������>����		*/
    int sum = 0;
    for(int i = 0; i < 5; i++){
        sum += value_array_baseinfo[i];
    }
    if(sum >= 2000){
        cout << "������Ϸ������ǻ�ΪŮ������" << endl;
    }else if(sum >= 1800 && sum < 2000){
        cout << "������Ϸ�������Ϊ����" << endl;
    }else if(sum >= 1200 && sum < 1600){
        int maxValue = value_array_baseinfo[0];
        int maxIndex = 0;
        for(int i = 1; i < 5; i++){
            if(maxValue < value_array_baseinfo[i]){
                maxValue = value_array_baseinfo;
                maxIndex = i;
            }
        }
        //ֻ���ж���ĳ�������������������������ж�
        if("����" == value_array_baseinfo_names[maxIndex] && value_array_baseinfo[2] > value_array_baseinfo[4]){
            //�߼�����	��������1200-1600��������ߣ�������>����
            cout << "�������ڵ�ѵ����" << value_daughter_name << "�ɳ���Ϊһ�����ٵĸ߼����룡" << endl;
        }

    }

















    return 0;
}
