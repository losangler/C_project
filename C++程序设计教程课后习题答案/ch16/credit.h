#ifndef CREDITCARD
#define CREDITCARD

#include "i:\C++´ð°¸\ch16\savings.h"

class Creditcard :public Savings{
public:
  Creditcard(unsigned accNo, float balan=0.0);
  bool Verify(char *);
  virtual void Withdrawal(float amount);
protected:
  static float minbalance;
  char password[11];
};

#endif

