//19_3

#include <iostream.h>
#include <strstrea.h>

void main()
{
  int n;
  char string[]="1 2 3 4 5 6 7 8 9";
  istrstream s(string);
  while(!s.eof()){
    s >>n;
	  cout <<n<<" ";
  }
	cout <<endl;
}



