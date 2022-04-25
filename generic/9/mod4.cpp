#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

template<typename T, typename K>
void print_modulo(const T& v, std::ostream& os, const K& m)
{
  auto Modulo_print = [&os, m](int x) { if(x%m==0) os<<'\t'<<x<<'\n'; };
  std::for_each(v.begin(), v.end(), Modulo_print);
}

int main()
{
  int m = 20;
  std::vector<int> v = {10, 20, 30, 40, 50};
  std::list<int> l = {100, 200, 310, 401, 560};

  std::cout << "v mod m:" << std::endl;
  print_modulo(v, std::cout, m);

  std::cout << "l mod m:" << std::endl;
  print_modulo(l, std::cout, m);


  return 0;
}
