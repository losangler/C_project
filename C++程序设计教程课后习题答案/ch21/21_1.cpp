//ch21_1.cpp

#include <iostream.h>
#include <string.h>

class String{
public:
  String(char*, int);
	int Length(){ return len; }
  class Range{        //异常类1
  public:
    Range(int j):index(j){}
    int index;
  };
  class Size{};       //异常类2
  class Pastm{};      //异常类3

  char& operator[](int k)
  {
	  if(0<=k && k<len){
      if(p[k]=='m' && k!=len-1 && p[k+1]<='z' && p[k+1]>='a')
				throw Pastm();
			if(k && p[k-1]=='m' && p[k]>='a' && p[k]<='z')
				throw Pastm();
			return p[k];
		}
    throw Range(k);
  }
private:
  char* p;
  int len;
  static int max;
};

int String::max = 20;

String::String(char* str, int si)
{
  if(si<0 || max<si)
    throw Size();

  p=new char[si];
  strncpy(p, str, si);
  len=si;
}

void g(String& str)
{
  int num=str.Length();
  for(int n=0; n<num; n++)
    cout <<str[n];
  cout <<endl;
}

void f()
{
  //代码区1
  try{
    //代码区2
    String s("abcdefghijklmnop", 16);
    g(s);
  }
  catch(String::Range r){
    cerr <<"\nerror: ->out of range: " <<r.index <<endl;
    //代码区3
  }
  catch(String::Size){
    cerr <<"\nerror: size illegal!\n";
  }
	catch(String::Pastm){
    cerr <<"\nerror: lower cast found following 'm'.\n";
	}
  //代码区4
  cout <<"\nThe program will be continued here.\n\n";
}

void main()
{
  //代码区5
  f();
  cout <<"\nf() is completed here.\n";
}
