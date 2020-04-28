//16_1.cpp

#include <iostream.h>
#include "account.h"
#include "savings.h"
#include "checking.h"

void main()
{
  Savings* pS;
  unsigned aN;
  float val;
  cout <<"please input some account and savings:\n";
  cin >>aN >>val;
  while(aN){
    pS=new Savings(aN,val);
    cout <<"please input some account and savings:\n";
    cin >>aN >>val;
  }
  for(Savings* p=(Savings*)pS->First(); p; p=(Savings*)p->Next())
    cout <<p->AccountNo() <<"  " <<p->AcntBalan() <<endl;

  for(Savings* p=(Savings*)pS->First(); p; ){
    Savings* t=p;
    p=(Savings*)p->Next();
    delete t;
  }
  pS->First()=NULL;

  Checking* pC;
  cout <<"please input some account and checking:\n";
  cin >>aN >>val;
  while(aN){
    pC=new Checking(aN,val);
    cout <<"please input some account and checking:\n";
    cin >>aN >>val;
  }
  for(Checking* p=(Checking*)pC->First(); p; p=(Checking*)p->Next())
    cout <<p->AccountNo() <<"  " <<p->AcntBalan() <<endl;

  for(Checking* p=(Checking*)pC->First(); p; ){
    Checking* t=p;
    p=(Checking*)p->Next();
    delete t;
  }
  pC->First()=NULL;
}

