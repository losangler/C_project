#ifndef MYCALC_H_INCLUDED
#define MYCALC_H_INCLUDED
#include <iostream>
using namespace std;
//�Զ����������ʹ�ú���ָ��

/** �ӷ� */
double addition(double, double);
/** ���� */
double subtraction(double, double);
/** �˷� */
double multiplication(double, double);
/** ���� */
double division(double, double);
/** ��ӡ������ */
void print_result(double (*)(double, double), double, double);

void print_result(double (*ptrCalc)(double, double), double num1, double num2)
{
    //���ú�������ӡ���
    double result = ptrCalc(num1, num2);
    cout << "������Ϊ��" << result << endl;
}

double addition(double num1, double num2)
{
    return num1 + num2;
}

double subtraction(double num1, double num2)
{
    return num1 - num2;
}

double multiplication(double num1, double num2)
{
    return num1 * num2;
}

double division(double num1, double num2)
{
    if(num2 == 0){
        cout << "��������Ϊ0������" << endl;
        return 0;
    }
    return num1 / num2;
}

#endif // MYCALC_H_INCLUDED
