//time.h

#ifndef TIME
#define TIME

class Time{
public:
  void Set(int h,int m,int s);
  void Display();
protected:
  int hour;
  int minute;
  int second;
};

#endif

