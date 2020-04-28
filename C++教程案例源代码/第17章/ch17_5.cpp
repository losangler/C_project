//**********************
//**    ch17_5.cpp    **
//**********************

#include <iostream.h>

class Animal{
public:
  Animal(){}
  void eat(){ cout <<"eat.\n"; }
};

class Giraffe :private Animal{
public:
  Giraffe(){}
  void StretchNeck(){ cout <<"stretch neck.\n"; }
  void take(){ eat(); }      //ok
};

void Func(Giraffe & an)
{
  an.take();
}

void main()
{
  Giraffe gir;
  gir.StretchNeck();
  Func(gir);    //ok
}
