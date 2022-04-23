#include "std_lib_facilities.h"

using namespace std;


int main()
try{

  double* a = new double(0.0);
  cout << *a << endl;

  int size = 0;
  cin >> size;

  double* b = new double[size];
  for(int i = 0; i < size; ++i)
    b[i] = i;
  cout << b[5] << endl;

  delete a;
  delete[] b;

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
