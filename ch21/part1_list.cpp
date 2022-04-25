#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Item{
  string name;
  int iid;
  double value;

  Item(string n, int i, double v): name(n), iid(i), value(v) {}
};

template<typename T>
void my_print(const T& v)
{
  for(const auto& e : v)
    cout << '\t' << e.name << ' ' << e.iid << ' ' << e.value << endl;
}

template<typename Iterator, typename Predicate>
Iterator my_find(Iterator first, Iterator last, Predicate pred)
{
  while(first != last && !pred(*first)) ++first;

  return first;
}


int main()
{
  list<Item> li;

  string iname = "input.txt";
  ifstream ist{iname};
  if (!ist) cout << "can't open input file==" << iname;
  string nm;
  int id;
  double val;
  while(ist>>nm>>id>>val) {
    li.push_back(Item{nm, id, val});
  }
  //cout << "After read: " << endl;
  //my_print(li);

  li.sort([](const Item& a, const Item& b) { return a.name < b.name; });
  //cout << "After sort by name: " << endl;
  //my_print(li);


  li.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });
  //cout << "After sort by iid: " << endl;
  //my_print(li);

  li.sort([](const Item& a, const Item& b) { return a.value > b.value; });
  //cout << "After sort by value: " << endl;
  //my_print(li);

  li.push_back(Item("horse shoe", 99, 12.34));
  li.push_back(Item("Canon S400", 9988, 499.95));
  cout << "After insertion: " << endl;
  my_print(li);


  cout << "After delete by name: " << endl;
  list<Item>::iterator p =
        my_find(li.begin(),li.end(), [](Item x) { return x.name == "FEFA"; });
  li.erase(p);
  p = my_find(li.begin(), li.end(), [](Item x) { return x.name == "WYWH"; });
  li.erase(p);
  my_print(li);

  cout << "After delete by iid: " << endl;
  p = my_find(li.begin(), li.end(), [](Item x) { return x.iid == 1; });
  li.erase(p);
  p = my_find(li.begin(), li.end(), [](Item x) { return x.iid == 9988; });
  li.erase(p);
  my_print(li);


}
