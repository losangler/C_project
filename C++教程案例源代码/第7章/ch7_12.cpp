//**********************
//**    ch7_12.cpp    **
//**********************

#include <iostream.h>
#include <iomanip.h>

int a[3][4]={{ 5, 7, 8, 2},
             {-2, 4, 1, 1},
             { 1, 2, 3, 4}};

int b[4][5]={{4,-2, 3, 3, 9},
             {4, 3, 8,-1, 2},
             {2, 3, 5, 2, 7},
             {1, 0, 6, 3, 4}};

int c[3][5];

bool MultiMatrix(int a[3][4], int arow, int acol,
                 int b[4][5], int brow, int bcol,
                 int c[3][5], int crow, int ccol);    //函数声明

void main()
{
  if(MultiMatrix(a,3,4, b,4,5, c,3,5)){
    cout <<"illegal matrix multiply.\n";
    return;
  }

  for(int i=0; i<3; i++){    //输出矩阵乘法的结果
    for(int j=0; j<5; j++)
      cout <<setw(5) <<c[i][j];
    cout <<endl;
  }
}

bool MultiMatrix(int a[3][4], int arow, int acol,
                 int b[4][5], int brow, int bcol,
                 int c[3][5], int crow, int ccol)
{
  if(!((acol==brow)&&(crow==arow)&&(ccol==bcol)))      //正确性检查
    return 1;

  for(int i=0; i<crow; i++)       //行
    for(int j=0; j<ccol; j++){    //列
      c[i][j]=0;       //此句可以省略，因为c是全局数组
      for(int n=0; n<acol; n++)   //求一个元素
        c[i][j]+= a[i][n] * b[n][j];
    }

  return 0;
}