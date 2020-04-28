#include <iostream>
#include <cmath>
using namespace std;

int main(){

      //int a,b,c;
	  //double s,area; 
	
   int a, b, c, s, area;
	cout << "a,b,c = " ;
	cin >> a >> b >> c;     
	cout<<a<<" "<<b<<" "<<c<<endl;//问题2c、d：3.45  5.618  4.012
	
	s = ( a + b + c ) / 2.0;	
	area = sqrt( s * ( s-a ) * ( s-b ) * ( s-c ) ); //求三角形的面积
	
	cout << "area = " << area << endl;
	
	return 0;
 }

