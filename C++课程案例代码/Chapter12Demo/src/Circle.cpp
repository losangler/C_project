#include "Circle.h"

ostream & operator<<(ostream & out, const Circle & circle){
    out << circle.radius ;
    out << endl;
    return out;
}

Circle::~Circle()
{
    //dtor
}
