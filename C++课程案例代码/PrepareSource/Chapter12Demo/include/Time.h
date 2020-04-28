/************************************************************************
 *  Project:
 *  Function:
 *  Description:
 *  Author: ��ͷ
 ************************************************************************
 *  Copyright 2018 by �Ͼ�ѧ��
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
        //���ؼӺ������������ʵ����Sum������ͬ
        Time operator+(const Time & time) const;

        //����-��*�����أ�
        Time operator-(const Time & time) const;

        Time operator*(double n)const;

        Time operator*=(int n);

        friend Time operator*(double m, Time & t){
            return t * m;   //inline ��������
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
