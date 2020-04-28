//fixed.cpp

#include "fixed.h"
#include <iostream.h>
#include <string.h>
#include <stdlib.h>

Fixed::Fixed(unsigned accNo, float balan)
  :Savings(accNo, balan)
{
  int interval;
  cout <<"please select a number of fixed year(1, 3, 5):\n";
	cin >>interval;
	switch(interval){
		case 1: rate=1.05f;  break;
		case 3: rate=1.08f;  break;
		case 5: rate=1.1f;  break;
		default: rate=1.08f;
	}
	_strdate(validDay);
  char strYear[3];
	strcpy(strYear, &validDay[6]);
	int intYear = atoi(strYear)+interval;
	_itoa(intYear,strYear,10);
	strcpy(&validDay[6], strYear);
}

bool Fixed::VerifyDate() const
{
  char strToday[9];
	_strdate(strToday);
	return strcmp(strToday, validDay) >= 0;
}

void Fixed::Withdrawal(float amount)
{
  if(balance){
	  balance *= (VerifyDate() ? rate : 1.01f);
	  Display();
	  balance=0;
	}
}




