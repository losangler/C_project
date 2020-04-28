#include <time.h>
#include <iostream.h>
#include <string.h>
#include <stdlib.h>

class Time{
public:
  Time(char* s=NULL);
	void operator+(Time& ti);
	void operator-(Time& ti);
	void Display();
protected:
	int hour;
	int minute;
	int second;
};

Time::Time(char* s)
{
  char str[9]={0};
  char t[3]={0};
  if(s)
		strncpy(str, s, 8);
  else
    _strtime(str);

	hour = atoi( strncpy(t, str, 2) ) % 24;	
	minute = atoi( strncpy(t, &str[3], 2) ) % 60;	
	second = atoi( strncpy(t, &str[6], 2) ) % 60;  
}

void Time::operator+(Time& ti)
{
  int st;
  st = second + ti.second;
	second = (st) % 60;
	st = st/60 + minute + ti.minute;
	minute = (st) % 60;
	st = st/60 + hour + ti.hour;
	hour = (st) % 24;
}

void Time::operator-(Time& ti)
{
  int st;
	st = 60 + second - ti.second;
	second = st % 60;
	st = 60 + st/60 + minute - ti.minute -1;
	minute = st % 60;
	st = 24 + st/60 + hour - ti.hour -1;
	hour = (st) % 24;
}	

void Time::Display()
{
  char result[9] = "XX:XX:XX";
  result[0]='0'+hour%10;
	result[1]='0'+hour/10;
	result[3]='0'+minute%10;
  result[4]='0'+minute/10;
	result[6]='0'+second%10;
	result[7]='0'+second/10;
	cout <<result <<endl;
}

void main()
{
  Time a;
	Time b("02:15:30");
  a + b;
	a.Display();
}



		
    

