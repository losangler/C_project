//************************
//**    checking.cpp    **
//************************

#include <iostream.h>
#include "account.h"
#include "checking.h"

Checking::Checking(unsigned accNo, float balan)
  :Account(accNo, balan){ remittance=other; }

void Checking::Withdrawal(float amount)
{
  float temp=amount;                //非信汇、电汇结算方式，则不收手续费
  if(remittance==remitByPost)        //若信汇，则加收30元手续费
    temp=amount+30;
  else if(remittance==remitByCable)  //若电汇，则加收60元手续费
    temp=amount+60;

  if(balance<temp)
    cout <<"Insufficient funds:balance withdrawal: " <<temp <<endl;
  else
    balance-=temp;
	Display();
}

void Checking::SetRemit(REMIT re){ remittance=re; }
