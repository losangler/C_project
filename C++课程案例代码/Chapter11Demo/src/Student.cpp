#include "Student.h"

Student::Student()
{
    cout << "Ĭ�Ϲ���" << endl;
}
//Student::Student(string name)
//{
 //   SetName(name);
    //cout << "���ô��ι��죺Student(string name)" << endl;
//}
Student::Student(int age)
{
    Setage(age);
    cout << "���ô��ι��죺Student(int age)" << endl;
    InitScores();
}
Student::Student(string name, string desc) : m_Name(name), m_desc(desc)//��ʼ�������б�
{
    //m_Name = name;  //�ȼ�д���� SetName(name);
    //m_desc = desc;
    cout << "���ô��ι��죺Student(string name, string desc)" << endl;
    InitScores();
}

void Student::InitScores()
{
    this->scores = new float[1];
    this->scoreCount = 1;
}

void Student::AddScore(float score)
{
    this->scores[this->scoreCount - 1] = score;
    //1������һ�������飬����scoreCount+1���ռ�
    //2������ԭ�����е����ݵ���������
    //3��scoreCount++
    //4��scoresָ��������

    float* newScores = new float[scoreCount + 1];
    float* oldScores = scores;
    memcpy(newScores, scores, sizeof(float) * scoreCount);
    scoreCount++;
    scores = newScores;
    delete oldScores;
}

void Student::ShowInfo()
{
    cout << m_desc << m_Name << endl;
    for(int i = 0; i < scoreCount - 1; i++){
        cout << this->scores[i] << "\t";
    }
    cout << endl;
}
float Student::GetTotal()
{
    float sum = 0;
    for(int i = 0; i < scoreCount - 1; i++){
        sum += scores[i];
    }
    return sum;
}
/**
 * ����ѧ�Զ���
 * @param otherStu Ҫ�Աȵ�����һ��ѧ������
 * @return �����ֱܷȽϴ���Ǹ�ѧ������
 */
Student& Student::GetSuperScholar(Student& otherStu) //const
{
    //otherStu.SetName("test");
    //�ֱ��������ѧ�����ܷ�
    if(this->GetTotal() > otherStu.GetTotal()){
        return *this;//���ص�ǰ���������
    }else{
        return otherStu;
    }
}

/*void MyShow(const Student* thiz){//C��д����this��C++�Ǻ�����������һ��������
    //thiz->AddScore()
}*/

Student::~Student()
{
    cout << m_Name << "���ͷ�" << endl;
    delete this->scores;

}
