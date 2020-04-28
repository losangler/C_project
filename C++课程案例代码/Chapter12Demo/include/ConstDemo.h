#ifndef CONSTDEMO_H_INCLUDED
#define CONSTDEMO_H_INCLUDED

#include <iostream>
using namespace std;

//1.const修饰成员变量
void ConstDemo1()
{
    int num1 = 1024;
    const int num2 = 1111;
    //assignment(分配) of read-only variable 'num2'|
    //num2 = 2048;
    const int * ptr1_num1 = &num1;
    int const * ptr2_num1 = &num1;
    ptr1_num1 = &num2;  //合法
    //*ptr1_num1 = 1234;  //不合法
    //const修饰指针变量时：
    //1.只有一个const时，如果const位于*的左侧：表示指针所指的数据是常量，不能通过该指针修改实际数据；
    //      指针本身是变量，可以指向其他内存单元
    //2.只有一个const时，如果const位于*的右侧：表示指针本身是常量，不能指向其他内存单元；所指向的数据可以修改
    int * const ptr3_num1 = &num1;
    //ptr3_num1 = ptr2_num1;  //不合法
    //3.如果有两个const位于*的左右两侧，表示指针和指针所指向的数据都不能修改
}

//2.const修饰函数参数
void ConstTest2(const int num)
{
    //num = 123;  //传递来的参数num在函数体内不可改变，与修饰变量时的性质一致
}
class Computer{
public:
    Computer(int core){this->m_core = core;}

    void buy() const{}

    void buy(int core)
    {

    }

    /** 修改电脑的核心频率 */
    void SetCore(int core){this->m_core = core;}
    int GetCore() const{return m_core;}
private:
    int m_core; //cpu的主频
};
void ConstTest3(const Computer & computer){
    //const修饰引用时，不能修改引用对象的任何成员 - 好处是可以保护传递参数；不需要一个新的参数副本（copy）
    //passing 'const Computer' as 'this' argument discards qualifiers [-fpermissive]|
    computer.buy();   //const成员函数不能调用非const成员函数
    //使用const传递对象的引用时，可以起到不copy对象的目的（节省效率）
}

//3.const修饰返回值
//强调：使用const修饰引用类型的一个常见的原因是：提高效率
const Computer & GetMax(const Computer & com1, const Computer & com2){
    if(com1.GetCore() > com2.GetCore()){
        return com1;
    }
    return com2;
}
//如果函数要返回局部对象，就应该直接返回这个对象，而不要返回对象的引用
//在可以返回对象、也可以可返回引用时，就应该首选引用，因为效率高

//4、const修饰函数 - 说明函数不会修改成员变量的值
class TestClass{
public:
    int value;
    void ModifyValue() const{
        //value = 1111;
    }
};




#endif // CONSTDEMO_H_INCLUDED
