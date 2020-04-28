//stack.cpp

#include "stack.h"
#include <stdlib.h>
#include <iostream.h>

Stack::Stack():head(NULL){}
void Stack::Put(int item)
{
  Node* p = new Node;
  p->a = item;
  p->next = head;
  head = p;
}

Stack::~Stack()
{
  for(Node* p=head; p;){
    Node* t = p;
    p=p->next;
    delete t;
  }
}

int Stack::Get()
{
  if(!head){
    cerr <<"error access stack underflow.\n";
    exit(1);
  }
  int result = head->a;
  Node* p = head;
  head = head->next;
  delete p;
  return result;
}

