#ifndef FIXEDDEPOSIT
#define FIXEDDEPOSIT

#include "i:\c++´ð°¸\ch16\savings.h"
#include <time.h>

class Fixed :public Savings{
public:
	Fixed(unsigned accNo,float balan=0.0);
	virtual void Withdrawal(float amount);
	bool VerifyDate() const;
protected:
	float rate;
	char validDay[9];
};

#endif

