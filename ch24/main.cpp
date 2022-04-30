#include "Matrix.h"
#include <iostream>

using namespace std;

int main()
{
  int i;
  double dob;
  char ch;
  short s;
  long l;
  float f;
  int* is;
  double* ds;
  cout << "int: " << sizeof(i) << endl
       << "double: " << sizeof(dob) << endl
       << "char: " << sizeof(ch) << endl
       << "short: " << sizeof(s) << endl
       << "long: " << sizeof(l) << endl
       << "float: " << sizeof(f) << endl
       << "int*: " << sizeof(is) << endl
       << "double*: " << sizeof(ds) << endl;

  Numeric_lib::Matrix<int,1> a(10);
  Numeric_lib::Matrix<int,1> b(100);
  Numeric_lib::Matrix<double,1> c(10);
  Numeric_lib::Matrix<int,2> d(10,10);
  Numeric_lib::Matrix<int,3> e(10,10,10);
  cout << "\nsizeof:a== " << sizeof(a) << endl
       << "sizeof:b== " << sizeof(b) << endl
       << "sizeof:c== " << sizeof(c) << endl
       << "sizeof:d== " << sizeof(d) << endl
       << "sizeof:e== " << sizeof(e) << endl;

  cout << "\nsize:a== " << a.size() << endl
       << "size:b== " << b.size() << endl
       << "size:c== " << c.size() << endl
       << "size:d== " << d.size() << endl
       << "size:e== " << e.size() << endl;
}
