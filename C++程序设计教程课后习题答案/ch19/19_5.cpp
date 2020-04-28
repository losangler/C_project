//19_5

#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
#include <string.h>

class AddressBook{
public:
  AddressBook(char* n, char* p, char* h);
  virtual void Display(ostream& out);
protected:
  char name[20];
  char phone[10];
  char handp[15];
};

AddressBook::AddressBook(char* n, char* p, char* h)
{
  strncpy(name, n, 19);  name[19]=0;
  strncpy(phone, p, 9);  phone[9]=0;
  strncpy(handp, h, 14); handp[14]=0;
}

void AddressBook::Display(ostream& out)
{
  out <<setiosflags(ios::left) <<setw(20) <<name
		  <<setw(10) <<phone <<setw(15) <<handp <<endl;
}

ostream& operator<<(ostream& out, AddressBook& a)
{
  a.Display(out);
  return out;
}

void main()
{
  AddressBook a1("Dill Arnson", "8869533", "13902201080");
  AddressBook a2("Welch Shammas", "6695482", "13023399001");
  AddressBook a3("Portel Braumbel", "5937221","13908032991");

  cout <<a1;
  cout <<a2;
  cout <<a3;
}

