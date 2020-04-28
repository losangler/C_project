//***********************
//**    ch12_15.cpp    **
//***********************
# include <iostream.h>
class A{
public:
  A(int j):age(j),num(age+1)
  {
    cout <<"age:" <<age <<",num:" <<num <<endl;  }
protected:
  int num;
  int age;
};

void main()
{
  A sa(15);
}