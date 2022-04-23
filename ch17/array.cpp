#include "std_lib_facilities.h"

void print_array10(ostream& os, int* a)
{
  for(int i = 0; i < 10; ++i)
      os<<a[i]<<' ';
  os<<endl;
}

void print_array(ostream& os, int*a, int n)
{
  for(int i = 0; i < n; ++i)
      os<<a[i]<<' ';
  os<<endl;
}

int main()
try{
  int* array = new int[10];
  for(int i = 0; i < 10; ++i) cout << array[i] << ' ';
  cout << endl;
  delete[] array;

  int* array2 = new int[10]
                {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
  print_array10(cout, array2);
  delete[] array2;

  int* array3 = new int[11]
                {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
  for(int i = 0; i < 11; ++i) cout << array3[i] << ' ';
  cout << endl;
  delete[] array3;

  int* array4 = new int[20]
                {100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
                 110, 111, 112, 113, 114, 115, 116, 117, 118, 119};
  print_array(cout, array4, 20);
  delete[] array4;

}
catch (exception& e){
  cerr << e.what() << endl;
  return 1;
}
catch (...){
  cerr << "Unknown exception" << endl;
  return 2;
}
