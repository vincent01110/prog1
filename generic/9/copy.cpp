#include <vector>
#include <list>
#include <iostream>

template<typename Iterator, typename Out>
Out my_copy(Iterator first, Iterator last, Out res)
{
  while(first != last)
  {
    *res = *first;
    ++first;
    ++res;
  }
  return res;
}

int main()
{
  std::vector<double> v(10);
  std::list<int> l = {1, 2, 3, 4, 5};

  if(v.size() < l.size())
  {
    std::cout << "v kisebb, mint l\n";
    return 1;
  }
  my_copy(l.begin(), l.end(), v.begin());

  for(const auto& e : l)
    std::cout << e << ' ';
  std::cout << std::endl;

  for(const auto& e : v)
    std::cout << e << ' ';
  std::cout << std::endl;

  return 0;
}
