#include <stdio.h>
#include <stdlib.h>
/**
 * ��������ϰ����
 */
int main()
{
    //scanf���÷�С��
    int num1, num2, num3;
    printf("�������������֣�");
    //Ĭ�ϵķָ����ǿո�
    scanf("%d%d%d", &num1, &num2, &num3);
    //scanf("%d", &num1);
    //scanf("%d", &num2);
    //scanf("%d", &num3);
    printf("������������ֱַ�Ϊ��%d\t%d\t%d\n", num1, num2, num3);
    return 0;
    /*
    1��Ҫ���û�����1-7֮�������
2���ж�����ĩ������ͨ������
   6��7           �������

int dayNum;//���ڼ�
printf("������1-7֮������֣�");
scanf("%d", &dayNum);
//�ж�����ĩ������ͨ������
if(dayNum == 6 || dayNum == 7)
{
	printf("����ĩ��\n");
}else if(dayNum == 1 || dayNum == 2.....)
{
	printf("�ǹ����գ�\n");
}else
{
	printf("�û�������ǷǷ����֣�\n");
}


char op;//�����
int num1, num2;
printf("�������һ����������");
scanf("%d", &num1);
printf("�������������");
scanf("%c", &op);
fflush(stdin);//��ջ�����
printf("�������������������");
scanf("%d", &num2);
//ʹ��switch�ṹ
switch(op)
{
	case '+':
		printf("%d", num1 + num2);
		break;
	case '-':
		printf("%d", num1 - num2);
		break;
}
    */
}
