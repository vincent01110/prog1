#include "std_lib_facilities.h"

template<typename T>
struct S
{
private:
    T val;

public:
    S(): val(T()) {};
    S(T v): val(v) {};
    T& get();
    const T& get() const;
    void set(T t);
    T& operator=(const T&);

};

    template<typename T> T& S<T>::get() { return val; }
    template<typename T> const T& S<T>::get() const { return val; }
    template<typename T> void S<T>::set(T t) { val = t; }
    template<typename T> T& S<T>::operator=(const T& t)
    {
      val = t;
      return val;
    }
    template<typename T> istream& operator>>(istream& is, S<T>& ss)
    {
        T v;
        cin >> v;
        if (!is) return is;
        ss = v;
        return is;
    }
    template<typename T> void read_val(T& v) { cin >> v; }
    /*template<typename T> istream& operator>>(istream& is, vector<T>& ss)
    {
      T v;
      cin >> v;
      ss.push_back(v);
      return is;
    }
    template<typename T> ostream& operator<<(ostream& os, vector<T>& ss)
    {
      for(int i = 0; i < ss.size(); ++i)
          os << ss[i] << endl;
      return os;
    }*/

int main()
try{
  S<int> is {6};
  S<char> cs{'h'};
  S<double> ds{2.6};
  S<string> ss{"parts"};
  vector<int> vec {1, 3, 5, 7, 9};
  S<vector<int>> vs (vec);

  /*cout << "drill::4" << endl;
  cout << is.val << endl;
  cout << cs.val << endl;
  cout << ds.val << endl;
  cout << ss.val << endl;
  for(int i = 0; i < vs.val.size(); ++i)
      cout << vs.val[i] << endl;*/


  cout << "drill::8" << endl;
  cout << is.get() << endl;
  cout << cs.get() << endl;
  cout << ds.get() << endl;
  cout << ss.get() << endl;
  for(int i = 0; i < vs.get().size(); ++i)
      cout << vs.get()[i] << endl;

  cout << "drill::9" << endl;
  is.set(2);
  cout << is.get() << endl;

  cout << "drill::10" << endl;
  S<int> fff {8};
  is = fff;
  cout << is.get() << endl;

  cout << "drill::13" << endl;
  read_val(is);
  cout << is.get() << endl;
  read_val(cs);
  cout << cs.get() << endl;
  read_val(ds);
  cout << ds.get() << endl;
  read_val(ss);
  cout << ss.get() << endl;

/*  while(cin) read_val(vs);
  for(int i = 0; i < vs.get().size(); ++i)
      cout << vs.get()[i] << endl;*/

  return 0;

}
catch (exception& e){
  cerr << e.what() << endl;
  return 1;
}
catch (...){
  cerr << "Unknown exception" << endl;
  return 2;
}
