#include <iostream>
#include <vector>

template<typename Iterator, typename Predicate>
Iterator find(Iterator first, Iterator last, Predicate pred)
{
  while(first != last && !pred(*first)) ++first;

  return first;
}

int v = 7;
bool larger_than_42(int x) { return x > 42; }
bool larger_than_v(int x) { return x > v; } //működik de NE

int main()
{
  std::vector<int> v;
  int a, x=10;

  while(std::cin>>a) v.push_back(a);

  auto p = find(v.begin(), v.end(), larger_than_v);

  if(p != v.end())
    std::cout << "Megtaláltuk!\n";
  else
    std::cout << "Nem találtuk meg!\n";

  return 0;
}
