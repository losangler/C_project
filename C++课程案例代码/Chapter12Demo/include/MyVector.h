#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <cstring>

using namespace std;

//自定义的容器类
//使用了模板技术：模板技术一般用来做算法，比如重载100次某个类型的算法
//注意：如果使用模板技术，那么类的声明和方法实现都要放在同一个头文件中！！！
//template<class T>
template<typename T>
class MyVector
{
    public:
        MyVector();
        MyVector(int len, T element);       //填充len长度的元素element
        MyVector(const MyVector<T> & vec);  //复制构造
        virtual ~MyVector();

        template<typename T2>
        friend ostream & operator<<(ostream & out, const MyVector<T2> & vec);

        MyVector<T> & operator=(const MyVector<T> & vec);
        T & operator[](int index);          //获取元素（可以写入）
        void push_back(T element);          //将元素element添加到内部数组中

        //请大家自行完成下面几个方法
        T pop_back();                       //返回并删除最后一个元素
        void insert(int pos, T element);    //在pos位置处，插入元素element
        void clear();                       //清空所有的元素

    protected:

    private:
        T * m_elements;     //用来存放元素的数组
        int m_length;       //所存放元素的实际个数
        int m_capacity;     //当前元素数组的大小
};

template<typename T>
MyVector<T>::MyVector() : m_capacity(16), m_length(0)
{
    this->m_elements = new T[m_capacity];
}

template<typename T>
MyVector<T>::MyVector(int len, T element):m_capacity(16){
    m_capacity = len + m_capacity;
    m_length = len;
    m_elements = new T[m_capacity];

    for(int i = 0; i < m_length; i++){
        //1.使用循环复制
        //m_elements[i] = element;        //注意：这里每次都会调用重载的赋值运算符
        //2.使用memcpy
        memcpy(&m_elements[i], &element, sizeof(T));
    }

}

template<typename T>
MyVector<T> & MyVector<T>::operator=(const MyVector<T> & vec){
    if(this == &vec) return *this;
    if(NULL != m_elements){
        delete[] m_elements;
        m_elements = NULL;
    }
    m_capacity = vec.m_length + vec.m_capacity;
    m_length = vec.m_length;
    m_elements = new T[vec.m_capacity];
    memcpy(m_elements, vec.m_elements, m_length * sizeof(T));
    return *this;
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T> & vec){
    m_capacity = vec.m_capacity;
    m_length = vec.m_length;
    m_elements = new T[m_capacity];
    memcpy(m_elements, vec.m_elements, m_length * sizeof(T));
}

template<typename T>
T & MyVector<T>::operator[](int index){
    return m_elements[index];
}

template<typename T>
void MyVector<T>::push_back(T element){
    //将元素element添加到内部数组的最后一个位置
    if(NULL == m_elements){
        m_capacity = 16;
        m_length = 0;
        m_elements = new T[m_capacity];
    }
    //判断当前的数组容量是否已满
    if(m_length == m_capacity){
        //如果满了，就扩容：当前容量*2+1
        T * newElements = new T[m_capacity * 2 + 1];
        m_capacity = m_capacity * 2 + 1;
        //把原来的元素拷贝到新空间中
        memcpy(newElements, m_elements, m_length * sizeof(T));
        delete[] m_elements;        //释放空间
        m_elements = newElements;   //将元素数组的指向修改为新空间
    }
    //m_elements[m_length++] = element;
    memcpy(&m_elements[m_length++], &element, sizeof(T));
}

template<typename T2>
ostream & operator<<(ostream & out, const MyVector<T2> & vec){
    for(int i = 0; i < vec.m_length; i++){
        out << vec.m_elements[i] << ", ";
    }
    out << endl;
    return out;
}

template<typename T>
T MyVector<T>::pop_back(){
    if(m_length > 1){
        m_length--;
        return m_elements[m_length];
    }
    return m_elements[0];
}

template<typename T>
void MyVector<T>::insert(int pos, T element){
    if(pos < 0 || pos > m_length) return;
    if(m_length == m_capacity){
        T * newElements = new T[m_capacity * 2 + 1];
        memcpy(newElements, m_elements, m_length * sizeof(T));
        m_capacity = m_capacity * 2 + 1;
        delete[] m_elements;
        m_elements = newElements;
    }
    for(int i = m_length; i > pos; i--){
        m_elements[i] = m_elements[i - 1];
    }
    m_elements[pos] = element;
    m_length++;
}

template<typename T>
void MyVector<T>::clear(){
    m_length = 0;
    m_capacity = 16;
    delete[] m_elements;
    m_elements = new T[m_capacity];
}

template<typename T>
MyVector<T>::~MyVector(){
    delete[] m_elements;
}


#endif // MYVECTOR_H
