/************************************************************************
 *  Project:
 *  Function:
 *  Description:
 *  Author: ��ͷ
 ************************************************************************
 *  Copyright 2018 by �Ͼ�ѧ��
 ************************************************************************/
#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>

namespace VECTOR{
    class Vector
    {
    public:
        //ֱ�����꣺x/y������
        //�����꣺50����λ��45��
        enum Mode{RECT, POL};       //ֱ������ / ������
    private:
        double x;       //ˮƽ����
        double y;       //��ֱ����
        double len;     //ʸ������
        double degree;  //ʸ�����򣨶ȣ�
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

        //��Ԫ����
        friend Vector operator*(double mult, const Vector & vec);
        friend std::ostream & operator<<(std::ostream &os, const Vector & vec);


        ~Vector();
    protected:


    };
}



#endif // MYVECTOR_H
