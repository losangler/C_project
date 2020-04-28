#include <iostream.h>

void main()
{
  int grade;
  cout <<"please input a number:\n";
  cin >>grade;

  if(grade>100||grade<0)
    cout <<"´íÎóµÄ³É¼¨.\n";
  else if(grade>=90)
    cout <<"A.\n";
  else if(grade>=80)
    cout <<"B.\n";
  else if(grade>=70)
    cout <<"C.\n";
  else if(grade>=60)
    cout <<"D.\n";
  else
    cout <<"E.\n";
}

