//stack.h

#ifndef STACK
#define STACK

struct Node{
  int a;
  Node* next;
};

class Stack{
public:
  Stack();
  ~Stack();
  void Put(int item);
  int Get();
protected:
  Node* head;
};

#endif
