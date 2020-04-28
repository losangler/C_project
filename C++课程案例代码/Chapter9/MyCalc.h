#ifndef MYCALC_H_INCLUDED
#define MYCALC_H_INCLUDED
#include <iostream>
using namespace std;
//自定义计算器，使用函数指针

/** 加法 */
double addition(double, double);
/** 减法 */
double subtraction(double, double);
/** 乘法 */
double multiplication(double, double);
/** 除法 */
double division(double, double);
/** 打印计算结果 */
void print_result(double (*)(double, double), double, double);

void print_result(double (*ptrCalc)(double, double), double num1, double num2)
{
    //调用函数，打印结果
    double result = ptrCalc(num1, num2);
    cout << "运算结果为：" << result << endl;
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
        cout << "除数不能为0！！！" << endl;
        return 0;
    }
    return num1 / num2;
}

#endif // MYCALC_H_INCLUDED
