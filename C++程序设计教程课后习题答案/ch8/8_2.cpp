//8_2

#include <iostream.h>

bool assign();
int num,interval;

void main()
{
  if(!assign())
    return;
  int* a=new int[num];
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
  delete[]a;
}

bool assign()
{
  while(1){
    cout <<"please input the number of boys,the interval:\n";
    cin >>num >>interval;

    if(num>1&&interval>1&&interval<num)
      return true;

    bool sign=true;
    while(sign){
      cout <<"error on your input data.\n";
      cout <<"please select following operation:\n";
      cout <<"\t\tstop at once!  ----- 1\n";
      cout <<"\t\tinput again. ------- 2\n";
      cout <<"\t\tas default values -- 3\n\n";
      int sele=0;
      cin >>sele;
      switch(sele){
        case 1: return false;
        case 2: sign=false; break;
        case 3: num=10; interval=3; return true;
      }  //end of switch
    }  //end of inner while
  }  //end of out while
}

