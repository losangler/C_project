#include <stdio.h>
#include <stdlib.h>
#define N 10
int main()
{
    int num[N];//定义输入的整数并限定范围
    int temp;
    for (int i =0;i<N;i++)
    {
    printf("请输入整数:\n");
    scanf("%d",&num[i]);
    }
    for(int i = 0 ;i <N-1;i++){
        for(int j = 0;j<N-i-1;j++){
        if (num[i]<num[j+1])
        {
            temp = num[j];
            num[j] = num[j+1];
            num[j+1] = temp;
        }
        }
    }
    printf("排序后：\n");
    for (int i=0;i<N;i++){
       printf("%d\t",num[i]);
    }


    return 0;
}
