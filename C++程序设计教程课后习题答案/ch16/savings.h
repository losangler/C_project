//*********************
//**    savings.h    **
//*********************

#ifndef SAVINGS
#define SAVINGS

#include "account.h"

class Savings :public Account{
public:
  Savings(unsigned accNo, float balan=0.0);
  virtual void Withdrawal(float amount);
protected:
  static float minbalance;
};

#endif
