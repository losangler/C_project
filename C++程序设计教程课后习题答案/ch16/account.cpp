//***********************
//**    account.cpp    **
//***********************

#include <iostream.h>
#include "account.h"

Account* Account::pFirst=0;        //链表为空
int Account::count=0;              //帐户个数为0

Account::Account(unsigned accNo, float balan)
 :acntNumber(accNo),balance(balan),pNext(NULL)
{
  count++;
  if(!pFirst)
    pFirst=this;
  else{
    Account* pS=pFirst;
    for( ; pS->pNext; pS=pS->pNext); //找到最后一个结点
    pS->pNext=this;
  }
}
unsigned Account::AccountNo(){ return acntNumber; }
float Account::AcntBalan(){ return balance; }
Account*& Account::First(){ return pFirst; }
Account* Account::Next(){ return pNext; }
int Account::NoAccounts(){ return count; }
void Account::Display(){ cout <<"Account number:" <<acntNumber <<" balance: " <<balance <<endl; }
void Account::Deposit(float amount){ balance+=amount;  Display(); }
void Account::Withdrawal(float amount){ return; }
