//*********************
//**    ch9_8.cpp    **
//*********************

#include <iostream.h>

int array[6][4]={{60,80,90,75},
                 {75,85,65,77},
                 {80,88,90,98},
                 {89,100,78,81},
                 {62,68,69,75},
                 {85,85,77,91}};

int& level(int grade[], int size, int& tA, int& tB);

void main()
{
  int typeA=0,typeB=0;
  int student=6;
  int gradesize=4;

  for(int i=0; i<student; i++)    //处理所有的学生
    level(array[i], gradesize, typeA, typeB)++;    //函数调用作为左值

  cout <<"number of type A is " <<typeA <<endl;
  cout <<"number of type B is " <<typeB <<endl;
}

int& level(int grade[], int size,int& tA, int& tB)
{
  int sum=0;
  for(int i=0; i<size; i++)    //成绩总分
    sum+=grade[i];

  sum/=size;      //平均分

  if(sum>=80)
    return tA;    //type A student
  else
    return tB;    //type B student
}