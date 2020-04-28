#include <iostream>
#include "LandOwnerV1.hpp"  //如果要使用类，那么必须包含类的头文件
#include "LandOwnerV2.h"
#include "LandOwnerV3.h"
#include "LandOwnerV4.h"
#include "Student.h"

#include "LandOwner.h"


using namespace std;


int main()
{
    //数据类型 变量名
    //int num;
    //num = 0;

    //LandOwnerV1 landOwner1; //声明了一个LandOwner1类型的变量-landOwner1
    //调用对象的成员方法
    //landOwner1.cards[0] = 9;    //不能直接使用对象的私有成员
    //landOwner1.TouchCard(100);

    //LandOwnerV2 landOwner2;
    //landOwner2.name = "于谦";
    //landOwner2.TouchCard(20);


    //LandOwnerV3 landOwner3;
    //landOwner3.name = "巴依老爷";
    //landOwner3.SetName("巴依老爷");
    //注意：模拟为地主修改积分
    //landOwner3.score = -100;
    //landOwner3.SetScore(-100);
    //landOwner3.ShowScore();
    //cout << landOwner3.GetName() << endl;


    //LandOwnerV4 landOwner4;
/*
    int num;
    Student stu1;   //在栈内存中直接分配空间
    Student stu2("马化腾", "普通家庭");
    //Student stu3(45);
    //Student stu4 = 50;
    stu2.ShowInfo();

    Student* stu5 = new Student("杰克马", "悔创阿里");
    stu5->ShowInfo();

    //当对象使用完毕时，记得delete，释放内存！
    delete stu5;
*/
/*
    LandOwner lan1 = {"专业都抵制"};
    LandOwner lan2("专业斗地主");

    LandOwner* ptr_landOwner1 = new LandOwner();
    LandOwner* ptr_landOwner2 = new LandOwner("专业斗地主");
    LandOwner* ptr_landOwner3 = new LandOwner("周扒皮");

    ptr_landOwner1->ShowInfo();
    ptr_landOwner2->ShowInfo();
    ptr_landOwner3->ShowInfo();

    ptr_landOwner2->TouchCard(20);

    delete ptr_landOwner1;
    delete ptr_landOwner2;
    delete ptr_landOwner3;
*/


    Student* ptrStu1 = new Student("迪热巴", "微胖女孩");
    ptrStu1->AddScore(78.9f);
    ptrStu1->AddScore(88.9f);
    ptrStu1->AddScore(98.9f);
    ptrStu1->AddScore(178.9f);
    ptrStu1->AddScore(278.9f);
    ptrStu1->ShowInfo();

    Student stu2 = {"刘强东", "不爱美人"};
    stu2.AddScore(85);
    stu2.AddScore(75);
    stu2.AddScore(65);
    stu2.AddScore(55);
    stu2.AddScore(45);

    Student& scholar1 = stu2.GetSuperScholar(*ptrStu1);  //返回迪热巴的引用
    Student& scholar2 = ptrStu1->GetSuperScholar(stu2);  //返回迪热巴的引用
    cout << "学霸是：" << scholar1.GetName()  << endl;
    cout << "学霸是：" << scholar2.GetName()  << endl;

    delete ptrStu1;


    //scholar1在栈内存中定义的，所以main结束后，会自动释放scholar1
    //scholar2在栈内存中定义的，所以main结束后，会自动释放scholar2





    return 0;
}
