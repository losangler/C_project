//***********************
//**    ch19_16.cpp    **
//***********************

#include <iostream.h>
#include <fstream.h>
#include "student.h"
#include "master.h"
#include <string.h>

void main()
{
  ifstream fin("e:\\bctemp\\abc.txt");

  char sFirst[10];
  char sLast[10];
  unsigned int uid;
  float nGrade;
  char type;
  char name[20];
  Student* pS;
  int i=0;

  fin>>sLast >>sFirst >>uid >>nGrade >>type;  while(!fin.eof()){
    strcpy(name,strcat(sLast," "));
    strcpy(name,strcat(name,sFirst));
    pS=new MasterStudent(name,uid,nGrade,type);
    cout <<"student #" <<++i <<":" <<*pS;    delete pS;

    name[0]=0;           //½«nameÖÐÄÚÈÝÖÃ¿Õ´®
    fin>>sLast >>sFirst >>uid >>nGrade >>type;  }
}