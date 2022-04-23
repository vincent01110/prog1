#include "std_lib_facilities.h"

using namespace std;

int length(char* str) //(char str[])
{
  int n = 0;
  while(str[n]) ++n;
  return n;
}

int main()
try{

  int var = 17;
  int* iptr = &var;

  int x = 42;
  int* pi = &x;

  double e = 2.71828;
  double* dptr = &e;

  cout << "iptr==" << iptr << ' ' << "val of iptr==" << *iptr << endl;
  cout << "pi==" << pi << ' ' << "val of pi==" << *pi << endl;
  cout << "dptr==" << dptr << ' ' << "val of dptr==" << *dptr << endl;

  cout << "Size of char==" << sizeof(char) << " bytes.\n";
  cout << "Size of double==" << sizeof(double) << " bytes.\n";
  cout << "Size of double*==" << sizeof(double*) << " bytes.\n";
  cout << "Size of char*==" << sizeof(char*) << " bytes.\n";

  /*double lad[1000];

  lad[7] = 100;
  cout << lad[7] << endl;
  for(int i = 0; i <= 100; ++i)
    lad[i] = i;

  for(int i = 0; i <= 100; ++i)
    cout << lad[i] << ' ';
  cout << endl;

  double* p = &lad[10];
  cout << *p << endl;
  cout << p[2] << endl;
  cout << p[-3] << endl;
  cout << p[-300] << endl;*/

  /*char ac[] = "Howdy\0";
  cout << "len==" << length(ac) << endl;*/


  return 0;
}
catch(exception& e){
  cerr << e.what() << endl;
  return 1;
}
catch(...){
  cerr << "Unknown exception" << endl;
  return 2;
}
