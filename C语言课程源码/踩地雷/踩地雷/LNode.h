#include<iostream>
#include<string>
using namespace std;

//��ͼ
typedef struct Map
{
	int	 x;			//��ͼ����
	int  y;
	int	 code;		//��ͼ��ʽ 1�յ�/2����/3����
	int  num;		//��ͼ��ʽ��������֣���¼�����Ƕ���
	int	 flag;		//�˵��Ƿ��Ѿ����߹�
}Map;

//���
typedef struct LNode
{
	Map map;			//������
	struct LNode * next;	//ָ����
}LNode, *LinkList;

//����һ���յĵ�����L
void initList(LinkList &L);

//��L���ҵ�ֵΪe�ģ�������
LNode * locateElem(LinkList L,Map e);

//��e����L��ĩβ
void addNode(LinkList &L,Map e);



