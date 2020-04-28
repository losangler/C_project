#include<iostream> //实现输入输出
#include<fstream>  //实现外部文件储存数据
#include<string>   //实现字符串的输入
#include<windows.h>//实现控制台窗口的颜色变化
using namespace std;


//===========================================================================================================

enum GoodsType //商品类别
{
	 Food=1,   //食品类 
     Drink,    //饮品类
	 Wear,     //穿着类
     Commodity //日用品类 
	 
};
//不用结构而用枚举是因为商品的类型储存是这四个里面的其中一个，并非全部;

//===========================================================================================================

struct Goods       //产品进货的基本信息
{    
	string code;   //产品编号
	string name;   //产品名称
	string place;  //生产地点
	string brand;  //生产厂家
	double price;  //进货单价
	               //进货总价
	double totalPrice;
	int num,staticnum;//产品数量
	GoodsType type;//产品类别
	               //入库时间
	int year,month,day;
	Goods *next;   //设置链表的节点（实现添加功能） 
};

//===========================================================================================================

struct SellRecord    //商品出货的售出信息
{ 
	string sellcode; //出货编码 
	string sellname; //已出售的商品名称
	string sellbrand;//已出售商品的厂家   
	int sellNum;     //出售数量
	double sellPrice;//出售价格
	double sellmoney;//总销售额 
	double profit;   //利润 
	                 //出库日期
	int sellyear,sellmonth,sellday; 
	SellRecord *next;//设置链表的节点（实现商品出货信息的统计）
}; 

//===========================================================================================================
	
class GoodsFunction         //产品各项功能的实现 
{ 
public:
	GoodsFunction();        //构造函数 
	~GoodsFunction(){}      //析构函数 
	void DisplayMainMenu(); //主菜单界面，显示可选功能 
	void AddGoodsInfo();    //添加产品信息(也是进货功能的实现）
	void DisplayGoodsInfo();//浏览产品信息
    void Search();          //搜索界面显示
	void SearchByCode();    //按照产品编号搜索产品信息
	void SearchByName();    //按照产品名称搜索产品信息
	void SearchByType();    //按照产品类别搜索产品信息
	void SearchByBrand();   //按照产品品牌搜索产品信息
	void SearchByTime();    //按照进货日期搜索产品信息
    void Edit();            //编辑界面显示
	void EditGoodsInfo();   //编辑产品信息
    void DeleteGoodsInfo(); //删除产品信息
	void SellGoodsInfo();   //出售产品信息（也是出货功能的实现）
	void SaveGoodsInfo();   //保存产品信息
private:
//	int sellnumber          //定义销售数量 
	int times;              //进货次数 
	int selltimes;          //出货次数 
	Goods *head;            //设置头结点
	SellRecord *top;        //设置头结点	
	Goods *DeleteHead;      //设置头结点 
};

//===========================================================================================================

GoodsFunction::GoodsFunction()//定义构造函数，给私有属性初始化 
{
//	sellnumber=0; 
	times=0;
	selltimes=0;
	head=new Goods;          //创造空间（链表），储存货物信息  
	head->next=NULL;         //下个空间为空 
	DeleteHead=new Goods;    //相当于收集删除信息的回收站 
	DeleteHead->next=NULL;   //下个空间为空
	top=new SellRecord;      //创造出货信息的储存空间 
	top->next=NULL;          //下个空间为空 
}


//===========================================================================================================

void GoodsFunction::DisplayMainMenu()//实现主菜单界面 
{
	cout<<"  =================================================================\n";
    cout<<" ┋                                                                ┋\n";
    cout<<" ┋                   欢迎使用商品库存管理系统                     ┋\n";
    cout<<" ┋                                                                ┋\n";
    cout<<" ┋                                                                ┋\n";
    cout<<" ┋                        【商品进货】…(a)                       ┋\n";
    cout<<" ┋                                                                ┋\n";
    cout<<" ┋                        【商品编辑】…(b)                       ┋\n";
	cout<<" ┋                                                                ┋\n";
    cout<<" ┋                        【商品删除】…(c)                       ┋\n";
	cout<<" ┋                                                                ┋\n";
    cout<<" ┋                   ┋—> 【按照编号查询】…(d)                   ┋\n";
	cout<<" ┋                   ┋                                            ┋\n";
	cout<<" ┋                   ┋—> 【按照名称查询】…(e)                   ┋\n";
	cout<<" ┋                   ┋                                            ┋\n";
	cout<<" ┋    【商品查询】—>┋—> 【按照类别查询】…(f)                   ┋\n";
	cout<<" ┋                   ┋                                            ┋\n";
	cout<<" ┋                   ┋—> 【按照厂家查询】…(g)                   ┋\n";
	cout<<" ┋                   ┋                                            ┋\n";
	cout<<" ┋                   ┋—> 【按照进货日期查询】…(h)               ┋\n";
	cout<<" ┋                                                                ┋\n";
    cout<<" ┋                        【商品出货】…(i)                       ┋\n";
    cout<<" ┋                                                                ┋\n";
    cout<<" ┋                        【商品统计】…(j)                       ┋\n";
	cout<<" ┋                                                                ┋\n";
    cout<<" ┋                        【信息保存】…(k)                       ┋\n";
	cout<<" ┋                                                                ┋\n";
    cout<<" ┋                                                                ┋\n";
    cout<<" ┋                          退出系统…(o)                         ┋\n";
    cout<<" ┋                                                                ┋\n";
    	cout<<"  =================================================================\n";
    cout<<"\n                     亲，请输入您要操作的编号：";           
}

//===========================================================================================================

//实现添加商品进货信息
void GoodsFunction::AddGoodsInfo()
{
	char num,judge;
	Goods *tail=head,*p;
	bool isRight;
	cout<<"          ☆☆☆☆☆☆现在进行商品进货信息的添加☆☆☆☆☆☆          "<<endl;
	while(tail->next!=NULL)
		tail=tail->next;//令tail指向链表中最后一个节点
	do
	{   cout<<"  =================================================================\n"; 
		isRight=0;
		p=new Goods;
		cout<<"请选择商品类别:"<<endl;
		cout<<"1.食品类 2.饮品类 3.穿着类 4.日用品类"<<endl;
		cout<<"请输入相应编号:";
		do
		{
			cin>>num;
			if(num>='1'&&num<='4')//判断用户输入编号是否存在
				isRight=1;
			else
			{
				cout<<"×××您输入的编号不存在！×××"<<endl;
			    cout<<"※※※请选择正确的商品类别:";
			}
		}while(isRight==0);//输入编号无误可用时跳出循环
		if(num=='1')p->type=Food;
		if(num=='2')p->type=Drink;
		if(num=='3')p->type=Wear;
		if(num=='4')p->type=Commodity;
		cout<<"您进货的商品类别为("<<p->type<<")类"<<endl;//表示商品类别
		cout<<"请输入进货商品的编号: ";
        cin>>p->code;
		do
		{
			Goods *q=head->next;
			while(q!=NULL&&q->code!=p->code)//当q指向NULL或输入的编号与之前编号重复时跳出循环
				q=q->next;                  //从头开始检索到尾 
			if(q==NULL)//当p指向NNULL且编号不重复时
				isRight=1;
			else//编号重复时
			{
				cout<<"∑(っ°Д°)っ存在该编号的货物！！！请重新输入编号:";
			    cin>>p->code;
			}
		}while(isRight==0);
		cout<<"请输入进货商品的名称：";
		cin>>p->name;
		cout<<"请输入生产厂家："; 
		cin>>p->brand;
		cout<<"请输入生产地址："; 
		cin>>p->place;
		cout<<"请输入进货单价：";
		cin>>p->price;
		cout<<"请输入商品数量：";
		cin>>p->num;
		p->staticnum=p->num;
		//自动计算总价储存信息 
		p->totalPrice=p->price*p->num;
        cout<<"请输入入库时间（年/月/日）：";
		cin>>p->year>>p->month>>p->day;
		tail->next=p;//将p链接到链表的尾部，填补空空间 
		p->next=NULL;//将下个空间放空 
		tail=p;      //移动链尾到尾部 
		//amount++;//商品量加一
		cout<<"(^_^)☆进货信息添加成功！！！想要继续添加吗(y/n):";
		cin>>judge;
		while(judge!='y'&&judge!='n')
		{
			cout<<"×××指令错误×××请输入<y/n>！"<<endl;
		    cout<<"进货信息添加成功！！！想要继续添加吗？(y/n):";
			cin>>judge;
		}
	}while(judge=='y');
	cout<<endl;
	cout<<"……进货信息已处理完毕……"<<endl;
	cout<<"……按任意键返回主菜单……"<<endl;
	getchar();//读取cin输入时的回车符，将其过度掉 
	getchar();//获取任意键返回主菜单 
}

//===========================================================================================================

//打印输出功能 
void output1(){
	
	cout<<"===========================================================================\n"; 
	cout<<"编号"<<"\t"<<"名称"<<"\t"<<"产地"<<"\t"<<"单价"<<"\t"<<"数量"<<"\t"<<"总价"<<endl;		    
} 
//-----------------------------------------------------------------------------------------------------------
void output2(){
    cout<<endl; 
	cout<<"商品类型"<<"\t"<<"生产厂家"<<"\t\t"<<"进货时间"<<endl;		    
} 

//===========================================================================================================

//实现修改信息的界面 
void GoodsFunction::Edit()
{
	cout<<" ====================================================================\n";
	cout<<" ┋                     ┋ 【编辑商品类型】…(1)                   ┋\n";
	cout<<" ┋                     ┋                                         ┋\n";
	cout<<" ┋                     ┋ 【编辑商品名称】…(2)                   ┋\n";
	cout<<" ┋                     ┋                                         ┋\n";
	cout<<" ┋                     ┋ 【编辑生产厂家】…(3)                   ┋\n";
	cout<<" ┋         【商品编辑】┋                                         ┋\n";
	cout<<" ┋                     ┋ 【编辑商品单价】…(4)                   ┋\n";
	cout<<" ┋                     ┋                                         ┋\n";
	cout<<" ┋                     ┋ 【编辑商品数量】…(5)                   ┋\n";
	cout<<" ┋                     ┋                                         ┋\n";
	cout<<" ┋                     ┋ 【编辑进货时间】…(6)                   ┋\n";
    cout<<" ====================================================================\n";
	cout<<"\n                     亲，请输入您要操作的编号：";  
	getchar();
}

//===========================================================================================================

//定义编辑商品信息函数，以寻找名称来实现，也可以以编号来实现 
void GoodsFunction::EditGoodsInfo()
{
	    char judge,item,number;
		Goods *p;
		bool isRight;
		string EditCode;
		cout<<"          ☆☆☆☆☆☆现在进行商品信息的编辑☆☆☆☆☆☆          "<<endl;
		do
		{   cout<<"===========================================================================\n"; 
			p=head->next;//设置检索起点 
			isRight=0;
			cout<<"请输入您要修改的产品的编号：";
			cin>>EditCode;
			while(p->next!=NULL&&p->code!=EditCode)
				p=p->next;//逐个寻找 
			if(p->code==EditCode)//找到了要编辑的对象 
			{ isRight=1; 
              output1();		
        cout<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->num<<"\t"<<p->totalPrice<<"\t"<<endl;
              output2();
        cout<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	 
		cout<<"===========================================================================\n";    
				cout<<"确认修改此产品的信息吗⊙(^ ◇^)⊙？<y/n>";
				cin>>judge;
				while(judge!='y'&&judge!='n')
				{
					cout<<"×××指令错误×××请输入<y/n>！";
					cin>>judge;
				}
				if(judge=='y')
				{
					system("cls");//清屏跳转GoodsFunction::Edit()的编辑页面 
					GoodsFunction::Edit();//类外调用成员函数Edit要用作用域符::  
					cin>>item;//选择修改项目 
		switch(item)
		{ 
         case'1':
		cout<<"请输入此商品的类别:\t1.食品类\t 2.饮品类\t 3.穿着类\t 4.日用品类"<<endl;
		do
		{	isRight=1;
		    cin>>number;
			if(number<'1'&&number>'4')
			{
				isRight=0;
				cout<<"(×人×)您输入的类别编号不存在！"<<endl;
			    cout<<"※※※请选择正确的商品类别:";
			}
		}while(!isRight);
		//实现对货物信息的添加 
		if(number=='1')p->type=Food;
		if(number=='2')p->type=Drink;
		if(number=='3')p->type=Wear;
		if(number=='4')p->type=Commodity;
		cout<<"\n                  (^_^)☆商品信息编辑成功！"<<endl;
		break;						
		case'2':
		cout<<"请输入此商品的名称：";
		cin>>p->name;
		cout<<"\n                  (^_^)☆商品信息编辑成功！"<<endl;
		break;
		case'3':
		cout<<"请输入商品的生产厂家："; 
		cin>>p->brand;
		cout<<"\n                  (^_^)☆商品信息编辑成功！"<<endl;
		break;
		case'4':
		cout<<"请输入此商品的单价：";
		cin>>p->price;
		p->totalPrice=p->num*p->price;
		cout<<"\n                  (^_^)☆商品信息编辑成功！"<<endl;
		break;
		case'5':
		cout<<"请输入此商品数量：";
		cin>>p->num;
		p->staticnum=p->num;
		p->totalPrice=p->num*p->price;
		cout<<"\n                  (^_^)☆商品信息编辑成功！"<<endl;
		break;
		case'6':
		cout<<"请输入进货的时间（年/月/日）：";
		cin>>p->year>>p->month>>p->day;
		cout<<"\n                  (^_^)☆商品信息编辑成功！"<<endl;
		break;
		default:
		cout<<"\n                  ∑(っ°Д°)っ编号输入不正确！"<<endl;
		break;       	
		}
//		cout<<"\n                  (^_^)☆商品信息编辑成功！"<<endl;	
		}
		else 
		cout<<"\n                  (^_^)☆取消编辑成功！"<<endl;
			}
			if(isRight==0) //未找到要编辑的对象 
			{
			  cout<<"〒▽〒对不起，您要编辑的商品不存在！！（是不是编号输错了呢？再输一次吧！或者去查询商品信息看看吧！）"<<endl;
                     
			}
			cout<<"\n                  您想要继续编辑吗？(y/n):";
			cin>>judge;
			while(judge!='y'&&judge!='n')
			{
				cout<<"\n                  ×××指令错误×××请输入<y/n>！"<<endl;
				cout<<"\n                  ※※※您想要继续编辑商品信息吗？(y/n):";
				cin>>judge;
			}
		}while(judge=='y');
		cout<<endl;
	    cout<<"……商品信息编辑完毕！……"<<endl;
	    cout<<"……按任意键返回主菜单……"<<endl;
		getchar();
		getchar();
}

//===========================================================================================================

//实现商品信息的删除
void GoodsFunction::DeleteGoodsInfo()
{
	Goods *q=head,*p,*tail=DeleteHead;
	p=new Goods;
	char judge;
	bool isRight=0;
	string Deletecode;//定义删除的编码  
	while(tail->next!=NULL)
		tail=tail->next;
	cout<<"          ☆☆☆☆☆☆现在进行商品信息的删除☆☆☆☆☆☆          "<<endl;
	do
	{   cout<<"===========================================================================\n"; 
        isRight=0;
        q=head;
		cout<<"请输入您要删除的商品的编号：";
		cin>>Deletecode;
		while(q->next!=NULL&&q->next->code!=Deletecode)
			q=q->next;
		if(q->next!=NULL) 
		{     isRight=1;
		      output1();		
        cout<<q->next->code<<"\t"<<q->next->name<<"\t"<<q->next->place<<"\t"<<q->next->price<<"\t"<<q->next->num<<"\t"<<q->next->totalPrice<<"\t"<<endl;
              output2();
        cout<<q->next->type<<"\t\t"<<q->next->brand<<"\t\t"<<q->next->year<<"/"<<q->next->month<<"/"<<q->next->day<<endl;	 
		cout<<"===========================================================================\n";
			cout<<"确认删除次商品的信息吗⊙(^ ◇^)⊙？<y/n>";
			cin>>judge;
			while(judge!='y'&&judge!='n')
			{   cout<<"×××指令错误×××请输入<y/n>！"<<endl;
				cout<<"※※※您想要继续删除商品信息吗？(y/n):";
				cin>>judge;
			}
			if(judge=='y')
			{  
				p=q->next;//把要删除的商品的数据copy到p空间上 
				q->next=q->next->next;//再用后面的数据信息把删除部分的数据信息覆盖 
				tail->next=p;//将删除的信息放到回收站 
				tail=p;//尾链移动到尾部 
				tail->next=NULL;
				cout<<"(^_^)☆此商品的信息删除成功！"<<endl;
			}
			else cout<<"(^_^)☆已取消此商品的信息删除！！！"<<endl;

		}
		if(isRight==0)
		{
			cout<<"〒▽〒对不起，您要删除的商品不存在！！（是不是编号输错了呢？再输一次吧！或者去查询商品信息看看吧！）"<<endl;

		}
		cout<<"您想要继续删除商品的信息吗？⊙(^ ◇^)⊙(y/n):";
		cin>>judge;
		while(judge!='y'&&judge!='n')
		{
			cout<<"×××指令错误×××请输入<y/n>！"<<endl;
			cout<<"※※※您想要继续删除商品信息吗？(y/n):";
			cin>>judge;
		}

	}while(judge=='y');
	cout<<endl;
	cout<<"……商品的信息删除完毕……"<<endl;
	cout<<"……按任意键返回主菜单……"<<endl;
	getchar();
	getchar();
}

//===========================================================================================================

//按照商品编号查找商品信息
void GoodsFunction::SearchByCode()
{	
	Goods *p;
	string FoundCode;
	cout<<"          ☆☆☆☆☆☆现在进行商品信息的查找☆☆☆☆☆☆          "<<endl;
	p=head;
	cout<<"请输入您要查找的商品编号：";
	cin>>FoundCode;
	   while(p->next!=NULL&&p->code!=FoundCode) 
	    p=p->next;
		if(p->code==FoundCode)
		{
	      output1();		
        cout<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->num<<"\t"<<p->totalPrice<<"\t"<<endl;
          output2();
        cout<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	 
		cout<<"===========================================================================\n";
		}
	    else
		{
		cout<<"〒▽〒对不起，您要查询的商品不存在！！（是不是商品的编号输错了呢？返回再试试吧，或者换其他查询方式也行哦！）"<<endl;				
		}
		cout<<endl;
		
		cout<<"……商品的信息查询完毕……"<<endl;
	    cout<<"……按任意键返回主菜单……"<<endl;
		getchar();
		getchar();
}

//===========================================================================================================

//按照商品名称查找商品信息
void GoodsFunction::SearchByName()
{	
	Goods *p;
	string FoundName;
	bool isRight=0; 
	cout<<"          ☆☆☆☆☆☆现在进行商品信息的查找☆☆☆☆☆☆          "<<endl;
		p=head;
		cout<<"请输入您要查找的商品名称：";
		cin>>FoundName;
		while(p->next!=NULL)
	    {	
	    p=p->next;
		if(p->name==FoundName)
		{ isRight=1;
	      output1();		
        cout<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->num<<"\t"<<p->totalPrice<<"\t"<<endl;
          output2();
        cout<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	 
		cout<<"===========================================================================\n";
		}
		}	
		if(isRight==0) 
		{
		cout<<"〒▽〒对不起，您要查询的商品不存在！！（是不是商品的名称输错了呢？返回再试试吧，或者换其他查询方式也行哦！）"<<endl;		
		}
		cout<<endl;
	 
		cout<<"……商品的信息查找完毕……"<<endl;
	    cout<<"……按任意键返回主菜单……"<<endl;
		getchar();
		getchar();
}

//===========================================================================================================

//按照商品类别查找商品信息
void GoodsFunction::SearchByType()
{
	
	Goods *p;
	string FoundType;
	bool isRight=0;
	cout<<"          ☆☆☆☆☆☆现在进行商品信息的查找☆☆☆☆☆☆          "<<endl;
		p=head;	
		cout<<"请输入您要查找的商品类别名称：";
		cin>>FoundType;
		while(p->next!=NULL)
		{
		p=p->next;//每个数据逐步搜索 
		if(FoundType=="食品类"&&p->type==Food)//p->type会按照枚举的顺序调用属性，当满足要求时才把信息输出 
		{ isRight=1;
	      output1();		
        cout<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->num<<"\t"<<p->totalPrice<<"\t"<<endl;
          output2();
        cout<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	 
		cout<<"===========================================================================\n";
		}
        else if(FoundType=="饮品类"&&p->type==Drink)
		{isRight=1;
	      output1();		
        cout<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->num<<"\t"<<p->totalPrice<<"\t"<<endl;
          output2();
        cout<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	 
		cout<<"===========================================================================\n";
		} 
		else if(FoundType=="穿着类"&&p->type==Wear)
	    {isRight=1;
	      output1();		
        cout<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->num<<"\t"<<p->totalPrice<<"\t"<<endl;
          output2();
        cout<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	 
		cout<<"===========================================================================\n";
		}
		else if(FoundType=="日用品类"&&p->type==Commodity)
		{isRight=1;
	      output1();		
        cout<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->num<<"\t"<<p->totalPrice<<"\t"<<endl;
          output2();
        cout<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	 
		cout<<"===========================================================================\n";
		}			
		}
		if(isRight==0) 
		{
		cout<<"〒▽〒对不起，您要查询的商品不存在！！（是不是商品的类别输错了呢？返回再试试吧，或者换其他查询方式也行哦！）"<<endl;		
		}	
		cout<<endl;
		cout<<"……商品的信息查找完毕……"<<endl;
	    cout<<"……按任意键返回主菜单……"<<endl;
		getchar();
		getchar();
}

//===========================================================================================================

//按照商品的生产厂家查找商品信息
void GoodsFunction::SearchByBrand()
{
	
	Goods *p;
	string FoundBrand;
	bool isRight=0;
	cout<<"          ☆☆☆☆☆☆现在进行商品信息的查找☆☆☆☆☆☆          "<<endl;
		p=head;
		cout<<"请输入您要查找商品的生产厂家：";
		cin>>FoundBrand;
		while(p->next!=NULL)
		{p=p->next;
		if(p->brand==FoundBrand)
		{ isRight=1;
	      output1();		
        cout<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->num<<"\t"<<p->totalPrice<<"\t"<<endl;
          output2();
        cout<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	 
		cout<<"===========================================================================\n";
		}
	    }
		if(isRight==0) 
		{
		cout<<"〒▽〒对不起，您要查询的商品不存在！！（是不是商品的厂家输错了呢？返回再试试吧，或者换其他查询方式也行哦！）"<<endl;			
		} 
		cout<<endl;
		cout<<"……商品的信息查找完毕……"<<endl;
	    cout<<"……按任意键返回主菜单……"<<endl;
		getchar();
		getchar();
        
}

//===========================================================================================================

//按照商品的进货时间查找商品信息
void GoodsFunction::SearchByTime()
{
	
	Goods *p;
	bool isRight=0;
	int FoundYear,FoundMouth,FoundDay;
	cout<<"          ☆☆☆☆☆☆现在进行商品信息的查找☆☆☆☆☆☆          "<<endl;
		p=head;
		cout<<"请输入您要查找商品的进货日期（年/月/日）：";
		cin>>FoundYear>>FoundMouth>>FoundDay;
		while(p->next!=NULL)
		{p=p->next;
		if(p->year==FoundYear&&p->month==FoundMouth&&p->day==FoundDay)
		{  isRight=1;
	      output1();		
        cout<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->num<<"\t"<<p->totalPrice<<"\t"<<endl;
          output2();
        cout<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	 
		cout<<"===========================================================================\n";
		}
	    }
		if(isRight=0) 
		{
		cout<<"〒▽〒对不起，您要查询的商品不存在！！（是不是商品的进货日期输错了呢？返回再试试吧，或者换其他查询方式也行哦！）"<<endl;			
		} 
		cout<<endl;
		cout<<"……商品的信息查找完毕……"<<endl;
	    cout<<"……按任意键返回主菜单……"<<endl;
		getchar();
		getchar();
        
}

//===========================================================================================================

////实现商品出库功能 
void GoodsFunction::SellGoodsInfo()
{

	char judge;
	Goods *p;
	bool isRight=0;
	SellRecord *tail=top,*q=new SellRecord; 
	while(tail->next!=NULL)
	tail=tail->next;
	string SellName;
	cout<<"          ☆☆☆☆☆☆现在进行商品的出售☆☆☆☆☆☆          "<<endl;
	do
	{cout<<"===========================================================================\n";
	isRight=0;
	p=head->next;
	cout<<"请输入您要出售商品的名称：";
	cin>>SellName;
	while(p->next!=NULL&&p->name!=SellName)
	      p=p->next;
	if(p->name==SellName)
	{isRight=1;
	 q->sellname=SellName;
	 q->sellbrand=p->brand;
	 q->sellcode=p->code;
	    output1();		
    cout<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->num<<"\t"<<p->totalPrice<<"\t"<<endl;
        output2();
    cout<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	 
	cout<<"===========================================================================\n";
		
	cout<<"确认出售此商品么吗⊙(^ ◇^)⊙？<y/n>";
	cin>>judge;
	while(judge!='y'&&judge!='n')
	{
	cout<<"\n×××指令错误×××请输入<y/n>！"<<endl;
	cout<<"※※※您想要继续出售此商品吗？(y/n):\n";
	cin>>judge;
	}
	if(judge=='y')
	{cout<<"此商品的现余量为："<<p->num<<endl; 
	cout<<"请输入出售的商品数量：";
	cin>>q->sellNum;
	if(q->sellNum<=p->num)
	{
	p->num-=q->sellNum;
	p->totalPrice=p->num*p->price;
	cout<<"请输入出售的商品售价：";
	cin>>q->sellPrice;
	cout<<"请输入出货的日期：";
	cin>>q->sellyear>>q->sellmonth>>q->sellday;
	q->sellmoney=q->sellNum*q->sellPrice;
	q->profit=q->sellNum*(q->sellPrice-p->price);
	cout<<"此次销售额为： "<<q->sellmoney<<endl;
	cout<<"此次利润为： "<<q->profit<<endl;
	cout<<"剩余库存量为："<<p->num<<endl; 
	cout<<"出货日期为："<<q->sellyear<<"/"<<q->sellmonth<<"/"<<q->sellday<<endl;
	selltimes++;
	tail->next=q;
    q->next=NULL;
    tail=q; 
	}
	else
	cout<<"库存不足！出库失败(〒︿〒)！"<<endl;	
	}
	else 
	cout<<"取消出货成功(′▽`)！"<<endl;
    }
	if(isRight==0) 
	cout<<"\n(〒︿〒)对不起，您出售的货物不存在！！（是不是商品的名称错了呢？返回再试试吧，或者去查询商品信息看看吧！）"<<endl;

	cout<<"\n您想要继续出售吗(￣▽￣)？(y/n):";
	cin>>judge;
	while(judge!='y'&&judge!='n')
	{
	cout<<"×××指令错误×××请输入<y/n>！"<<endl;
	cout<<"※※※您想要继续出售商品吗？(y/n):";
	cin>>judge;
	}
	}while(judge=='y');
	cout<<endl;
    cout<<"……商品的出售完毕！！……"<<endl;
	cout<<"……按任意键返回主菜单……"<<endl;
	getchar();
	getchar();

}

//===========================================================================================================

//实现商品信息统计
void GoodsFunction::DisplayGoodsInfo()
{
	Goods *p=head;
	cout<<"          ☆☆☆☆☆☆进货商品的信息的统计☆☆☆☆☆☆          "<<endl;		
	while(p->next!=NULL)
	{
		p=p->next;
		output1();		
    cout<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->staticnum<<"\t"<<p->staticnum*p->price<<"\t"<<endl;
        output2();
    cout<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	 
	cout<<"===========================================================================\n";
	}
	cout<<endl;
	SellRecord *q=top;
	cout<<"          ☆☆☆☆☆☆出货商品的信息统计☆☆☆☆☆☆          "<<endl;
	cout<<"==========================================================================="<<endl;
	cout<<"编号"<<"\t"<<"名称"<<"\t"<<"售价"<<"\t"
        <<"销售数量"<<"\t"<<"销售总额"<<"\t"<<"利润"<<"\t"<<"出货时间"<<endl;			
	while(q->next!=NULL)
	{
		q=q->next;
		cout<<q->sellcode<<"\t"<<q->sellname<<"\t"<<q->sellPrice<<"\t"
	    <<q->sellNum<<"\t\t"<<q->sellmoney<<"\t\t"<<q->profit<<"\t"
		<<q->sellyear<<"/"<<q->sellmonth<<"/"<<q->sellday<<endl;
		cout<<"==========================================================================="<<endl;
	}
	cout<<endl;
//	cout<<"          ☆☆☆☆☆☆现库存商品的信息统计☆☆☆☆☆☆          "<<endl;
//	ifstream  infile;
//	infile.open("货物信息.txt");
//	string jh;
//	while(getline(infile,jh))
//	{
//		cout<<jh<<endl;
//	}  
//	infile.close() ;
    cout<<"……商品的信息统计完毕……"<<endl;
	cout<<"……按任意键返回主菜单……"<<endl;
	getchar();
	getchar();
}

//===========================================================================================================

//定义商品信息保存函数
void GoodsFunction::SaveGoodsInfo()
{
	 Goods *p=head;
	 cout<<"          ☆☆☆☆☆☆现在进行商品信息的保存☆☆☆☆☆☆          "<<endl;
	 ofstream output("货物信息.txt",ios::out);
	 if(!output)
	 {
		 cerr<<"(〒︿〒)打开文件<货物信息.txt>失败！！！"<<endl;
	 }
	cout<<"进货产品信息："<<endl; 
//	cout<<"编号"<<"\t\t"<<"名称"<<"\t\t"<<"生产厂家"<<"\t\t"
//        <<"单价"<<"\t\t"<<"商品类别"<<"\t\t"<<"数量"<<"\t\t"<<"入库时间"<<endl;	
//	output<<"进货次数为: "<<times<<"\n";
//    output<<"编号"<<"\t\t"<<"名称"<<"\t\t"<<"生产厂家"<<"\t\t"
//          <<"单价"<<"\t\t"<<"商品类别"<<"\t\t"<<"数量"<<"\t\t"<<"入库时间"<<endl;	
	while(p->next!=NULL)
	 {
//		 p=p->next;
//		 cout<<p->code<<"\t\t"<<p->name<<"\t\t"<<p->brand<<"\t\t"
//	    <<p->price<<"\t\t"<<p->type<<"\t\t\t"<<p->num<<"\t\t"
//		<<p->date.year<<"/"<<p->date.month<<"/"<<p->date.day<<endl;
//		
//		 output<<p->code<<"\t\t"<<p->name<<"\t\t"<<p->brand<<"\t\t"
//	    <<p->price<<"\t\t"<<p->type<<"\t\t\t"<<p->num<<"\t\t"
//		<<p->date.year<<"/"<<p->date.month<<"/"<<p->date.day<<endl;
	p=p->next;
	output1();
	output<<"===========================================================================\n"; 
	output<<"编号"<<"\t"<<"名称"<<"\t"<<"产地"<<"\t"<<"单价"<<"\t"<<"数量"<<"\t"<<"总价"<<endl;		    
 		
    cout<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->staticnum<<"\t"<<p->staticnum*p->price<<"\t"<<endl;
    output<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->staticnum<<"\t"<<p->staticnum*p->price<<"\t"<<endl;       
	    output2();
	    output<<"商品类型"<<"\t\t"<<"生产厂家"<<"\t\t"<<"进货时间"<<endl;
    cout<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	
	output<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	 
	cout<<"===========================================================================\n";
    output<<"===========================================================================\n";
    }
	cout<<endl;
    cout<<"============================================================================="<<endl;
	SellRecord *q=top;
	cout<<"出货产品信息： "<<endl;
	cout<<"编号"<<"\t"<<"名称"<<"\t"<<"售价"<<"\t"
        <<"销售数量"<<"\t"<<"销售总额"<<"\t"<<"利润"<<"\t"<<"出货时间"<<endl;			
	output<<"出货次数为："<<selltimes<<endl; 
	output<<"编号"<<"\t"<<"名称"<<"\t"<<"售价"<<"\t"
        <<"销售数量"<<"\t\t"<<"销售总额"<<"\t"<<"利润"<<"\t"<<"出货时间"<<endl;	
	while(q->next!=NULL)
	{
		q=q->next;
		cout<<q->sellcode<<"\t"<<q->sellname<<"\t"<<q->sellPrice<<"\t"
	    <<q->sellNum<<"\t\t"<<q->sellmoney<<"\t\t"<<q->profit<<"\t"
		<<q->sellyear<<"/"<<q->sellmonth<<"/"<<q->sellday<<endl;
		output<<q->sellcode<<"\t"<<q->sellname<<"\t"<<q->sellPrice<<"\t"
	    <<q->sellNum<<"\t\t"<<q->sellmoney<<"\t\t"<<q->profit<<"\t"
		<<q->sellyear<<"/"<<q->sellmonth<<"/"<<q->sellday<<endl;
	}
	cout<<endl;

	 cout<<"(*^▽^*)成功将货物信息保存到<货物信息.txt>"<<endl;
	 cout<<"……商品的信息保存完毕……"<<endl;
	 cout<<"……按任意键返回主菜单……"<<endl;
	 getchar();
	 getchar();
	 output.close();
}

//===========================================================================================================


int main()//主函数
{
	char choice;
	bool isRight=1;
	GoodsFunction goods;//调用GoodsFunction构造函数 
	//system("color f8"); //设置屏幕的颜色为亮白灰色 
	                    //系统初始页面： 
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<
	"                欢迎使用库存管理系统服务......系统正在为您加载中";
	Sleep(2000);        //页面休眠2秒 
	system("cls");      //实现清屏操作
	goods.DisplayMainMenu();//实现主菜单界面显示； 
	for(;;)             //实现功能的可持续性 
	{
		do              //实现用户想要的功能 
		{	isRight=1;
			cin>>choice;
			if(choice<'a'||choice>'k'&&choice!='o')
			{
		    	isRight=0;
				cout<<"\n                  ×××您输入的编号不存在！×××"<<endl;
			    cout<<"\n                  ※※※请选择相应的字母进行操作:";
			}
		}while(!isRight);
	system("cls");//实现清屏操作
    switch(choice)//根据用户选择的功能调用相应模块实现 
		{
		case'a':goods.AddGoodsInfo();
			break;
		case'b':goods.EditGoodsInfo();
			break;
		case'c':goods.DeleteGoodsInfo();
			break;
		case'd':goods.SearchByCode();
			break;
		case'e':goods.SearchByName();
			break;
		case'f':goods.SearchByType();
			break;
		case'g':goods.SearchByBrand();
			break;
		case'h':goods.SearchByTime();
			break;
		case'i':goods.SellGoodsInfo();
			break;
		case'j':goods.DisplayGoodsInfo();
			break;
		case'k':goods.SaveGoodsInfo();
			break;
		case'o':
		    cout<<"程序已退出，感谢您的使用，记得给个好评哦亲☆(*^ ▽^*)☆" <<endl;
		    exit(0);
			break;
    	} 
		system("cls");
			goods.DisplayMainMenu();
	}
}	
