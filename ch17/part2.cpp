#include "std_lib_facilities.h"

void print_array(ostream& os, int* a, int n)
{
  for(int i = 0; i < n; ++i)
      os<<a[i]<<' ';
  os<<endl;
}

int main()
try{
  int n = 7;
  int* p1 = &n;
  cout << "n==" << n << endl;
  cout << "p1==" << p1 << " val==" << *p1 << endl;

  int* arr = new int[7]{1,2,4,8,16,32,64};
  int* p2 = arr;
  cout << "arr==" << arr << endl;
  cout << " p2=="<< p2 << endl;

  int* p3 = p2;
  p2 = p1;
  p2 = p3;
  cout << "p1==" << p1 << endl;
  cout << "p2==" << p2 << endl;
  cout << "p3==" << p3 << endl;

  delete[] arr;

  int* arr2 = new int[10]{1,2,4,8,16,32,64,128,256,512};
  p1 = arr2;

  int* arr3 = new int[10];
  p2 = arr3;

  arr3 = arr2;
  print_array(cout, arr2, 10);
  print_array(cout, arr3, 10);

}
catch (exception& e){
  cerr << e.what() << endl;
  return 1;
}
catch (...){
  cerr << "Unknown exception" << endl;
  return 2;
}
