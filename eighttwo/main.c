#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a[3];
    int i;
    void swap (int *p );
    printf ("请输入三个数\n");
    scanf ("%d%d%d",&a[0],&a[1],&a[2]);
    swap (a);
    for ( i=0 ; i<3 ; ++i ){
        printf ("%d ",a[i]);
    }
    return 0;
}

void swap ( int *p )
{
    int temp;
    int i,j;
    int k;
    for ( i=0 ; i<2 ; ++i )
    {
        k = i;
        for ( j=i+1 ; j<3 ; ++j )
        {
            if ( *(p+j) < *(p+k) )
                 k = j;
            if ( k != i )
            {
                temp = * (p+k);
                * (p+k) = * (p+i);
                * (p+i) = temp;
            }
        }
    }
    return 0;
}
