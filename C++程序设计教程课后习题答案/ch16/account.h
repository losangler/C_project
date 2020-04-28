//*********************
//**    account.h    **
//*********************

#ifndef ACCOUNT
#define ACCOUNT

class Account{
public:
  Account(unsigned accNo, float balan=0.0);
  unsigned AccountNo();
  float AcntBalan();
  static Account*& First();
  Account* Next();
  static int NoAccounts();
  void Display();
  void Deposit(float amount);
  virtual void Withdrawal(float amount);
protected:
  static Account* pFirst;
  Account* pNext;
  static int count;
  unsigned acntNumber;
  float balance;
};

#endif