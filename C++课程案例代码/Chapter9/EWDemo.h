#ifndef EWDEMO_H_INCLUDED
#define EWDEMO_H_INCLUDED
//��ά����Ĵ���

#include <iostream>

using namespace std;

void show(const double (*)[5], int);

void show(const double (*arrs)[5], int len)
{
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << arrs[i][j] << "\t";
        }
        cout << endl;
    }
}

#endif // EWDEMO_H_INCLUDED
