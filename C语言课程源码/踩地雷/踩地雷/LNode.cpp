#include "LNode.h"

//构造一个空的单链表L
void initList(LinkList &L)
{
	L=new LNode;
	L->next=NULL;
}

//在带头结点的单链表L中查找值为e的元素
LNode * locateElem(LinkList L,Map e)
{
	LNode *p =L->next;
	while(p && ((p->map.x != e.x)||(p->map.y!=e.y)))//寻找满足条件的结点 
	{
		p=p->next;
	}
	return p;	//返回L中值为e的数据元素的位置，失败返回NULL;
}

//将e插入L的末尾
void addNode(LinkList &L,Map e)
{

	LNode *r = L;			//尾指针r 指向头结点
	while(r->next!=NULL)
	{
		r=r->next;
	}

	LNode *p= new LNode;	//生成新的结点

	p->map.x	 =	e.x;
	p->map.y	 =	e.y;
	p->map.code  =	e.code;
	p->map.num	 =	e.num;
	p->map.flag	 =	e.flag;

	p->next      =  NULL;
	r->next      =  p;		//插入到标尾
}
