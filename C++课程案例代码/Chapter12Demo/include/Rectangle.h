#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "Circle.h"

using namespace std;

//自定义的矩形类
class Rectangle
{
    public:
        //Rectangle();                            //无参默认构造，可以由编译器自动生成
        //Rectangle(float width, float height);   //带参构造
        Rectangle(const Rectangle & rect){}      //拷贝构造
        //Rectangle(float width);                 //转换构造 - 将其他类型转换为当前类型时使用

        //将几个构造融合在一起的写法
        Rectangle(float width = 0, float height = 0) : width(width), height(height){}

        operator float() const{     //将矩形转换成float类型
            return width;
        }

        operator Circle() const{    //将矩形转换成Circle类型
            return Circle(width / 2);
        }

        void display(){
            cout << "width:" << width << ", height:" << height << endl;
        }
        virtual ~Rectangle();

    protected:

    private:
        float width;
        float height;
};

#endif // RECTANGLE_H
