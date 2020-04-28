#include <iostream>

using namespace std;

int main()
{
    int num = 1024;
    int& r_num = num;
    cout << &num << '\t' << &r_num << endl;



    /*
    int arrays[] {15, 23, 30, 40, 50, 60};
    int * ptr_start = arrays;       //指向第一个元素
    int * ptr_end   = arrays + 5;   //指向最后一个元素
    int temp;

    while(ptr_start != ptr_end)
    {
        temp = *ptr_start;
        *ptr_start = *ptr_end;
        *ptr_end = temp;
        ptr_start++;
        ptr_end--;
    }

    for(int i = 0; i < 6; i++){
        cout << arrays[i] << endl;
    }
















/*
   int num = 90;
   double d_nums[6] = {3, 4, 5, 6};
   double * dArray = new double[10];

    int * p = new int;
    *p = 90;











/*
    double score1[] {11, 22, 33, 44, 55};
    double score2[] {11, 22, 33, 44, 55};
    double score3[] {11, 22, 33, 44, 55};
    double score4[] {11, 22, 33, 44, 55};
    double score5[] {11, 22, 33, 44, 55};
    double score[] {11, 22, 33, 44, 55};
    double * ptr_score = score;

    cout << *++ptr_score << endl;
    //数组-数组名就是数组的首地址

    cout << sizeof(score) << '\t' << sizeof(ptr_score) << endl;

    cout << *(ptr_score - 9) << endl;








    /*
    double num = 3.14;
    double * ptr_num1 = &num;
    void *   ptr_num2 = &num;
    cout << boolalpha;
    cout << (ptr_num1 == ptr_num2) << endl;

    *ptr_num2 = 112234;


    /*
    double * ptr_double = nullptr;    //野指针
    cout << ptr_double << endl;


    /*
    char ch = 'a';
    char * ptr_ch = &ch;

    cout << (void *)ptr_ch << '\t' << *ptr_ch << endl;

    /*
    double num = 1024.5;
    //声明一个指针，指向num变量
    double* ptr_num = &num;
    cout << "ptr_num的值：" << ptr_num << "\t" << &num << endl;
    cout << "ptr_num指向空间的值是：" << *ptr_num << endl;
    */
    return 0;
}
