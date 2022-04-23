#include "std_lib_facilities.h"

vector<int> gv = {1,2,4,8,16,32,64,128,256,512};

void print_vector(ostream& os, vector<int> v, int n)
{
  for(int i = 0; i < n; ++i)
      os<<v[i]<<' ';
  os<<endl;
}

void f(vector<int> vec)
{
  vector<int> lv(gv.size());
  lv = gv;
  print_vector(cout, lv, lv.size());

  vector<int> lv2 = vec;
  print_vector(cout, lv2, lv2.size());
}


int main()
try{
  f(gv);

  vector<int> vv;
  int x;
  vv.push_back(1);
  for(int i = 2; i < 11; ++i)
  {
    x=1;
    for(int j = i-1; j > 0; --j)
    {
      x *= j;
    }
    x *= i;
    vv.push_back(x);
  }
  f(vv);

}
catch (exception& e){
  cerr << e.what() << endl;
  return 1;
}
catch (...){
  cerr << "Unknown exception" << endl;
  return 2;
}
