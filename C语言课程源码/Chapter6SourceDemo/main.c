#include <stdio.h>
#include <stdlib.h>
#define N 5 //�궨�壬�����Ǳ����
int main()
{
    int i, j;
    //ʹ�ö�ά�����ʾѧ���ĳɼ���
    //�ĸ�ѧ����3�ſγɼ� - 4�� 3��
    double scores[4][3] = {
        {98, 67, 89},
        {89, 67, 88},
        {99, 77, 55},
        {78, 99, 67}
    };
    printf("����\tӢ��\t��ѧ\n");
    //ʹ��ѭ����ӡÿ������Ԫ��
    for(i = 0; i < 4; i++)//���ѭ�������м���ѧ��
    {
        for(j = 0; j < 3; j++)
        {
            printf("%-8.2lf", scores[i][j]);
        }
        printf("\n");
    }

















    /*
    ɾ�����߼�
    12 34 23 67 9
    12 34 67 9 9
    1������Ҫɾ�����ֵ��±� 2
    2�����±꿪ʼ������һ������ǰ��һ������
    3��������ܳ���-1
    */
    /*
    int count = 5;      //��ʾ����Ԫ�صĸ���
    double powers[] = {42322, 45771, 40907, 41234, 40767};
    int test;
    double deletePower; //�û�Ҫɾ����ս��ֵ
    int deleteIndex = -1;//Ҫɾ��ս��ֵ���±�,��һ�������ܵĳ�ֵ�������ж�
    int i;              //ѭ������
    double insertPower; //�²����ս��ֵ
    printf("������Ҫɾ����ս��ֵ��");
    scanf("%lf", &deletePower);
    for(i = 0; i < count; i++)
    {
        if(deletePower == powers[i])
        {
            //��¼�µ�ǰ���±�
            deleteIndex = i;
            break;//�ҵ���Ҫɾ����ս��ֵ��ֱ������ѭ��������Ч��
        }
    }
    //�����жϣ��Ƿ��ҵ�����ִ�к����Ĳ���
    if(-1 == deleteIndex)
    {
        printf("���ź���û���ҵ�Ҫɾ����ս��ֵ��ɾ��ʧ�ܣ�\n");
    }
    else
    {
        //���±꿪ʼ������һ������ǰ��һ������
        for(i = deleteIndex; i < count - 1; i++)
        {
            powers[i] = powers[i + 1];
        }
        //ɾ����Ϻ�һ���ǵ�������ܳ���-1  ���۷�Ҫ������
        count--;
    }
    printf("ɾ����Ľ��Ϊ��\n");
    for(i = 0; i < count; i++)
    {
        printf("%.2lf\t", powers[i]);
    }
    //ɾ��֮����в���
    printf("��������ս��ֵ��");
    scanf("%lf", &insertPower);
    powers[count] = insertPower;//ע��������
    //���������Ϻ󣬼ǵ������ܳ���+1
    count++;
    printf("�����Ľ��Ϊ��\n");
    test = 123456;
    for(i = 0; i < count; i++)
    {
        printf("%.2lf\t", powers[i]);
    }
    //�������ս��ֵ��������ֱ��ʹ��ð�����򼴿�

*/



    /*
    16  25  9  90 23
    �������� - �Ӵ�С
    ð������Ļ���ԭ�������ͽ���
    ��һ��ѭ����
    ĳ������С�ں�������֣���ô�ͽ���
    1    25 16 9 90 23
    2    25 16 9 90 23
    3    25 16 90 9 23
    4    25 16 90 23 9 ��С�����־�ð�������
    1����Ҫ�Ƚ϶��� (���鳤�� - 1) ��
    2��ÿһ�ֱȽϵĴ�������һ��-1��
       (���鳤�� - 1) - ��ǰ������
    */
    /*
    int i, j;   //ѭ������
    int temp;   //������������ʱ����
    int nums[N] = {16,  25,  9,  90, 23};
    //���ѭ������ ����
    for(i = 0; i < N - 1; i++)
    {
        //�ڲ�ѭ������ ÿ�ֵıȽϴ���
        for(j = 0; j < N - i - 1; j++)
        {
            //�����ǰֵС�ں���һ��ֵ���ͽ���
            if(nums[j] < nums[j + 1])
            {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }

        }
    }
    printf("�����Ľ���ǣ�\n");
    for(i = 0; i < N; i++)
    {
        printf("%d\t", nums[i]);
    }
    for(i = 0; i < N - 1; i++)
    {
        //�ڲ�ѭ������ ÿ�ֵıȽϴ���
        for(j = 0; j < N - i - 1; j++)
        {
            //�����ǰֵС�ں���һ��ֵ���ͽ���
            if(nums[j] > nums[j + 1])
            {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }

        }
    }
    printf("�����Ľ���ǣ�\n");
    for(i = 0; i < N; i++)
    {
        printf("%d\t", nums[i]);
    }
*/

















    /*
    //ս������
    double powers[N] = {45771, 34565, 12345, 89765, 45213};
    int i, j;            //ѭ������
    double tempPower;    //������������ʱ����
    int deleteIndex = -1;//Ҫɾ��Ԫ�ص��±�
    double deletePower;     //Ҫɾ����ս��ֵ
    int count = N;       //��ʾ��ǰ��Ԫ������
    //1.�������в���ӡ
    for(i = 0; i < N - 1; i++)
    {
        for(j = 0; j < N - i - 1; j++)
        {
            if(powers[j] < powers[j + 1])
            {
                tempPower = powers[j];
                powers[j] = powers[j + 1];
                powers[j + 1] = tempPower;
            }
        }
    }
    printf("�����\n");
    for(i = 0; i < N; i++)
    {
        printf("%.2lf\t", powers[i]);
    }




    printf("������Ҫɾ����ս��ֵ��");
    scanf("%lf", &deletePower);
    //1������Ҫɾ�������±�
    for(i = 0; i < count; i++)
    {
        if(deletePower == powers[i])
        {
            //�ҵ���Ҫɾ����Ԫ�أ���¼Ԫ�ص��±�
            deleteIndex = i;
            break;
        }
    }
    //2�����ҵ����±꿪ʼ������һ������ǰ��һ��Ԫ��
    if(deleteIndex == -1)
    {
        printf("û���ҵ�Ҫɾ����Ԫ�أ�\n");
    }
    else
    {
        //ע��������ܳ���Ҫ-1
        for(i = deleteIndex; i < count - 1; i++)
        {
            powers[i] = powers[i + 1];
        }
    }
    //3�����۷��������ܳ���-1
    count--;
    printf("ɾ����\n");
    for(i = 0; i < count; i++)
    {
        printf("%.2lf\t", powers[i]);
    }

*/




    /*
    int i, j;
    int temp;//������������ʱ����
    int nums[5] = {33, 44, 22, 11, 78};
    //��ѭ������Ƚϵ�����
    for(i = 0; i < 5 - 1; i++)
    {
        //��ѭ������ÿ�αȽϲ�����
        for(j = 0; j < 5 - i - 1; j++)
        {
            //ǰ��һ���Ⱥ���һ���󣬾ͽ���
            if(nums[j] < nums[j + 1])
            {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    printf("����������Ϊ��\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d\t", nums[i]);
    }
*/




    /*
    //����һ���������飬��ֵ���������������ż������
    int array[N];
    int i;
    int count1 = 0, count2 = 0;//�ֱ��ʾ�����ĸ�����ż���ĸ���
    int searchNum;  //Ҫ���ҵ�Ԫ��
    int searchIndex = -9999;//Ҫ����Ԫ�ص��±꣨Ҫ�趨һ�������ܵ�ֵ��
    //ʹ��ѭ��¼��
    for(i = 0; i < N; i++)
    {
        printf("�������%d�����֣�", i + 1);
        scanf("%d", &array[i]);
    }
    //ʹ������һ��ѭ��ͳ�Ƹ���
    for(i = 0; i < N; i++)
    {
        if(array[i] % 2 == 0)//��������е�ĳ��Ԫ��Ϊż��
        {
            count2++;
        }
        else
        {
            count1++;
        }
    }
    printf("������%d����ż����%d��\n", count1, count2);

    printf("������Ҫ���ҵ�Ԫ�أ�");
    scanf("%d", &searchNum);
    //ͨ��forѭ������
    for(i = 0; i < N; i++)
    {
        if(searchNum == array[i])
        {
            searchIndex = i;//���ҵ��������±걣�浽searchIndex������
            break;//�ҵ��󣬾�û�б�Ҫ�ټ��������ˣ�����ѭ��
        }
    }
    if(searchIndex == -9999)//���searchIndex������ֵ�ǳ�ֵ-1��֤��û���ҵ�Ԫ��
    {
        printf("û���ҵ�%d���Ԫ�أ�\n", searchNum);
    }
    else
    {
        printf("�ҵ��ˣ�Ԫ�ص��±�Ϊ��%d\n", searchIndex);
    }
*/











    /*
    //int nums[] = {8, 0, 0, 99, 2, 1, 23, 344, 12};
    int nums[] = {8, [3]=99, 2, 1, 23, 344, 12};//C99֮��֧��
    int i;
    //�����ֵ
    int max = nums[0];//���Ǽ��������еĵ�һ��Ԫ�����
    int min = nums[0];
    //ͨ��ѭ�����Ƚϣ�max���൱����̨��˭�󣬾�������̨��
    for(i = 0; i < N; i++)
    {
        if(max < nums[i])//�൱���佫pk������Ϊ���ֵ����û����̨�ϵĴ�
        {//�������ֵ������̨
            max = nums[i];
        }
        if(min > nums[i])
        {
            min = nums[i];
        }
    }
    printf("�����е����ֵ�ǣ�%d\t��Сֵ�ǣ�%d\n", max, min);
    */
    /*
    ��һ�����У�8��4��2��1��23��344��12
        ѭ��������е�ֵ
        ��������������ֵ�ĺͼ�ƽ��ֵ
        ������Ϸ���Ӽ�������������һ�����ݣ��ж��������Ƿ��������
    */
    /*
    int i;          //ѭ������
    int sum = 0;    //���
    double avg;     //��ƽ��
    int searchNum;  //Ҫ���ҵ�����
    //1.�������飬����ʼ��
    int nums[N] = {8, 4, 2, 1, 23, 344, 12};
    //2.ѭ�����
    printf("�������Ԫ�أ�\n");
    for(i = 0; i < N; i++)
    {
        printf("%d\t", nums[i]);
    }
    printf("\n*****************************\n");
    //3.��ͺ���ƽ��ֵ
    for(i = 0; i < N; i++)
    {
        sum += nums[i];//�����ۼ�
    }
    avg = sum / 7.0;
    //4.��������
    printf("������Ҫ���ҵ����֣�");
    scanf("%d", &searchNum);
    for(i = 0; i < N; i++)
    {
        //һ��һ��Ԫ�ؽ��жԱ�
        //�����Ҫ���ҵ����ָ������е�ĳ��Ԫ����ͬ
        if(searchNum == nums[i])
        {
            //�ҵ���
            printf("Գ�డ���ҵ�����ͬ��Ԫ�أ�\n");
            //�ҵ��󣬼ǵ�����ѭ��
            break;
        }
    }
    //����ѭ������������ж��Ƿ��ҵ����أ�������
    //ͨ���۲죬ѭ�������˳�ʱ��i��ֵӦ��Ϊ7
    if(i == 7){
        printf("ãã�˺���û���ҵ���������֣�\n");
    }
*/









    /*
    //��̬¼��
    double score[N];
    int i;  //ѭ������
    //ʹ��ѭ����������ʱ��Ҫע�⣺һ��ѭ������ֻ��һ����
    for(i = 0; i < N; i++)
    {
        printf("�������%dλͬѧ�ĳɼ���", i + 1);
        scanf("%lf", &score[i]);
    }
    //�����ѭ��������ӡ����Ԫ��
    for(i = 0; i < N; i++)
    {
        printf("��%dλͬѧ�ĳɼ��ǣ�%.2lf\n", i + 1, score[i]);
    }

*/
    return 0;
}
