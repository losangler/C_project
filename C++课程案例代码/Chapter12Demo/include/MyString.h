#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

using namespace std;

//自定义的字符串包装类
class String
{
    public:
        String();
        String(char * str);
        String(const String & str); //复制构造/拷贝构造函数
        virtual ~String();

        //重载赋值运算符，将数组中的每个元素都进行复制，而不是只复制数组指针
        const String & operator=(const String & str);

        friend ostream & operator<<(ostream & out, const String & str);

    protected:

    private:
        int m_length;       //字符串的实际长度-不包括\0
        char * m_value;     //实际存储字符的字符数组
};

#endif // STRING_H
