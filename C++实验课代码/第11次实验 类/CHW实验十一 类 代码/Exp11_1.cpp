#include <iostream>//chw:#include <iostream.h>
#include <cmath>//chw:#include <math.h>
using namespace std;//chw:增加 

class Point
{
	public:
		void Set(double ix,double iy)//设置坐标 
		{
			x=ix;
			y=iy;
		}
		
		double xOffset()//chw:取y轴坐标分量 改为x 
		{
			return x;
		}
		double yOffset()//chw:取x轴坐标分量 改为y 
		{
			return y;
		} 
		
		double angle()//取点的极坐标θ 
		{
			return (180/3.14159)*atan2(y,x);//？返回的是方位角，也可以理解为计算复数 x+yi 的辐角，计算时atan2 比 atan 稳定
		}
		
		double radius()//取点的极坐标半径 
		{
			return sqrt(x*x+y*y); 
		}
	protected:
		double x;//x轴分量
		double y;//y轴分量 
};
int main()
{
	Point p;
	double x,y;
	
	cout<<"Enter x and y:\n";
	cin>>x>>y;
	
	p.Set(x,y);
	//p.x+=5;
	//p.y+=6;//chw:数据成员x和y的访问权限是protected，因此不能在类外访问
	
	cout<<"angle="<<p.angle()
		<<",radius="<<p.radius()
		<<",x offset="<<p.xOffset()
		<<",y offset="<<p.yOffset()<<endl;//chw:"endl; 
	return 0;
}
