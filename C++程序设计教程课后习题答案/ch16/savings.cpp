//***********************
//**    savings.cpp    **
//***********************

#include <iostream.h>
#include "account.h"
#include "savings.h"

float Savings::minbalance=500.0;     //…Ë÷√Õ∏÷ß∑∂Œß

Savings::Savings(unsigned accNo, float balan)
  :Account(accNo, balan){}

void Savings::Withdrawal(float amount)
{
  if(balance+minbalance<amount)
    cout <<"Insufficient funds withdrawal: " <<amount <<endl;
  else
    balance-=amount;
	Display();
}
