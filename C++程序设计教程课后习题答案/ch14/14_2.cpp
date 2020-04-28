//14_2

#include <iostream.h>
#include <stdlib.h>

class Vector{
public:
  Vector(int s=100);
  Vector(const Vector& v);
  int& Elem(int ndx);
  void Display();
  void Set();
  ~Vector();
protected:
  int size;
  int* buffer;
};

Vector::Vector(int s)
{
  buffer=new int[size=s];
  for(int i=0; i<size; i++)
    buffer[i]=i*i;
}

Vector::Vector(const Vector& v):size(v.size)
{
  buffer = new int[size];
  for(int i=0; i<size; i++)
    buffer[i] = v.buffer[i];
}

int& Vector::Elem(int ndx)
{
  if(ndx<0||ndx>=size){
    cout <<"error in index" <<endl;
    exit(1);
  }
  return buffer[ndx];
}

void Vector::Display()
{
  for(int j=0; j<size; j++)
    cout <<buffer[j] <<endl;
}

void Vector::Set()
{
  for(int j=0; j<size; j++)
    buffer[j]=j+1;
}

Vector::~Vector(){ delete[]buffer; }

void main()
{
  Vector a(10);
  Vector b(a);
  a.Set();
  b.Display();
}
