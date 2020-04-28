//*********************
//**    ch4_4.cpp    **
//*********************

#include <iostream.h>
#include <iomanip.h>
#include <math.h>

void main()
{
  double s=0,x=1;  //初始值
  long k=1;
  int sign=1;

  while(fabs(x)>1e-8){   //项值在比较前要先求绝对值
    s += x;
    k += 2;
    sign *= -1;
    x = sign/double(k);  //强制转换使x得到浮点数值
  }

  s *= 4;                //π值
  cout <<"the pi is "    //输出
       <<setiosflags(ios::fixed)
       <<setprecision(8)
       <<s <<endl;
}
