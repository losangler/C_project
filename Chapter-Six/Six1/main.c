#include <stdio.h>
#include <stdlib.h>
#define N 5
int main()
{
    //动态录入
    double score[N];
    int i;//循环变量
    for(i=0;i<N;i++){
        printf("请输入第%d位同学成绩：",i+1);
        scanf("%lf",&score[i]);//scanf里面的第i个元素
    }
    //下面用循环来打印数组元素
    for(i=0;i<N;i++){
       printf("\n第%d位同学成绩是：%.2lf",i+1,score[i]);
        //scanf("%lf",&score[i]);//scanf里面的第i个元素
    }
    return 0;
}
