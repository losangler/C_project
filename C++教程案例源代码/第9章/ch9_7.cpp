//*********************
//**    ch9_7.cpp    **
//*********************

#include <iostream.h>

int array[6][4]={{60,80,90,75},
                 {75,85,65,77},
                 {80,88,90,98},
                 {89,100,78,81},
                 {62,68,69,75},
                 {85,85,77,91}};

int getLevel(int grade[], int size);

void main()
{
  int typeA=0,typeB=0;
  int student=6;
  int gradesize=4;

  for(int i=0; i<student; i++)      //处理所有的学生
    if(getLevel(array[i], gradesize))
      typeA++;
    else
      typeB++;

  cout <<"number of type A is " <<typeA <<endl;
  cout <<"number of type B is " <<typeB <<endl;
}

int getLevel(int grade[], int size)
{
  int sum=0;
  for(int i=0; i<size; i++)    //成绩总分
    sum+=grade[i];

  sum/=size;      //平均分

  if(sum>=80)
    return 1;     //type A student
  else
    return 0;     //type B student
}