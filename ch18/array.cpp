#include "std_lib_facilities.h"

int* ga = new int[10]{1,2,4,8,16,32,64,128,256,512};

void print_array(ostream& os, int* a, int n)
{
  for(int i = 0; i < n; ++i)
      os<<a[i]<<' ';
  os<<endl;
}
void f(int* a, int n)
{
  int* la = new int[10];
  la = ga;
  print_array(cout, la, 10);
  int* p = new int[n];
  p = a;
  print_array(cout, p, n);
  delete[] p;
}


int main()
try{
  f(ga, 10);

  int* aa = new int[10];
  int x;
  aa[0] = 1;
  for(int i = 2; i < 11; ++i)
  {
    x=1;
    for(int j = i-1; j > 0; --j)
    {
      x *= j;
    }
    x *= i;
    aa[i-1] = x;
  }

  f(aa, 10);


}
catch (exception& e){
  cerr << e.what() << endl;
  return 1;
}
catch (...){
  cerr << "Unknown exception" << endl;
  return 2;
}
