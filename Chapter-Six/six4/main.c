#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a[10]={1,3,12,96,188,249,800};
    int x,i,j=6;
    printf("输入一个数:");
    scanf("%d",&x);
    a[0]=x;
    i=j;
    while((i>0)&&(a[i]>a[0]))
    {
        a[i+1]=a[i];
        i--;
    }
    a[++i]=a[0];
    j++;
    for(i=1;i<=j;i++)
    {
        printf("%8d",a[i]);
    }

    printf("\n");
    return 0;
}
