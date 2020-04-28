//16_3

#include <iostream.h>
#include "account.h"
#include "savings.h"
#include "checking.h"

void DoSavings(int n);
void DoChecking(int n);
void DoAccess(int n);

void main()
{
  int sele;
  while(1){
    cout <<"bank management\n\n"
         <<"0. Return\n"
         <<"1. Savings business\n"
         <<"2. Checking business\n\n"
         <<"select : ";
    cin >>sele;
    if(sele==1||sele==2)
      DoAccess(sele);
    if(sele==0)
      break;
  }
  //sanhou
  for(Account* p=Account::First(); p; ){
    Account* t=p;
    p=p->Next();
    delete t;
  }
  Account::First()=NULL;

}

void DoAccess(int s)
{
  int sele=0;
  while(1){
    cout <<"Fetching or saving\n\n"
         <<"0. Return\n"
         <<"1. Fetching\n"
         <<"2. Saving\n\n"
         <<"select : ";
    cin >>sele;
    if(sele==1||sele==2)
      if(s==1)
        DoSavings(sele);
      else
        DoChecking(sele);
    if(sele==0)
      break;
  }
  //sanhou
}

void DoSavings(int n)
{
  unsigned aN;
  float val;
  if(n==2){  //saving
    cout <<"please input some account and checking:\n";
    cin >>aN >>val;
    while(aN){
      new Savings(aN,val);
      cout <<"please input some account and checking:\n";
      cin >>aN >>val;
    }
  }else{
    cout <<"please input a account number:\n";
    cin >>aN;
    while(aN){
      for(Account* p=Account::First(); p; p=p->Next())
        if(p->AccountNo()==aN && dynamic_cast<Savings*>(p)){
          cout <<"Savings Account: "<<p->AccountNo()
               <<"  " <<p->AcntBalan() <<endl;
          break;
        }
      cout <<"please input a account number:\n";
      cin >>aN;
    }
  }
}

void DoChecking(int n)
{
  unsigned aN;
  float val;
  if(n==2){  //checking
    cout <<"please input some account and checking:\n";
    cin >>aN >>val;
    while(aN){
      new Checking(aN,val);
      cout <<"please input some account and checking:\n";
      cin >>aN >>val;
    }
  }else{
    cout <<"please input a account number:\n";
    cin >>aN;
    while(aN){
      for(Account* p=Account::First(); p; p=p->Next())
        if(p->AccountNo()==aN && dynamic_cast<Checking*>(p)){
          cout <<p->AccountNo() <<"  " <<p->AcntBalan() <<endl;
          break;
        }
      cout <<"please input a account number:\n";
      cin >>aN;
    }
  }
}

