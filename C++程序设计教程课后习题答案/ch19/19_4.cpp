//19_4

#include <iostream.h>
#include <iomanip.h>

void main()
{
  cout <<setiosflags(ios::uppercase);
  for(char ch='A'; ch<='Z'; ch++){
    cout <<ch <<" " <<hex <<(int)ch <<", ";
	  if(ch=='I'||ch=='R') cout <<endl;
  }
	cout <<endl;
}
