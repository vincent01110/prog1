#include "std_lib_facilities.h"

using namespace std;

struct Item
{
  string name;
  int iid;
  double value;
  Item() :name(), iid(0), value(0) {};
  Item(string n, int i, double v) :name(n), iid(i), value(v) {};
};

struct  Comp_by_name {
    bool operator()(const Item& a, const Item& b) const
    {
        return a.name < b.name;
    }
};

struct Comp_by_iid {
  bool operator() (const Item& a, const Item& b) const
  {
    return a.iid < b.iid;
  }
};

struct Comp_by_value {
  bool operator() (const Item& a, const Item& b) const
  {
    return a.value > b.value;
  }
};

int main()
try{
  vector<Item> vi;
  string iname = "input.txt";
  ifstream ist{iname};
  if (!ist) error("can't open input file ",iname);
  string nm;
  int id;
  double val;
  while(ist>>nm>>id>>val) {
    vi.push_back(Item{nm, id, val});
  }
  for (int i = 0; i < vi.size(); i++) {
    cout << vi[i].name << ' ' << vi[i].iid << ' ' << vi[i].value << endl;
  }

  cout << "\n2.:" << endl;
  sort(vi.begin(), vi.end(), Comp_by_name());
  for (int i = 0; i < vi.size(); i++) {
    cout << vi[i].name << ' ' << vi[i].iid << ' ' << vi[i].value << endl;
  }

  cout << "\n3.:" << endl;
  sort(vi.begin(), vi.end(), Comp_by_iid());
  for (int i = 0; i < vi.size(); i++) {
    cout << vi[i].name << ' ' << vi[i].iid << ' ' << vi[i].value << endl;
  }

  cout << "\n4.:" << endl;
  sort(vi.begin(), vi.end(), Comp_by_value());
  for (int i = 0; i < vi.size(); i++) {
    cout << vi[i].name << ' ' << vi[i].iid << ' ' << vi[i].value << endl;
  }

  cout << "\n5.:" << endl;
  vi.push_back(Item{"horse shoe", 99, 12.34});
  vi.push_back(Item{"Canon S400", 9988, 499.95});
  for (int i = 0; i < vi.size(); i++) {
    cout << vi[i].name << ' ' << vi[i].iid << ' ' << vi[i].value << endl;
  }

  cout << "\n6.:" << endl;
  cout << "Enter 2 Names to remove them" << endl;
  string n1, n2;
  cin >> n1 >> n2;
  find(vi.begin(), vi.end(), n1);

}
catch(exception& e){
  cerr << e.what() << endl;
  return 1;
}
catch(...){
  cerr << "Unknown exception" << endl;
  return 2;
}
