#include "std_lib_facilities.h"

struct Person {
private:
  string fnme;
  string lnme;
  int ag;
public:
  Person() {};
  Person(string fnm, string lnm, int aa);

  string fname() const { return fnme; }
  string lname() const { return lnme; }
  int age() const { return ag; }
};

Person::Person(string fn, string ln,int aa): fnme(fn), lnme(ln), ag(aa){
  if (aa < 0 || aa > 150) {
    error("Age: out_of_range");
  }

  string nn = fn + ln;
  for (int i = 0; i < nn.length(); i++) {
    switch (nn[i]) {
      case ';': case ':': case '"': case '[': case ']': case '*':
      case '&': case '^': case '%': case '$': case '#': case '@': case '!':
        error("Name: Illegal_character");
        break;
      default:
        break;
    }
  }
}

istream& operator>>(istream& is, Person& p){
  string fn, ln;
  int a;
  is >> fn >> ln >> a;
  p = Person(fn, ln, a);
  return is;
}

ostream& operator<<(ostream& os, Person& p){
  os << p.fname() << ' ' << p.lname() << ' ' << p.age();
  return os;
}


int main()
try {
  /*Person dog;
  dog.name = "Goofy";
  dog.age = 63;*/

  /*Person inp_per;
  cin >> inp_per;
  cout << inp_per << endl;*/

  int i = -1;
  Person per;
  vector<Person> vec;
  while(cin){
    cin >> per;
    if(per.fname() == "end") break;
    vec.push_back(per);
  }
  for (Person j : vec) {
    cout << j << endl;
  }

}
catch(exception& e){
  cerr << "exception: " << e.what() << endl;
  return 1;
}
catch(...){
  cerr << "Unknown exception!" << endl;
  return 2;
}
