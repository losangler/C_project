#include <stdio.h>
#include <stdlib.h>
#define N 8
int main()
{
    int i,j;//循环变量
    int middle;//用来交换的临时变量
    int nums[N] = {18,25,7,36,13,2,89,63};
    for (i=0;i<N-1;i++){
        for(j=0;j<N-i-1;j++){
            if(nums[j]>nums[j+1]){
                middle=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=middle;
            }
        }
    }

    for(i=0;i<N;i++){
        printf("%d\t",nums[i]);
    }
    return 0;
}
