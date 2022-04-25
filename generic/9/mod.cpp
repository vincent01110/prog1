#include <vector>
#include <iostream>
#include <algorithm>

void print_modulo(const std::vector<int>& v, std::ostream& os, const int& m)
{
  std::for_each(v.begin(), v.end(), [&os, m](int x) { if(x%m==0) os<<x<<'\n'; });
}


int main()
{
  std::vector<int> v = {10, 20, 30, 40, 50};
  int m = 20;

  print_modulo(v, std::cout, m);

  return 0;
}
