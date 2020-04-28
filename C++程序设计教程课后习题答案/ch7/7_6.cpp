//7_6

#include <iostream.h>

void findMax(int a[][4], int row,int col);
void findBad(int a[][4], int row,int col);
void average(int a[][4], int row,int col);

void main()
{
  int array[5][4]={{88,67,48,91},
                   {61,65,37,77},
                   {92,81,73,60},
                   {51,55,60,60},
                   {77,63,70,80}};
  findMax(array,5,4);
  findBad(array,5,4);
  average(array,5,4);
}

void findMax(int a[][4], int row,int col)
{
  int r=0,c=0;
  for(int i=0; i<row; i++)
    for(int j=0; j<col; j++)
      if(a[i][j]>a[r][c])
        r=i,c=j;
  cout <<"成绩最高的学生序号: " <<(r+1) <<"    ";
  for(int i=0; i<col; i++)
    cout <<a[r][i]<<" ";
  cout <<endl;
}

void findBad(int a[][4], int row,int col)
{
  for(int i=0; i<row; i++)
    for(int j=0; j<col; j++)
      if(a[i][j]<60){
        cout <<"有不及格课程的学生序号: " <<(i+1) <<"   ";
        for(int k=0; k<col; k++)
          cout <<a[i][k] <<" ";
        cout <<endl;
        break;
      }
}

void average(int a[][4], int row,int col)
{
  double sum=0;
  for(int i=0; i<row; i++)
    for(int j=0; j<col; j++)
      sum+=a[i][j];

  cout <<"所有课程平均分数为: " <<sum/row/col <<endl;
}
