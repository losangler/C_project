#include <iostream>
#include "Integer.h"
#include "ConstDemo.h"
#include "MyString.h"
#include "Array.h"
#include "MyVector.h"
#include "Rectangle.h"

using namespace std;

void TestInteger();
void TestString();
void TestArray();
void TestVector();
void TestRectangle();

int main()
{
    //cout << "Hello world!" << endl;
    //TestInteger();
    //ConstDemo1();
    //TestString();
    //TestArray();
    //TestVector();
    TestRectangle();
    return 0;
}

void TestInteger()
{
//    int num1 = 111;
//    int num2 = 222;
//    int num3;
//    num3 = num1 + num2;
//    //思考：运算完毕后，num1和num2的值有没有变化？
    Integer int1(1024), int2(2048), int3;
    int3 = int1 + int2;
    cout << "int3 = int1 + int2的结果为：" << int3.IntValue() << endl;
    int3 = int1 - int2;
    cout << "int3 = int1 - int2的结果为：" << int3.IntValue() << endl;
    int3 = int1 * int2;
    cout << "int3 = int1 * int2的结果为：" << int3.IntValue() << endl;
    int3 = int1 / int2;
    cout << "int3 = int1 / int2的结果为：" << int3.IntValue() << endl;
    int3 = int1 % int2;
    cout << "int3 = int1 % int2的结果为：" << int3.IntValue() << endl;


    Integer int4;
    int4 = int3;
    cout << "int4 = int3的结果：" << int4.IntValue() << endl;

    Integer int5;
    int5 = 1024 + int4;
    //int5 = int4 + 1024;
    cout << "int5 = " << int5.IntValue() << endl;

    cout << "重载了<<运算符后，可以直接打印对象：int5 = " << int5 << endl;

    Integer int6;
    cin >> int6;
    cout << "输入的int6为：" << int6 <<endl;
}

void TestString(){
    String str1("这里是中文");
    //String str2 = "abcdefg";
    String str2(str1);
    cout << str1 << endl;
    cout << str2 << endl;
    cout << "对象之间的赋值：" << endl;
    //str1 = str2;
    cout << str1 << endl;
    cout << str2 << endl;

}

void TestArray(){
    Array arr1(10);
    arr1[0] = 1234;
    arr1[11] = 34;
    cout << arr1 << endl;
}

void TestVector(){
    MyVector<int> vec1;      //默认构造
    MyVector<double> vec2(10, 99.9);
    cout << "vec1:" << vec1 << endl;
    cout << "vec2:" << vec2 << endl;
    MyVector<String> vec3(5, String("abc"));
    cout << "vec3:" << vec3 << endl;

    vec3.push_back("123");
    cout << "vec3:" << vec3 << endl;

    String result = vec3.pop_back();
    result = vec3.pop_back();
    result = vec3.pop_back();
    result = vec3.pop_back();
    result = vec3.pop_back();
    result = vec3.pop_back();
    result = vec3.pop_back();
    cout << "返回的元素：" << result << endl;
    cout << "vec3:" << vec3 << endl;
}

void TestRectangle(){
    Rectangle rect1;                //调用默认构造
    Rectangle rect2(25.0, 50.5);    //调用带参构造
    Rectangle rect3(rect1);         //调用拷贝构造
    //能够与基本类型进行互相转换？
    Rectangle rect4 = 55;           //调用一个参数的构造 - 转换构造
    Rectangle rect5(55);
    rect4.display();

    float rect4_width = float(rect4);
    cout << "rect4_width = " << rect4_width << endl;
    Circle circle = rect4;      //Rectangle和Circle之间可以自由转换
    cout << "圆的信息：" << circle << endl;

}











