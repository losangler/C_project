//10_4_3

#include <iostream.h>

struct Lnode
{
  double data;
  Lnode* next;
};

void ShowList(Lnode* head);
void AddToEnd(Lnode* pnew, Lnode*& head);
Lnode* GetNode();
void DeleteList(Lnode* head);

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
  DeleteList(head);
}

void ShowList(Lnode* head)
{
  if(head){
    cout <<head->data <<endl;
    if(head->next)
      ShowList(head->next);         //递归调用
  }
}

void AddToEnd(Lnode* pnew, Lnode*& head)
{
  if(!head){
    head=pnew;
    pnew->next=NULL;
  }else
    AddToEnd(pnew, head->next);     //递归调用
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

void DeleteList(Lnode* head)
{
  for(Lnode* p=head; p; ){
    Lnode* t=p;
    p=p->next;
    delete t;
  }
}
