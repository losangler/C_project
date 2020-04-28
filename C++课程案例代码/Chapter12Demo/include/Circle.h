#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
using namespace std;

class Circle
{
    public:
        //Circle();
        Circle(float radius = 0): radius(radius){}
        virtual ~Circle();

        friend ostream & operator<<(ostream & out, const Circle & circle);

    protected:

    private:
        float radius;       //半径
        float area;         //面积
};



#endif // CIRCLE_H
