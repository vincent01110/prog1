#include "std_lib_facilities.h"

void print_vector(ostream& os, vector<int> v, int n)
{
  for(int i = 0; i < n; ++i)
      os<<v[i]<<' ';
  os<<endl;
}

int main()
try{

  vector<int> vec = {1,2,4,8,16,32,64,128,256,512};
  vector<int> vec2;
  for(int i = 0; i < 10; ++i) vec2.push_back(vec[i]);
  print_vector(cout, vec, 10);
  print_vector(cout, vec2, 10);

}
catch (exception& e){
  cerr << e.what() << endl;
  return 1;
}
catch (...){
  cerr << "Unknown exception" << endl;
  return 2;
}
