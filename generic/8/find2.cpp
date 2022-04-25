#include <iostream>
#include <vector>

template<typename Iterator, typename Predicate>
Iterator find(Iterator first, Iterator last, Predicate pred)
{
  while(first != last && !pred(*first)) ++first;

  return first;
}

bool odd(int x) { return x % 2; }

int main()
{
  std::vector<int> v;
  int a, x=10;

  while(std::cin>>a) v.push_back(a);

  auto p = find(v.begin(), v.end(), odd);

  if(p != v.end())
    std::cout << "Megtaláltuk!\n";
  else
    std::cout << "Nem találtuk meg!\n";

  return 0;
}
