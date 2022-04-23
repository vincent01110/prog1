#include "std_lib_facilities.h"

using namespace std;

class My_vector {
  int sz;
  double* elem;
public:
  My_vector(int s): sz(s), elem{new double[s]}
  {
    for(int i = 0; i < s; ++i) elem[i]=0;
  }
  My_vector(initializer_list<double> lst):
            sz(lst.size()), elem{new double[sz]}
  {
    copy(lst.begin(), lst.end(), elem);
  }
  My_vector(const My_vector& arg):
            sz{arg.sz}, elem{new double[sz]}
  {
    copy(arg.elem, arg.elem+arg.sz, elem);
  }
  My_vector& operator=(const My_vector& arg)
  {
    double* p = new double[arg.sz];
    copy(arg.elem, arg.elem+arg.sz, p);
    delete[] elem;
    elem = p;
    sz = arg.sz;
    return *this;
  }
  ~My_vector() { delete[] elem; }

  int size() const { return sz; }
  double get(int i) const { return elem[i]; }
  void set(int i, double val) { elem[i] = val; }
};


int main()
try{

  My_vector mv(10);

  cout << "mv size==" << mv.size() << endl;

  for(int i = 0; i < mv.size(); ++i)
    mv.set(i, i*1.5);

  for(int i = 0; i < mv.size(); ++i)
    cout << mv.get(i) << ' ';
  cout << endl;


  My_vector mv2{10.2, 14.6, 20.1};

  cout << "mv2 size==" << mv2.size() << endl;

  for(int i = 0; i < mv2.size(); ++i)
    cout << mv2.get(i) << ' ';
  cout << endl;

  //My_vector mv3 = mv2; NEM JÓ!!!
  My_vector mv3 (mv);
  cout << "mv3 size==" << mv3.size() << endl;
  for(int i = 0; i < mv3.size(); ++i)
    cout << mv3.get(i) << ' ';
  cout << endl;

  My_vector mv4{4.2, 8.6, 20.1};
  mv4 = mv;
  cout << "mv4 size==" << mv4.size() << endl;
  for(int i = 0; i < mv4.size(); ++i)
    cout << mv4.get(i) << ' ';
  cout << endl;



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
