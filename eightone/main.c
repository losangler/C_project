#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a =10;
    int *ptr_a;
    ptr_a=&a;
    int b = 12;
    int *ptr_b;
    ptr_b=&b;
    printf("a的值为%d\n",b);
    printf("b的值为%d\n",a);
    return 0;
}
