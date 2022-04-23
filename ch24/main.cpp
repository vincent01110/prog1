#include "std_lib_facilities.h"
#include "Matrix.h"

using namespace std;

int main()
try{
  int i;
  double do;
  char ch;
  short s;
  long l;
  float f;
  int* is;
  double* ds;
  cout << "int: " << sizeof(i) << endl
       << "double: " << sizeof(do) << endl
       << "char: " << sizeof(ch) << endl
       << "short: " << sizeof(s) << endl
       << "long: " << sizeof(l) << endl
       << "float: " << sizeof(f) << endl
       << "int*: " << sizeof(is) << endl
       << "double*: " << sizeof(ds) << endl;

  Matrix<int,1> a(10);
  Matrix<int,1> b(100);
  Matrix<double,1> c(10);
  Matrix<int,2> d(10,10);
  Matrix<int,3> e(10,10,10);
  cout << "\na: " << sizeof(a) << endl
       << "b: " << sizeof(b) << endl
       << "c: " << sizeof(c) << endl
       << "d: " << sizeof(d) << endl
       << "e: " << sizeof(e) << endl;
}
catch(exception& e){
  cerr << e.what() << endl;
  return 1;
}
catch(...){
  cerr << "Unknown exception" << endl;
  return 2;
}
