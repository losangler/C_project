//----------------------------------------
#include <iostream.h>
#include <math.h>
//----------------------------------------
double Cylinder(double r, double h);
//----------------------------------------
void main()
{
  double radius, height;
  cout <<"请输入圆柱体的半径和高:\n";
  cin >>radius >>height;

  double volume = Cylinder(radius, height);

  cout <<"该圆柱体的体积为：" <<volume <<endl;
}
//----------------------------------------
double Cylinder(double r, double h)
{
  return r*r*M_PI*h;
}
//----------------------------------------

