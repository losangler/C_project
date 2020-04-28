//class.h

#ifndef CLASS
#define CLASS

class Class{
public:
  Class(int v):value(v){ staticV++; }
  ~Class(){ staticV--; }
  int Get(){ return value; }
  static int staticV;
protected:
  int value;
};

#endif

