//6_3_3

#include "multab.h"

void multab3()
{
  cout <<"  *";
  for(int i=1; i<=9; i++)
    cout <<setw(4) <<i;
  cout <<"\n-----------------------------------------\n";
  
  for(int i=1; i<=9; i++){
    cout <<setw(3) <<i;
    if(i!=1)
      cout <<setw(4*i-4) <<" ";
    for(int j=i; j<=9; j++)
      cout <<setw(4) <<i*j;
    cout <<endl;
  }
  cout <<endl <<endl;
}