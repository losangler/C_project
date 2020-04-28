#ifndef GZDEMO_H_INCLUDED
#define GZDEMO_H_INCLUDED
//使用函数升级《小公举养成记》中的基本属性录入及排序功能
//基本属性：体力、智力、魅力、道德、气质
#include <iostream>
using namespace std;

//函数定义
void input(int [], int);
void print(const int *, int);
//自行完成删除和修改数组元素


//函数实现
void input(int values[], int len)
{
    if(len > 5)
    {
        cout << "数组长度只能是5以内！！！"<< endl;
        return;//退出返回值为void的函数
    }
    string valueNames[] = {"体力", "智力", "魅力", "道德", "气质"};
    for(int i = 0; i < len; i++)
    {
        cout << valueNames[i] << "：" ;
        cin >> values[i];
    }
}

void print(const int * values, int len)
{
    string valueNames[] = {"体力", "智力", "魅力", "道德", "气质"};
    for(int i = 0; i < len; i++)
    {
        cout << valueNames[i] << "：" << values[i] << endl;
    }
}


#endif // GZDEMO_H_INCLUDED
