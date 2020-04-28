#include "Time.h"

Time::Time()
{
    this->hours = this->minutes = 0;
}

Time::Time(int hours, int minutes){
    this->hours = hours;
    this->minutes = minutes;
}

void Time::AddMinutes(int minutes){
    this->minutes += minutes;
    this->hours += minutes / 60;
    this->minutes %= 60;
}

void Time::AddHours(int housr){
    this->hours += hours;
}

void Time::Reset(int hours, int minutes){
    this->hours = hours;
    this->minutes = minutes;
}

//����������Ϊ���õ�Ŀ����Ϊ�����Ч�ʣ��ٶȿ졢ʹ���ڴ����
Time Time::Sum(const Time & time) const{
    Time sum;
    sum.minutes = this->minutes + time.minutes;
    sum.hours = hours + time.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum; //��Ҫ���ؾֲ����������ã���Ϊ��������ʱ�ֲ���������ɾ�������ý�ָ�򲻴��ڵ�����
}

//���ؼӺ������������ʵ����Sum������ͬ
Time Time::operator+(const Time & time) const{
//    Time sum;
//    sum.minutes = this->minutes + time.minutes;
//    sum.hours = hours + time.hours + sum.minutes / 60;
//    sum.minutes %= 60;
//    return sum;
    return this->Sum(time);

}

Time Time::operator-(const Time & time) const{
    Time diff;
    int total1, total2;
    total1 = time.minutes + 60 * time.hours;
    total2 = minutes + 60 * hours;
    //��Ҫת���ɷ��Ӻ��ټ��㣬�������ת������
    diff.minutes = (total2 - total1) % 60;
    diff.hours = (total2 - total1) / 60;
    return diff;
}

Time Time::operator*(double mult)const{
    Time result;
    long totalMinutes = hours * mult * 60 + minutes * mult;
    result.hours = totalMinutes / 60;
    result.minutes = totalMinutes % 60;
    return result;
}

//ǰ�˵ľ����ǣ���ֵ�������븴�ϸ�ֵ��������+=��*=�ȣ�Ӧ�����������������
//һ�������ʹ��������������ʹ�ã���һ����Ҳ���Լ��������ͳ�����ʱ�����Ŀ�����
Time Time::operator*=(int mult){
    long totalMinutes = hours * mult * 60 + minutes * mult;
    this->minutes = totalMinutes % 60;
    this->hours = totalMinutes / 60;
    return *this;
}

void Time::Show() const{
    std::cout << hours << "Сʱ, "<< minutes << "���ӡ�" << std::endl;
}

void Time::TimeTest(){
    Time planing;
    Time spyTime(2, 40);
    Time sauna(5, 55);
    Time total;

    cout << "�ƻ�ʱ�䣺";
    planing.Show();
    cout << endl;

    cout << "Spyʱ�䣺";
    spyTime.Show();
    cout << endl;

    cout << "ɣ��ʱ�䣺";
    sauna.Show();
    cout << endl;

//    total = spyTime.Sum(sauna);
//    cout << "spyTime.Sum(sauna):";

    //total = spyTime + sauna;          //��ʽ���� �������ӣ��൱��Ƕ�׵��ú���
    total = spyTime.operator+(sauna);   //��ʾ����
    cout << "total = spyTime + sauna : ";
    total.Show();
    cout << endl;

    total = total - sauna;
    cout << "total = total - sauna;";
    total.Show();
    cout << endl;

    //total = 1.5 * total;      //���Ϸ�
    total *= 5;             //��Ҫ��д*=�����
    //total = total * 1.5;
    cout << "��ˣ�";
    total.Show();
    cout << endl;

    cout << "****************************************" << endl;
    cout << total * 1.5 << endl;
}

//�ǳ�Ա���������أ����û�����ʹ�ã� cout << Time������;
std::ostream & operator<<(std::ostream & os, const Time & time){
    os << time.hours << "Сʱ��" << time.minutes << "����\n";
    return os;
}


Time::~Time()
{
    //dtor
}
