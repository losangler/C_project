// 踩地雷.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "LNode.h"
#include <windows.h>
#include <time.h>
#include <conio.h>


#define	 NUMBER 17//雷的数量
#define  SIZE  150	//地图大小


typedef struct XY	//坐标
{
	int x;
	int y;
}XY;

//存档
void stopAndKeep(LinkList L)
{
	cout<<endl;
	cout<<"回车可存档!"<<endl;
	cout<<"按任意键继续...(除了“上下左右”四个方向键)";
	int c;
	c=getch();
	if(c==13)
	{
		FILE * pFile=fopen("../file.txt","w");
		LNode * p=L->next;
		while(p!=NULL)
		{
			fprintf(pFile,"%d %d %d %d %d ",p->map.x,
											p->map.y,
											p->map.code,
											p->map.num,
											p->map.flag);
			p=p->next;
		}
		cout<<endl<<endl;
		cout<<"存档成功"<<endl<<endl;
		fclose(pFile);
		system("pause");
	}
}

//产生随机坐标
void randNumber(XY &xy)
{

	int x;
	int y;
	//do{
	//	x=rand()%15;
	//	y=rand()%10;
	//}while (x==y);

	x=rand()%15;
	y=rand()%10;

	xy.x=x;
	xy.y=y;
}

//把周围有雷的空地填上数字
void addNumber(LinkList &L)
{
	LNode *p=L;
	while( (p=p->next)!=NULL )
	{
		//如果自己是雷 ,下一个
		if(p->map.code==2)
		{
			continue;
		}
		int count=0;//记录周围有多少雷
		for(int i=-1;i<2;i++)	//找周围的雷
		{
			Map m;
			m.x = p->map.x + i;
			for(int j=-1;j<2; j++)
			{
				if(i==0&&j==0)
					continue;
				m.y = p->map.y +j ;
				LNode *q =locateElem(L,m);
				if(q!=NULL && q->map.code==2)		
					count++;	//记录雷的数量
			}
		}

		if(count==0)
		{
			p->map.code=1;
		}
		else
		{
			p->map.code	= 3;
			p->map.num	= count;
		}
	}
}

//新游戏创建地图
void createMap(LinkList &L)
{
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<15; j++)
		{
			Map m;
			m.code=1;
			m.flag=0;
			m.num=0;
			m.x=j;
			m.y=i;
			addNode(L,m);
		}
	}

	//创建50个随机坐标，将此位置变为地雷
	for(int i=0;i<NUMBER;i++)
	{
		XY	xy;
		randNumber(xy);
		Map temp;
		temp.x=xy.x;
		temp.y=xy.y;

		//修改map坐标xy的code
		LNode * p=locateElem(L,temp);

		if(p->map.code==2)		//如果已经是地雷了，重新生成新的位置
			i--;
		p->map.code=2;
	}

	addNumber(L);
}

// return 地图当前位置的对应图片
string getGraph(Map m)
{
	string graph="";
	if(m.flag==0)
	{
		graph="■";
	}
	else
	{
		if(m.code==1)
		{
			graph="〇";		//空地
		}
		else if(m.code==2)
		{
			graph="★";		//地雷
		}
		else if(m.code==3)
		{
			switch (m.num)
			{
			case 1:
				graph="1 ";break;
			case 2:
				graph="2 ";break;
			case 3:
				graph="3 ";break;
			case 4:
				graph="4 ";break;
			case 5:
				graph="5 ";break;
			case 6:
				graph="6 ";break;
			case 7:
				graph="7 ";break;
			case 8:
				graph="8 ";break;
			default:
				break;
			}
		}
	}

	return graph;
}

//显示地图
void showMap(LinkList L)
{
	LNode * p=L->next;
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<15; j++)
		{
			string str=getGraph(p->map);
			cout<<str<<"";
			p=p->next;
		}
		cout<<endl;
	}

}

//开始游戏
void startGame(LinkList &L)
{
	int count=0;
	while(count < SIZE-NUMBER )
	{

		system("cls");
		showMap(L);
		stopAndKeep(L);

		//随机一个坐标，模拟点击
		XY	xy;
		randNumber(xy);
		Map temp;
		temp.x=xy.x;
		temp.y=xy.y;

		//找到随机的坐标
		LNode * p=locateElem(L,temp);

	
		if(p->map.flag==1)	//判断是否已经点过
		{
			continue;
		}
		else
		{
			count++;
			//如果没有点过 判断点击的是什么
			if(p->map.code==2)
			{
				p->map.flag=1;
				system("cls");
				showMap(L);
				break;
			}
			else
				p->map.flag=1;
		}
	
	}
	cout<<endl<<endl;
	if(count==SIZE-NUMBER)
		cout<<"胜利！"<<endl<<endl;
	else
		cout<<"踩到地雷，失败！"<<endl<<endl;
}

//读取存档 
int readFile(LinkList &L)
{
	Map m;
	int x,y,code,num,flag,ret=1;

	FILE * pFile=fopen("../file.txt","r");
	if(pFile==NULL)
	{
		cout<<"Open File Error!"<<endl;
		return 0;
	}
	else
	{	
		while(ret>=0)
		{
			ret=fscanf(pFile,"%d%d%d%d%d ",&x,&y,&code,&num,&flag);
			m.x=x;
			m.y=y;
			m.code=code;
			m.num=num;
			m.flag=flag;
			addNode(L,m);
		}
		return 1;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"**************************************************************"<<endl;
	cout<<"**                                                          **"<<endl;
	cout<<"**                                                          **"<<endl;
	cout<<"**                   踩    地    雷                         **"<<endl;
	cout<<"**                                                          **"<<endl;
	cout<<"**                                                          **"<<endl;
	cout<<"**************************************************************"<<endl<<endl;

	cout<<"*********		1、新游戏      *********"<<endl<<endl;

	cout<<"*********		2、读取存档      *********"<<endl<<endl<<endl;

	cout<<"*********  提示：在游戏过程中，按回车可以存档哦！  ****"<<endl<<endl;
	

	int choose;//选择 新游戏 还是 读档
	do{
		cout<<"请输入1/2选择:";
		cin>>choose;
	}while(choose!=1 && choose!=2);

	cout<<endl<<endl;

	srand((unsigned)time(NULL));
	LinkList L;
	initList(L);

	if(choose==1)
	{
		createMap(L);
		startGame(L);
	
	}
	else
	{
		if(readFile(L)==0)
			return 0;
		else
			startGame(L);
	}
	return 0;
}

