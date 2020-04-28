//7_7

#include <iostream.h>

int a[3][3]={{5,7,8},{2,-2,4},{1,1,1}};
int b[3][3]={{4,-2,3},{3,9,4},{8,-1,2}};
int c[3][3];

void main()
{
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      c[i][j]=a[i][j]+b[i][j];
      cout <<c[i][j] <<" ";
    }
    cout <<endl;
  }
}

