#include <stdio.h>
#include <stdlib.h>
/*
��д����ʵ������Ԫ�صĲ��ң�Ҫ�󷵻��ҵ���Ԫ���±�
��д����ʵ��ð�����򲢷�������������
��д����Ҫ���û��������루6λ���������������룩�����ز���ӡ�û��������ȷ����
*/

//��д����ʵ������Ԫ�صĲ��ң�Ҫ�󷵻��ҵ���Ԫ���±�
int search();
//��д����ʵ��ð�����򲢷�������������
//double[] sort();
//��д����Ҫ���û��������루6λ���������������룩�����ز���ӡ�û��������ȷ����
//char * password();

int main()
{

    int index = search();
    printf("�ҵ���Ԫ���±��ǣ�%d\n", index);
    return 0;
}

int search()
{
    int nums[] = {34, 56, 78, 3, 2};
    int i;
    //Ҫ���ҵ����֣����������ֵ��±꣬û�ҵ�indexΪ-1
    int searchNum;
    int searchIndex = -1;
    printf("������Ҫ���ҵ��������֣�");
    scanf("%d", &searchNum);
    for(i = 0; i < 5; i++)
    {
        if(searchNum == *(nums + i))
        {
            searchIndex = i;//��¼�²��ҵ����±�
            //return searchNum;
            break;
        }
    }//���ز��ҵ���Ԫ���±�
    return searchIndex;
}




