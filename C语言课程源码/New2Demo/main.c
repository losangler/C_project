#include <stdio.h>
#include <stdlib.h>
/*
Բ��s = PI * r * r;
���Σ�s = width * height;
�����Σ�s = width * height / 2;
*/
//���ݴ���İ뾶������Բ���
/*
double calcCircle(double);
//���û���������зǸ���֤/���û�������ȷ��ֵ/�õ��û����������ȷֵ
int validate(double);   //��֤�����double���������Ƿ�Ϊ����
//double input(); //������ֱ�����û����룬���������Ҫ�������¼�룬����¼����ȷ������

double calcRectangle(double, double);//������ε����
*/



int * test()
{
    int nums[] = {33, 44, 55, 66, 6767};
    int * p = nums;
    return p;
}

int main()
{
    int * nums = test();
    int i= 0;
    for(; i < 5; i++)
    {
        printf("%d\n", *(nums + i));
    }













    /*
    //˼�����ڱ����У���Щ�����ǱȽ�ͨ�õģ��ǿ�����д�ɺ�����ε��õģ�
    //1���û�����ı���������
    //2����ӡ���
    double radius;          //�û�����İ뾶
    double width, height;   //ͼ�εĿ�͸�
    double s;               //ͼ�ε����
    int choice;             //�û���ѡ��

    printf("1��Բ\n");
    printf("2������\n");
    printf("3��������\n");
    printf("��ϵͳ֧�ּ�������ͼ�ε��������ѡ��\n");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        printf("������Բ�뾶����������Բ�������");
        do{
            scanf("%lf", &radius);  //¼��
            if(!validate(radius))//���û��ͨ����֤���ʹ�ӡһ����ʾ
            {
                printf("��¼������ݲ���Ϊ����������������һ��������");
            }
        }while(!validate(radius));//����֤��ͨ����ʱ������¼��
        s = calcCircle(radius); //���ü���Բ����ķ���
        break;
    case 2:
        printf("��������εĿ�͸ߣ�����������ε������");
        do{
            scanf("%lf%lf", &width, &height);
            if(!validate(width) || !validate(height))
            {
                printf("��¼������ݲ���Ϊ��������������������������");
            }
        }while(!validate(width) || !validate(height));
        //��֤ͨ��֮�󣬵��÷�������ͼ�ε����
        s = calcRectangle(width, height);
        break;
    case 3:
        break;
    default:
        printf("��ϵͳֻ֧��3��ͼ�Σ�����1-3֮��ѡ��");
    }

    printf("ͼ�ε����Ϊ��%.2lf\n", s);
    //�ں�����ʵ�ֵ��� ��ͼ�εļ������
    */
    return 0;
}
/*
double calcCircle(double radius)
{
    //pow���������Լ�����
    double s = 3.14 * pow(radius, 2);
    //���ؼ���õ����ֵ
    return s;
}
//��֤�����double���������Ƿ�Ϊ����
int validate(double num)
{
    return num > 0 ;    //���num>0���᷵��һ������ֵ����ʾ��
}
//���ݴ���ľ��ο�͸ߣ����ؾ������
double calcRectangle(double width, double height)
{
    return width * height;
}
*/
