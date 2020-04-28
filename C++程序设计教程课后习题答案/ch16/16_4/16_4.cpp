//16_4.cpp

#include <iostream.h>
#include "account.h"
#include "savings.h"
#include "checking.h"
#include "credit.h"

void DoSavings(int access);
void DoChecking(int access);
void DoAccess(int type);
void DoCredit(int access);

void main()
{
  int sele=1;
  while(sele){
    cout <<"\nbank management\n\n"
         <<"0. Return\n"
         <<"1. Savings business\n"
         <<"2. Checking business\n"
		     <<"3. Credit business\n\n"
         <<"select : ";
    cin >>sele;
    if(sele>=1 && sele <=3)  DoAccess(sele);
  }
  Account* p=Account::First();   //ртобиф╨С
  while(p){
    Account* t=p;
    p=p->Next();
    delete t;
  }
  Account::First()=NULL;
}

void DoAccess(int type)
{
  int sele=1;
  while(sele){
    cout <<"\nFetching or saving\n\n"
         <<"0. Return\n"
         <<"1. Fetching\n"
         <<"2. Saving\n\n"
         <<"select : ";
    cin >>sele;
    if(sele!=1 && sele!=2) continue;
	  switch(type){
	    case 1: DoSavings(sele); break;
	    case 2: DoChecking(sele); break;
	    case 3: DoCredit(sele); break;
		}
  }
}

void DoSavings(int access)
{
  unsigned aN;
  float val;
  if(access==2){  //saving
    cout <<"\nplease input some account and amount for saving(input 0 for end):\n";
    cin >>aN >>val;
		while(aN && val>0){
      Account* p;
			for(p=Account::First(); p; p=p->Next())  //finding
        if(p->AccountNo()==aN && dynamic_cast<Savings*>(p)){
          p->Deposit(val);
          break;
				}
			if(!p)  //not found
			  new Savings(aN,val);
      cout <<"\nplease input some account and amount for saving(input 0 for end):\n";
      cin >>aN >>val;
    }
  }else{  //fetching
    cout <<"please input a account number and amount for fetching(input 0 for end):\n";
    cin >>aN >>val;
    while(aN && val>0){
			Account* p;
	    for(p=Account::First(); p; p=p->Next())  //finding
        if(p->AccountNo()==aN && dynamic_cast<Savings*>(p)){
          p->Withdrawal(val);
          break;
				}
			if(!p)
				cout <<"error: the account number isn't found.\n"; 
			cout <<"\nplease input a account number and amount for fetching(input 0 for end):\n";
      cin >>aN >>val;
    }
  }
}

void DoChecking(int access)
{
  unsigned aN;
  float val;
  if(access==2){  //saving
    cout <<"\nplease input some account and amount for saving(input 0 for end):\n";
    cin >>aN >>val;
		while(aN && val>0){
      Account* p;
			for(p=Account::First(); p; p=p->Next())  //finding
        if(p->AccountNo()==aN && dynamic_cast<Checking*>(p)){
          p->Deposit(val);
          break;
				}
			if(!p)  //not found
			  new Checking(aN,val);
      cout <<"\nplease input some account and amount for saving(input 0 for end):\n";
      cin >>aN >>val;
    }
  }else{  //fetching
    cout <<"\nplease input a account number and amount for fetching(input 0 for end):\n";
    cin >>aN >>val;
    while(aN && val>0){
			Account* p;
	    for(p=Account::First(); p; p=p->Next())  //finding
        if(p->AccountNo()==aN && dynamic_cast<Checking*>(p)){
          p->Withdrawal(val);
          break;
				}
			if(!p)
				cout <<"error: the account number isn't found.\n"; 
			cout <<"\nplease input a account number and amount for fetching(input 0 for end):\n";
      cin >>aN >>val;
    }
  }
}

void DoCredit(int access)
{
  unsigned aN;
  float val;
  if(access==2){  //saving
    cout <<"please input some account and amount for saving(input 0 for end):\n";
    cin >>aN >>val;
		while(aN && val>0){
      Account* p;
			for(p=Account::First(); p; p=p->Next())  //finding
        if(p->AccountNo()==aN && dynamic_cast<Creditcard*>(p)){
          p->Deposit(val);
          break;
				}
			if(!p)  //not found
			  new Creditcard(aN,val);
      cout <<"\nplease input some account and amount for saving(input 0 for end):\n";
      cin >>aN >>val;
    }
  }else{  //fetching
    cout <<"\nplease input a account number and amount for fetching(input 0 for end):\n";
    cin >>aN >>val;
    while(aN && val>0){
			Account* p;
	    for(p=Account::First(); p; p=p->Next())  //finding
        if(p->AccountNo()==aN && dynamic_cast<Creditcard*>(p)){
          p->Withdrawal(val);
          break;
				}
			if(!p)
				cout <<"error: the account number isn't found.\n"; 
			cout <<"\nplease input a account number and amount for fetching(input 0 for end):\n";
      cin >>aN >>val;
    }
  }
}

