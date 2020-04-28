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

//将参数声明为引用的目的是为了提高效率，速度快、使用内存更少
Time Time::Sum(const Time & time) const{
    Time sum;
    sum.minutes = this->minutes + time.minutes;
    sum.hours = hours + time.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum; //不要返回局部变量的引用，因为函数结束时局部变量将被删除，引用将指向不存在的数据
}

//重载加号运算符，方法实现与Sum方法相同
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
    //需要转换成分钟后再计算，将结果再转换回来
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

//前人的经验是：赋值操作符与复合赋值操作符（+=、*=等）应返回左操作数的引用
//一方面可以使操作符可以连续使用；另一方面也可以减掉创建和撤销临时副本的开销。
Time Time::operator*=(int mult){
    long totalMinutes = hours * mult * 60 + minutes * mult;
    this->minutes = totalMinutes % 60;
    this->hours = totalMinutes / 60;
    return *this;
}

void Time::Show() const{
    std::cout << hours << "小时, "<< minutes << "分钟。" << std::endl;
}

void Time::TimeTest(){
    Time planing;
    Time spyTime(2, 40);
    Time sauna(5, 55);
    Time total;

    cout << "计划时间：";
    planing.Show();
    cout << endl;

    cout << "Spy时间：";
    spyTime.Show();
    cout << endl;

    cout << "桑拿时间：";
    sauna.Show();
    cout << endl;

//    total = spyTime.Sum(sauna);
//    cout << "spyTime.Sum(sauna):";

    //total = spyTime + sauna;          //隐式调用 可以连加，相当于嵌套调用函数
    total = spyTime.operator+(sauna);   //显示调用
    cout << "total = spyTime + sauna : ";
    total.Show();
    cout << endl;

    total = total - sauna;
    cout << "total = total - sauna;";
    total.Show();
    cout << endl;

    //total = 1.5 * total;      //不合法
    total *= 5;             //需要重写*=运算符
    //total = total * 1.5;
    cout << "相乘：";
    total.Show();
    cout << endl;

    cout << "****************************************" << endl;
    cout << total * 1.5 << endl;
}

//非成员函数的重载，让用户可以使用： cout << Time的类型;
std::ostream & operator<<(std::ostream & os, const Time & time){
    os << time.hours << "小时，" << time.minutes << "分钟\n";
    return os;
}


Time::~Time()
{
    //dtor
}
