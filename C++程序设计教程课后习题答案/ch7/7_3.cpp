//7_3

#include <iostream.h>
const int num=17;
void main()
{
  int interval=3;
  int a[num];
  for(int i=0; i<num; i++)
    cout <<(a[i]=i+1) <<",";
  cout <<endl;
  int i=(interval-1)%num;
  for(int k=1; k<num; k++){
    cout <<a[i] <<",";
    a[i]=0;
    for(int j=1; !(a[i]&&(j++==interval)); i=(i+1)%num);  //数数
  }
  cout <<"\nNo." <<a[i] <<" boy has won.\n";    //输出胜利者
}
