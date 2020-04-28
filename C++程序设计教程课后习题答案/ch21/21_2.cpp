#include <iostream.h>

class A{
public:
	class Error{};
  A()
	{
	  n = new int;
		init();
	}
private:
  int* n;
  void init()
	{
    //do something ...
	  throw Error();
	}
};

void main()
{
  try{
    A a;
  }
  catch(A::Error&){
    cout <<"error when initialize.\n";
  }
}
   
