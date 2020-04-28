// �ȵ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "LNode.h"
#include <windows.h>
#include <time.h>
#include <conio.h>


#define	 NUMBER 17//�׵�����
#define  SIZE  150	//��ͼ��С


typedef struct XY	//����
{
	int x;
	int y;
}XY;

//�浵
void stopAndKeep(LinkList L)
{
	cout<<endl;
	cout<<"�س��ɴ浵!"<<endl;
	cout<<"�����������...(���ˡ��������ҡ��ĸ������)";
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
		cout<<"�浵�ɹ�"<<endl<<endl;
		fclose(pFile);
		system("pause");
	}
}

//�����������
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

//����Χ���׵Ŀյ���������
void addNumber(LinkList &L)
{
	LNode *p=L;
	while( (p=p->next)!=NULL )
	{
		//����Լ����� ,��һ��
		if(p->map.code==2)
		{
			continue;
		}
		int count=0;//��¼��Χ�ж�����
		for(int i=-1;i<2;i++)	//����Χ����
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
					count++;	//��¼�׵�����
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

//����Ϸ������ͼ
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

	//����50��������꣬����λ�ñ�Ϊ����
	for(int i=0;i<NUMBER;i++)
	{
		XY	xy;
		randNumber(xy);
		Map temp;
		temp.x=xy.x;
		temp.y=xy.y;

		//�޸�map����xy��code
		LNode * p=locateElem(L,temp);

		if(p->map.code==2)		//����Ѿ��ǵ����ˣ����������µ�λ��
			i--;
		p->map.code=2;
	}

	addNumber(L);
}

// return ��ͼ��ǰλ�õĶ�ӦͼƬ
string getGraph(Map m)
{
	string graph="";
	if(m.flag==0)
	{
		graph="��";
	}
	else
	{
		if(m.code==1)
		{
			graph="��";		//�յ�
		}
		else if(m.code==2)
		{
			graph="��";		//����
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

//��ʾ��ͼ
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

//��ʼ��Ϸ
void startGame(LinkList &L)
{
	int count=0;
	while(count < SIZE-NUMBER )
	{

		system("cls");
		showMap(L);
		stopAndKeep(L);

		//���һ�����꣬ģ����
		XY	xy;
		randNumber(xy);
		Map temp;
		temp.x=xy.x;
		temp.y=xy.y;

		//�ҵ����������
		LNode * p=locateElem(L,temp);

	
		if(p->map.flag==1)	//�ж��Ƿ��Ѿ����
		{
			continue;
		}
		else
		{
			count++;
			//���û�е�� �жϵ������ʲô
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
		cout<<"ʤ����"<<endl<<endl;
	else
		cout<<"�ȵ����ף�ʧ�ܣ�"<<endl<<endl;
}

//��ȡ�浵 
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
	cout<<"**                   ��    ��    ��                         **"<<endl;
	cout<<"**                                                          **"<<endl;
	cout<<"**                                                          **"<<endl;
	cout<<"**************************************************************"<<endl<<endl;

	cout<<"*********		1������Ϸ      *********"<<endl<<endl;

	cout<<"*********		2����ȡ�浵      *********"<<endl<<endl<<endl;

	cout<<"*********  ��ʾ������Ϸ�����У����س����Դ浵Ŷ��  ****"<<endl<<endl;
	

	int choose;//ѡ�� ����Ϸ ���� ����
	do{
		cout<<"������1/2ѡ��:";
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

