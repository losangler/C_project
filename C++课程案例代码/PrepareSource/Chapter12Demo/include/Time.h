/************************************************************************
 *  Project:
 *  Function:
 *  Description:
 *  Author: 窖头
 ************************************************************************
 *  Copyright 2018 by 老九学堂
 ************************************************************************/
#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;
class Time
{
    public:
        Time();
        Time(int hours, int minutes = 0);
        void AddMinutes(int minutes);
        void AddHours(int hours);
        void Reset(int hours = 0, int minutes = 0);
        Time Sum(const Time & time) const;
        //重载加号运算符，方法实现与Sum方法相同
        Time operator+(const Time & time) const;

        //新增-和*的重载：
        Time operator-(const Time & time) const;

        Time operator*(double n)const;

        Time operator*=(int n);

        friend Time operator*(double m, Time & t){
            return t * m;   //inline 内联函数
        }

        friend ostream & operator<<(ostream & os, const Time & time);

        void Show() const;
        virtual ~Time();
        void TimeTest();
    protected:

    private:
        int hours;
        int minutes;
};

#endif // TIME_H
