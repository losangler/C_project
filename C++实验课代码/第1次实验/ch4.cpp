#include <iostream>
#include <cmath>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double max(double x,double y)
{
	if(x>y)
		return x;
	else
		return y;		
}

int main() {
	double a,b,c;
	cout<<"input two numbers:\n";
	cin>>a>>b;
	
	c=max(a,b);
	
	cout<<"the sqaurt of maximum= "<<sqrt(c);
	return 0;
}
