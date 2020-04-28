//*********************
//**    ch8_8.cpp    **
//*********************

#include <iostream.h>
#include <alloc.h>

void main()
{
  int arraysize;    //元素个数
  int *array;
  cout <<"please input a number of array:\n";
  cin >>arraysize;

  if((array=(int*)malloc(arraysize*sizeof(int)))==NULL){
    cout <<"can't allocate more memory, terminating.\n";
    return ;
  }

  for(int count=0; count<arraysize; count++)
    array[count]=count*2;

  for(int count=0; count<arraysize; count++)
    cout <<array[count] <<"  ";

  cout <<endl;
  free(array);     //释放堆内存
}
