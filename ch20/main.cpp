#include "std_lib_facilities.h"

int main()
try{
  int n = 10;
  int A1[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> vtr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  list<int> lis = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  int *A2;
  A2 = A1;

  for(int i = 0; i < vtr.size(); i++) vtr[i] += 3;
  vector<int> vtr2;
  vtr2 = vtr;

  list<int> lis2;
  lis2 = lis;


  for (int i = 0; i < n; i++) {
    A1[i] += 2;
    cout << A1[i] << ' ';
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << A2[i] << ' ';
  }
  cout << endl;

  for (int i = 0; i < vtr.size(); i++) {
    cout << vtr[i] << ' ';
  }
  cout << endl;
  for (int i = 0; i < vtr2.size(); i++) {
    cout << vtr2[i] << ' ';
  }
  cout << endl;

  for (auto l : lis) {
    cout << l << ' ';
  }
  cout << endl;
  for (auto l2 : lis2) {
    cout << l2 << ' ';
  }
  cout << endl;
}
catch(exception& e)
{
  cerr << e.what() << endl;
  return 1;
}
catch(...)
{
  cerr << "Unknown exception" << endl;
}
