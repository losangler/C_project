#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//����ԭ��
void calcCircle();      //����Բ���
void calcRectangle();   //����������
int calcSum();         //��1-100֮���ż����
/**
 * ����Բ�����������ʵ��)
 */
void calcCircle()
{
    double radius, s;//�뾶�����
    printf("������Բ�뾶��");
    scanf("%lf", &radius);
    //Բ���=3.14���԰뾶��ƽ��
    s = 3.14 * pow(radius, 2);
    printf("�뾶Ϊ%.2lf��Բ���Ϊ��%.2lf\n", radius, s);
}
void calcRectangle(void)
{
    double width, height;   //���εĿ�͸�
    double s;               //���ε����
    printf("��������εĿ�͸ߣ�");
    scanf("%lf%lf", &width, &height);
    if(width <= 0 || height <= 0)
    {
        printf("��͸߲���Ϊ��������ˣ�����أ���\n");
        return;
    }
    s = width * height;
    printf("���ε����Ϊ��%.2lf", s);

}
int calcSum()
{
    //1-100֮���ż����
    int sum = 0;
    int i = 1;
    for(i = 1; i <= 100; i++)
    {
        if(i % 2 == 0)
            sum++;
    }
    //������õĽ������
    return sum;
}

int main()
{
    //��д�����Ĳ��裺��ɺ�����Ҫ��-����ֵ���͡��������ơ������б�
    //��������Ҫһ��ʼ��ȥ����������ĳ������


















    /*
    //��ʾ��̬�����ڴ棺
    int i;
    int * nums;
    //Ϊǰ���ָ�붯̬������20���ֽ�(5������)�Ŀռ�
    //nums = (int *)malloc(sizeof(int) * 5);
    nums = calloc(5, sizeof(int));
    //double * dNums = (double *)malloc(sizeof(double) * 5);
    //�ȼ��ڣ�int nums[999999]
    //Ϊָ�붯̬����ռ��ָ��ͱ��������

    nums[3] = 1121;
    nums++;//ָ�뱻�ƶ���

    printf("����Ԫ��Ϊ��\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d\t", *(nums + i));
    }
    free(nums); //�ͷŶ�̬������ڴ�
    nums  = NULL;   //���õı��ϰ��










/*
    //1.����������� - һ���ʱ�����ã���Ϊʱ��ÿʱÿ���ǲ�ͬ��
    srand(time(NULL));
    //2.ȡ�����
    int num = rand();
    printf("%d\n", num);

    exit(0);//0-�����˳�Ӧ�ó��� ������ǲ������˳�











    /*&
    //ceil - ��һ��    floor - ȥβ��
    //����Ǹ����������෴

    printf("%.2lf\n", ceil(98.01));
    printf("%.2lf\n", floor(98.9));

    printf("%.2lf\n", sqrt(9));//��ƽ����

    printf("%.2lf\n", pow(5, 4));//���һ�����ֵĵڶ������ִ���

    printf("%d\n", abs(-98));    //�����ֵ

*/











    /*
    printf("%d\n", isupper('a'));
    printf("%d\n", islower('a'));
    printf("%d\n", isalpha(97));   //�����ַ��Ƿ�Ϊ��ĸ
    //�������������֣���ʾ����ascii��
    printf("%d\n", isdigit(50));     //�����ַ��Ƿ�Ϊ����
    //ת����Сд
    printf("��д��%c", toupper('9'));

    //˼���⣺��ν��û������Сд����ת�����Ĵ�д��
    //1234   -     ҼǪ������ʰ��Ԫ��
    int money, count = 0;//count�����ֵ�λ��
    int i = 0;
    int moneys[6];//Ĭ��֧��6λ����
    char unit[10][4] = {"��", "Ҽ", "��", "��", "��", "��", "½", "��", "��", "��"};
    printf("�������");
    scanf("%d", &money);
    //�ж��û����˼�λ���֣���ÿһλ����ȡ����
    while(money != 0)
    {
        moneys[i] = money % 10;
        money /= 10; //ȥ�����һλ
        i++;
        count++;
    }
    printf("�û����������һ����%dλ��\n", count);
    printf("�����е����ݣ� \n");
    for(i = 0; i < count; i++)
    {
        printf("%d - %s\n", moneys[i], unit[moneys[i]]);
    }

/*
    int i;
    //��ӡ���е�ascii���Ӧ���ַ�
    for(i = 0; i < 127; i++)
    {
        printf("%c,", i);
    }
*/
    return 0;
}
