#include <stdio.h>
#include <stdlib.h>
#define N 5
int main()
{
    //��̬¼��
    double score[N];
    int i;//ѭ������
    for(i=0;i<N;i++){
        printf("�������%dλͬѧ�ɼ���",i+1);
        scanf("%lf",&score[i]);//scanf����ĵ�i��Ԫ��
    }
    //������ѭ������ӡ����Ԫ��
    for(i=0;i<N;i++){
       printf("\n��%dλͬѧ�ɼ��ǣ�%.2lf",i+1,score[i]);
        //scanf("%lf",&score[i]);//scanf����ĵ�i��Ԫ��
    }
    return 0;
}
