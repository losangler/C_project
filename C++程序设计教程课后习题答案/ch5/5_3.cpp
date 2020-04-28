//5_3

#include <iostream.h>
#include <iomanip.h>

void multab1();
void multab2();
void multab3();

void main()
{
  multab1();
  multab2();
  multab3();
}

void multab1()
{
  cout <<"  *";
  for(int i=1; i<=9; i++)
    cout <<setw(4) <<i;
  cout <<"\n-----------------------------------------\n";

  for(int i=1; i<=9; i++){
    cout <<setw(3) <<i;
    for(int j=1; j<=9; j++)
      cout <<setw(4) <<i*j;
    cout <<endl;
  }
  cout <<endl <<endl;
}

void multab2()
{
  cout <<"  *";
  for(int i=1; i<=9; i++)
    cout <<setw(4) <<i;
  cout <<"\n-----------------------------------------\n";

  for(int i=1; i<=9; i++){
    cout <<setw(3) <<i;
    for(int j=1; j<=i; j++)
      cout <<setw(4) <<i*j;
    cout <<endl;
  }
  cout <<endl <<endl;
}

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