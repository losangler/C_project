#include "Integer.h"

//调用默认构造时，会为私有m_value赋一个默认值为0
Integer::Integer() : m_value(0)
{
    //ctor
}

//重载+运算符
const Integer Integer::operator+(const Integer & other) const
{
    Integer result(this->m_value + other.m_value);     //用来返回的结果对象
    return result;
}

const Integer Integer::operator-(const Integer & other) const
{
    return Integer(this->m_value - other.m_value);
}
const Integer Integer::operator*(const Integer & other) const
{
    return Integer(this->m_value * other.m_value);
}
const Integer Integer::operator/(const Integer & other) const
{
    return Integer(this->m_value / other.m_value);
}
const Integer Integer::operator%(const Integer & other) const
{
    return Integer(this->m_value % other.m_value);
}

const Integer & Integer::operator=(const Integer & other)
{
    //条款11：如果是自我赋值，就不要做任何事情
    //int4 = int4;
    if(this == &other) //证同测试
        return *this;
    this->m_value = other.m_value;
    return *this;
}

//友元函数不需要使用域运算符了
const Integer operator+(int intValue, const Integer & other)
{
    std::cout << "使用友元方式重载了+运算符，实现int类型和Integer类型的相加" << std::endl;
    return Integer(intValue + other.m_value);
}

istream & operator>>(istream & in, Integer & num){
    std::cout << "请输入一个整数：";
    in >> num.m_value;
    return in;
}

//流运算符一般只能使用友元的方式重载
ostream & operator<<(ostream & out, const Integer & num)
{
    out << num.m_value;
    return out;
}

Integer::~Integer()
{
    //dtor
}
