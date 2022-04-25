#include <iostream>
#include <vector>

using namespace std;

template<typename Iterator, typename Predicate>
Iterator find(Iterator first, Iterator last, Predicate pred)
{
  while(first != last && !pred(*first)) ++first;

  return first;
}
/*
class Larger_than {
  int v;
public:
  Larger_than(int vv): v{vv} {};
  bool operator()(int x) const { return x > v; }
};*/

int main()
{
  vector<int> v;
  int a, x = 42;

  while(cin>>a) v.push_back(a);

  //auto p = find(v.begin(), v.end(), [](int e) { return e > 42; });
  auto p = find(v.begin(), v.end(), [&](int e) { return e > x; });

  if(p != v.end())
    cout << "Megtaláltuk!\n";
  else
    cout << "Nem találtuk meg!\n";

  return 0;
}
