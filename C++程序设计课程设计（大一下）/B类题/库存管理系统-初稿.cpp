#include<iostream> //ʵ���������
#include<fstream>  //ʵ���ⲿ�ļ���������
#include<string>   //ʵ���ַ���������
#include<windows.h>//ʵ�ֿ���̨���ڵ���ɫ�仯
using namespace std;


//===========================================================================================================

enum GoodsType //��Ʒ���
{
	 Food=1,   //ʳƷ�� 
     Drink,    //��Ʒ��
	 Wear,     //������
     Commodity //����Ʒ�� 
	 
};
//���ýṹ����ö������Ϊ��Ʒ�����ʹ��������ĸ����������һ��������ȫ��;

//===========================================================================================================

struct Goods       //��Ʒ�����Ļ�����Ϣ
{    
	string code;   //��Ʒ���
	string name;   //��Ʒ����
	string place;  //�����ص�
	string brand;  //��������
	double price;  //��������
	               //�����ܼ�
	double totalPrice;
	int num,staticnum;//��Ʒ����
	GoodsType type;//��Ʒ���
	               //���ʱ��
	int year,month,day;
	Goods *next;   //��������Ľڵ㣨ʵ����ӹ��ܣ� 
};

//===========================================================================================================

struct SellRecord    //��Ʒ�������۳���Ϣ
{ 
	string sellcode; //�������� 
	string sellname; //�ѳ��۵���Ʒ����
	string sellbrand;//�ѳ�����Ʒ�ĳ���   
	int sellNum;     //��������
	double sellPrice;//���ۼ۸�
	double sellmoney;//�����۶� 
	double profit;   //���� 
	                 //��������
	int sellyear,sellmonth,sellday; 
	SellRecord *next;//��������Ľڵ㣨ʵ����Ʒ������Ϣ��ͳ�ƣ�
}; 

//===========================================================================================================
	
class GoodsFunction         //��Ʒ����ܵ�ʵ�� 
{ 
public:
	GoodsFunction();        //���캯�� 
	~GoodsFunction(){}      //�������� 
	void DisplayMainMenu(); //���˵����棬��ʾ��ѡ���� 
	void AddGoodsInfo();    //��Ӳ�Ʒ��Ϣ(Ҳ�ǽ������ܵ�ʵ�֣�
	void DisplayGoodsInfo();//�����Ʒ��Ϣ
    void Search();          //����������ʾ
	void SearchByCode();    //���ղ�Ʒ���������Ʒ��Ϣ
	void SearchByName();    //���ղ�Ʒ����������Ʒ��Ϣ
	void SearchByType();    //���ղ�Ʒ���������Ʒ��Ϣ
	void SearchByBrand();   //���ղ�ƷƷ��������Ʒ��Ϣ
	void SearchByTime();    //���ս�������������Ʒ��Ϣ
    void Edit();            //�༭������ʾ
	void EditGoodsInfo();   //�༭��Ʒ��Ϣ
    void DeleteGoodsInfo(); //ɾ����Ʒ��Ϣ
	void SellGoodsInfo();   //���۲�Ʒ��Ϣ��Ҳ�ǳ������ܵ�ʵ�֣�
	void SaveGoodsInfo();   //�����Ʒ��Ϣ
private:
//	int sellnumber          //������������ 
	int times;              //�������� 
	int selltimes;          //�������� 
	Goods *head;            //����ͷ���
	SellRecord *top;        //����ͷ���	
	Goods *DeleteHead;      //����ͷ��� 
};

//===========================================================================================================

GoodsFunction::GoodsFunction()//���幹�캯������˽�����Գ�ʼ�� 
{
//	sellnumber=0; 
	times=0;
	selltimes=0;
	head=new Goods;          //����ռ䣨���������������Ϣ  
	head->next=NULL;         //�¸��ռ�Ϊ�� 
	DeleteHead=new Goods;    //�൱���ռ�ɾ����Ϣ�Ļ���վ 
	DeleteHead->next=NULL;   //�¸��ռ�Ϊ��
	top=new SellRecord;      //���������Ϣ�Ĵ���ռ� 
	top->next=NULL;          //�¸��ռ�Ϊ�� 
}


//===========================================================================================================

void GoodsFunction::DisplayMainMenu()//ʵ�����˵����� 
{
	cout<<"  =================================================================\n";
    cout<<" ��                                                                ��\n";
    cout<<" ��                   ��ӭʹ����Ʒ������ϵͳ                     ��\n";
    cout<<" ��                                                                ��\n";
    cout<<" ��                                                                ��\n";
    cout<<" ��                        ����Ʒ��������(a)                       ��\n";
    cout<<" ��                                                                ��\n";
    cout<<" ��                        ����Ʒ�༭����(b)                       ��\n";
	cout<<" ��                                                                ��\n";
    cout<<" ��                        ����Ʒɾ������(c)                       ��\n";
	cout<<" ��                                                                ��\n";
    cout<<" ��                   ����> �����ձ�Ų�ѯ����(d)                   ��\n";
	cout<<" ��                   ��                                            ��\n";
	cout<<" ��                   ����> ���������Ʋ�ѯ����(e)                   ��\n";
	cout<<" ��                   ��                                            ��\n";
	cout<<" ��    ����Ʒ��ѯ����>����> ����������ѯ����(f)                   ��\n";
	cout<<" ��                   ��                                            ��\n";
	cout<<" ��                   ����> �����ճ��Ҳ�ѯ����(g)                   ��\n";
	cout<<" ��                   ��                                            ��\n";
	cout<<" ��                   ����> �����ս������ڲ�ѯ����(h)               ��\n";
	cout<<" ��                                                                ��\n";
    cout<<" ��                        ����Ʒ��������(i)                       ��\n";
    cout<<" ��                                                                ��\n";
    cout<<" ��                        ����Ʒͳ�ơ���(j)                       ��\n";
	cout<<" ��                                                                ��\n";
    cout<<" ��                        ����Ϣ���桿��(k)                       ��\n";
	cout<<" ��                                                                ��\n";
    cout<<" ��                                                                ��\n";
    cout<<" ��                          �˳�ϵͳ��(o)                         ��\n";
    cout<<" ��                                                                ��\n";
    	cout<<"  =================================================================\n";
    cout<<"\n                     �ף���������Ҫ�����ı�ţ�";           
}

//===========================================================================================================

//ʵ�������Ʒ������Ϣ
void GoodsFunction::AddGoodsInfo()
{
	char num,judge;
	Goods *tail=head,*p;
	bool isRight;
	cout<<"          ����������ڽ�����Ʒ������Ϣ����ӡ������          "<<endl;
	while(tail->next!=NULL)
		tail=tail->next;//��tailָ�����������һ���ڵ�
	do
	{   cout<<"  =================================================================\n"; 
		isRight=0;
		p=new Goods;
		cout<<"��ѡ����Ʒ���:"<<endl;
		cout<<"1.ʳƷ�� 2.��Ʒ�� 3.������ 4.����Ʒ��"<<endl;
		cout<<"��������Ӧ���:";
		do
		{
			cin>>num;
			if(num>='1'&&num<='4')//�ж��û��������Ƿ����
				isRight=1;
			else
			{
				cout<<"������������ı�Ų����ڣ�������"<<endl;
			    cout<<"��������ѡ����ȷ����Ʒ���:";
			}
		}while(isRight==0);//�������������ʱ����ѭ��
		if(num=='1')p->type=Food;
		if(num=='2')p->type=Drink;
		if(num=='3')p->type=Wear;
		if(num=='4')p->type=Commodity;
		cout<<"����������Ʒ���Ϊ("<<p->type<<")��"<<endl;//��ʾ��Ʒ���
		cout<<"�����������Ʒ�ı��: ";
        cin>>p->code;
		do
		{
			Goods *q=head->next;
			while(q!=NULL&&q->code!=p->code)//��qָ��NULL������ı����֮ǰ����ظ�ʱ����ѭ��
				q=q->next;                  //��ͷ��ʼ������β 
			if(q==NULL)//��pָ��NNULL�ұ�Ų��ظ�ʱ
				isRight=1;
			else//����ظ�ʱ
			{
				cout<<"��(�á㧥��)�ô��ڸñ�ŵĻ������������������:";
			    cin>>p->code;
			}
		}while(isRight==0);
		cout<<"�����������Ʒ�����ƣ�";
		cin>>p->name;
		cout<<"�������������ң�"; 
		cin>>p->brand;
		cout<<"������������ַ��"; 
		cin>>p->place;
		cout<<"������������ۣ�";
		cin>>p->price;
		cout<<"��������Ʒ������";
		cin>>p->num;
		p->staticnum=p->num;
		//�Զ������ܼ۴�����Ϣ 
		p->totalPrice=p->price*p->num;
        cout<<"���������ʱ�䣨��/��/�գ���";
		cin>>p->year>>p->month>>p->day;
		tail->next=p;//��p���ӵ������β������տռ� 
		p->next=NULL;//���¸��ռ�ſ� 
		tail=p;      //�ƶ���β��β�� 
		//amount++;//��Ʒ����һ
		cout<<"(^_^)�������Ϣ��ӳɹ���������Ҫ���������(y/n):";
		cin>>judge;
		while(judge!='y'&&judge!='n')
		{
			cout<<"������ָ����������������<y/n>��"<<endl;
		    cout<<"������Ϣ��ӳɹ���������Ҫ���������(y/n):";
			cin>>judge;
		}
	}while(judge=='y');
	cout<<endl;
	cout<<"����������Ϣ�Ѵ�����ϡ���"<<endl;
	cout<<"������������������˵�����"<<endl;
	getchar();//��ȡcin����ʱ�Ļس�����������ȵ� 
	getchar();//��ȡ������������˵� 
}

//===========================================================================================================

//��ӡ������� 
void output1(){
	
	cout<<"===========================================================================\n"; 
	cout<<"���"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"�ܼ�"<<endl;		    
} 
//-----------------------------------------------------------------------------------------------------------
void output2(){
    cout<<endl; 
	cout<<"��Ʒ����"<<"\t"<<"��������"<<"\t\t"<<"����ʱ��"<<endl;		    
} 

//===========================================================================================================

//ʵ���޸���Ϣ�Ľ��� 
void GoodsFunction::Edit()
{
	cout<<" ====================================================================\n";
	cout<<" ��                     �� ���༭��Ʒ���͡���(1)                   ��\n";
	cout<<" ��                     ��                                         ��\n";
	cout<<" ��                     �� ���༭��Ʒ���ơ���(2)                   ��\n";
	cout<<" ��                     ��                                         ��\n";
	cout<<" ��                     �� ���༭�������ҡ���(3)                   ��\n";
	cout<<" ��         ����Ʒ�༭����                                         ��\n";
	cout<<" ��                     �� ���༭��Ʒ���ۡ���(4)                   ��\n";
	cout<<" ��                     ��                                         ��\n";
	cout<<" ��                     �� ���༭��Ʒ��������(5)                   ��\n";
	cout<<" ��                     ��                                         ��\n";
	cout<<" ��                     �� ���༭����ʱ�䡿��(6)                   ��\n";
    cout<<" ====================================================================\n";
	cout<<"\n                     �ף���������Ҫ�����ı�ţ�";  
	getchar();
}

//===========================================================================================================

//����༭��Ʒ��Ϣ��������Ѱ��������ʵ�֣�Ҳ�����Ա����ʵ�� 
void GoodsFunction::EditGoodsInfo()
{
	    char judge,item,number;
		Goods *p;
		bool isRight;
		string EditCode;
		cout<<"          ����������ڽ�����Ʒ��Ϣ�ı༭�������          "<<endl;
		do
		{   cout<<"===========================================================================\n"; 
			p=head->next;//���ü������ 
			isRight=0;
			cout<<"��������Ҫ�޸ĵĲ�Ʒ�ı�ţ�";
			cin>>EditCode;
			while(p->next!=NULL&&p->code!=EditCode)
				p=p->next;//���Ѱ�� 
			if(p->code==EditCode)//�ҵ���Ҫ�༭�Ķ��� 
			{ isRight=1; 
              output1();		
        cout<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->num<<"\t"<<p->totalPrice<<"\t"<<endl;
              output2();
        cout<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	 
		cout<<"===========================================================================\n";    
				cout<<"ȷ���޸Ĵ˲�Ʒ����Ϣ���(^ ��^)�ѣ�<y/n>";
				cin>>judge;
				while(judge!='y'&&judge!='n')
				{
					cout<<"������ָ����������������<y/n>��";
					cin>>judge;
				}
				if(judge=='y')
				{
					system("cls");//������תGoodsFunction::Edit()�ı༭ҳ�� 
					GoodsFunction::Edit();//������ó�Ա����EditҪ���������::  
					cin>>item;//ѡ���޸���Ŀ 
		switch(item)
		{ 
         case'1':
		cout<<"���������Ʒ�����:\t1.ʳƷ��\t 2.��Ʒ��\t 3.������\t 4.����Ʒ��"<<endl;
		do
		{	isRight=1;
		    cin>>number;
			if(number<'1'&&number>'4')
			{
				isRight=0;
				cout<<"(���ˡ�)�����������Ų����ڣ�"<<endl;
			    cout<<"��������ѡ����ȷ����Ʒ���:";
			}
		}while(!isRight);
		//ʵ�ֶԻ�����Ϣ����� 
		if(number=='1')p->type=Food;
		if(number=='2')p->type=Drink;
		if(number=='3')p->type=Wear;
		if(number=='4')p->type=Commodity;
		cout<<"\n                  (^_^)����Ʒ��Ϣ�༭�ɹ���"<<endl;
		break;						
		case'2':
		cout<<"���������Ʒ�����ƣ�";
		cin>>p->name;
		cout<<"\n                  (^_^)����Ʒ��Ϣ�༭�ɹ���"<<endl;
		break;
		case'3':
		cout<<"��������Ʒ���������ң�"; 
		cin>>p->brand;
		cout<<"\n                  (^_^)����Ʒ��Ϣ�༭�ɹ���"<<endl;
		break;
		case'4':
		cout<<"���������Ʒ�ĵ��ۣ�";
		cin>>p->price;
		p->totalPrice=p->num*p->price;
		cout<<"\n                  (^_^)����Ʒ��Ϣ�༭�ɹ���"<<endl;
		break;
		case'5':
		cout<<"���������Ʒ������";
		cin>>p->num;
		p->staticnum=p->num;
		p->totalPrice=p->num*p->price;
		cout<<"\n                  (^_^)����Ʒ��Ϣ�༭�ɹ���"<<endl;
		break;
		case'6':
		cout<<"�����������ʱ�䣨��/��/�գ���";
		cin>>p->year>>p->month>>p->day;
		cout<<"\n                  (^_^)����Ʒ��Ϣ�༭�ɹ���"<<endl;
		break;
		default:
		cout<<"\n                  ��(�á㧥��)�ñ�����벻��ȷ��"<<endl;
		break;       	
		}
//		cout<<"\n                  (^_^)����Ʒ��Ϣ�༭�ɹ���"<<endl;	
		}
		else 
		cout<<"\n                  (^_^)��ȡ���༭�ɹ���"<<endl;
			}
			if(isRight==0) //δ�ҵ�Ҫ�༭�Ķ��� 
			{
			  cout<<"�������Բ�����Ҫ�༭����Ʒ�����ڣ������ǲ��Ǳ��������أ�����һ�ΰɣ�����ȥ��ѯ��Ʒ��Ϣ�����ɣ���"<<endl;
                     
			}
			cout<<"\n                  ����Ҫ�����༭��(y/n):";
			cin>>judge;
			while(judge!='y'&&judge!='n')
			{
				cout<<"\n                  ������ָ����������������<y/n>��"<<endl;
				cout<<"\n                  ����������Ҫ�����༭��Ʒ��Ϣ��(y/n):";
				cin>>judge;
			}
		}while(judge=='y');
		cout<<endl;
	    cout<<"������Ʒ��Ϣ�༭��ϣ�����"<<endl;
	    cout<<"������������������˵�����"<<endl;
		getchar();
		getchar();
}

//===========================================================================================================

//ʵ����Ʒ��Ϣ��ɾ��
void GoodsFunction::DeleteGoodsInfo()
{
	Goods *q=head,*p,*tail=DeleteHead;
	p=new Goods;
	char judge;
	bool isRight=0;
	string Deletecode;//����ɾ���ı���  
	while(tail->next!=NULL)
		tail=tail->next;
	cout<<"          ����������ڽ�����Ʒ��Ϣ��ɾ���������          "<<endl;
	do
	{   cout<<"===========================================================================\n"; 
        isRight=0;
        q=head;
		cout<<"��������Ҫɾ������Ʒ�ı�ţ�";
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
			cout<<"ȷ��ɾ������Ʒ����Ϣ���(^ ��^)�ѣ�<y/n>";
			cin>>judge;
			while(judge!='y'&&judge!='n')
			{   cout<<"������ָ����������������<y/n>��"<<endl;
				cout<<"����������Ҫ����ɾ����Ʒ��Ϣ��(y/n):";
				cin>>judge;
			}
			if(judge=='y')
			{  
				p=q->next;//��Ҫɾ������Ʒ������copy��p�ռ��� 
				q->next=q->next->next;//���ú����������Ϣ��ɾ�����ֵ�������Ϣ���� 
				tail->next=p;//��ɾ������Ϣ�ŵ�����վ 
				tail=p;//β���ƶ���β�� 
				tail->next=NULL;
				cout<<"(^_^)�����Ʒ����Ϣɾ���ɹ���"<<endl;
			}
			else cout<<"(^_^)����ȡ������Ʒ����Ϣɾ��������"<<endl;

		}
		if(isRight==0)
		{
			cout<<"�������Բ�����Ҫɾ������Ʒ�����ڣ������ǲ��Ǳ��������أ�����һ�ΰɣ�����ȥ��ѯ��Ʒ��Ϣ�����ɣ���"<<endl;

		}
		cout<<"����Ҫ����ɾ����Ʒ����Ϣ�𣿡�(^ ��^)��(y/n):";
		cin>>judge;
		while(judge!='y'&&judge!='n')
		{
			cout<<"������ָ����������������<y/n>��"<<endl;
			cout<<"����������Ҫ����ɾ����Ʒ��Ϣ��(y/n):";
			cin>>judge;
		}

	}while(judge=='y');
	cout<<endl;
	cout<<"������Ʒ����Ϣɾ����ϡ���"<<endl;
	cout<<"������������������˵�����"<<endl;
	getchar();
	getchar();
}

//===========================================================================================================

//������Ʒ��Ų�����Ʒ��Ϣ
void GoodsFunction::SearchByCode()
{	
	Goods *p;
	string FoundCode;
	cout<<"          ����������ڽ�����Ʒ��Ϣ�Ĳ��ҡ������          "<<endl;
	p=head;
	cout<<"��������Ҫ���ҵ���Ʒ��ţ�";
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
		cout<<"�������Բ�����Ҫ��ѯ����Ʒ�����ڣ������ǲ�����Ʒ�ı��������أ����������԰ɣ����߻�������ѯ��ʽҲ��Ŷ����"<<endl;				
		}
		cout<<endl;
		
		cout<<"������Ʒ����Ϣ��ѯ��ϡ���"<<endl;
	    cout<<"������������������˵�����"<<endl;
		getchar();
		getchar();
}

//===========================================================================================================

//������Ʒ���Ʋ�����Ʒ��Ϣ
void GoodsFunction::SearchByName()
{	
	Goods *p;
	string FoundName;
	bool isRight=0; 
	cout<<"          ����������ڽ�����Ʒ��Ϣ�Ĳ��ҡ������          "<<endl;
		p=head;
		cout<<"��������Ҫ���ҵ���Ʒ���ƣ�";
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
		cout<<"�������Բ�����Ҫ��ѯ����Ʒ�����ڣ������ǲ�����Ʒ������������أ����������԰ɣ����߻�������ѯ��ʽҲ��Ŷ����"<<endl;		
		}
		cout<<endl;
	 
		cout<<"������Ʒ����Ϣ������ϡ���"<<endl;
	    cout<<"������������������˵�����"<<endl;
		getchar();
		getchar();
}

//===========================================================================================================

//������Ʒ��������Ʒ��Ϣ
void GoodsFunction::SearchByType()
{
	
	Goods *p;
	string FoundType;
	bool isRight=0;
	cout<<"          ����������ڽ�����Ʒ��Ϣ�Ĳ��ҡ������          "<<endl;
		p=head;	
		cout<<"��������Ҫ���ҵ���Ʒ������ƣ�";
		cin>>FoundType;
		while(p->next!=NULL)
		{
		p=p->next;//ÿ������������ 
		if(FoundType=="ʳƷ��"&&p->type==Food)//p->type�ᰴ��ö�ٵ�˳��������ԣ�������Ҫ��ʱ�Ű���Ϣ��� 
		{ isRight=1;
	      output1();		
        cout<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->num<<"\t"<<p->totalPrice<<"\t"<<endl;
          output2();
        cout<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	 
		cout<<"===========================================================================\n";
		}
        else if(FoundType=="��Ʒ��"&&p->type==Drink)
		{isRight=1;
	      output1();		
        cout<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->num<<"\t"<<p->totalPrice<<"\t"<<endl;
          output2();
        cout<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	 
		cout<<"===========================================================================\n";
		} 
		else if(FoundType=="������"&&p->type==Wear)
	    {isRight=1;
	      output1();		
        cout<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->num<<"\t"<<p->totalPrice<<"\t"<<endl;
          output2();
        cout<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	 
		cout<<"===========================================================================\n";
		}
		else if(FoundType=="����Ʒ��"&&p->type==Commodity)
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
		cout<<"�������Բ�����Ҫ��ѯ����Ʒ�����ڣ������ǲ�����Ʒ�����������أ����������԰ɣ����߻�������ѯ��ʽҲ��Ŷ����"<<endl;		
		}	
		cout<<endl;
		cout<<"������Ʒ����Ϣ������ϡ���"<<endl;
	    cout<<"������������������˵�����"<<endl;
		getchar();
		getchar();
}

//===========================================================================================================

//������Ʒ���������Ҳ�����Ʒ��Ϣ
void GoodsFunction::SearchByBrand()
{
	
	Goods *p;
	string FoundBrand;
	bool isRight=0;
	cout<<"          ����������ڽ�����Ʒ��Ϣ�Ĳ��ҡ������          "<<endl;
		p=head;
		cout<<"��������Ҫ������Ʒ���������ң�";
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
		cout<<"�������Բ�����Ҫ��ѯ����Ʒ�����ڣ������ǲ�����Ʒ�ĳ���������أ����������԰ɣ����߻�������ѯ��ʽҲ��Ŷ����"<<endl;			
		} 
		cout<<endl;
		cout<<"������Ʒ����Ϣ������ϡ���"<<endl;
	    cout<<"������������������˵�����"<<endl;
		getchar();
		getchar();
        
}

//===========================================================================================================

//������Ʒ�Ľ���ʱ�������Ʒ��Ϣ
void GoodsFunction::SearchByTime()
{
	
	Goods *p;
	bool isRight=0;
	int FoundYear,FoundMouth,FoundDay;
	cout<<"          ����������ڽ�����Ʒ��Ϣ�Ĳ��ҡ������          "<<endl;
		p=head;
		cout<<"��������Ҫ������Ʒ�Ľ������ڣ���/��/�գ���";
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
		cout<<"�������Բ�����Ҫ��ѯ����Ʒ�����ڣ������ǲ�����Ʒ�Ľ�������������أ����������԰ɣ����߻�������ѯ��ʽҲ��Ŷ����"<<endl;			
		} 
		cout<<endl;
		cout<<"������Ʒ����Ϣ������ϡ���"<<endl;
	    cout<<"������������������˵�����"<<endl;
		getchar();
		getchar();
        
}

//===========================================================================================================

////ʵ����Ʒ���⹦�� 
void GoodsFunction::SellGoodsInfo()
{

	char judge;
	Goods *p;
	bool isRight=0;
	SellRecord *tail=top,*q=new SellRecord; 
	while(tail->next!=NULL)
	tail=tail->next;
	string SellName;
	cout<<"          ����������ڽ�����Ʒ�ĳ��ۡ������          "<<endl;
	do
	{cout<<"===========================================================================\n";
	isRight=0;
	p=head->next;
	cout<<"��������Ҫ������Ʒ�����ƣ�";
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
		
	cout<<"ȷ�ϳ��۴���Ʒô���(^ ��^)�ѣ�<y/n>";
	cin>>judge;
	while(judge!='y'&&judge!='n')
	{
	cout<<"\n������ָ����������������<y/n>��"<<endl;
	cout<<"����������Ҫ�������۴���Ʒ��(y/n):\n";
	cin>>judge;
	}
	if(judge=='y')
	{cout<<"����Ʒ��������Ϊ��"<<p->num<<endl; 
	cout<<"��������۵���Ʒ������";
	cin>>q->sellNum;
	if(q->sellNum<=p->num)
	{
	p->num-=q->sellNum;
	p->totalPrice=p->num*p->price;
	cout<<"��������۵���Ʒ�ۼۣ�";
	cin>>q->sellPrice;
	cout<<"��������������ڣ�";
	cin>>q->sellyear>>q->sellmonth>>q->sellday;
	q->sellmoney=q->sellNum*q->sellPrice;
	q->profit=q->sellNum*(q->sellPrice-p->price);
	cout<<"�˴����۶�Ϊ�� "<<q->sellmoney<<endl;
	cout<<"�˴�����Ϊ�� "<<q->profit<<endl;
	cout<<"ʣ������Ϊ��"<<p->num<<endl; 
	cout<<"��������Ϊ��"<<q->sellyear<<"/"<<q->sellmonth<<"/"<<q->sellday<<endl;
	selltimes++;
	tail->next=q;
    q->next=NULL;
    tail=q; 
	}
	else
	cout<<"��治�㣡����ʧ��(���䨓)��"<<endl;	
	}
	else 
	cout<<"ȡ�������ɹ�(�䨌`)��"<<endl;
    }
	if(isRight==0) 
	cout<<"\n(���䨓)�Բ��������۵Ļ��ﲻ���ڣ������ǲ�����Ʒ�����ƴ����أ����������԰ɣ�����ȥ��ѯ��Ʒ��Ϣ�����ɣ���"<<endl;

	cout<<"\n����Ҫ����������(������)��(y/n):";
	cin>>judge;
	while(judge!='y'&&judge!='n')
	{
	cout<<"������ָ����������������<y/n>��"<<endl;
	cout<<"����������Ҫ����������Ʒ��(y/n):";
	cin>>judge;
	}
	}while(judge=='y');
	cout<<endl;
    cout<<"������Ʒ�ĳ�����ϣ�������"<<endl;
	cout<<"������������������˵�����"<<endl;
	getchar();
	getchar();

}

//===========================================================================================================

//ʵ����Ʒ��Ϣͳ��
void GoodsFunction::DisplayGoodsInfo()
{
	Goods *p=head;
	cout<<"          ������������Ʒ����Ϣ��ͳ�ơ������          "<<endl;		
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
	cout<<"          ������������Ʒ����Ϣͳ�ơ������          "<<endl;
	cout<<"==========================================================================="<<endl;
	cout<<"���"<<"\t"<<"����"<<"\t"<<"�ۼ�"<<"\t"
        <<"��������"<<"\t"<<"�����ܶ�"<<"\t"<<"����"<<"\t"<<"����ʱ��"<<endl;			
	while(q->next!=NULL)
	{
		q=q->next;
		cout<<q->sellcode<<"\t"<<q->sellname<<"\t"<<q->sellPrice<<"\t"
	    <<q->sellNum<<"\t\t"<<q->sellmoney<<"\t\t"<<q->profit<<"\t"
		<<q->sellyear<<"/"<<q->sellmonth<<"/"<<q->sellday<<endl;
		cout<<"==========================================================================="<<endl;
	}
	cout<<endl;
//	cout<<"          ��������ֿ����Ʒ����Ϣͳ�ơ������          "<<endl;
//	ifstream  infile;
//	infile.open("������Ϣ.txt");
//	string jh;
//	while(getline(infile,jh))
//	{
//		cout<<jh<<endl;
//	}  
//	infile.close() ;
    cout<<"������Ʒ����Ϣͳ����ϡ���"<<endl;
	cout<<"������������������˵�����"<<endl;
	getchar();
	getchar();
}

//===========================================================================================================

//������Ʒ��Ϣ���溯��
void GoodsFunction::SaveGoodsInfo()
{
	 Goods *p=head;
	 cout<<"          ����������ڽ�����Ʒ��Ϣ�ı���������          "<<endl;
	 ofstream output("������Ϣ.txt",ios::out);
	 if(!output)
	 {
		 cerr<<"(���䨓)���ļ�<������Ϣ.txt>ʧ�ܣ�����"<<endl;
	 }
	cout<<"������Ʒ��Ϣ��"<<endl; 
//	cout<<"���"<<"\t\t"<<"����"<<"\t\t"<<"��������"<<"\t\t"
//        <<"����"<<"\t\t"<<"��Ʒ���"<<"\t\t"<<"����"<<"\t\t"<<"���ʱ��"<<endl;	
//	output<<"��������Ϊ: "<<times<<"\n";
//    output<<"���"<<"\t\t"<<"����"<<"\t\t"<<"��������"<<"\t\t"
//          <<"����"<<"\t\t"<<"��Ʒ���"<<"\t\t"<<"����"<<"\t\t"<<"���ʱ��"<<endl;	
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
	output<<"���"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"����"<<"\t"<<"�ܼ�"<<endl;		    
 		
    cout<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->staticnum<<"\t"<<p->staticnum*p->price<<"\t"<<endl;
    output<<p->code<<"\t"<<p->name<<"\t"<<p->place<<"\t"<<p->price<<"\t"<<p->staticnum<<"\t"<<p->staticnum*p->price<<"\t"<<endl;       
	    output2();
	    output<<"��Ʒ����"<<"\t\t"<<"��������"<<"\t\t"<<"����ʱ��"<<endl;
    cout<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	
	output<<p->type<<"\t\t"<<p->brand<<"\t\t"<<p->year<<"/"<<p->month<<"/"<<p->day<<endl;	 
	cout<<"===========================================================================\n";
    output<<"===========================================================================\n";
    }
	cout<<endl;
    cout<<"============================================================================="<<endl;
	SellRecord *q=top;
	cout<<"������Ʒ��Ϣ�� "<<endl;
	cout<<"���"<<"\t"<<"����"<<"\t"<<"�ۼ�"<<"\t"
        <<"��������"<<"\t"<<"�����ܶ�"<<"\t"<<"����"<<"\t"<<"����ʱ��"<<endl;			
	output<<"��������Ϊ��"<<selltimes<<endl; 
	output<<"���"<<"\t"<<"����"<<"\t"<<"�ۼ�"<<"\t"
        <<"��������"<<"\t\t"<<"�����ܶ�"<<"\t"<<"����"<<"\t"<<"����ʱ��"<<endl;	
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

	 cout<<"(*^��^*)�ɹ���������Ϣ���浽<������Ϣ.txt>"<<endl;
	 cout<<"������Ʒ����Ϣ������ϡ���"<<endl;
	 cout<<"������������������˵�����"<<endl;
	 getchar();
	 getchar();
	 output.close();
}

//===========================================================================================================


int main()//������
{
	char choice;
	bool isRight=1;
	GoodsFunction goods;//����GoodsFunction���캯�� 
	//system("color f8"); //������Ļ����ɫΪ���׻�ɫ 
	                    //ϵͳ��ʼҳ�棺 
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<
	"                ��ӭʹ�ÿ�����ϵͳ����......ϵͳ����Ϊ��������";
	Sleep(2000);        //ҳ������2�� 
	system("cls");      //ʵ����������
	goods.DisplayMainMenu();//ʵ�����˵�������ʾ�� 
	for(;;)             //ʵ�ֹ��ܵĿɳ����� 
	{
		do              //ʵ���û���Ҫ�Ĺ��� 
		{	isRight=1;
			cin>>choice;
			if(choice<'a'||choice>'k'&&choice!='o')
			{
		    	isRight=0;
				cout<<"\n                  ������������ı�Ų����ڣ�������"<<endl;
			    cout<<"\n                  ��������ѡ����Ӧ����ĸ���в���:";
			}
		}while(!isRight);
	system("cls");//ʵ����������
    switch(choice)//�����û�ѡ��Ĺ��ܵ�����Ӧģ��ʵ�� 
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
		    cout<<"�������˳�����л����ʹ�ã��ǵø�������Ŷ�ס�(*^ ��^*)��" <<endl;
		    exit(0);
			break;
    	} 
		system("cls");
			goods.DisplayMainMenu();
	}
}	
