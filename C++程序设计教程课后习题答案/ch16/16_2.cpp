//16_2.cpp

#include <iostream.h>
#include "account.h"
#include "savings.h"
#include "checking.h"

void main()
{
  unsigned aN;
  float val;
  cout <<"please input some account and savings:\n";
  cin >>aN >>val;
  while(aN){
    new Savings(aN,val);
    cout <<"please input some account and savings:\n";
    cin >>aN >>val;
  }

  cout <<"please input some account and checking:\n";
  cin >>aN >>val;
  while(aN){
    new Checking(aN,val);
    cout <<"please input some account and checking:\n";
    cin >>aN >>val;
  }
  for(Account* p=Account::First(); p; p=p->Next())
    cout <<p->AccountNo() <<"  " <<p->AcntBalan() <<endl;

  for(Account* p=Account::First(); p; ){
    Account* t=p;
    p=p->Next();
    delete t;
  }
  Account::First()=NULL;
}
