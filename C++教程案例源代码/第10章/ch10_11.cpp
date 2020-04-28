//***********************
//**    ch10_11.cpp    **
//***********************

#include <iostream>
#include <iomanip>
using namespace std; 
struct Student
{
  long number;
  float score;
  Student* next;
};

Student* head;    //Á´Ê×Ö¸Õë

Student* getNode()
{
  int num;
  float sc;
  cin>>num>>sc;
  if(num==0)
  return NULL;
  Student*p=new Student;
  p->number=num;
  p->score=sc;
  return p;
}
void Create(){
if((head=getNode())==0)
return;
for(Student*pE=head,*pS;pS=getNode();pE=pS)

pE->next=pS;}

void ShowList(){
cout<<"now the items of list are \n";
for(Student*p=head;p;p=p->next)
cout<<p->number<<","<<p->score<<endl; 
}

int main(){
	cout<<fixed<<setprecision(1);
	Create();
	ShowList();
}

