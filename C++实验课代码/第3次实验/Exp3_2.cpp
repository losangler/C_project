//Please input the radius of the ball.
#include <iostream>
using namespace std;

int main()//double main()
{
	double r, s, v, m, pi, p;
	//r radius；s 表面积 superficialArea；v 体积 volume；m 质量 mass； 
 
	
	cout<<"Please input the radius of the ball\n";//cout << "r = " ;
	cin >> r;      //输入球的半径
    
	pi = 3.14;
	p = 7.8;
	s = 4 * pi * r * r;    //求球的表面积
	v = 4/3 * pi * r * r * r;     //求球的体积  4.0/3 
	m = p * v;        //求球的质量
    
	cout << "s = "<< s << endl;
	cout << "v = "<< v << endl;
	cout << "m = "<< m << endl;
	
	return 0;//改 
}	

