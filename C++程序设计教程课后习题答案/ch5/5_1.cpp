//5_1

#include <iostream.h>
#include <iomanip.h>
#include <math.h>

bool isprime(long n);

void main()
{
  //input
  long a,b,l=0;
  cout <<"please input two numbers:\n";
  cin >>a >>b;
  cout <<"primes from " <<a <<" to " <<b <<" is \n";

  //process
  if(a%2==0) a++;

  for(long m=a; m<=b; m+=2)
    if(isprime(m)){
      //output
      if(l++%10==0)
        cout <<endl;
      cout <<setw(5) <<m;
    }
}

bool isprime(long n)
{
  int sqrtm=sqrt(n);
  for(int i=2; i<=sqrtm; i++)  //ÅÐÃ÷ËØÊý
    if(n%i==0)
      return false;
  return true;
}

