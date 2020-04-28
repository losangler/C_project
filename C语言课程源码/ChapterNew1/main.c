#include <stdio.h>
#include <stdlib.h>

int main()
{

    //字符串演示
    //char words[] = "我是中国人！";
    //指针里并没有存放字符串！
    //p_words指针指向了 常量- "我也是中国人，好巧！" 的内存
    /*char * p_words;// = "我也是中国人，好巧！";
    scanf("%s", p_words);
    printf("%s\n", p_words);
    printf("%p\t%s\n", p_words, *p_words);
*/

    //编程输入一行字符，运用指针找出其中的大写字母，空格，数字，及其他字符的个数
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0; //对应要统计的4个总数
    char words[500];
    int i;
    printf("请输入一个字符串：");
    scanf("%s", words);
    for(i = 0; i < 500; i++)
    {
        if(*(words + i) == '\0')
        {
            break;//\0表示字符串的结尾
        }
        if(*(words + i) >= 'A' && *(words + i) <= 'Z')
        {
            count1++;
        }
    }
    printf("有%d个大写字母\n", count1);



















    //数组名就是数组的首地址（数组首元素地址）
    //二维数组的理解：1-是由n个1维数组所组成
    /*int i, j;
    double score[5][3] = {
        {55, 66, 77},
        {52, 62, 72},
        {15, 26, 37},
        {54, 65, 76},
        {55, 66, 77},
    };
    double (*ptr_score)[3] = score;
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 3; j++)
        {
            //printf("%.2lf\t", score[i][j]);   // score[i] => *(score[i] + i)
            //printf("%.2lf\t", *(score[i] + j));
            printf("%.2lf\t", *(*(ptr_score + i) + j));
        }
        printf("\n");
    }


*/




/*
    //遍历第一行数据：第一行的数组名就是score[0]
    for(i = 0; i < 3; i++)
    {
        printf("%.2lf\t", score[0][i]);
    }
    printf("\n");
    //遍历第二行数据：score[1]
    for(i = 0; i < 3; i++)
    {
        printf("%.2lf\t", score[1][i]);
    }

*/














    /*
    int score[5] = {55, 66, 77, 88, 99};
    int * p_score = score;
    int i;
    printf("数组名：%p\t首元素地址：%p\n", score, &score[0]);
    //printf("数组的第1个元素：%d\n", *(score + 0)); // score[0]
    //printf("数组的第2个元素：%d\n", *(score + 1)); // score[1]
    //printf("数组的第3个元素：%d\n", *(score + 2)); // score[2]
    //遍历数组元素

    for(i = 0; i < 5; i++)
    {
        //printf("%d\n", score[i]);
        printf("%d\n", *(p_score + i)); //score[i]
    }
    printf("%d\n", *p_score);
    */
    return 0;
}
