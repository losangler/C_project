#include "MyVector.h"
#include <cmath>
using namespace std;
namespace VECTOR{
    const double  RadToDegree = 45.0 / atan(1.0);

    Vector::Vector(){
        x = y = len = degree = 0;
    }

    Vector::Vector(double x, double y, Mode mode){
        this->mode = mode;
        switch(mode){
        case RECT:          //ֱ������ϵ
            this->x = x;
            this->y = y;
            SetLen();
            SetDegree();
            break;
        case POL:           //������
            len = x;
            degree = y / RadToDegree;
            SetX();
            SetY();
            break;
        default:
            cout << "��������ȷ��ʸ������" << endl;
        }
    }

    void Vector::SetX(){x = len * cos(degree);}
    void Vector::SetY(){y = len * sin(degree);}



    void Vector::SetLen(){
        //����֮��ľ���
        len = sqrt(x * x + y * y);
    }

    void Vector::SetDegree(){
        if(x == 0.0 && y == 0.0){
            degree = 0.0;
        }else{
            degree = atan2(y, x);
        }
    }

    void Vector::RectMode(){mode = RECT;}

    void Vector::PolarMode(){mode = POL;}

    void Vector::operator+(const Vector & vec) const{
        return Vector(x + vec.x, y + vec.y);
    }

    void Vector::operator-(const Vector & vec) const{
        return Vector(x - vec.x, y - vec.y);
    }

    void Vector::operator-() const{
        return Vector(-x, -y);
    }

    Vector Vector::operator*() const{

    }



    ~Vector(){}

}

