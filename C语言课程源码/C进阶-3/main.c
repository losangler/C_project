    #include <stdio.h>
    void report_count();
    void counter(int num);
    int count = 0;  //�ļ��������ⲿ����
    int test;
    int main()
    {

        printf("%d\n", num);

        printf("%d\n", test);
        int value;      //�Զ�����
        register int i; //�Ĵ�������
        printf("�������������֣�0�˳���");
        while(scanf("%d", &value) == 1 && value > 0)
        {
            count++;
            for(i = value; i >= 0; i--)
                counter(i);
            printf("�������������֣�0�˳���");
        }
        report_count();
    }
    void report_count()
    {
        printf("ѭ��ִ����%d��\n", count);
    }
