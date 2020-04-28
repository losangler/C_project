#include<iostream>
#include<string>
using namespace std;

//地图
typedef struct Map
{
	int	 x;			//地图坐标
	int  y;
	int	 code;		//地图样式 1空地/2地雷/3数字
	int  num;		//地图样式如果是数字，记录数字是多少
	int	 flag;		//此地是否已经被走过
}Map;

//结点
typedef struct LNode
{
	Map map;			//数据域
	struct LNode * next;	//指针域
}LNode, *LinkList;

//构造一个空的单链表L
void initList(LinkList &L);

//在L中找到值为e的，并返回
LNode * locateElem(LinkList L,Map e);

//将e插入L的末尾
void addNode(LinkList &L,Map e);



