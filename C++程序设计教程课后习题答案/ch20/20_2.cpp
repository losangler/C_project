//20_2.cpp

#include <iostream.h>

template<class T>
class Stack{
public:
  Stack();
  ~Stack(){ delete[] stack; }
  void Push(T& n);
  T Pop();
private:
  static const int SIZE;
  T* stack;
  int tos;
};

template<class T>
const int Stack<T>::SIZE = 100;

template<class T>
Stack<T>::Stack()
  :tos(0)
{
  stack = new T[SIZE];
}

template<class T>
void Stack<T>::Push(T& n)
{
  if(tos==100) return;
  stack[tos++] = n;
}

template<class T>
T Stack<T>::Pop()
{
  if(tos==0) return T(0);
  return stack[--tos];
}

void main()
{
  Stack<int> ai;
  Stack<char> ac;
  Stack<float> af;
  
  int i[3]={3,5,7};
  ai.Push(i[0]);
  ai.Push(i[1]);
  ai.Push(i[2]);

  char c[3]={'2','5','9'};
	ac.Push(c[0]);
  ac.Push(c[1]);
  ac.Push(c[2]);

  float f[2]={1.5,3.8};
	af.Push(f[0]);
  af.Push(f[1]);
  
  cout <<ai.Pop() <<" ";
	cout <<ai.Pop() <<" ";
	cout <<ai.Pop() <<endl;
  cout <<ac.Pop() <<" ";
	cout <<ac.Pop() <<" ";
	cout <<ac.Pop() <<endl;
  cout <<af.Pop() <<" ";
	cout <<af.Pop() <<" " <<endl;
}
