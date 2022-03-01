#include "std_lib_facilities.h"

struct Person {
private:
  string nme;
  int ag;
public:
  Person() { };
  Person(string nm, int aa): nme(nm), ag(aa){};

  string name() const { return nme; }
  int age() const { return ag; }
};

istream& operator>>(istream& is, Person& p){
  string n;
  int a;
  is >> n >> a;
  return is;
}

ostream& operator<<(ostream& os, Person& p){
  os << p.name() << ' ' << p.age();
  return os;
}


int main(){
  /*Person dog;
  dog.name = "Goofy";
  dog.age = 63;*/

  Person inp_per;
  cin >> inp_per;
  cout << inp_per << endl;
}
