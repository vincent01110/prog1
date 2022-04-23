#include "std_lib_facilities.h"

using namespace std;

class My_out_of_range{};

struct No_default {
  No_default(int k) { a = k; }
  int a = 0;
  int b = 0;
};

template<typename T, typename A = allocator<T>>
class My_vector {
  A alloc;
  int sz;
  T* elem;
  int space;
  void debug(const string& str)
  {
    cerr << this << "->" << str << " elem ptr: " << elem << endl;
  }
public:
  My_vector(): sz{0}, space{0}, elem{nullptr} {}
  explicit My_vector(int s):
                    sz(s), elem{alloc.allocate(s)}, space(s)
  {
    for(int i = 0; i < s; ++i) alloc.construct(&elem[i], T());
    //debug("int constructor");
  }
  My_vector(initializer_list<T> lst):
            sz(lst.size()), elem{alloc.allocate(sz)}, space(lst.size())
  {
    //copy(lst.begin(), lst.end(), elem);
    for(int i = 0; i < sz; ++i) alloc.construct(&elem[i], *(lst.begin()+i));
    //debug("lst constructor");
  }
  My_vector(const My_vector& arg):
            sz{arg.sz}, elem{alloc.allocate(sz)}, space{arg.sz}
  {
    //copy(arg.elem, arg.elem+arg.sz, elem);
    for(int i = 0; i < sz; ++i) alloc.construct(&elem[i], arg[i]);
    //debug("copy constructor");
  }
  My_vector& operator=(const My_vector& arg)
  {
    if(this == &arg) return *this;

    if(arg.sz <= space)
    {
      for(int i = 0; i < arg.sz; ++i)
          alloc.construct(&elem[i], arg[i]);
      for(int i = arg.sz; i < sz; ++i)
          alloc.destroy(&elem[i]);
      sz = arg.sz;
      return *this;
    }

    T* p = alloc.allocate(arg.sz);
    //copy(arg.elem, arg.elem+arg.sz, p);
    for(int i = 0; i < arg.sz; ++i) alloc.construct(&p[i], arg[i]);
    alloc.deallocate(elem, space);
    //delete[] elem;
    elem = p;
    sz = arg.sz;
    space = arg.space;
    //debug("copy assignment");
    return *this;
  }
  My_vector(My_vector&& arg): sz{arg.sz}, elem{arg.elem}, space{arg.space}
  {
    arg.sz = 0;
    arg.space = 0;
    arg.elem = nullptr;
    //debug("move constructor");
  }
  My_vector& operator=(My_vector&& arg)
  {
    //delete[] elem;
    for(int i = 0; i < sz; ++i) alloc.destroy(&elem[i]);
    alloc. deallocate(elem, space);
    space = arg.space;
    sz = arg.sz;
    elem = arg.elem;
    arg.sz = 0;
    arg.space = 0;
    arg.elem = nullptr;
    //debug("move assignment");
    return *this;
  }
  ~My_vector()
  {
    //delete[] elem; /*debug(" destructor");*/
    for(int i = 0; i < sz; ++i) alloc.destroy(&elem[i]);
    alloc.deallocate(elem, space);
  }

  int size() const { return sz; }
  int capacity() const { return space; }
  //double get(int i) const { return elem[i]; }
  //void set(int i, double val) { elem[i] = val; }

  T& operator[](int n) { return elem[n]; }
  const T& operator[](int n) const { return elem[n]; }

  T& at(int n)
  {
    if(n < 0 || n >= sz) throw My_out_of_range();
    return elem[n];
  }

  const T& at(int n) const
  {
    if(n < 0 || n >= sz) throw My_out_of_range();
    return elem[n];
  }

  void reserve(int newalloc)
  {
    if(newalloc <= space) return;
    //T* p = new T[newalloc];
    T* p = alloc.allocate(newalloc);
    for(int i = 0; i < sz; ++i) alloc.construct(&p[i], elem[i]);
    //for(int i = 0; i < sz; ++i) p[i] = elem[i];
    for(int i = 0; i < sz; ++i) alloc.destroy(&elem[i]);
    alloc.deallocate(elem, space);
    //delete[] elem;
    elem = p;
    space = newalloc;
  }

  void resize(int newsize, T val = T())
  {
    reserve(newsize);
    for(int i = sz; i < newsize; ++i) alloc.construct(&elem[i], val);
    for(int i = newsize; i < sz; ++i) alloc.destroy(&elem[i]);
    sz = newsize;
  }

  void push_back(const T& d)
  {
    if(space == 0)
        reserve(8);
    else if (sz == space)
        reserve(2*space);
    //elem[sz] = d;
    alloc.construct(&elem[sz], d);
    ++sz;
  }

};


My_vector<double> fill()
{
   My_vector<double> t{1, 3.5, 12.89, 23};
   return t;
}

My_vector<double> glob(10);

void test_constructors()
{
  cout << "mv1" << endl;
  My_vector<double> mv {15.2, 18.6, 120.1};
  for(int i = 0; i < mv.size(); ++i)
    cout << mv.at(i) << ' ';
  cout << endl;

  cout << "mv2" << endl;
  My_vector<double> mv2 (mv);
  for(int i = 0; i < mv2.size(); ++i)
    cout << mv2.at(i) << ' ';
  cout << endl;

  cout << "mv3" << endl;
  My_vector<double> mv3 {1.4, 18.6, 120.1};
  mv3 = mv;
  for(int i = 0; i < mv3.size(); ++i)
    cout << mv3.at(i) << ' ';
  cout << endl;

  cout << "mv4" << endl;
  My_vector<double> mv4 = fill();
  for(int i = 0; i < mv4.size(); ++i)
    cout << mv4.at(i) << ' ';
  cout << endl;

  cout << "mv5" << endl;
  My_vector<double> mv5 {1.4, 18.6, 120.1};
  mv5 = fill();
  for(int i = 0; i < mv5.size(); ++i)
    cout << mv5.at(i) << ' ';
  cout << endl;
}



int main()
/*try*/{

  test_constructors();

  My_vector<double> dmv {10.5, 10.3, 10.7};
  for(int i = 0; i < dmv.size(); ++i)
      cout << dmv[i] << endl;

  My_vector<string> smv {"Jack", "Jill", "John"};
  for(int i = 0; i < smv.size(); ++i)
      cout << smv[i] << endl;

  My_vector<No_default> ndmv {No_default(2)};
  ndmv.resize(10, No_default(2));


  return 0;
}
/*catch(exception& e){
  cerr << e.what() << endl;
  return 1;
}
catch(...){
  cerr << "Unknown exception" << endl;
  return 2;
}*/
