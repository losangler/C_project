#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstring>
using namespace std;
//自定义的数组类
class Array
{
    public:
        Array(int length = 0);
        Array(const Array & arr);   //拷贝构造
        virtual ~Array();

        //int operator[](int index);  //获取元素（无法写入）
        int & operator[](int index);

        const Array & operator=(const Array & arr);

        friend ostream & operator<<(ostream & out, const Array & arr);

    protected:

    private:
        int m_length;
        int * m_datas;
};

#endif // ARRAY_H
