#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
//��Ҫ�����á������������������á�����������ѡ������ӣ�-lwinmm
//��Setting��Compiler��Linker settings��Other link option ��ӣ�-lwinmm
/*
 * ��Ҫ�ر��г�����չ֪ʶ�㣺
 * 1�����������ĺ���������������
 * 2��Sleep()����
 * 3���ַ������鼰�򵥵��ַ�����������Ƚϡ�����
 * 4��ʱ�亯����exit����
 */
#pragma comment(lib, "Winmm.lib")
#define DAY_COUNT 10
int main()
{
    int i;          //ѭ�����������ʹ��
    int count = 5;  //��ŵ�ǰ���������
    int currDay = 0;//��Ϸ��ǰ���е��˵ڼ���
    int choice;     //��������û���ѡ��
    int tempCount;  //��ʱ������������źøжȵ���60�ĸ���
    int index = -1; //�������ɾ��������ʱ������
    char name[8];   //��������û����������
    //�������飬�������6���ַ�����ÿ���ַ�������󳤶�Ϊ8���ַ���Ӣ�ģ�
    char names[6][8] = {"��ʩ", "����", "���Ѿ�", "����", "�Է���"};
    //�������飬�������5���ַ�����ÿ���ַ�������󳤶�Ϊ8���ַ���Ӣ�ģ�
    char levelNames[5][8] = {"����", "����", "����", "�ʹ���", "�ʺ�"};
    //�������ÿ�����ӵĵȼ�����levelNames���á�-1��ʾδ����
    int level[] = {0, 2, 0, 0, 0, -1};
    //�������ÿ�����ӵĺøжȣ�-1��ʾδ����
    int loves[] = {100, 100, 100, 100, 100, -1};
    do{
        PlaySound(TEXT("sounds\\��������.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        printf("��%d�죺\n", ++currDay);
        printf("1���ʵ���ּѡ����\t�����ӣ�\n");
        Sleep(500);
        printf("2�����Ƴ���\t\t���޸�״̬��\n");
        Sleep(500);
        printf("3�������乬��\t\t��ɾ����\n");
        Sleep(500);
        printf("4���޵İ����أ�\t\t�����ң�\n");
        printf("������ѡ��");
        scanf("%d", &choice);
        switch(choice){
        case 1://�������ӣ������˺øж�-10
            PlaySound(TEXT("sounds\\ѡ��.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            //�����ж����鳤���Ƿ��������Ԫ��
            if(count >= sizeof(level)/sizeof(int))
            {
                printf("\n������Ϊ�������»����ٵȵȰɣ�\n\n");
                break;
            }
            printf("����ɽ�������ˣ���ǧ����һ���~\n");
            printf("�������䣺");
            scanf("%s", name);
            //������Ԫ�ط���count��
            strcpy(names[count], name);
            level[count] = 0;
            loves[count] = 100;
            printf("\n�������ӣ������˺øж�-10\n\n");
            for(i = 0; i < count; i++){
                loves[i] -= 10;
            }
            count++;
            break;
        case 2://���Ƴ��ң����ҵ����Ӻøж�+20��������-10
            PlaySound(TEXT("sounds\\����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            printf("����������Ҫ���ҵ�������");
            scanf("%s", &name);
            for(i = 0; i < count; i++){
                if(strcmp(name, names[i]) == 0){
                    index = i;
                    continue;
                }
                loves[i] -= 10;
            }
            if(index == -1)//û���ҵ�
            {
                printf("\n�����δͳһ�����ܶ�Ů�鳤��\n\n");
            }
            else
            {
                loves[index] += 20;
                //ÿ����һ�Σ���������1�������Ϊ4�����ʺ�
                level[index] == 4 ? 4 : level[index]++;
                printf("\n******************************\n");
                printf("Duang~%s�����ȼ�Ϊ��%s\n", names[index], levelNames[level[index]]);
                printf("******************************\n\n");
                printf("���ݻ��ӶԴ������ȹ��������š�\n����ȴ�۹���������ʧ��ʱ��¶���� \n");
                printf("��������øж�-10��\n\n");
            }
            index = -1;
            break;
        case 3://�����乬��ִ��ɾ���������������Ӻøж�ͳһ+10
            PlaySound(TEXT("sounds\\�乬.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            printf("����Ҫ����λ��������乬�أ�");
            scanf("%s", &name);
            for(i = 0; i < count; i++){
                if(strcmp(name, names[i]) == 0){
                   index = i;
                   break;
                }
            }
            if(index == -1)//δ�ҵ�Ҫɾ��������
            {
                printf("\n�龪һ�������˴����乬���óԳԸúȺ�~\n\n");
                break;
            }
            //ִ��ɾ������
            for(i = index; i < count - 1; i++)
            {
                strcpy(names[i], names[i + 1]);
                level[i] = level[i + 1];
                loves[i] = loves[i + 1];
            }
            count--;//������-1
            index = -1;//������������Ϊ��ʼֵ�������´�ʹ��
            printf("\n%s�ѱ������乬��������ů����������øж�+10��\n\n", name);
            for(i = 0; i < count; i++){
                loves[i] += 10;
            }
            index = -1;
            break;
        case 4://�����������ң��øж�+10
            PlaySound(TEXT("sounds\\һЦ���.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            printf("������Ҫ���ҵ�������");
            scanf("%s", name);
            for(i = 0; i < count; i++){
                if(strcmp(name, names[i]) == 0){
                    printf("\n΢΢һЦͦ��ǣ�%s�ĺøж�+10\n\n", name);
                    loves[i] += 10;
                    break;
                }
            }
            break;
        }// end of switch
        printf("����\t�ȼ�\t�øж�\n");
        printf("-----------------------\n");
        for(i = 0; i < count; i++){
            printf("%s\t%s\t%d\n", names[i], levelNames[level[i]], loves[i]);
        }
        //ÿ�����øжȣ�һ�������������ϵ������øжȵ���60���������ң���Ϸ����
        tempCount = 0;//��ʱ������������źøжȵ���60�ĸ���
        for(i = 0; i < count; i++){
            if(loves[i] < 60)
                tempCount++;
        }
        if(tempCount >= 3){
            printf("���ѵ������������ǣ����ˢ����ȥ�ˣ�\n");
            //ʱ�亯���Ĺ̶��÷�
            time_t timep;
            struct tm * p;
            time(&timep);
            p = gmtime(&timep);
            printf("��Ԫ%d��%d��%d�գ��ʵ��䣡��ִ��%d��\n", 1900+p->tm_year, 1+p->tm_mon, p->tm_mday, currDay);
            exit(0);
        }
    }while(currDay < DAY_COUNT);

    printf("�ʵ۵ǻ�10��������ȷ�ǡ������˳����檳�Ⱥ����������\n");
    printf("û��û����������������š�������������\n");
    printf("����\t�ȼ�\t�øж�\n");
    printf("-----------------------\n");
    for(i = 0; i < count; i++){
        printf("%s\t%s\t%d\n", names[i], levelNames[level[i]], loves[i]);

    }
    return 0;
}
