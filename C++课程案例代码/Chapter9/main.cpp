#include <iostream>
#include <cmath>
#include "GzDemo.h"
#include "EWDemo.h"
#include "FuncPtr.h"
#include "MyCalc.h"

using namespace std;
/*
    ������״��������㹫ʽ���£�
    �����壺�� �� �� �� ��
    Բ���壺Բ���� �� �뾶��ƽ�� �� ��
    Բ׶�壺1/3 �� ����� �� ��
*/

//1.���������������ֱ���������������״�����
//2.��main�������û�����ѡ�����ĳ����״�����
/*
void calcCuboid();  //���㳤��������
void calcCylinder();//����Բ��������
void calcCone();    //����Բ׶������
*/


void change(int &num)
{
    num++;
}

int main()
{
    //���庯��ָ��
    typedef double (*ptrCalc)(double, double);
    ptrCalc ptrCalc1;
    double num1, num2;
    char op;
    cout << "������������������";
    cin >> num1 >> num2;
    cout << "�������������";
    cin >> op;
    switch(op)
    {
    case '+':
        //���üӷ�����
        ptrCalc = addition;
        break;
    case '-':
        //���ü�������
        ptrCalc = subtraction;
        break;
    case '*':
        ptrCalc = multiplication;
        break;
    case '/':
        ptrCalc = division;
        break;
    }
    //����
    print_result(ptrCalc, num1, num2);












    /*


    //int power(int, int);

    //��������ָ�� - ptrPower   int* ptrInt;
    int (*ptrPower)(int, int);
    //�������ĺ���ָ��ָ�������Ա����
    ptrPower = power;

    cout << (*ptrPower)(3, 4) << endl;










    /*
    double powers[3][5] = {
        {45.5, 55.6, 88.9, 66.6, 78},
        {98.2, 69.1, 33.7, 49.3, 58},
        {78.2, 58.5, 12.8, 37.8, 43}
    };
    show(powers, 3);















    /*
    int values[5];
    //input(values, sizeof(values)/sizeo(int));
    input(values, 5);
    print(values, 5);
    print(values, 5);
*/








    /*
    int choice = -1;
    while(choice)
    {
        cout << "1��������" << endl;
        cout << "2��Բ����" << endl;
        cout << "0���˳�" << endl;
        cin >> choice;
        switch(choice)
        {
        case 1:
            calcCuboid();
            break;
        case 2:
            calcCylinder();
            break;

        }
    }
    cout << "��лʹ�ñ���������úõ�����£�" << endl;*/
    return 0;
}







/*
void calcCuboid()
{
    //���볤���
    double len, width, height;
    cout << "�����볤��ߣ�";
    cin >> len >> width >> height;
    //�������
    double v = len * width * height;
    cout << "����������Ϊ��" << v << endl;
}

void calcCylinder()
{
    double radius, height;  //�뾶
    cout << "������뾶�͸ߣ�";
    cin >> radius >> height;
    //�������
    double pi = 4 * atan(1.0);
    double v = pi * pow(radius, 2) * height;
    cout << "Բ��������Ϊ��" << v << endl;

}
*/
