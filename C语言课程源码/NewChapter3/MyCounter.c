/**
 * MyCount.c
 * ������ż��㺯�����ô����ĺ���ԭ�ͼ�ʵ��
 */
//�������ⲿ����
extern int whileCount;

void counter(int);//��������counter����ִ���˶��ٴ�

void counter(int i)
{
    static int subTotal = 0;    //��̬����

    subTotal++;

    printf("counter������������%d��\n", subTotal);
    printf("��ǰ��while�ĵ�%d�֣�\n", whileCount);
    return ;
}
