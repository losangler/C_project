//**********************
//**    ch11_5.cpp    **
//**********************

#include <iostream.h>
#include <math.h>

class Point{
public:
  void Set(double ix,double iy)    //设置坐标
  {
    x=ix;  y=iy;
  }

  double xOffset()             //取y轴坐标分量
  {
    return x;
  }

  double yOffset()      //取x轴坐标分量
  {
    return y;
  }

  double angle()        //取点的极坐标
  {
    return (180/3.14159)*atan2(y,x);
  }

  double radius()        //取点的极坐标半径
  {
    return sqrt(x*x+y*y);
  }
protected:
  double x;      //x轴分量
  double y;      //y轴分量
};

void main()
{
  Point p;
  double x,y;
  for(;;){      //重复输入x和y轴分量，直到x分量值小于0
    cout <<"Enter x and y:\n";
    cin >>x >>y;
    if(x<0)
      break;
    p.Set(x,y);
    cout <<"angle=" <<p.angle()
         <<",radius=" <<p.radius()
         <<",x offset=" <<p.xOffset()
         <<",y offset=" <<p.yOffset() <<endl;
  }
}
