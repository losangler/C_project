#include <stdio.h>
#include <stdlib.h>

int main()
{
    //ɱ����switch�ṹ���÷�
    //һ�㴦��������ĳ����������
    //��֪��ĳ�����ж�����
    //�߼����û������·ݣ������·��жϵ��µ�����
    int month;  //�û�������·�
    printf("�������·ݣ������ж�������");
    scanf("%d", &month);
    switch(month)
    {
    default:
        printf("��ǰ������ʱֻ���ж�1-4�µ������\n");
        break;
    case 1:
        printf("1����31�죡\n");
        printf("1�¹�������꣡\n");
        break;
    case 2:
        //����ܹ����ж����Ƿ�������
        printf("2����28�죡\n");
        printf("�����д�˵�е���٣�\n");
        break;
    case 3:
        printf("3����31�죡\n");
        printf("�̻����������ݣ�\n");
        break;
    case 4:
        printf("4����30�죡\n");
        break;

    }

















    /*
    double flowerPrice; //�ʻ��ļ۸�
    //��ӡ����
    printf("��һ���ºڷ�ߵ�ҹ��\n");
    printf("һ��С�������Լ����㻨Ǯ��СŮ������һ���ʻ�\n");
    printf("СŮ����С�����ʻ��ļ۸񣬡��⻨����Ǯ?��\n");
    printf("С������");
    //��Ҫ¼���ʻ��ļ۸�
    scanf("%lf", &flowerPrice);
    //�������ģ��СŮ���ķ�Ӧ
    if(flowerPrice > 999999)
    {
        printf("СŮ��ֱ�����˹�ȥ��\n");
    }
    else if(flowerPrice >= 100000 && flowerPrice <= 999999)//10��999999֮��
    {
        printf("����ͽ�飡\n");
    }
    else if(flowerPrice >= 10000 && flowerPrice < 100000)
    {
        printf("��������˼��˼��������Լ��");
    }
    else
    {
        printf("�ðɣ���������ͨ���ѣ����Ǹ�����!\n");
    }
*/













    /*
    //����ܼ۴���5000�ʹ�7�ۣ�����9��
    double price1 = 229.0;
    double price2 = 10240.55;
    double price3 = 2345.3;
    double total = price1 + price2 + price3;
    double zhekou;  //�ۿ�
    //�̼Ҹ��������ۿ۵Ĺ���
    //��������������Ʒ��һ����Ʒ���۴���1000
    //��������Ʒ�ܽ�����5000���ۿ���Ϊ30%��
    //����û���ۿ�
    if(price1 > 1000 || price2 > 1000 || price3 > 1000 || total > 5000)
    {
        zhekou = 0.3;
    }
    /*
    if(total > 5000)
    {
        //total *= 0.7;//total = total * 0.7;
        zhekou = 0.7;
    }
    else
    {
        //total *= 0.9;
        zhekou = 0.9;
    }*/
    /*
    total = zhekou * total;//total *= zhekou;
    printf("�ܼ�����Ӧ֧���Ľ��Ϊ��%.2lf\n", total);
    */
































    /*
    //�ж��·ݵ�����
    int month;
    printf("�������·ݣ�");
    scanf("%d", &month);
    //if(month == 1 || month == 3 || month == 5)
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    //....
    printf("31��");
    break;
    case 4:
    case 6:
    //.....
    printf("30��");
    break;

    }
    /*
    int choice = 3;//ѡ��
    printf("1���ͻ�\n");
    printf("2����������\n");
    printf("3���ͼ�F16\n");
    printf("��ѡ��");
    scanf("%d", &choice);
    switch(choice)
    {
    default:
        printf("ɧ�꣬��Ҫ����������������\n");
        break;
    case 1:
        printf("�ɹ�������һ���ʻ���\n");
        break;
    case 2:
        printf("�ɹ�������һ�����ۻ�Ӱ9000\n");
        break;
    case 3:
        printf("�ɹ�������һ��F16ս����\n");
        break;

    }
*/












    /*
    char ch1, ch2;
    printf("�ַ�1��");
    ch1 = getchar();
    fflush(stdin);//��ջ�����-����
    printf("�ַ�2��");
    ch2 = getchar();

    putchar(ch1);
    putchar(',');
    putchar(ch2);
*/
   /* //ʹ�ó����ж��û�������ַ��Ƿ��ǺϷ���Ӳ���̷�A-Z
    char hardChar;  //Ӳ���̷�
    printf("�������̷���ĸ��");
    //scanf("%c", &hardChar);
    hardChar = getchar();   //��ȡ�û����뵥���ַ�
    //�ж��û�������ַ��Ƿ���A-Z֮��
    //if('A' <= hardChar <= 'Z')
    if(hardChar >= 'A' && hardChar <= 'Z')
    {
        printf("����ȷ���̷���\n");
    }
    else
    {
        printf("������ȷ���̷���");
    }*/








    /*
   //��������� + - * / %
   //��ϵ����� > < >= <= == !=
   //�߼������ && || !
   //��ֵ����� = += -= /= *= %=
   int num = 10; //  9<20
   int result = --num < 20 && num++ > 11;//��·����
   //���⣺result=��  num=��
   printf("result=%d\tnum=%d\n", result, num);
*/







    /*
    //��ʾgetchar��putchar���÷�
    char ch1, ch2;    //�ַ��ͱ���
    printf("������һ���ַ���");
    //scanf("%c", &ch); ���뵥���ַ��ĵȼ�д��
    ch1 = getchar();// a
    //��ջ�����  <- ��ҵ�в�������ݣ���ҿ���ɾ��fflush���۲첻ͬ�Ľ��
    fflush(stdin);
    printf("������ڶ����ַ���");
    ch2 = getchar();// �س���\n
    //printf("��������ַ��ǣ�%c, %c\n", ch1, ch2);
    printf("��������ַ��ǣ�");
    putchar(ch1);   //putcharһ��ֻ�ܴ�ӡһ���ַ�
    putchar(',');
    putchar(ch2);
    */
    return 0;

}
