#include <stdio.h>
#include <stdlib.h>

int main()
{
    int value1 = 44;
    int arr[4];
    int value2 = 88;
    int i;

    printf("value1 = %d, value2 = %d\n", value1, value2);
    arr[-1] = 9;
//    for(i = -1; i <= 4; i++){
//        arr[i] = 2 * i + 1;
//    }
    /*
    for(i = -1; i < 7; i++){
        printf("%d\t%d\n", i, arr[i]);
    }*/
    printf("\n");
    printf("value1 = %d, value2 = %d\n", value1, value2);

    printf("arr[-1]�ĵ�ַ��%p\n", &arr[-1]);
    printf("arr[9]�ĵ�ַ��%p\n", &arr[4]);
    printf("value1�ĵ�ַ��%p\n", &value1);
    printf("value2�ĵ�ַ��%p\n", &value2);

    /*
    int age;
    int i;
    int count = 0;//������
    for(i = 0; i < 5; i++)
    {
        printf("������������䣺");
        scanf("%d", &age);
        if(age >= 0)//��ȷ
        {
            continue;//������ȷ�����
        }
        count++;
    }
    printf("�������%d�Σ�\n", count);
*/













    /*
    int price = 7890;   //Ҫ�û��µ���Ʒ�۸�Ҳ����ʹ�������������
    int guessPrice;     //�û��²����Ʒ�۸�
    int count = 0;      //������¼�µĴ���
    srand(time(NULL));
    price = rand() % 10000;
    printf("%d", price);
    for(;;)
    {
        printf("������²����Ʒ�۸�");
        scanf("%d", &guessPrice);
        if(guessPrice > price)
        {
            printf("���ˣ�\n");
        }
        else if(guessPrice < price)
        {
            printf("С�ˣ�\n");
        }
        else//����
        {
            printf("��ϲ���¶�����\n");
            count++;
            break;//����¶��ˣ�������ѭ��
        }
        count++;

    }

    printf("��һ������%d��\n", count);
    if(count <= 5)
    {
        printf("���ʣ�����ֱ����ţ�\n");
    }

*/









    /*
    //ѭ��������ҵ����䣬�������Ϊ����ֹͣ���룬��ʾ�������
    int age;    //��ҵ�����
    //for(;;)
    //while(1)
    for(;;)
    {
        printf("������������䣺");
        scanf("%d", &age);
        //�ж�
        if(age < 0)
        {
            printf("���䲻��Ϊ����������ǿ���˳���\n");
            break;
        }
    }
    */
    //













/*
    //��ӡ���׼ӷ���
    //1����ӡ���ļӷ���
    int num;
    int i;  //ѭ������
    printf("������һ�����֣�");
    scanf("%d", &num);
    for(i = 0; i < num; i++)
    {
        //0 + 8 = 8
        printf("%d + %d = %d", i, (num - i), num);
        //������Ҫ̽�֣�ʲô�����ӡ\tʲô�����ӡ\n
        //���ۣ�������Ҫͨ���ж�ѭ��������ֵ��ȷ����ӡ�ķ���
        if(i % 2 == 0)//��i��ż���������0,2,4,6)
        {
            printf("\t");
        }
        else//���������
        {
            printf("\n");
        }

    }
*/










    /*
    int y = 1;//��ʮ�����ӵ�����
    int i = 0;//����ѭ���Ĵ��� - 9��ѭ��
    while(i < 9)
    {
        y = (y + 1) * 2;
        i++;
    }
    printf("��һ������������ǣ�%d\n", y);
    */
    return 0;
}
