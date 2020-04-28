#include <iostream.h>

void main()
{
  int a;
  cout <<"please input a number:\n";
  cin >>a;

  int c1 = a%3 ==0;
  int c2 = a%5 ==0;
  int c3 = a%7 ==0;
  
  switch((c1<<2)+(c2<<1)+c3){
    case 0: cout <<"不能被3,5,7整除.\n"; break;
    case 1: cout <<"只能被7整除.\n"; break;
    case 2: cout <<"只能被5整除.\n"; break;
    case 3: cout <<"可以被5,7整除.\n"; break;
    case 4: cout <<"只能被3整除.\n"; break;
    case 5: cout <<"可以被3,7整除.\n"; break;
    case 6: cout <<"可以被3,5整除.\n"; break;
    case 7: cout <<"可以被3,5,7整除.\n"; break;
  }
}

