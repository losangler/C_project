//10_2

#include <iostream.h>
#include <string.h>

struct Node{
  char str[20];
  Node* next;
};
void Insert(Node*& head);

void main()
{
  Node* p;
  Node* x=new Node;
  strncpy(x->str,"hello",20);
  x->next = NULL;
  p =x;
  x=new Node;
  strncpy(x->str,"jone",20);
  x->next = p;
  p=x;
  x=new Node;
  strncpy(x->str,"good",20);
  x->next = p;
  p=x;
  x=new Node;
  strncpy(x->str,"better",20);
  x->next = p;
  p=x;

  cout <<"\n插入之前:\n";
  for(Node* pT=p; pT; pT=pT->next)
    cout <<pT->str <<"->";
  cout <<"0\n";

  Insert(p);

  cout <<"\n插入之后:\n";
  for(Node* pT=p; pT; pT=pT->next)
    cout <<pT->str <<"->";
  cout <<"0\n";
}

void Insert(Node*& head)
{
  Node* p=new Node;
  strncpy(p->str,"marit",20);
  head->str[19]='\0';
  if(!head){
    head = p;
    p->next = NULL;
    return;
  }
  if(!strcmp(head->str, "jone")){
    p->next = head;
    head = p;
    return;
  }
  Node* sp;
  for(sp=head; sp->next&& strcmp(sp->next->str,"jone"); sp=sp->next);
  p->next = sp->next;
  sp->next = p;
}

