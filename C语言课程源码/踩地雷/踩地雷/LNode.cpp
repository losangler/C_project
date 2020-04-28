#include "LNode.h"

//����һ���յĵ�����L
void initList(LinkList &L)
{
	L=new LNode;
	L->next=NULL;
}

//�ڴ�ͷ���ĵ�����L�в���ֵΪe��Ԫ��
LNode * locateElem(LinkList L,Map e)
{
	LNode *p =L->next;
	while(p && ((p->map.x != e.x)||(p->map.y!=e.y)))//Ѱ�����������Ľ�� 
	{
		p=p->next;
	}
	return p;	//����L��ֵΪe������Ԫ�ص�λ�ã�ʧ�ܷ���NULL;
}

//��e����L��ĩβ
void addNode(LinkList &L,Map e)
{

	LNode *r = L;			//βָ��r ָ��ͷ���
	while(r->next!=NULL)
	{
		r=r->next;
	}

	LNode *p= new LNode;	//�����µĽ��

	p->map.x	 =	e.x;
	p->map.y	 =	e.y;
	p->map.code  =	e.code;
	p->map.num	 =	e.num;
	p->map.flag	 =	e.flag;

	p->next      =  NULL;
	r->next      =  p;		//���뵽��β
}
