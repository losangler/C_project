    #include <stdio.h>
    void report_count();
    void counter(int num);
    int count = 0;  //文件作用域，外部链接
    int test;
    int main()
    {

        printf("%d\n", num);

        printf("%d\n", test);
        int value;      //自动变量
        register int i; //寄存器变量
        printf("请输入任意数字，0退出：");
        while(scanf("%d", &value) == 1 && value > 0)
        {
            count++;
            for(i = value; i >= 0; i--)
                counter(i);
            printf("请输入任意数字，0退出：");
        }
        report_count();
    }
    void report_count()
    {
        printf("循环执行了%d次\n", count);
    }
