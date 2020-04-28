#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct _account
{
    char *bankName;
    char *userName;
    double limit;       //�˻��Ķ��
    double billAmount;  //�����˵����
}Account;
//�õ�ĳ���˻�����Ӧ������
//���ݽṹ����ʱ���Ǹ��������ṹ������ֵ�������� - Ч�ʵ�
//double GetRepayment(Account account);

//�������ݵ��ǽṹָ�� - ����Ƭ
//����������const�󣬻���ָ����Ӱ�ȫ
double GetRepayment(const Account *account);


#endif // ACCOUNT_H_INCLUDED
