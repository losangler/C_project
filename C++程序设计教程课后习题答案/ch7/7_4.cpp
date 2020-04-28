//7_4

void Swap(int& a, int& b){ int temp=a; a=b; b=temp; }

void Bsort(int a[], int n)
{
  bool dontLoopAgain=false;
  while(dontLoopAgain=!dontLoopAgain)
    for(int i=0,pass=--n; i<n; i++)
      if(a[i]>a[i+1]){
        dontLoopAgain=false;
        Swap(a[i],a[i+1]);
      }
}


