//10_4_1

#include <iostream.h>

struct Lnode
{
  double data;
  Lnode* next;
};

void ShowList(Lnode* head)
{
  for(Lnode* p=head; p; p=p->next)
    cout <<p->data <<endl;
}

void AddToEnd(Lnode* pnew, Lnode*& head)
{
  if(!head)
    head=pnew;
  else{
    Lnode* p;
    for(p=head; p->next; p=p->next);
    p->next = pnew;
  }
  pnew->next=NULL;
}

Lnode* GetNode()
{
  Lnode* item = new Lnode;
  if(item){
    item->next=NULL;
    item->data=0.0;
  }else
    cout <<"Nothing allocated\n";
  return item;
}

void main()
{
  Lnode* head=NULL;
  Lnode* temp;
  double d;
  cout <<"data? ";
  cin >>d;
  while(d>0&&(temp=GetNode())){
    temp->data=d;
    AddToEnd(temp, head);
    cout <<"data? ";
    cin >>d;
  }
  ShowList(head);
}
