//*********************
//**    ch7_6.cpp    **
//*********************

#include <iostream.h>

void main()
{
  int array1[2][3]={1,2,3,4,5};
  int array2[2][3]={{1,2},{4}};

  int i,j;
  for(i=0; i<2; i++){    //按行列输出数组array1
    for(j=0; j<3; j++)
      cout <<array1[i][j] <<",";
    cout <<endl;
  }

  cout <<endl;
  for(i=0; i<2; i++){    //按行列输出数组array2
    for(j=0; j<3; j++)
      cout <<array2[i][j] <<",";
    cout <<endl;
  }
}
