#include <stdio.h>
#include <stdlib.h>
#define N 10
int main()
{
    int num[N];//����������������޶���Χ
    int temp;
    for (int i =0;i<N;i++)
    {
    printf("����������:\n");
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
    printf("�����\n");
    for (int i=0;i<N;i++){
       printf("%d\t",num[i]);
    }


    return 0;
}
