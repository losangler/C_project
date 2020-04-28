//14_1

#include <iostream.h>

class Samp{
public:
  void Setij(int a, int b){i=a,j=b;}
  ~Samp(){ cout <<"Destroying.." <<i <<endl; }
  int GetMulti(){ return i*j; }
protected:
  int i;
  int j;
};

void main()
{
  Samp* p = new Samp[10];
  if(!p){
    cout <<"Allocation error\n";
    return;
  }
  for(int j=0; j<10; j++)
    p[j].Setij(j,j);

  for(int k=0; k<10; k++)
    cout <<"Multi[" <<k <<"] is:"
         <<p[k].GetMulti() <<endl;

  delete[]p;
}
