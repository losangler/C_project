#include <iostream>
#include "LandOwnerV1.hpp"  //���Ҫʹ���࣬��ô����������ͷ�ļ�
#include "LandOwnerV2.h"
#include "LandOwnerV3.h"
#include "LandOwnerV4.h"
#include "Student.h"

#include "LandOwner.h"


using namespace std;


int main()
{
    //�������� ������
    //int num;
    //num = 0;

    //LandOwnerV1 landOwner1; //������һ��LandOwner1���͵ı���-landOwner1
    //���ö���ĳ�Ա����
    //landOwner1.cards[0] = 9;    //����ֱ��ʹ�ö����˽�г�Ա
    //landOwner1.TouchCard(100);

    //LandOwnerV2 landOwner2;
    //landOwner2.name = "��ǫ";
    //landOwner2.TouchCard(20);


    //LandOwnerV3 landOwner3;
    //landOwner3.name = "������ү";
    //landOwner3.SetName("������ү");
    //ע�⣺ģ��Ϊ�����޸Ļ���
    //landOwner3.score = -100;
    //landOwner3.SetScore(-100);
    //landOwner3.ShowScore();
    //cout << landOwner3.GetName() << endl;


    //LandOwnerV4 landOwner4;
/*
    int num;
    Student stu1;   //��ջ�ڴ���ֱ�ӷ���ռ�
    Student stu2("����", "��ͨ��ͥ");
    //Student stu3(45);
    //Student stu4 = 50;
    stu2.ShowInfo();

    Student* stu5 = new Student("�ܿ���", "�ڴ�����");
    stu5->ShowInfo();

    //������ʹ�����ʱ���ǵ�delete���ͷ��ڴ棡
    delete stu5;
*/
/*
    LandOwner lan1 = {"רҵ������"};
    LandOwner lan2("רҵ������");

    LandOwner* ptr_landOwner1 = new LandOwner();
    LandOwner* ptr_landOwner2 = new LandOwner("רҵ������");
    LandOwner* ptr_landOwner3 = new LandOwner("�ܰ�Ƥ");

    ptr_landOwner1->ShowInfo();
    ptr_landOwner2->ShowInfo();
    ptr_landOwner3->ShowInfo();

    ptr_landOwner2->TouchCard(20);

    delete ptr_landOwner1;
    delete ptr_landOwner2;
    delete ptr_landOwner3;
*/


    Student* ptrStu1 = new Student("���Ȱ�", "΢��Ů��");
    ptrStu1->AddScore(78.9f);
    ptrStu1->AddScore(88.9f);
    ptrStu1->AddScore(98.9f);
    ptrStu1->AddScore(178.9f);
    ptrStu1->AddScore(278.9f);
    ptrStu1->ShowInfo();

    Student stu2 = {"��ǿ��", "��������"};
    stu2.AddScore(85);
    stu2.AddScore(75);
    stu2.AddScore(65);
    stu2.AddScore(55);
    stu2.AddScore(45);

    Student& scholar1 = stu2.GetSuperScholar(*ptrStu1);  //���ص��Ȱ͵�����
    Student& scholar2 = ptrStu1->GetSuperScholar(stu2);  //���ص��Ȱ͵�����
    cout << "ѧ���ǣ�" << scholar1.GetName()  << endl;
    cout << "ѧ���ǣ�" << scholar2.GetName()  << endl;

    delete ptrStu1;


    //scholar1��ջ�ڴ��ж���ģ�����main�����󣬻��Զ��ͷ�scholar1
    //scholar2��ջ�ڴ��ж���ģ�����main�����󣬻��Զ��ͷ�scholar2





    return 0;
}
