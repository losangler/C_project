#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num = 123456789;
    //��4λ����ÿһλ��ȡ����
    printf("��λ��%d\n", num % 10);
    printf("ʮλ��%d\n", num / 10 % 10);
    printf("��λ��%d\n", num / 100 % 10);
    printf("ǧλ��%d\n", num / 1000 % 10);

    exit(0);//�˳�ϵͳ


    //���ɣ���10��ģ10
    int temp;   //��ʱ����
    while(num > 0)
    {
        printf("%d\n", num % 10);
        num /= 10;//ȡ����λ���ֺ�����ȥ����λ����
    }






    /*
    int choice;     //�û���ѡ��
    while(1)
    {
        //��ӡ��Ϸ�˵�
        printf("�Ը���ԣ�\n");
        printf("�������һλ�������������Եİ�����ϣ����\n");
        printf("1��ֻҪ��һλ�氮������\n");
        printf("2��������λ���ϵİ���\n");
        printf("3��ӵ����ǧ����\n");
        do{//���������󣬽���һֱѭ������
            printf("��ѡ��:");
            scanf("%d", &choice);
            if(choice <= 0 || choice > 3)
            {
                printf("ֻ������1-3֮������֣����������룺\n");
            }
        }while(choice <= 0 || choice > 3);//˼����choiceΪʲôֵ��ʱ��ִ��ѭ��?
        //���ִ�е������֤���û�����������ȷ�ģ���1-3֮��
        switch(choice)
        {
        case 1:
            printf("��ѡ���������е�Ψһ��Ȼ���Ͼž��ѿ�����һ�У�\n");
            break;
        case 2:
            printf("������Ĵ��ܲ���\n");
            break;
        case 3:
            printf("����磬10Ԫ/�������㻦���ʣ�\n");
            break;
        }
    }*/
    return 0;
}




