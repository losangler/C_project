//8_5

int strcmp(const char* str1, const char* str2)
{
  char* p1=(char*)str1;
  char* p2=(char*)str2;
  while(*p1 && *p1==*p2){
    p1++; p2++;
  }
  return *p1 - *p2;
}