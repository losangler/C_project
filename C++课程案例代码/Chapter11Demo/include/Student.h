/**
 *
 * @author �Ͼ�ѧ�á���ͷ
 * @version 1.0
 * @copyright �Ͼ�ѧ��
 * @remarks TODO
 *
 */#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student
{
    public:
        //���캯�������ع�������ͨ����������ͬ
        Student();
        Student(int);   //������캯���У�ֻ��һ���Ǵ�Ψһ�Ĳ���:Student stu4 = 50;
        //Student(string);
        Student(string, string);  //���ι���
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

        void InitScores();      //��ʼ��ѧ���ɼ����飬Ĭ�Ϸ���1��Ԫ�ؿռ�
        void AddScore(float);   //��scores���������һ������

        //��д������Ҫ�󷵻�ѧ�Զ���
        Student& GetSuperScholar(Student&); //const;
        //�����Ľ�β����Ϊconst�������ڲ��������޸Ķ��������ñ������const�����ͻᱨ��

        float GetTotal();

    protected:

    private:
        string m_Name;
        string m_desc;
        int m_age;
        int scoreCount; //ѧ���ɼ��ĸ���
        float* scores;  //ѧ���ķ�������
};

#endif // STUDENT_H
