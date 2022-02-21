/* g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` */
#include "std_lib_facilities.h"

struct B1 {
  virtual void vf() {cout << "B1::vf()" << endl;};
  void f() {cout << "B1::f()" << endl;};
  virtual void pvf() =0;
};

struct D1:B1 {
  void vf() override{cout << "D1:B1::vf()" << endl;};
  void f() {cout << "D1:B1::f()" << endl;};
};

struct D2:D1 {
  void pvf() override {cout << "D2:D1::pvf()" << endl;};
};

struct B2 {
  virtual void pvf() =0;
};

struct D21:B2 {
  string str = "D21:B2::pvf()";
  void pvf() override {cout << str << endl;};
};

struct D22:B2 {
  int i = 30;
  void pvf() override {cout << i << endl;};
};

void f(B2& b) {
  b.pvf();
}

int main() {

  /*B1 b;
  b.vf();
  b.f();

  D1 d;
  d.vf();
  d.f();

  B1& ref {d};
  ref.vf();
  ref.f();

  D2 d2;
  d2.vf();
  d2.f();
  d2.pvf();*/

  D21 d_21;
  f(d_21);

  D22 d_22;
  f(d_22);


}
