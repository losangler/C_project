//8_4

//the result of 3 and 2 is not 8
//(t)116+4,(h)104+9,(e)101+6,( )32+2,(r)114+8,(e)101+7,(s)115+3,
//(u)117+4,(l)108+9,(t)116+6,( )32+2,(o)111+8,(f)102+7,( )32+3,
//(3)51+4,( )32+9,(a)97+6,(n)110+2,(d)100+8,( )32+7,(2)50+3,
//( )32+4,(i)105+9,(s)115+6,( )32+2,(n)110+8,(o)111+7,(t)116+3,
//( )32+4,(8)56+9
//得到密文为:
//xqk″zlvyuzqn′6$jtf(9#m!&pw #

#include <iostream.h>

char* jiami(const char* str);
char* jiemi(const char* str);
const char key[]={4,9,6,2,8,7,3};
const keylen=sizeof(key);

void main()
{
  char* s="the result of 3 and 2 is not 8";
  cout <<"\n原文为: \n" <<s <<endl;

  char* result1=jiami(s);

  cout <<"\n密文为: \n" <<result1 <<endl;

  char* result2=jiemi(result1);

  cout <<"\n解密之后为: \n" <<result2 <<endl;

  delete[] result1;
  delete[] result2;
}

char* jiami(const char* str)
{
  int len=strlen(str);
  char* result = new char[len+1];
  for(int i=0,j=0; i<len; i++,j=(j+1)%keylen){
    result[i] = str[i]+key[j];
    if(result[i]>122)
      result[i]-=90;
  }
  return result;
}

char* jiemi(const char* str)
{
  int len=strlen(str);
  char* result = new char[len+1];
  for(int i=0,j=0; i<len; i++,j=(j+1)%keylen){
    result[i] = str[i]-key[j];
    if(result[i]<32)
      result[i]+=90;
  }
  return result;
}






