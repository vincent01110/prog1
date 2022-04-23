#include "std_lib_facilities.h"

void print_vector(ostream& os, vector<int> vec, int n)
{
  for(int i = 0; i < n; ++i)
      os<<vec[i]<<' ';
  os<<endl;
}

int main()
try{


  vector<int> vec =
                {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
  print_vector(cout, vec, vec.size());

  vector<int> vec2 =
                {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
  print_vector(cout, vec2, vec2.size());

  vector<int> vec3 =
                {100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
                 110, 111, 112, 113, 114, 115, 116, 117, 118, 119};
  print_vector(cout, vec3, vec3.size());

}
catch (exception& e){
  cerr << e.what() << endl;
  return 1;
}
catch (...){
  cerr << "Unknown exception" << endl;
  return 2;
}
