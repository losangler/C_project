#include "MyString.h"

String::String() : m_length(0)
{
    //char * str = "";    //长度为0，但是实际的字符数组中会存在唯一的元素：\0
    this->m_value = new char[1];
    this->m_value[0] = '\0';
}

String::String(char * str)
{
    //将传入的字符串str的值赋给当前对象中的m_value
    if(NULL == str){
        this->m_value = new char[1];
        this->m_value[0] = '\0';
        return;
    }
    m_length = strlen(str);             //获得要复制字符串的长度
    m_value = new char[m_length + 1];   //为\0留出一个空间
    strcpy(m_value, str);
}

String::String(const String & str)
{
    m_length = strlen(str.m_value);
    m_value =  new char[m_length + 1];
    strcpy(m_value, str.m_value);
}

ostream & operator<<(ostream & out, const String & str){
    out << str.m_value << "\n";
    //out << "str的长度：" << str.m_length;
    printf("%p", str.m_value);
    return out;
}

//当重载赋值运算符时，务必确定将一个对象中的所有数据都复制到另一个对象中（特别是有指针时）
//如果包含多个成员，那么每个成员都需要复制到内存对象中 - 深复制
//如果一个类拥有指针类型的成员，那么大部分情况下，都需要使用深复制 - 才能将指针指向的内容复制一份出来，让原有的对象和新对象相互独立
//如果类的成员没有指针，那么一般浅复制足以
const String & String::operator=(const String & str)
{
    if(this == &str) return *this;
    delete[] m_value;       //首先要释放字符串的原始空间
    m_length = str.m_length;
    m_value = new char[m_length + 1];
    strcpy(m_value, str.m_value);
    return *this;
}

String::~String()
{
    //析构时，释放字符数组所指向的空间
    delete[] m_value;
}
