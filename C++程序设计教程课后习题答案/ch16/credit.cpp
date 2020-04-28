#include "credit.h"
#include <string.h>
#include <iostream.h>

float Creditcard::minbalance = 5000.0;

Creditcard::Creditcard(unsigned accNo, float balan)
  :Savings(accNo,balan)
{
  char str[11];
  cout <<"your own password(less than 10 chars)\n";
  cin >>str;
  strncpy(password,str,10);
  password[10]='\0';
}

bool Creditcard::Verify(char* s)
{
  return strcmp(s, password)==0;
}

void Creditcard::Withdrawal(float amount)
{
   char str[11];
   cout <<"password(max 10 characters) for verifing?\n";
   cin >>str;
   if(!Verify(str)){
	   cout <<"sorry! error on your password.\n";
	   return;
   }
   if(balance + minbalance < amount)
	   cout <<"Insufficient funds:balance withdrawal: " <<amount <<endl;
   else
	   balance-=amount;
	 Display();
}

