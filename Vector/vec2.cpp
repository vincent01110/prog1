#include "std_lib_facilities.h"

using namespace std;

class My_vector {
  int sz;
  double* elem;
  void debug(const string& str)
  {
    cerr << this << "->" << str << " elem ptr: " << elem << endl;
  }
public:
  explicit My_vector(int s): sz(s), elem{new double[s]}
  {
    for(int i = 0; i < s; ++i) elem[i]=0;
    debug("int constructor");
  }
  My_vector(initializer_list<double> lst):
            sz(lst.size()), elem{new double[sz]}
  {
    copy(lst.begin(), lst.end(), elem);
    debug("lst constructor");
  }
  My_vector(const My_vector& arg):
            sz{arg.sz}, elem{new double[sz]}
  {
    copy(arg.elem, arg.elem+arg.sz, elem);
    debug("copy constructor");
  }
  My_vector& operator=(const My_vector& arg)
  {
    double* p = new double[arg.sz];
    copy(arg.elem, arg.elem+arg.sz, p);
    delete[] elem;
    elem = p;
    sz = arg.sz;
    debug("copy assignment");
    return *this;
  }
  My_vector(My_vector&& arg): sz{arg.sz}, elem{arg.elem}
  {
    arg.sz = 0;
    arg.elem = nullptr;
    debug("move constructor");
  }
  My_vector& operator=(My_vector&& arg)
  {
    delete[] elem;
    sz = arg.sz;
    elem = arg.elem;
    arg.sz = 0;
    arg.elem = nullptr;
    debug("move assignment");
    return *this;
  }
  ~My_vector() { delete[] elem; debug(" destructor");}

  int size() const { return sz; }
  double get(int i) const { return elem[i]; }
  void set(int i, double val) { elem[i] = val; }
};

My_vector fill()
{
   My_vector t{1, 3.5, 12.89, 23};
   return t;
}

My_vector glob(10);

int main()
try{

  cout << "mv1" << endl;
  My_vector mv {15.2, 18.6, 120.1};
  for(int i = 0; i < mv.size(); ++i)
    cout << mv.get(i) << ' ';
  cout << endl;

  cout << "mv2" << endl;
  My_vector mv2 (mv);
  for(int i = 0; i < mv2.size(); ++i)
    cout << mv2.get(i) << ' ';
  cout << endl;

  cout << "mv3" << endl;
  My_vector mv3 {1.4, 18.6, 120.1};
  mv3 = mv;
  for(int i = 0; i < mv3.size(); ++i)
    cout << mv3.get(i) << ' ';
  cout << endl;

  cout << "mv4" << endl;
  My_vector mv4 = fill();
  for(int i = 0; i < mv4.size(); ++i)
    cout << mv4.get(i) << ' ';
  cout << endl;

  cout << "mv5" << endl;
  My_vector mv5 {1.4, 18.6, 120.1};
  mv5 = fill();
  for(int i = 0; i < mv5.size(); ++i)
    cout << mv5.get(i) << ' ';
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
