/**
 *
 * @author 老九学堂·窖头
 * @version 1.0
 * @copyright 老九学堂
 * @remarks TODO
 *
 */#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student
{
    public:
        //构造函数的重载规则与普通函数重载相同
        Student();
        Student(int);   //如果构造函数中，只有一个是带唯一的参数:Student stu4 = 50;
        //Student(string);
        Student(string, string);  //带参构造
        ~Student();

        void ShowInfo();

        string GetName() { return m_Name; }
        void SetName(string val) { m_Name = val; }
        string Getdesc() { return m_desc; }
        void Setdesc(string val) { m_desc = val; }
        int Getage() { return m_age; }
        void Setage(int val) {
            if(val < 0){
                m_age = 18;
            }else{
                m_age = val;
            }
        }

        void InitScores();      //初始化学生成绩数组，默认分配1个元素空间
        void AddScore(float);   //向scores数组中添加一个分数

        //书写函数，要求返回学霸对象
        Student& GetSuperScholar(Student&); //const;
        //函数的结尾声明为const：函数内部不允许修改对象本身，调用本对象非const方法就会报错

        float GetTotal();

    protected:

    private:
        string m_Name;
        string m_desc;
        int m_age;
        int scoreCount; //学生成绩的个数
        float* scores;  //学生的分数数组
};

#endif // STUDENT_H
