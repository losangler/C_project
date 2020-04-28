//*********************
//**    listtmp.h    **
//*********************
#ifndef LIST
#define LIST

#include <iostream>

template<class T> class List{
public:
  List();
  void Add(T&);
  void Remove(T&);
  T* Find(T&);
  void PrintList();
  ~List();
protected:
  struct Node{
    Node* pNext;
    T* pT;
  };
  Node *pFirst;        //链首结点指针
};

template<class T> List<T>::List()
{
  pFirst = 0;
}

template<class T>
void List<T>::Add(T& t)
{
  Node* temp = new Node;             //①
  temp->pT =&t;                      //②
  temp->pNext = pFirst;              //③
  pFirst = temp;                     //④
}

template<class T>
void List<T>::Remove(T& t)
{
  Node *q = 0;                       //用来定位待删的结点
  if(*(pFirst->pT)==t){              //T类中==须有定义    q = pFirst;
    pFirst = pFirst->pNext;          //待删结点在链首时的脱链
  }else{
    for(Node* p=pFirst; p->pNext; p=p->pNext)   //顺链查找      if(*(p->pNext->pT)==t){
        q = p->pNext;
        p->pNext = q->pNext;           //⑤
        break;
      }
  }
  if(q){
    delete q->pT;                     //⑥
    delete q;                         //⑦
  }
}

template<class T>
T* List<T>::Find(T& t)
{
  for(Node* p=pFirst; p; p=p->pNext)
    if(*(p->pT)==t)
      return p->pT;

  return 0;
}

template<class T>
void List<T>::PrintList()
{
  for(Node* p=pFirst; p; p=p->pNext)
    cout <<*(p->pT)<<" ";             //须有T的友元处理T对象输出
  cout <<endl;
}

template<class T>
List<T>::~List()
{
  Node* p;
  while(p = pFirst){
    pFirst = pFirst->pNext;
    delete p->pT;
    delete p;
  }
  pFirst = 0;
}

#endif

