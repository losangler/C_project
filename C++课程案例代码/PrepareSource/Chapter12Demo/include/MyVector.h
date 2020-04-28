/************************************************************************
 *  Project:
 *  Function:
 *  Description:
 *  Author: 窖头
 ************************************************************************
 *  Copyright 2018 by 老九学堂
 ************************************************************************/
#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>

namespace VECTOR{
    class Vector
    {
    public:
        //直角坐标：x/y轴坐标
        //极坐标：50个单位，45度
        enum Mode{RECT, POL};       //直角坐标 / 极坐标
    private:
        double x;       //水平坐标
        double y;       //垂直坐标
        double len;     //矢量长度
        double degree;  //矢量方向（度）
        Mode mode;

        void SetX();
        void SetY();
        void SetLen();
        void SetDegree();
        public:


        Vector();
        Vector(double x, double y, Mode mode = RECT);
        void reset(double x, double y, Mode mode = RECT);

        double getX() const {return x;}
        double getY() const {return y;}
        double getLen() const {return len;}
        double getDegree() const {return degree;}

        void PolarMode();
        void RectMode();

        Vector operator+(const Vector & vec) const;
        Vector operator-(const Vector & vec) const;
        Vector operator-() const;
        Vector operator*(double mult) const;

        //友元函数
        friend Vector operator*(double mult, const Vector & vec);
        friend std::ostream & operator<<(std::ostream &os, const Vector & vec);


        ~Vector();
    protected:


    };
}



#endif // MYVECTOR_H
