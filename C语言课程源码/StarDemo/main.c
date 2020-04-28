#include <stdio.h>
#include <stdlib.h>

int main()
{
    //打印星号图形
    int i, j;
    //外层循环 控制行(行数、换行)
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j <= 2 - i; j++)
        {
            printf(" ");
        }
        //内层循环 控制列(列数、列的符号)
        for(j = 0; j <= 2 * i; j++)
        {
            //挖空的原理：判断什么时候打印星号，什么时候打印空格
            if(i == 0 || i == 3 || j == 0 || j == 2 * i)
                printf("%c", '*');
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
