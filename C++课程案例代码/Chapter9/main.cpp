#include <iostream>
#include <cmath>
#include "GzDemo.h"
#include "EWDemo.h"
#include "FuncPtr.h"
#include "MyCalc.h"

using namespace std;
/*
    三种形状的体积计算公式如下：
    长方体：长 × 宽 × 高
    圆柱体：圆周率 × 半径的平方 × 高
    圆锥体：1/3 × 底面积 × 高
*/

//1.定义三个函数，分别用来计算三种形状的体积
//2.在main函数中用户可以选择计算某个形状的体积
/*
void calcCuboid();  //计算长方体的体积
void calcCylinder();//计算圆柱体的体积
void calcCone();    //计算圆锥体的体积
*/


void change(int &num)
{
    num++;
}

int main()
{
    //定义函数指针
    typedef double (*ptrCalc)(double, double);
    ptrCalc ptrCalc1;
    double num1, num2;
    char op;
    cout << "请输入两个操作数：";
    cin >> num1 >> num2;
    cout << "请输入运算符：";
    cin >> op;
    switch(op)
    {
    case '+':
        //调用加法函数
        ptrCalc = addition;
        break;
    case '-':
        //调用减法函数
        ptrCalc = subtraction;
        break;
    case '*':
        ptrCalc = multiplication;
        break;
    case '/':
        ptrCalc = division;
        break;
    }
    //调用
    print_result(ptrCalc, num1, num2);












    /*


    //int power(int, int);

    //声明函数指针 - ptrPower   int* ptrInt;
    int (*ptrPower)(int, int);
    //让声明的函数指针指向函数，以便调用
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
        cout << "1、长方体" << endl;
        cout << "2、圆柱体" << endl;
        cout << "0、退出" << endl;
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
    cout << "感谢使用本软件，觉得好点个赞呗！" << endl;*/
    return 0;
}







/*
void calcCuboid()
{
    //输入长宽高
    double len, width, height;
    cout << "请输入长宽高：";
    cin >> len >> width >> height;
    //计算体积
    double v = len * width * height;
    cout << "长方体的体积为：" << v << endl;
}

void calcCylinder()
{
    double radius, height;  //半径
    cout << "请输入半径和高：";
    cin >> radius >> height;
    //计算体积
    double pi = 4 * atan(1.0);
    double v = pi * pow(radius, 2) * height;
    cout << "圆柱体的体积为：" << v << endl;

}
*/
