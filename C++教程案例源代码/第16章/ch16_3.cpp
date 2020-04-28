//**********************
//**    ch16_3.cpp    **
//**********************

#include<iostream.h>ª¤
#include<math.h>ª¤ª¤

class Shapeª¤
{ª¤
  ¡þpublic:ª¥
    Shape(double x, double y) :xCoord(x), yCoord(y){}ª¥
    ¡¼WT5¡±BKH¡½virtual¡¼WT5¡±BKB¡½ double Area() const {return 0.0;}ª¤
¡þ  protected:ª¥
    double xCoord, yCoord;ª¤
};ª¤ª¤

class Circle :public Shapeª¤
{ª¤
  ¡þpublic:ª¥
    Circle(double x, double y, double r) :Shape(x, y), radius(r){}ª¥
    ¡¼WT5¡±BKH¡½virtual¡¼WT5¡±BKB¡½ double Area() const {return 3.14*radius*radi
us;}ª¤
¡þ  protected:ª¥
    double radius;ª¤
};ª¤ª¤

class Rectangle :public Shapeª¤
{ª¤
  ¡þpublic:ª¥
    Rectangl¡¼ZK(¡½e(double x1, double y1, double x2, double y2)ª¤
            :Shape(x1,y1), x2Coord(x2), y2Coord(y2){}¡¼ZK)¡½ª¥
    [WT5¡±BKH]virtual¡¼WT5¡±BKB¡½ double Area() const;ª¤
¡þ  protected:ª¥
    double x2Coord, y2Coord;ª¤
};ª¤ª¤

double Rectangle¡ËArea() constª¤
{ª¤
¡þ  return fabs((xCoord-x2Coord)*(yCoord-y2Coord));ª¤
}ª¤ª¤

void fun(const Shape& sp)ª¤
{ª¤
¡þ  cout <¡¼KG-ª³2¡½<sp.Area() <¡¼KG-ª³2¡½<endl;ª¤
}ª¤ª¤

void main()ª¤
{ª¤
  ¡þCircle c(2.0,5.0,4.0);ª¤
  ¡þfun(c);ª¤
  ¡þRectangle t(2.0,4.0,1.0,2.0);ª¤
  ¡þfun(t);ª¤
}