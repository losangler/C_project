//11_1

#include <math.h>

class Point{
public:
  void Set(double ix,double iy)     //设置坐标
  {
      x=ix;  y=iy;
  }

  double xOffset()                  //取y轴坐标分量
  {
    return x;
  }

  double yOffset()                  //取x轴坐标分量
  {
    return y;
  }

  double angle()                    //取点的极坐标θ
  {
    return (180/3.14159)*atan2(y,x);
  }

  double radius()                   //取点的极坐标半径
  {
    return sqrt(x*x+y*y);
  }
protected:
  double x;                         //x轴分量
  double y;                         //y轴分量
}           //error: 缺少分号

void main()
{
  Point p;
  double x,y;

  cout <<"Enter x and y:\n";
  cin >>x >>y;

  p.Set(x,y);
  p.x+=5;   //error: 私有成员不能在类外被访问
  p.y+=6;   //error: 同上

  cout <<"angle=" <<p.angle()
       <<",radius=" <<p.radius()
       <<",x offset=" <<p.xOffset()
       <<",y offset=" <<p.yOffset() <<endl;}